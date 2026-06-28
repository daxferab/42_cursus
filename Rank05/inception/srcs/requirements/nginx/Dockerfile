FROM debian:bookworm

RUN apt update -y && apt install nginx -y

RUN mkdir -p /etc/nginx/ssl

RUN apt install openssl -y

# This line is for requesting the certificates (only generating the public and private key)
# -x509: autosigned certificate | -nodes: skip password | -out: path to store cert | -keyout path to store key | -subj include info the command would ask for
RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/cert.crt \
	-keyout /etc/nginx/ssl/certkey.key \
	-subj "/C=SP/ST=Mad/L=Mad/O=42/OU=42Mad/CN=daxferna.42.fr"

# Create folder to store the conf files
RUN mkdir -p /var/run/nginx

# Copy config files from host (/conf/nginx.conf) into container
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Give permissions to /var/www/html (its where wordpress will write on)
# www-data is the user NGINX and PHP-FPM run as
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

# Let the container keep running (PID 1)
CMD [ "nginx", "-g", "daemon off;" ]
