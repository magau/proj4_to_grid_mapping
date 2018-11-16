#!/usr/bin/env bash

set -e
test ! -z "$1" || (echo "Missing argument (.cpp) source file!" && exit 1)

src=$1
out=$(echo $1 | cut -f 1 -d '.')

g++ $src -std=c++11\
  -I/home/jmacedo/anaconda3/envs/dev_env/include\
  -L/home/jmacedo/anaconda3/envs/dev_env/lib\
  -lgdal\
  -Wl,-rpath -Wl,/home/jmacedo/anaconda3/envs/dev_env/lib\
  -o $out
