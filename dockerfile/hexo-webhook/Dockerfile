FROM alpine
LABEL maintainer="ultraji"

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories

RUN apk add --no-cache git pcre nginx supervisor\
	&& rm -f /etc/nginx/conf.d/default.conf \
	&& mkdir -p /app/logs/ \
	&& mkdir -p /run/nginx/	\
	&& mkdir -p /etc/supervisor.d/ \
	&& rm -rf /var/cache/apk/*

RUN echo "daemon off;" >> /etc/nginx/nginx.conf

COPY conf/supervisor.ini /etc/supervisor.d/supervisor.ini
COPY conf/webhook /app/
COPY conf/deploy.sh /app/
COPY conf/startup.sh /app/
COPY conf/hexo.conf /etc/nginx/conf.d

WORKDIR /app

EXPOSE 80

ENTRYPOINT [ "sh", "startup.sh" ]
