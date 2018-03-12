FROM    debian

ENV     TERM=xterm

RUN     apt-get update -yqq && apt-get install -yqq \
            git \
            cmake \
            nano

RUN     git clone https://github.com/jjaniec/ft_ls.git

WORKDIR ft_ls

RUN     make

CMD     ["bash"]
