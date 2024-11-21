import mysql.connector

mydb = mysql.connector.connect(
    host="127.0.0.1",
    user="root@localhost@localhost",
    password="NO",
    database="lademy"
)

cursor = mydb.cursor()

cursor.execute("SHOW TABLES")

for table in cursor:
    print(table)

mydb.close()