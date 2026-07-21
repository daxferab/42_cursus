FROM debian:bookworm

# Update packages
RUN apt-get update -y && apt-get upgrade -y

# Install MariaDB and clear cache
RUN apt-get install -y mariadb-server \
	&& rm -rf /var/lib/apt/lists/*

# Create directory for mysql to store files. (-p for making parent folders)
# Then, change its owner (-R recursive)
# Change permissions (everyone reading/exec, writing limited to root/mysql)
RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 755 /var/run/mysqld

# Copy configuration from host to default config files folders
# Editing the original 50-server.cnf file (the daemon section)
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# Copy script to initializate the database (so its not empty and can work)
# Change its permissions (everyone can execute it)
COPY tools/initdb.sh .
RUN chmod +x ./initdb.sh

# Document the port that will be used by MariaDB
EXPOSE 3306

ENTRYPOINT [ "./initdb.sh" ]
