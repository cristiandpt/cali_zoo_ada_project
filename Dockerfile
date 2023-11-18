FROM gcc:4.9
COPY . /usr/src/cali_zoo
WORKDIR /usr/src/cali_zoo
RUN gcc -o cali_zoo main.c
CMD ["bash"]