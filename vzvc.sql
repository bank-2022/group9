CREATE USER 'pankkiuser'@'localhost' IDENTIFIED WITH mysql_native_password BY 'pankkipass';
GRANT ALL on pankki.* to 'pankkiuser'@'localhost';