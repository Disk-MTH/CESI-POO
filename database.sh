#!/bin/bash

DB_PASSWORD="4pQ4ZVpJz22g6z"
DB_FILE_PATH="Projet-POO/BDD.cpp"
DOCKER_CONTAINER="ms-server"
SEARCH_LINE='String^ connectString = "Data Source=127.0.0.1,1433;Initial Catalog = test;User ID=sa;Password='
REPLACE_LINE="${SEARCH_LINE}${DB_PASSWORD}\";"

sed -i "s|$SEARCH_LINE.*\";|$REPLACE_LINE|" "$DB_FILE_PATH"
if grep -q "$REPLACE_LINE" "$DB_FILE_PATH"; then
    echo "DB password changer to \"$DB_FILE_PATH\""
else
    echo "Failed to set DB password \"$DB_FILE_PATH\""
    exit 1
fi

echo "Start docker in:"
echo "    - i[nstall]"
echo "    - u[p]"
echo "    - d[own]"
MODE=""
read -rp "Mode: " MODE

if [ "$MODE" = "i" ]; then
    echo "Install container \"$DOCKER_CONTAINER\""
    docker run --name $DOCKER_CONTAINER -e "ACCEPT_EULA=Y" -e "MSSQL_SA_PASSWORD=$DB_PASSWORD" -p 1433:1433 -d mcr.microsoft.com/mssql/server:2022-latest
elif [ "$MODE" = "u" ]; then
    echo "Start container \"$DOCKER_CONTAINER\""
    docker start $DOCKER_CONTAINER
elif [ "$MODE" = "d" ]; then
    echo "Stop container \"$DOCKER_CONTAINER\""
    docker stop $DOCKER_CONTAINER
else
    echo "Unknown mode \"$MODE\""
fi

read -rp "Press key to exit"