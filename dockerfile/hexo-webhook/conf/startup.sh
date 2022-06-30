#!/bin/sh

sh deploy.sh
sed -i "s/secret/$WEBHOOK_SECRET/g" /etc/supervisor.d/supervisor.ini 
supervisord -c /etc/supervisord.conf