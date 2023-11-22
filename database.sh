#!/bin/bash

DB_SERVER="127.0.0.1,1433"
DB_USER="sa"
DB_PASSWORD="4pQ4ZVpJz22g6z"
DB_DATABASE="database"
DB_FILE_PATH="Projet-POO/src/BDD.cpp"
DOCKER_CONTAINER="ms-server"
SEARCH_LINE="String^ connectString = \"Data Source=$DB_SERVER;Initial Catalog = $DB_DATABASE;User ID=$DB_USER;Password="
REPLACE_LINE="${SEARCH_LINE}${DB_PASSWORD}\";"

sed -i "s|$SEARCH_LINE.*\";|$REPLACE_LINE|" "$DB_FILE_PATH"
if grep -q "$REPLACE_LINE" "$DB_FILE_PATH"; then
    echo "DB password change to \"$DB_FILE_PATH\""
else
    echo "Failed to set DB password \"$DB_FILE_PATH\""
    read -rp "Press enter to exit..."
    exit 1
fi

while true 
do
  echo "Start docker in:"
  echo "    - i[nstall]"
  echo "    - u[p]"
  echo "    - d[own]"
  echo "    - b[ackup]"
  echo "    - r[estore]"
  echo "    - e[xit]"
  echo ""
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
  elif [ "$MODE" = "b" ]; then
      backupFile="backup_$(date '+%Y%m%d_%H%M%S').bak"
      echo "Backup container \"$DOCKER_CONTAINER\" to \"./backups/$backupFile\""
      docker exec $DOCKER_CONTAINER sh -c "/opt/mssql-tools/bin/sqlcmd -U $DB_USER -P $DB_PASSWORD -d $DB_DATABASE -Q \"BACKUP DATABASE [$DB_DATABASE] TO DISK = '/tmp/$backupFile' WITH FORMAT;\""
      docker cp "$DOCKER_CONTAINER:/tmp/$backupFile" "./backups/$backupFile"
  elif [ "$MODE" = "r" ]; then
      backupFile=""
      for file in ./backups/*.bak; do
          if [ -z "$backupFile" ] || [ "$file" -nt "$backupFile" ]; then
            backupFile="${file:10}"
          fi
      done
      if [ -z "$backupFile" ]; then
          echo "No backup file found in \"./backups/\""
      else 
        echo "Restore container \"$DOCKER_CONTAINER\" from \"./backups/$backupFile\""
        docker cp "./backups/$backupFile" "$DOCKER_CONTAINER:/tmp/$backupFile"
        docker exec $DOCKER_CONTAINER sh -c "/opt/mssql-tools/bin/sqlcmd -U $DB_USER -P $DB_PASSWORD -Q \"RESTORE DATABASE [$DB_DATABASE] FROM DISK = '/tmp/$backupFile' WITH REPLACE;\""
      fi
  elif [ "$MODE" = "e" ]; then
      echo "Exit"
      exit 0
  else
      echo "Unknown mode \"$MODE\""
  fi
  echo ""
done

read -rp "Press enter to continue..."