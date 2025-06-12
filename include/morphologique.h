#ifndef MORPHOLOGIQUE_H
#define MORPHOLOGIQUE_H

#include "image.h"

Image miroir(Image image);

void erosion(Image image, Image image_erodee);
void dilatation(Image image, Image image_dilatee);
Image reconstruction(Image image, Image graine);

#endif
