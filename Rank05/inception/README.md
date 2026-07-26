*This project has been created as a part of the 42 curriculum by daxferna*
# 🐋 Inception 🐋
## Description
This project consists on creating a small WordPress blog using Docker.

It must consist on these three containers:
- NGINX: with TLSv1.2 or TLSv1.3 only. (This will be the only entrypoint through the port 443 (https))
- MariaDB: without NGINX
- WordPress: with phpfpm configured. Without NGINX

There must also be two named volumes that contain:
- The WordPress database (with an admin and a regular user)
- The WordPress website files

The use of Docker Hub is forbidden.

It's also required to set up a docket-network, in order for the containers to communicate between each other\
The domain (pointing to localhost) must be `login.42.fr`

There has to be one Dockerfile per container, and one docker-compose.yml that sets them up. Everything must be executed using a Makefile.

## Instructions
To set up the containers, one must follow these simple steps:
- Paste a properly configured **secrets** folder in root
- Add an **.env** file under the srcs/ folder
- Run `make` to set up the containers.
	- This can also be done in two steps; `make build` to build the image and `make up` to start the container

Once the containers are running, the WordPress page can be accessed through https://localhost, or any other domain name properly set in `/etc/hosts`

- Run `make down` to turn the containers off
- Run `make clean` or `make fclean` to clear the containers or the containers and directories

## Project description
The steps followed to create this project were:
- Documentation (Docker, Nginx, WordPress and MariaDB, also PHP and MySQL)
- Prepare the Virtual Machine:
	- Install Debian with 15Gb to let the containers enough room to deploy
	- Install Docker and giving the main user docker and sudo permissions
	- Creation of the directory for the project
- Write the Dockerfiles, config files and initialization scripts
	- Nginx: Installing nginx and ssl, set it as PID 1
	- MariaDB: Installing mariadb server and running the init script to create the database
	- WordPress: Installing WordPress, php, mariadb client... and running the init script to set the website info and create the users
- Properly set variables in srcs/.env and secrets/
- Set docker-compose.yml to define the containers, volumes, network and secrets
- Write the makefile to create the volume folders and start the containers with compose

- **Virtual Machines vs Docker**\
	A virtual machine is a software that allows to have a full OS inside of a host machine and completely isolated from it, while Docker is an environment that holds only the required dependencies that are needed from an application to work.\
	An VM has its own kernel, while Docker shares it with the host machine, which makes it lighter.\
	Docker is faster on startup than a VM and its portability is higher.

- **Secrets vs Environment variables**\
	Both of them are used to store sensitive information like credentials, usernames, passwords...
	The main difference resides on visibility:
	- Environment variables are stored in a file (.env) that can be accessed from every container
	- Secrets are stored in separate files inside the secrets/ directory, and they can be set so only certain containers have access to certain secret variable

- **Docker Network vs Host Network**

	The main difference is isolation and port management.\
	**Docker Network** -> the container runs on its own isolated virtual network with a private IP address. You must explicitly map container ports to the host to access services externally, which achieves better security and isolation.\
	**Host network** -> the container shares the host machine's network. It uses the host's IP addresses and ports. This removes network isolation and requires that the used ports do not conflict with other services on the host.

- **Docker Volumes vs Bind Mounts**

	| Docker Volumes | Bind Mounts |
	| - | - |
	| Created on container start | Pre-existing folder in host filesystem |
	| Hidden in Docker filesystem | Stored in path specified by user |
	| High portability | Low portability |

## Resources
- **Documentation:** \
[Docker instalation in Debian VM](https://docs.docker.com/engine/install/debian/#install-using-the-repository)\
[Access VM through ssh](https://www.youtube.com/watch?v=KQbiii-EEQs)\
[Docker docs](https://docs.docker.com/)\
[Nginx docs](https://nginx.org/en/docs/)\
[MariaDB docs](https://mariadb.com/docs)\
[Docker CLI Cheatsheet](https://docs.docker.com/get-started/docker_cheatsheet.pdf)\
[Inception guide](https://tuto.grademe.fr/inception/)\
[OpenSSL guide](https://docs.openssl.org/)\
[404 Error](https://stackoverflow.com/questions/57561236/how-nginx-process-404-fallback-in-try-files)

- **AI usage** \
Used to understand concepts and complex commands
None of the code within this repo is AI generated
