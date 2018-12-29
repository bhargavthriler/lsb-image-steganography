#include <header.h>

void encodeImg(FILE *source, FILE *secretfile, FILE *newbmp)
{
	int sizeSource = sizeImgFile(source);		//get source bmp image size
	int sizeStext = sizeTxtFile(secretfile);	//get secret text file size

	printf("Size of source image: %d\t Size of text file: %d\n", sizeSource, sizeStext);
	
	//if secret text file is greater than source image than operations are not possile , exit from program 
	if(sizeSource < sizeStext)
	{
		FILE_SIZE_ERROR;
		EXIT;
	}
	
	int i, check1;
	char tempStr;
	rewind(source);		//keep the file pointer again in beginning of the file
	
	//place the file pointer to 54th byte
	for(i = 0; i < 54; i++)
	{
		tempStr = fgetc(source);
		fputc(tempStr, newbmp);
		check1++;
	}
	
	//check if the pointer is pointed to 54th byte
	if(i == check1)
	{
		printf("SUCESS: .bmp header files copied\n");
	}
	else
	{
		printf("ERROR: .bmp header files copy failed\n");
		EXIT;
	}
	
	//for magic string
	//
	//magic string encoding in the new bmp file
	char magic[3] = "$#";
	
	//calling string encode function
	stringEncode(magic, source, newbmp);
	printf("SUCESS: magic string encrypted to new bmp file\n");

	//for password
	//
	char pass[10];
	//take password
	printf("enter a password (max 10 characters): ");
	for(i = 0; ((pass[i] = getchar()) != '\n'); i++);
	pass[i] = '\0';

	char passSize = (char)strlen(pass);			//get password string length

	//password size encrypt
	sizeEncode(passSize, source, newbmp);

	//password encrypt
	stringEncode(pass, source, newbmp);

	printf("SUCESS: password encrypted\n");
	
	//secret msg encrypt
	sizeEncode(sizeStext, source, newbmp);
	secretEncode(source, secretfile, newbmp);

	//close all files
	fclose(source);
	fclose(secretfile);
	fclose(newbmp);
}
