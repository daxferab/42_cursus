#!/bin/bash

echo "----------- Wordpress: Initializing... ----------"

WP_PATH="/var/www/html"

# Get credentials from secrets (automattically mounted in /run)
SQL_PASSWORD=$(cat /run/secrets/db_user_password)
SQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

# Ensure PHP runtime dir exists
mkdir -p /run/php

cd /var/www/wordpress

# Wait until mariadb is up
while ! printf "" 2>>/dev/null >/dev/tcp/mariadb/3306; do
	echo "Waiting..."
	sleep 1
done

## If config not set, run
if [ ! -f wp-config.php ]; then

	# creates wp-config.php (link wp to db)
	wp config create \
	--allow-root \				# Allows root access
	--dbname=$SQL_DATABASE \
	--dbuser=$SQL_USER \
	--dbpass=$SQL_PASSWORD \
	--dbhost=mariadb:3306 \		# DB host (MariaDB)
	--path='/var/www/wordpress'	# Path to wordpress

	# finish initial WP instalation (adds admin)
	core install \
	--allow-root \
	--url=$WP_URL \
	--title=$WP_TITLE \
	--admin_user=$WP_ADMIN \
	--admin_password=$WP_ADMIN_PASSWORD \
	--admin_email=$WP_ADMIN_EMAIL \
	--path='/var/www/wordpress'

	# creates normal user
	user create $WP_USER $WP_USER_EMAIL \
	--user_pass=$WP_USER_PASSWORD \
	--role=author \
	--allow-root
	# changes WP files ownership to www-data (the one that runs PHP-FPM)
	# www-data has now permission to do certain things, without having full root permissions
	chown -R www-data:www-data /var/www/wordpress
fi

# Start PHP-FPM as PID 1
echo "Starting PHP"
exec php-fpm8.2 -F
