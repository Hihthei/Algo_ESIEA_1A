#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"
#include "tri_image.h"

int main()
{
	//ouverture de l'image
	Image* image = readImage("siu.bmp");
	
	//fonction
	triSelection(image, compLexicoRGB);

	//�criture de l'image
	writeImage(image, "siuuu.bmp");
	
	//lib�ration des donn�es m�moires
	freeImage(image);

	return 0;
}
