#!/bin/bash
service mysql start; #Start the service

# Execute the next SQL sentences
mysql -e "CREATE DATABASE IT NOT EXISTS \`${SQL_DB}\`;"
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DB}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
