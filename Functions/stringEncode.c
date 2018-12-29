#include <header.h>

//function for encoding magic string and password
void stringEncode(char *String, FILE *source, FILE *newbmp)
{
	char source_buff, text_buff;
	int i, j = 0;
	int bit_lsb;
	int source_lsb_bit;

	while((text_buff = String[j++]) != '\0')
	{
		for(i = 1; i <= 8; i++)			//i <= 8 because only char datatypes
		{
			source_buff = fgetc(source);
			source_lsb_bit = (source_buff & 1);

			bit_lsb = get_bit(text_buff, i);
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
}


int get_bit(char byte, int bit)
{
	return ((byte >> 8 - bit) & 1);
}
