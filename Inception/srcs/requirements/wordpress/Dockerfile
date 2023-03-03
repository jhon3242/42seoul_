FROM debian:buster

RUN apt-get upgrade -y && apt-get update -y && apt-get install php-fpm -y && apt-get install vim -y && apt-get install wget -y && apt-get install tar -y
RUN wget https://wordpress.org/latest.tar.gz && tar -xvzf latest.tar.gz && mkdir -p /var/www/html/wordpress && mv wordpress/ var/www/html/
COPY ["./conf/www.conf", "/etc/php/7.3/fpm/pool.d/www.conf"]

RUN	mkdir -p /var/www/html

EXPOSE 9000

CMD	service php7.3-fpm start && tail -f /dev/null
