SRCS = $(wildcard *.c)
TRGT = ../Library/libStegno.so
IFLAG = -I../Include

${TRGT} : ${SRCS}
	gcc -fPIC -shared ${IFLAG} $^ -o $@

clean :
	rm ${TRGT}
