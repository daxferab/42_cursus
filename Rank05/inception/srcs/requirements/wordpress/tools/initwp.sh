#!/bin/bash

echo "----------- Wordpress: Initializing... ----------"

# Read environment variables (they come from .env via docker-compose)
export SQL_DATABASE="${SQL_DATABASE}"
export SQL_USER="${SQL_USER}"
export WP_URL="${WP_URL}"
export WP_TITLE="${WP_TITLE}"
export WP_ADMIN="${WP_ADMIN}"
export WP_ADMIN_EMAIL="${WP_ADMIN_EMAIL}"
export WP_USER="${WP_USER}"
export WP_USER_EMAIL="${WP_USER_EMAIL}"

WP_PATH="/var/www/wordpress"

# Get credentials from secrets (automattically mounted in /run)
SQL_PASSWORD=$(cat /run/secrets/db_user_password)
SQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

# Ensure PHP runtime dir exists
mkdir -p /run/php
cd $WP_PATH

# Wait until mariadb is up
while ! printf "" 2>>/dev/null >/dev/tcp/mariadb/3306; do
	echo "Waiting..."
	sleep 1
done

if [ ! -f wp-config.php ]; then
# creates wp-config.php (link wp to db)
	wp config create \
	--allow-root \
	--dbname="$SQL_DATABASE" \
	--dbuser="$SQL_USER" \
	--dbpass="$SQL_PASSWORD" \
	--dbhost=mariadb:3306 \
	--path="$WP_PATH"

# finish initial WP instalation (adds admin)
	wp core install \
	--allow-root \
	--url="$WP_URL" \
	--title="$WP_TITLE" \
	--admin_user="$WP_ADMIN" \
	--admin_password="$WP_ADMIN_PASSWORD" \
	--admin_email="$WP_ADMIN_EMAIL" \
	--path="$WP_PATH"

# creates normal user
	wp user create "$WP_USER" "$WP_USER_EMAIL" \
	--user_pass="$WP_USER_PASSWORD" \
	--role=author \
	--allow-root
# changes WP files ownership to www-data (the one that runs PHP-FPM)
# www-data has now permission to do certain things, without having full root permissions
	chown -R www-data:www-data $WP_PATH
fi

# Start PHP-FPM as PID 1
echo "Starting PHP"
exec php-fpm8.2 -F
