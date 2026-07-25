COMPOSE = srcs/docker-compose.yml
VOLUME = /home/daxferna/data

all: build up

# Create volume directories in host
$(VOLUME)/mariadb:
	mkdir -p $(VOLUME)/mariadb
	chown -R mysql:mysql $(VOLUME)/mariadb
$(VOLUME)/wordpress:
	mkdir -p $(VOLUME)/wordpress
	chown -R www-data:www-data $(VOLUME)/wordpress

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
