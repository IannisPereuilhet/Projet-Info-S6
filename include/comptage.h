#ifndef COMPTAGE_H
#define COMPTAGE_H

#include "image.h"

void suppression_bord(Image image, Image image_sans_bord);
void bouchage_trous(Image image, Image image_sans_trous);
void erosion_manuelle(Image image, int n, Image image_erodee);

void erodes_ultimes(Image image, Image image_erodes_ultimes);
void DFS(unsigned char** pixels, int ligne, int colonne, unsigned char** tableau_booleen);
int comptage(Image image, Image image_numerotee);

#endif
