#include <header.h>

//function to encode secret text inside the bmp file
void secretEncode(FILE *source, FILE *secretfile, FILE *newbmp)
{
	//encoding the secret message from text to new bmp file
	char source_buff, text_buff;
	int i, bit_lsb, source_lsb_bit; 

	while((text_buff = fgetc(secretfile)) != EOF)
	{
		for(i = 1; i <= 8; i++)			//i <= 8 since char datatype
		{
			source_buff = fgetc(source);

			source_lsb_bit = source_buff & 1;

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
	
	//copying rest of the bmp file contents to the new bmp file
	char source_temp;
	while(!feof(source))
	{
		source_temp = fgetc(source);
		fputc(source_temp, newbmp);
	}

	if(text_buff == EOF)
	{
		printf("done\n");
	}
	else
	{
		printf("not done\n");
	}
}
