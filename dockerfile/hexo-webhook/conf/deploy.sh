#!/bin/sh

SITE_PATH='/app/hexo'
CLONE_URL=${CLONE_URL:-""}
USER_NAME=${USER_NAME:-""}
USER_TOKEN=${USER_TOKEN:-""}
URL_SCHEME="https://"

if [ "$CLONE_URL" == "" ]; then
    echo "CLONE_URL is empty!"
    exit 1
fi

if [ ! -d "$SITE_PATH/.git" ]; then
    mkdir -p $SITE_PATH
    if [ "$USER_NAME" != "" ] && [ "$USER_TOKEN" != "" ]; then
        echo "Private repo!"  # private repo
        git clone ${URL_SCHEME}${USER_NAME}":"${USER_TOKEN}"@"${CLONE_URL##*//} $SITE_PATH
    else
        echo "Public repo!"   # public repo
        git clone ${CLONE_URL} $SITE_PATH
    fi
fi

cd $SITE_PATH
git clean -f
git pull
echo '[SUCC]: Success!'