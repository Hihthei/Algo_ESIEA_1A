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

	//écriture de l'image
	writeImage(image, "siuuu.bmp");
	
	//libération des données mémoires
	freeImage(image);

	return 0;
}
