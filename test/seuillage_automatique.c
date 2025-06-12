#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "operation.h"
#include "seuillage.h"



int main(int argc, char** argv)
{
  printf("\n");

  if (argc != 2)
  {
    printf("Erreur argument\n");
    printf("\n");
    exit(1);
  }

  char* image_pgm = argv[1];
  char image_seuillee_pgm[] = "fichiers/traitement/image_seuillée_automatiquement.pgm";

  Image image = lecture_pgm(image_pgm);

  printf("Image initiale : %s\n", image_pgm);
  printf("\n");

  Image image_seuillee = copie_image(image);

  seuillage_automatique(image, image_seuillee);

  ecriture_pgm(image_seuillee, image_seuillee_pgm);

  printf("Image seuillée automatiquement à %d : %s\n", seuil_Otsu(image), image_seuillee_pgm);
  printf("\n");

  free_image(image_seuillee);
  free_image(image);

  return 0;
}
