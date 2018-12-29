#include <header.h>

//function for encoding size of password and secret text
void sizeEncode(int val, FILE *source, FILE *newbmp)
{
	char source_buff;
	int i, bit_lsb, source_lsb_bit;

	for(i = 1; i <= 32; i++)		//i <= 32 since size is of int datatype
	{
		source_buff = fgetc(source);

		source_lsb_bit = source_buff & 1;
		bit_lsb = ((val >> (32 - i)) & 1);  

		if(source_lsb_bit == bit_lsb)
		{
			fputc(source_buff, newbmp);
		}
		else
		{
			if(source_lsb_bit == 0)
			{
				source_buff |= 1;
			}
			else
			{
				source_buff ^= 1;
			}

			fputc(source_buff, newbmp);
		}
	}
}

