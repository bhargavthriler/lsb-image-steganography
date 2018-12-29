#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "errorHandle.c"

//encode image main function
void encodeImg(FILE *source, FILE *secretfile, FILE *newbmp);

//size of image file(called from encodeImg)
int sizeImgFile(FILE *s1);

//size secret text file(called from encodeImg)
int sizeTxtFile(FILE *s2);

//string encode(called from encodeImg)
void stringEncode(char *String, FILE *source, FILE *newbmp);

//get character bits(called from stringEncode)
int get_bit(char byte, int bit);

//size encode(called from encodeImg)
void sizeEncode(int val, FILE *source, FILE *newbmp);

//secret encode(called from encodeImg)
void secretEncode(FILE *source, FILE *secretfile, FILE *newbmp);

//decode image main function
void decodeimg(FILE *newbmp, FILE *secretmsg);

//size decode(called from decodeimg)
void sizeDcp(FILE *newbmp, int *size);

//string decode(called from decodeimg)
void strDcp(FILE *newbmp, char *str, int size);

//secret decode(called from decodeimg)
void secretDcp(FILE *newbmp, FILE *secretmsg, int secretSize);



#define INVALID_ARGUMENTS printf("./a.out: missing file(s) operand\nTry - ./a.out <-e or -d> <source bmp image> <secret text file> <new bmp image>\n") 

#define EXIT exit(1)

#define FILE_ERROR(file_name) printf("couldn't open file: %s\n", file_name) 

#define FILE_SIZE_ERROR printf("cannot perform operatio: size of secret message is greater than the imagefile\n")

