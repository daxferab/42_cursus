FROM debian:bookworm

# Update packages
RUN apt-get update -y && apt-get upgrade -y

# ------------------------ WORDPRESS ---------------------------

# wget to install Wordpress via https
RUN apt-get install -y wget

# Install Wordpress (-P to indicate where to install)
# /var/www is the location of the nginx server
RUN wget https://wordpress.org/wordpress-6.9.3.tar.gz -P /var/www

# move to /var/www and unzip. Remove file
RUN cd /var/www && tar -xzf wordpress-6.9.3.tar.gz \
	&& rm wordpress-6.9.3.tar.gz

# Change owner to root recursively for everything inside
RUN chown -R root:root /var/www/wordpress

# ------------------------- PHP-FPM ----------------------------

# Install php, fpm and mysql client
RUN apt-get install -y \
	php8.2 \
	php-fpm \
	php-mysql

# Copy config from host to default PHP config file location
COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

# ---------------------- WORDPRESS CLI -------------------------

# Install CLI to manage wordpress from the terminal
# Set it to be executable
# Move it to the proper directory
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# ---------------------- MariaDB client ------------------------
# To chech if MariaDB is reachable (from the following script)
RUN apt-get install -y mariadb-client

# ---------------------- Initialization script

COPY tools/initwp.sh .
RUN chmod +x ./initwp.sh

# Document the port that will be used by WP
EXPOSE 9000

ENTRYPOINT ["./initwp.sh"]
