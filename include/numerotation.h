#ifndef NUMEROTATION_H
#define NUMEROTATION_H

#include "image.h"

Image nombre_image(int lignes, int colonnes);

Image numerotation_0(Image image_nombre);
Image numerotation_1(Image image_nombre);
Image numerotation_2(Image image_nombre);
Image numerotation_3(Image image_nombre);
Image numerotation_4(Image image_nombre);
Image numerotation_5(Image image_nombre);
Image numerotation_6(Image image_nombre);
Image numerotation_7(Image image_nombre);
Image numerotation_8(Image image_nombre);
Image numerotation_9(Image image_nombre);
Image numerotation_image(Image image_nombre, int n);

void numerotation(Image image, int nombre, int ligne, int colonne, Image imgae_numerotee);

#endif
