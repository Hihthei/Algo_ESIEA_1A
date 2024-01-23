#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"
#include "tri_image.h"

int main()
{
	Image* image = readImage("imageenbmp.bmp");

	quicksort(image, &compLexicoRGB);
	writeImage(image, "exm.bmp");
	freeImage(image);
	return 0;
}