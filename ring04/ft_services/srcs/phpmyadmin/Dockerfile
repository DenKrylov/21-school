# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monie <monie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 22:04:06 by monie             #+#    #+#              #
#    Updated: 2020/11/03 19:06:55 by monie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	alpine

RUN 	apk update && \
	apk add openrc 

RUN     apk add nginx supervisor \
        php7 php7-fpm php7-mysqli \ 
        php7-zlib php7-curl php7-mbstring \
        php7-json php7-session

RUN     mkdir -p /www/

RUN     wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz && \
        tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz && \
        rm phpMyAdmin-5.0.2-all-languages.tar.gz && \
        mv phpMyAdmin-5.0.2-all-languages /www/phpmyadmin

COPY 	./srcs/nginx.conf /etc/nginx/conf.d/default.conf

COPY    ./srcs/config.inc.php /www/phpmyadmin/

COPY 	./srcs/supervisord.conf /etc/supervisord.conf

COPY    ./srcs/start.sh .

RUN 	chmod 711 start.sh

EXPOSE  5000

CMD     [ "sh", "start.sh" ]