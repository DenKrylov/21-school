#!bin/sh

rc default

mkdir www/phpmyadmin/tmp

chmod 777 www/phpmyadmin/tmp

mkdir /run/nginx

chmod 744 /run/nginx

/usr/bin/supervisord -c /etc/supervisord.conf
