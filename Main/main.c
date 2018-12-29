#include <header.h>

int main(int argc, char *argv[])
{
	//declaring variables  and file pointers
	char *option = argv[1];
	FILE *source;		//source bmp image
	FILE *secretfile;		//secret text file
	FILE *newbmp;		//new bmp image
	FILE *secretmsg;	//decrypted data text file

	//encode operations
	if(argc == 5)
	{
		//if argument passed is '-e'
		if(!strcmp(option, "-e"))
		{
				if((source = fopen(argv[2], "r")) == NULL)
				{
					FILE_ERROR(argv[2]);
					EXIT;
				}
				
				if((secretfile = fopen(argv[3], "r")) == NULL)
				{
					FILE_ERROR(argv[3]);
					EXIT;
				}

				if((newbmp = fopen(argv[4], "w")) == NULL)
				{
					FILE_ERROR(argv[4]);
					EXIT;
				}
				encodeImg(source, secretfile, newbmp);
		}
		else
		{
			INVALID_ARGUMENTS;
			EXIT;
		}
	}

	//decode operations
	else if(argc == 4)
	{
		//if argument passed is '-d'
		if(!strcmp(option, "-d"))
		{
				if((newbmp = fopen(argv[2], "r")) == NULL)
				{
					FILE_ERROR(argv[2]);
					EXIT;
				}
				if((secretmsg = fopen(argv[3], "w")) == NULL)
				{
					FILE_ERROR(argv[3]);
					EXIT;
				}
				decodeimg(newbmp, secretmsg);
		}
		else
		{
			INVALID_ARGUMENTS;
			EXIT;
		}
	}
	//if no other argument is passed
	else
	{
		INVALID_ARGUMENTS;
		EXIT;
	}

	
}
