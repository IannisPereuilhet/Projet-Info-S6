#ifndef OPERATION_H
#define OPERATION_H

#include "image.h"

Image copie_image(Image image);
Image image_vide(Image image);

void cadre_blanc(Image image, Image image_cadre_blanc);
void inverse_image(Image image, Image image_inversee);
void composition_images(Image image_mere, Image image_fille, int ligne, int colonne, Image image_composee);
int compare_images(Image image1, Image image2);


int puissance_entier(int x, int n);
void inverse_tab_entier(int* tab, int taille);
int nombre_de_chiffres(int n);
void decomposition_entier(int n, int* tab);


#endif
