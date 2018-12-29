#include <header.h>

//size decode
void sizeDcp(FILE *newbmp, int *size)
{
	int newbmp_buff = 0, i, byte, lsb_bit;

	for(i = 0; i < 32; i++)			// i < 32 since size is of int datatype
	{
		byte = fgetc(newbmp);
		lsb_bit = (byte & 1);

		if(lsb_bit)
		{
			newbmp_buff = (newbmp_buff << 1) | 1;
		}
		else
		{
			newbmp_buff <<= 1;
		}
	}

	*size = newbmp_buff;
}

//string decode
void strDcp(FILE *newbmp, char *str, int size)
{
	int newbmp_buff = 0, lsb_bit;
	int ch_buff, i, j = 0, k = 0;

	for(i = 0; i < (size * 8); i++)
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
			newbmp_buff = newbmp_buff << 1;
		}

		if(j == 8)
		{
			str[k++] = (char)newbmp_buff;
			j = 0;
			newbmp_buff = 0;
		}
	}

	str[k] = '\0';
}
