#include <header.h>

//size of image file
int sizeImgFile(FILE *source)
{
	int width, height;
	fseek(source, +18, SEEK_SET);

	fread(&width, sizeof(int), 1, source);

	fread(&height, sizeof(int), 1, source);

	printf("Dimension of image: %d x %d\n", width, height);

	rewind(source);

	return ((width * height * 3) / 8);

}

//size of secret file
int sizeTxtFile(FILE *secretfile)
{
	fseek(secretfile, 0L, SEEK_END);
	int	sizefile = ftell(secretfile);
	rewind(secretfile);

	return sizefile;
}
