# cali_zoo_ada_project
This is for the course project for the Design and analysis of algorithms of Valle's University



## The docker image for the building tool is https://hub.docker.com/_/gcc

## To compile the zoo app
* docker run --rm -v "$PWD":/usr/src/cali_zoo  -w /usr/src/cali_zoo  gcc:4.9 gcc -o cali_zoo main.c
