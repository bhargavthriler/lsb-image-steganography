#include <header.h>

//secret message decryption
void secretDcp(FILE *newbmp, FILE *secretmsg, int secretSize)
{
	int newbmp_buff = 0, i, j = 0, k = 0, ch_buff, lsb_bit;

	char msg[256] = {0};

	for(i = 0; i < (secretSize * 8); i++)
	{
		j++;
		ch_buff = fgetc(newbmp);
		lsb_bit = (ch_buff & 1);

		if(lsb_bit)
		{
			newbmp_buff = (newbmp_buff << 1) | 1;
		}
		else
		{
			newbmp_buff <<= 1;
		}

		if(j == 8)
		{
			putc(newbmp_buff, secretmsg);
			msg[k++] = newbmp_buff;
			j = 0;
			newbmp_buff = 0;
		}
	}

	printf("SUCCESS your secret message is:\t\t%s\n", msg);
}
