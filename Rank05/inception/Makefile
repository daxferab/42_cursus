COMPOSE = srcs/docker-compose.yml
VOLUME = /home/daxferna/data

all: build up

# Create volume directories in host, 999 us mysql UID, 33 is www-data UID
$(VOLUME)/mariadb:
	mkdir -p $(VOLUME)/mariadb
	sudo chown -R 999:999 $(VOLUME)/mariadb
$(VOLUME)/wordpress:
	mkdir -p $(VOLUME)/wordpress
	sudo chown -R 33:33 $(VOLUME)/wordpress

# Build images (requires volume directories)
# Calls compose, -f to specify route
build: $(VOLUME)/mariadb $(VOLUME)/wordpress
	docker compose -f $(COMPOSE) build

# Start / stop containers (-d to run it in the background)
up:
	docker compose -f $(COMPOSE) up -d

down:
	docker compose -f $(COMPOSE) down

clean:
	docker compose -f $(COMPOSE) down
	docker system prune -af

fclean: clean
	docker volume prune -f
	sudo rm -rf $(VOLUME)

re: fclean all

.PHONY: all build up down clean fclean re
