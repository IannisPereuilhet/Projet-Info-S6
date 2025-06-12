#ifndef IMAGE_H
#define IMAGE_H

typedef struct
{
  int nombre_lignes;
  int nombre_colonnes;
  unsigned char** pixels;
} Image;

unsigned char** allocation_dynamique(unsigned char** tab, int nombre_lignes, int nombre_colonnes);
void creer_image(Image* image, int nombre_lignes, int nombre_colonnes, unsigned char** pixels);
Image lecture_pgm(char* image_pgm);
void ecriture_pgm(Image image, char* image_pgm);

void free_pixels(unsigned char** tab);
void free_image(Image image);

#endif
