CREATE DATABASE base;

CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';
GRANT ALL PRIVILEGES ON base.* TO 'admin'@'localhost';
FLUSH PRIVILEGES;
