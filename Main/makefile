SRCS = $(wildcard *.c)
TRGT = $(SRCS:.c=.out)
LFLAG = -L../Library -lStegno
IFLAG = -I../Include

all : ${TRGT}		#for multiple files

%.out : %.c			#for multiple files
	gcc $^ ${IFLAG} ${LFLAG} -o $@

clean :
	rm ${TRGT}
