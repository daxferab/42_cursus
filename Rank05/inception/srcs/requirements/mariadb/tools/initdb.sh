#!/bin/bash

echo "----------- MariaDB: Initializing... ----------"

# Create needed directories and change ownership
# /var/lib/mysql -> keep persistent data
# /run/mysqld -> keep temporary files
mkdir -p /var/lib/mysql /run/mysqld /var/log/mysql && chown -R mysql:mysql /var/lib/mysql /run/mysqld /var/log/mysql

# Get credentials from secrets (automattically mounted in /run)
SQL_PASSWORD=$(cat /run/secrets/db_password)
SQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

if [ ! -d "/var/lib/mysql/$SQL_DATABASE" ]; then # If db doesnt exist
	# skip-grant-tables -> bypass password checks during setup
	# skip-networking -> skips TCP/IP (uses local socket)
	mysqld_safe --skip-grant-tables --skip-networking &

	# Wait for it to start (ping it to know if its silent or it woke up)
	until mysqladmin ping -h localhost --silent; do
		echo "Waiting..."
		sleep 1
	done

	echo "Creating users..."

	# Create users database with user root (-u root) (- EOF ignores tabs)
	# - FLUSH PRIVILEGES -> restores privileges after --skip-grant-tables
	# - % -> allow connections from any host
	# - "IF NOT EXISTS" -> evita error
	# - ALTER USER -> changes root password
	# - FLUSH PRIVILEGES (again) -> Saves all changes (reloads RAM)
	mysql -u root <<-EOF
		FLUSH PRIVILEGES;
		CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
		CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';
		ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
		FLUSH PRIVILEGES;
		EOF

	# Kill the background process (delete temp files, save data, end process)
	mysqladmin -u root -p"${SQL_ROOT_PASSWORD}" shutdown
fi

echo "--------------- MariaDB: Started --------------"
# Executes mysqld as PID 1
# Logs errors in log-error
exec mysqld --log-warnings=1