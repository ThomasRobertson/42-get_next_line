FROM ubuntu:latest
LABEL description="Valgrind"
ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update
RUN apt-get install build-essential valgrind zsh curl -y
RUN apt-get install gcc make libbsd-dev git-core clang -y
RUN apt-get install -y python3-pip
RUN python3 -m pip install --upgrade pip setuptools
RUN python3 -m pip install norminette
RUN apt-get upgrade -y
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended
WORKDIR /valgrind