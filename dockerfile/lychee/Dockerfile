FROM ubuntu
MAINTAINER Jack Wang <ultraji@live.com>

# 更换清华源，用于apt-get加速
RUN sed -i "s/archive.ubuntu.com/mirrors.tuna.tsinghua.edu.cn/g"  /etc/apt/sources.list

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -yq wget git unzip nginx \
    mysql-server mysql-client php7.2-fpm php7.2-gd php7.2-mysql php7.2-mbstring php-imagick \
    imagemagick libimage-exiftool-perl ufraw-batch supervisor

RUN ln -fs /usr/share/zoneinfo/UTC /etc/localtime
    
# ------------------------------------------------------------------------------
# 配置 php-fpm
RUN sed -i -e "s/output_buffering\s*=\s*4096/output_buffering = Off/g" /etc/php/7.2/fpm/php.ini
RUN sed -i -e "s/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g" /etc/php/7.2/fpm/php.ini
RUN sed -i -e "s/upload_max_filesize\s*=\s*2M/upload_max_filesize = 500M/g" /etc/php/7.2/fpm/php.ini
RUN sed -i -e "s/post_max_size\s*=\s*8M/post_max_size = 500M/g" /etc/php/7.2/fpm/php.ini
RUN sed -i -e "s:;\s*session.save_path\s*=\s*\"N;/path\":session.save_path = /tmp:g" /etc/php/7.2/fpm/php.ini

# 配置 nginx
RUN mkdir /run/php
RUN chown www-data:www-data /var/www
RUN rm /etc/nginx/sites-enabled/*
RUN rm /etc/nginx/sites-available/*
RUN sed -i -e"s/keepalive_timeout\s*65/keepalive_timeout 2/" /etc/nginx/nginx.conf
RUN sed -i -e"s/keepalive_timeout 2/keepalive_timeout 2;\n\tclient_max_body_size 100m/" /etc/nginx/nginx.conf
RUN echo "daemon off;" >> /etc/nginx/nginx.conf
ADD conf/php.conf /etc/nginx/
ADD conf/lychee /etc/nginx/sites-enabled/

# 配置 mysql
RUN sed -i -e"s/^bind-address\s*=\s*127.0.0.1/bind-address = 0.0.0.0/" /etc/mysql/my.cnf
RUN service mysql start && \
    mysql -uroot -e "CREATE DATABASE IF NOT EXISTS lychee;" && \
    mysql -uroot -e "CREATE USER 'lychee'@'localhost' IDENTIFIED BY 'lychee';" && \
    mysql -uroot -e "GRANT ALL PRIVILEGES ON *.* TO 'lychee'@'localhost' WITH GRANT OPTION;" && \
    mysql -uroot -e "FLUSH PRIVILEGES;"
RUN mkdir /var/lib/mysql_init && \
    mv /var/lib/mysql/* /var/lib/mysql_init

# 安装 Lychee
WORKDIR /var/www

RUN git clone https://github.com/electerious/Lychee.git lychee

RUN chown -R www-data:www-data /var/www/lychee
RUN chmod -R 770 /var/www/lychee
RUN chmod -R 777 /var/www/lychee/uploads/ 
RUN chmod -R 777 /var/www/lychee/data/

EXPOSE 80

WORKDIR /

VOLUME /var/www/lychee/uploads
VOLUME /var/www/lychee/data
VOLUME /var/lib/mysql

ADD conf/startup.conf /etc/supervisor/conf.d/

CMD ["supervisord", "-c", "/etc/supervisor/supervisord.conf"]
