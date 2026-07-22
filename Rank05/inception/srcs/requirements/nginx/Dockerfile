FROM debian:bookworm

# Install nginx and openssl. Remove cache
RUN apt update -y \
	&& apt install -y nginx openssl \
	&& rm -rf /var/lib/apt/lists/*
	
# Create folder for ssl certs
RUN mkdir -p /etc/nginx/ssl

# This line is for requesting the certificates (only generating the public and private key)
# -x509: autosigned certificate | -nodes: skip password | -out: path to store cert | -keyout path to store key | -subj include info the command would ask for
RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/cert.crt \
	-keyout /etc/nginx/ssl/certkey.key \
	-subj "/C=SP/ST=Mad/L=Mad/O=42/OU=42Mad/CN=${WP_URL}"

# Create folder to store the conf files
RUN mkdir -p /var/run/nginx

# Copy config files from host into container
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Give permissions to /var/www/html (its where wordpress will write on)
# www-data is the user NGINX and PHP-FPM run as
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

# Let the container keep running (PID 1) (daemon would kill it)
CMD [ "nginx", "-g", "daemon off;" ]
