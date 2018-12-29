
#define INVALID_ARGUMENTS printf("./a.out: missing file(s) operand\nTry - ./a.out <-e or -d> <source bmp image> <secret text file> <new bmp image>\n") 

#define EXIT exit(1)

#define FILE_ERROR(file_name) printf("couldn't open file: %s\n", file_name) 

#define FILE_SIZE_ERROR printf("cannot perform operatio: size of secret message is greater than the imagefile\n")
