COMPOSE = srcs/docker-compose.yml
VOLUME = /home/daxferna/data

all: build up

# Create volume directories in host
$(VOLUMES)/mariadb:
	mkdir -p $(VOLUMES)/mariadb
$(VOLUMES)/wordpress:
	mkdir -p $(VOLUMES)/wordpress

# Build images (requires volume directories)
# Calls compose, -f to specify route
build: $(VOLUMES)/mariadb $(VOLUMES)/wordpress
	docker compose -f $(COMPOSE_FILE) build

# Start / stop containers (-d to run it in the background)
up:
	docker compose -f $(COMPOSE_FILE) up -d

down:
	docker compose -f $(COMPOSE_FILE) down

clean:
	docker compose -f $(COMPOSE_FILE) down
	docker system prune -af

fclean: clean
	docker volume prune -f
	sudo rm -rf $(DATA_DIR)

re: fclean all

.PHONY: all build up down clean fclean re
