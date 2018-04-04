# ft_ls
[![Build Status](https://travis-ci.org/jjaniec/ft_ls.svg?branch=master)](https://travis-ci.org/jjaniec/ft_ls) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/055cf66f6c374e1899e476d5d958078a)](https://app.codacy.com/app/jjaniec/ft_ls?utm_source=github.com&utm_medium=referral&utm_content=jjaniec/ft_ls&utm_campaign=badger) 

[![Docker Automated build](https://img.shields.io/docker/automated/jjaniec/ft_ls.svg)](https://hub.docker.com/r/jjaniec/ft_ls/) [![Docker Build Status](https://img.shields.io/docker/build/jjaniec/ft_ls.svg)](https://hub.docker.com/r/jjaniec/ft_ls/)

## What's ft_ls ?

ft_ls is my remake of the well known `ls` UNIX program, mainly made to learn about the filesystem, but also many other things, for more informations about the subject, see [ft_ls.fr.pdf](https://github.com/jjaniec/ft_ls/blob/master/ft_ls.fr.pdf) :fr: / [ft_ls.en.pdf](https://github.com/jjaniec/ft_ls/blob/master/ft_ls.en.pdf) :uk:

## Features

My implementation of the `ls` command comes with some basic features:

```
-A: List all entries except for . and ..
-G / --color: Enable colorized output
-R: Recursively list subdirectories encountered
-a: Include directory entries whose names begin with a dot (.)
-l: List in long format
-n: Display user and group IDs numerically
-r: Reverse the order of the sort
-t: Sort by time modified
```

Term width is not yet supported, meaning output of ```ft_ls``` will be the same of the real ```ls``` when you use the ```-1``` option when ```-l``` is not toggled


### Bonus cool features and particularities

#### Linux adaption

When run on linux, error messages and default sorting will be adapted to match the real `ls` command of your operating system

To enable linux like default sorting on MacOS, the following option can be toggled

``./ft_ls --linux-sort``

As sorting order of the Linux version of ls is based on locales and using ```strcoll``` was forbidden by the subject, I tried to replica as much as possible the output of the real ```ls``` with ```LC_COLLATE``` set to ```en_US.UTF-8```

If ```ft_ls``` is ran on MacOs without sorting options, elements will be sorted by ascii values

#### The ``$FT_LS_COLORS`` environnement variable

Like the ``$LS_COLORS`` variable, the ``$FT_LS_COLORS`` can be defined to be read by the program, if the ``FT_LS_COLORS`` variable is set, it's content will be parsed to modify output colors of the ``-G / --color`` options.

The content of this variable should be something similar to this:

```
di=34:ln=35:so=32:pi=33:ex=31:bd=34;46:cd=34;43:su=30;41:sg=30;46:tw=30;42:ow=30;43
```

Where each key sets color codes for each directory entry type,

```
di: Directories
ln: Symbolic links
so: Sockets
pi: Pipes / FIFOs
ex: Executables
bd: Block special files
cd: Char special files
su: Executables with the setuid bit
sg: Executables with the setgid bit
tw: Directories that are sticky and other-writable (+t,o+w)
ow: Directories that are not sticky and other-writable (o+w)
```

Unfortunately, keys like ``*.pdf=`` are not currently supported, but maybe will be one day ¯\\\_(ツ)\_/¯

To generate your very own ```LS_COLORS``` config, website like [this one](https://geoff.greer.fm/lscolors/) could help you

---

### Performances

About the performances of the ```ls``` of MacOS, but also less features

```
time ls -laRG ~
...
ls -laRG ~  5.78s user 10.82s system 46% cpu 35.697 total
```

```
time ./ft_ls -laRG ~
...
./ft_ls -laRG ~  6.31s user 9.14s system 44% cpu 34.946 total
```


## Trying it

### The docker way

```
docker run -it --rm jjaniec/ft_ls:master
```

### From source

Clone the project and compile it, dependencies will be cloned by the makefile
```sh
git clone https://github.com/jjaniec/ft_ls
make
```

Then run it with options and paths

```
./ft_ls -[lRaArtn] [--linux-sort] -[G / -color] [file ...]
```
