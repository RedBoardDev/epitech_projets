DROP DATABASE IF EXISTS epytodo;

CREATE DATABASE epytodo;

USE epytodo;

CREATE TABLE `user` (
	`id` INT unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`email` VARCHAR(100) NOT NULL,
	`password` VARCHAR(100) NOT NULL,
	`name` VARCHAR(100) NOT NULL,
	`firstname` VARCHAR(100) NOT NULL,
	`created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE `todo` (
	`id` INT unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`title` VARCHAR(100) NOT NULL,
	`description` VARCHAR(100) NOT NULL,
	`created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
	`due_time` DATETIME NOT NULL,
	`status` VARCHAR(12) DEFAULT 'not started' COMMENT 'not started by default / todo / in progress / done',
	`user_id` INT unsigned NOT NULL,
	FOREIGN KEY (user_id)
        REFERENCES user(id)
);

GRANT ALL ON epytodo.* to USERS_DB_OWNER@'%' IDENTIFIED BY '1234';
