# Developer Documentation
## Setup environment from scratch
- Install docker from its oficial repo
- Give your user sudo privileges and add it to the *docker* group
- Paste a properly configured **secrets** folder in the root of the repository
- Add an **.env** file under the srcs/ folder

## Build and launch the project
Once the secrets and environment variables have been set, to set up the containers, one must follow these simple steps:
- Run `make` to set up the containers.
	- This can also be done in two steps; `make build` to build the image and `make up` to start the container

- Run `make down` to turn the containers off
- Run `make clean` or `make fclean` to clear the containers or the containers and directories

## Manage the containers and volumes
Once the containers are **UP** and running the following commands can be run

- `docker compose ps` to list the current containers
- `docker volume ls` to list the current volumes
- `docker volume inspect <volume name>` to inspect the specified volume
- `docker network ls` to check current docker networks
- `docker log <service name>` to check the container logs (see if an error ocurred)

## Identify where the project data is stored and how it persist

The volumes are specified in `docker-compose.yml`

```YAML
volumes:
  mariadb:
    driver: local
    driver_opts:
      type: 'none'
      o: 'bind'
      device: '/home/${LOGIN}/data/mariadb'
  wordpress:
    driver: local
    driver_opts:
      type: 'none'
      o: 'bind'
      device: '/home/${LOGIN}/data/wordpress'
```
The volumes are created in: /home/login/data/.


This are some available commands to check volumes:
- `docker volume ls` to list the current volumes
- `docker volume inspect <volume name>` to inspect the specified volume