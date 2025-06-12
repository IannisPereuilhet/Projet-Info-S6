#ifndef SEUILLAGE_H
#define SEUILLAGE_H

#include "image.h"

void seuillage_manuel(Image image, int seuil, Image image_seuillee);

void histogramme(Image image, float tableau_histogramme[256]);
int seuil_Otsu(Image image);
void seuillage_automatique(Image image, Image image_seuillee);

#endif
