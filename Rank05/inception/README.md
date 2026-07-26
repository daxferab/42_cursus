*This project has been created as a part of the 42 curriculum by daxferna*
# 🐋 Inception 🐋
## Description
This project consists on creating a small Wordpress blog using Docker.\
It must consist on these three containers:
- NGINX: with TLSv1.2 or TLSv1.3 only. (This will be the only entrypoint through the port 443 (https))
- MariaDB: without NGINX
- Wordpress: with phpfpm configured. Without NGINX

There must also be two named volumes that contain:
- The Wordpress database (with an admin and a regular user)
- The Wordpress website files

The use of Docker Hub is forbidden.\

It's also required to set up a docket-network, in order for the containers to communicate between each other\
The domain (pointing to localhost) must be `login.42.fr`\
There has to be one Dockerfile per container, and one docker-compose.yml that sets them up. Everything must be executed using a Makefile.

## Instructions
To set up the containers, one must follow these simple steps:
- Paste a properly configured **secrets** folder in root
- Add an **.env** file under the srcs/ folder
- Run `make` to set up the containers.
	- This can also be done in two steps; `make build` to build the image and `make up` to start the container

Once the containers are running, the Wordpress page can be accessed through https://localhost, or any other domain name properly set in `/etc/hosts`

- Run `make down` to turn the containers off
- Run `make clean` or `make fclean` to clear the containers or the containers and directories

## Project description
Set-up the web server with NGINX:
	- Install NGINX
	- The default server-client communication is HTTP, so we should install TLS to protect it and transform it into HTTPS
	- To install TLS we need:
		- Public certificate and private key
		- Modify the nginx.conf file so it points to those certificates

- **Virtual Machines vs Docker**\
A virtual machine is a software used to have a full OS inside of a host machine and completely isolated from it, while Docker is an environment that holds only the required dependencies that are needed from an application to work.
An VM has its own kernel, while Docker shares it with the host machine, which makes it lighter
Docker is faster on startup than a VM and its portability is higher

- **Secrets vs Environment variables**\
Environment variables are used for storing information that will be used by one or more containers.\
Secrets are similar, but with them we let Docker know the info there is highly sensitive, and that it should be used carefuly and only when needed. They will not leave traces in logs and wont be visible for other users.

You can select which secrets are shared with a container.

- **Docker Network vs Host Network**\
The main difference is isolation and port management.\
**Docker Network** -> the container runs on its own isolated virtual network with a private IP address. Docker handles communication with the host or the outside world. You must explicitly map container ports to the host to access services externally, which achieves better security and isolation.\
**Host network** -> the container shares the host machine's network. It uses the host's IP addresses and ports. This removes network isolation and requires that the used ports do not conflict with other services on the host.

- **Docker Volumes vs Bind Mount**\
The distinction between **Docker volumes** and **bind mounts** primarily concerns portability, management, and the underlying storage mechanism.

| Feature | Docker Volumes | Bind Mounts |
| :--- | :--- | :--- |
| **Management** | Docker | User/host OS |
| **Location** | Docker-managed path (hidden) | Host path specified by user |
| **Portability** | High (works across hosts easily) | Low (depends on host directory structure) |
| **Performance** | Optimized (especially on Windows/macOS) | Depends on host filesystem |
| **Use Case** | Production data persistence, backups | Development, code editing |

Use **volumes** for production data storage where you want Docker to handle the details, and use **bind mounts** when you need direct access to host files, typically during development.

## Resources
- **Documentation:** \
[Docker instalation in Debian VM](https://docs.docker.com/engine/install/debian/#install-using-the-repository)
[Access VM through ssh](https://www.youtube.com/watch?v=KQbiii-EEQs)
[Docker docs](https://docs.docker.com/)\
[Docker CLI Cheatsheet](https://docs.docker.com/get-started/docker_cheatsheet.pdf)
[Inception guide](https://tuto.grademe.fr/inception/)
[OpenSSL guide](https://docs.openssl.org/)
[404 Error](https://stackoverflow.com/questions/57561236/how-nginx-process-404-fallback-in-try-files)

-**AI usage** \
Used to understand concepts and complex commands
None of the code within this repo is AI generated
