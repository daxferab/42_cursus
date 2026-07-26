# User Documentation

## Services provided
This infrastructure consists of three services running in isolated containers:

- **WordPress**: A PHP-FPM container that runs the WordPress application. It processes dynamic content and interacts with the database.
- **MariaDB**: A database container that stores all WordPress data, including user information, posts, and configuration.
- **Nginx**: Acts as the web server. It handles all incoming HTTPS traffic (port 443) and forwards requests to the WordPress container. It is configured to use TLSv1.2 or TLSv1.3.

These services communicate over a private Docker network and persist data using named volumes.

## Starting and Stopping the Project

To set up the containers, one must follow these simple steps:
- Paste a properly configured **secrets** folder in root
- Add an **.env** file under the srcs/ folder
- Run `make` to set up the containers.
	- This can also be done in two steps; `make build` to build the image and `make up` to start the container

- Run `make down` to turn the containers off
- Run `make clean` or `make fclean` to clear the containers or the containers and directories

## Access the website and the admin panel

Once the containers are running, the WordPress page can be accessed through https://localhost, or any other domain name properly set in `/etc/hosts`

To access the admin panel, simply go to `https://localhost/wp-admin`

## Locate and manage credentials

The credentials are located in the secrets folder and the .env file

## Check that services are running properly

Once your Docker Compose is UP this ocmmands can be run

Check containers: `docker compose ps`
Check volumes list: `docker volume ls`
Inspect volume: `docker volume inspect <volume name>`
Check network `docker network ls`
