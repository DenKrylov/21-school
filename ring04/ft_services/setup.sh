minikube start

eval $(minikube -p minikube docker-env)

# Делаем metallb
minikube addons enable metallb
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
kubectl apply -f ./srcs/metallb.yaml

# build nginx
docker build -t nginx ./srcs/nginx/
# apply rele nginx
kubectl apply -f ./srcs/nginx/nginx-service.yaml
kubectl apply -f ./srcs/nginx/nginx-deployment.yaml

# build mysql
docker build -t mysql ./srcs/mysql/
# apply rule mysql
kubectl apply -f ./srcs/mysql/mysql-volume.yaml
kubectl apply -f ./srcs/mysql/mysql-deployment.yaml
kubectl apply -f ./srcs/mysql/mysql-service.yaml

# build phpmyadmin
docker build -t phpmyadmin ./srcs/phpmyadmin/
# apply rule phpmyadmin
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin-deployment.yaml
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin-service.yaml

# build wordpress
docker build -t wordpress ./srcs/wordpress/
# apply rule wordpress
kubectl apply -f ./srcs/wordpress/wordpress-deployment.yaml
kubectl apply -f ./srcs/wordpress/wordpress-service.yaml

# build influxdb
docker build -t influxdb ./srcs/influxdb
# apply rule influxdb
kubectl apply -f ./srcs/influxdb/influxdb-volume.yaml
kubectl apply -f ./srcs/influxdb/influxdb-configmap.yaml
kubectl apply -f ./srcs/influxdb/influxdb-deployment.yaml
kubectl apply -f ./srcs/influxdb/influxdb-service.yaml

# build telegraf
docker build -t telegraf ./srcs/telegraf
# apply rule telegraf
kubectl apply -f ./srcs/telegraf/telegraf.yaml

# build grafana
docker build -t grafana ./srcs/grafana
# apply rule grafana
kubectl apply -f ./srcs/grafana/grafana-deployment.yaml
kubectl apply -f ./srcs/grafana/grafana-service.yaml

# build ftps
docker build -t ftps ./srcs/ftps

# apply rule ftps
kubectl apply -f ./srcs/ftps/ftps-deployment.yaml
kubectl apply -f ./srcs/ftps/ftps-service.yaml

open http://192.168.99.201

minikube dashboard

# check
# kubectl exec deploy/ftps -- pkill vsftpd
# kubectl exec deploy/grafana -- pkill grafana
# kubectl exec deploy/telegraf -- pkill telegraf
# kubectl exec deploy/influxdb -- pkill influx
# kubectl exec deploy/wordpress -- pkill nginx
# kubectl exec deploy/wordpress -- pkill php-fpm7
# kubectl exec deploy/phpmyadmin -- pkill nginx
# kubectl exec deploy/phpmyadmin -- pkill php-fpm7
# kubectl exec deploy/mysql -- pkill /usr/bin/mysqld 
# kubectl exec deploy/nginx -- pkill nginx
# kubectl exec deploy/nginx -- pkill sshd