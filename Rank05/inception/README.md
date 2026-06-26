*This project has been created as a part of the 42 curriculum by daxferna*
# 🐋 Inception 🐋
## Description
The **Inception** project consists on creating 3 Docker containers and 2 volumes within a virtual machine.\
The use of Docker Hub is forbidden, the base of each container must be the penultimate stable version of Debian or Alpine.\
These containers must be set-up simultaneously using Docker Compose, and everything must be executed using a Makefile.\
The containers and it's requirements are:
- NGINX: with TLSv1.2 or TLSv1.3 only. (This will be the only entrypoint through the port 443 (https))
- MariaDB: without NGINX
- Wordpress: with phpfpm configured. Without NGINX

The volumes must be named volumes and they must contain:
- First vol: the Wordpress database
- Second vol: the Wordpress website files

They must be available from /home/login/data from the host machine\
It's also required to set up a docket-network, in order for the containers to communicate between each other\
The wordpress db must have an admin and a regular user.\
The domain (pointing to localhost) must be login.42.fr\
There has to be one Dockerfile per container, and one docker-compose.yml that sets up everything.

## Instructions
Run `make` to set up the containers.

## Project description
Set-up the web server with NGINX

- **Virtual Machines vs Docker**
A virtual machine is a software used to have a full OS inside of a host machine and completely isolated from it, while Docker is an environment that holds only the required dependencies that are needed from an application to work.
An VM has its own kernel, while Docker shares it with the host machine, which makes it lighter
Docker is faster on startup than a VM and its portability is higher

- **Secrets vs Environment variables**
- **Docker Network vs Host Network**
- **Docker Volumes vs Bind Mount**
## Resources
- **Documentation:** \
[Docker docs](https://docs.docker.com/
)\
[Docker CLI Cheatsheet](https://docs.docker.com/get-started/docker_cheatsheet.pdf)
[Inception guide](https://tuto.grademe.fr/inception/)
