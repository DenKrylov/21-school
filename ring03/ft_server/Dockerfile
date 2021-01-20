# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monie <monie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 16:00:03 by monie             #+#    #+#              #
#    Updated: 2020/08/25 16:06:49 by monie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

WORKDIR		/srcs

EXPOSE		80 443

RUN			apt-get update && apt-get -y upgrade

RUN			apt-get -y install nginx default-mysql-server wordpress\
			vim mc wget

RUN			apt-get -y install php php-fpm php-mysql php-mbstring php-gd php-cli \
			php7.3-gmp php7.3-curl php7.3-intl php7.3-xmlrpc php7.3-xml php7.3-zip \
			php7.3-common

ADD			https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
			phpmyadmin.tar.gz

RUN			tar -xf phpmyadmin.tar.gz && mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin

COPY		/srcs/createdb.sql /srcs/start_server.sh /srcs/index.sh ./

RUN			chmod 777 start_server.sh

COPY		/srcs/localhost.conf /etc/nginx/sites-available/

RUN			ln -s /etc/nginx/sites-available/localhost.conf /etc/nginx/sites-enabled/localhost.conf && \
			rm /etc/nginx/sites-enabled/default && rm /etc/nginx/sites-available/default

RUN			cp -r /usr/share/wordpress /var/www/html/ && rm /var/www/html/wordpress/wp-config.php

RUN			rm /var/www/html/index.html

COPY		/srcs/wp-config.php /var/www/html/wordpress/

RUN			chown -R www-data:www-data /var/www/html

RUN			openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
			-keyout /etc/ssl/private/localhost.key \
			-out /etc/ssl/certs/localhost.crt \
			-subj "/C=RU/ST=Moscow/L=Moscow/O=42/OU=21/CN=localhost"

CMD			["bash", "start_server.sh"]