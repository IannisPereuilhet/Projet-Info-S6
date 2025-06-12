#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "operation.h"
#include "seuillage.h"
#include "comptage.h"
#include "numerotation.h"

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
  char image_seuillee_pgm[] = "fichiers/traitement/image_seuillée.pgm";
  char image_sans_bord_pgm[] = "fichiers/traitement/image_sans_bord.pgm";
  char image_sans_trous_pgm[] = "fichiers/traitement/image_sans_trous.pgm";
  char image_erodee_pgm[] = "fichiers/traitement/image_érodée.pgm";
  char image_numerotee_pgm[] = "fichiers/traitement/image_numérotée.pgm";

  Image image = lecture_pgm(image_pgm);

  printf("Image initiale : %s\n", image_pgm);
  printf("\n");

  Image image_seuillee = copie_image(image);

  seuillage_automatique(image, image_seuillee);

  ecriture_pgm(image_seuillee, image_seuillee_pgm);

  printf("Image seuillée : %s\n", image_seuillee_pgm);
  printf("\n");

  Image image_sans_bord = copie_image(image_seuillee);

  suppression_bord(image_seuillee, image_sans_bord);

  ecriture_pgm(image_sans_bord, image_sans_bord_pgm);

  printf("Image sans bords : %s\n", image_sans_bord_pgm);
  printf("\n");

  Image image_sans_trous = copie_image(image_sans_bord);

  bouchage_trous(image_sans_bord, image_sans_trous);

  ecriture_pgm(image_sans_trous, image_sans_trous_pgm);

  printf("Image sans trous : %s\n", image_sans_trous_pgm);
  printf("\n");

  Image image_numerotee = copie_image(image_sans_trous);

  Image image_erodee;

  int choix = -1;

  while ((choix != 0) && (choix != 1))
  {
    printf("De quelle manière voulez-vous éroder l'image ?\n");
    printf("érosion manuelle = 0    |    érosion automatique = 1 ");
    scanf("%d", &choix);
    printf("\n");
  }

  if (choix == 0)
  {
    int n;
    printf("Entrez le nombre d'érosion (nombre entier) : ");
    scanf("%d", &n);
    printf("\n");

    image_erodee = copie_image(image_sans_trous);

    erosion_manuelle(image_sans_trous, n, image_erodee);
  }

  else if (choix == 1)
  {
    image_erodee = image_vide(image_sans_trous);

    erodes_ultimes(image_sans_trous, image_erodee);
  }

  ecriture_pgm(image_erodee, image_erodee_pgm);

  printf("Image érodée : %s\n", image_erodee_pgm);
  printf("\n");

  int compteur = comptage(image_erodee, image_numerotee);

  ecriture_pgm(image_numerotee, image_numerotee_pgm);

  printf("Image numérotée : %s\n", image_numerotee_pgm);
  printf("\n");

  printf("Il y a %d cellules !\n", compteur);
  printf("\n");

  free_image(image_numerotee);
  free_image(image_erodee);
  free_image(image_sans_trous);
  free_image(image_sans_bord);
  free_image(image_seuillee);
  free_image(image);

  return 0;
}
