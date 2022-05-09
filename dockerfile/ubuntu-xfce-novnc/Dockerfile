FROM ubuntu

ENV DEBIAN_FRONTEND=noninteractive

ENV LANG='en_US.UTF-8' \
    LANGUAGE='en_US:en' \
    LC_ALL='en_US.UTF-8' \
    USER=ubuntu \
    PASSWORD=123456 \
    HOME=/home/ubuntu \
    NO_VNC_HOME=/home/ubuntu/.novnc \
    NO_VNC_PASSWORD=123456

RUN sed -i "s/archive.ubuntu.com/mirrors.tuna.tsinghua.edu.cn/g"  /etc/apt/sources.list

# install tools
RUN apt-get update && apt-get install -y \
    vim wget net-tools locales python-numpy git sudo gdb \
    && apt-get autoclean \
    && locale-gen en_US.UTF-8

# install xfce
RUN apt-get install -y supervisor xfce4 xfce4-terminal

# install tigervnc
RUN wget -qO- https://dl.bintray.com/tigervnc/stable/tigervnc-1.8.0.x86_64.tar.gz | tar xz --strip 1 -C /

# change the password of root and add user
RUN (echo "root:123456" | chpasswd) && adduser ${USER} --disabled-password \
    && (echo "${USER}:${PASSWORD}" | chpasswd) \
    && usermod -aG sudo ${USER}

USER ${USER}
WORKDIR ${HOME}

# install novnc for ${USER} and change vncpassword
RUN mkdir -p ${NO_VNC_HOME}/utils/websockify && cd ${NO_VNC_HOME}/utils
RUN wget -qO- https://github.com/novnc/noVNC/archive/v1.1.0.tar.gz | tar xz --strip 1 -C ${NO_VNC_HOME}
RUN wget -qO- https://github.com/novnc/websockify/archive/v0.9.0.tar.gz | tar xz --strip 1 -C ${NO_VNC_HOME}/utils/websockify
RUN chmod +x -v $NO_VNC_HOME/utils/*.sh
RUN (echo $NO_VNC_PASSWORD; echo $NO_VNC_PASSWORD; echo n) | vncpasswd
RUN cp ${NO_VNC_HOME}/vnc.html ${NO_VNC_HOME}/index.html

USER root

ADD conf/vnc_startup.sh ./
RUN chmod +x ./vnc_startup.sh

EXPOSE 6080

USER ${USER}

CMD [ "./vnc_startup.sh" ]
