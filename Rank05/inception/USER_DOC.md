# User Documentation

## Services provided
This infrastructure consists of three services running in isolated containers:

- **Nginx**: Acts as the web server. It handles all incoming HTTPS traffic (port 443) and forwards requests to the WordPress container. It is configured to use TLSv1.2 or TLSv1.3.
- **WordPress**: A PHP-FPM container that runs the WordPress application. It processes dynamic content and interacts with the database.
- **MariaDB**: A database container that stores all WordPress data, including user information, posts, and configuration.

These services communicate over a private Docker network and persist data using named volumes.

## Starting and Stopping the Project

Make sure you are inside the project directory and have a valid `.env` (in srcs) and a `secrets\` folder in root.

Execute `make` to build and run the services\
Execute `make up` run the services (with already built images)\
Execute `make down` to stop the services\

## Access the website and the admin panel

Go to https://daxferna.42.fr once the service is started\

## Locate and manage credentials

The credentials are located in the secrets folder and the .env file

## Check that services are running properly

Once your Docker Compose is UP this ocmmands can be run

Check containers: `docker compose ps`
Check volumes list: `docker volume ls`
Inspect volume: `docker volume inspect <volume name>`
Check network `docker network ls`
