# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monie <monie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 15:42:32 by monie             #+#    #+#              #
#    Updated: 2020/10/28 21:41:23 by monie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	alpine

RUN 	apk update && \
	apk add openrc 

ADD     https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_linux_amd64.tar.gz /etc/

RUN     tar -xzf /etc/telegraf-1.15.3_linux_amd64.tar.gz -C /etc/ ; rm -rf /etc/telegraf-1.15.3_linux_amd64.tar.gz && \
        mv /etc/telegraf-1.15.3 /telegraf && \
        cp -r telegraf/* / && rm -rf /telegraf

RUN     wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub && \
        wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk && \
        apk add glibc-2.28-r0.apk

RUN     telegraf -sample-config telegraf.conf --input-filter cpu:mem --output-filter influxdb > telegraf.conf

COPY    telegraf.conf /etc/telegraf/

CMD     [ "telegraf" ]