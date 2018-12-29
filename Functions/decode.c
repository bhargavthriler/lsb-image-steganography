#include <header.h>

void decodeimg(FILE *newbmp, FILE *secretmsg)
{
	//seek to 54th byte
	fseek(newbmp, 54, SEEK_SET);
	

	//for magic string 
	int magicSize = 2;
	char magicStrEn[3], magicStrOG[3] = "$#";
	
	//magic string decryption
	strDcp(newbmp, magicStrEn, magicSize);
	
	//check correct magic string or not
	int check;
	check = strcmp(magicStrOG, magicStrEn);

	if(check)
	{
		printf("wrong magic string\n");
		EXIT;
	}
	else
	{
		printf("SUCCESS: correct magic string\n");
	}

	//for password
	char pass[10], passStr[10];
	int passSize;

	//password size decryption
	sizeDcp(newbmp, &passSize);

	//password decryption
	strDcp(newbmp, passStr, passSize);
	
	//prompt user for password
	printf("enter the password: ");
	scanf("%s", pass);

	//validate password
	check = strcmp(pass, passStr);

	if(check)
	{
		printf("you have entered incorrect passord\n");
		EXIT;
	}
	else
	{
		printf("SUCCESS: password accepted\n");
	}

	//for getting secret text
	int secretSize;

	//secret text size decryption
	sizeDcp(newbmp, &secretSize);
	
	//secret text decryption
	secretDcp(newbmp, secretmsg, secretSize);

	printf("done DECRYPTION COMPLETED\n");

	//close all the files
	fclose(newbmp);
	fclose(secretmsg);
}
