COMPOSE_PATH = ./srcs/docker-compose.yml
VOLUMES_PATH = /home/daxferna/data

all : setup
	sudo docker compose -f $(COMPOSE_PATH) up --build -d

# Create volume folders and set permissions
setup:
	sudo mkdir -p $(VOLUMES_PATH)/mariadb
	sudo mkdir -p $(VOLUMES_PATH)/wordpress
	sudo chown -R 777 $(VOLUMES_PATH)/mariadb
	sudo chown -R 777 $(VOLUMES_PATH)/wordpress

stop:
	sudo docker compose -f $(COMPOSE_PATH) stop

down:
	sudo docker compose -f $(COMPOSE_PATH) down

up:
	sudo docker compose -f $(COMPOSE_PATH) up -d

clean:
	sudo docker compose -f $(COMPOSE_PATH) down -v

fclean: clean
	@sudo rm -rf $(VOLUMES_PATH)
	sudo docker system prune -af

re: fclean all

.PHONY: all setup stop down clean fclean re
