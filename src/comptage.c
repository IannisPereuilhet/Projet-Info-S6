#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "operation.h"
#include "booleenne.h"
#include "morphologique.h"
#include "numerotation.h"


void suppression_bord(Image image, Image image_sans_bord)
{
  // supprime les bords de l'image_erodee

  Image image_cadre_blanc = copie_image(image);

  cadre_blanc(image, image_cadre_blanc);

  Image image_reconstruite = reconstruction(image, image_cadre_blanc); // la graine est un cadre blanc

  operation_xor(image_reconstruite, image, image_sans_bord);

  free_image(image_cadre_blanc);
  free_image(image_reconstruite);
}


void bouchage_trous(Image image, Image image_sans_trous)
{
  // bouche les trous de l'image

  Image image_cadre_blanc = copie_image(image);

  inverse_image(image, image_sans_trous);

  cadre_blanc(image, image_cadre_blanc);

  Image image_reconstruite = reconstruction(image_sans_trous, image_cadre_blanc); // la graine est un cadre blanc

  inverse_image(image_reconstruite, image_sans_trous);

  free_image(image_cadre_blanc);
  free_image(image_reconstruite);
}


void erosion_manuelle(Image image, int n, Image image_erodee)
{
  // érode manuellement

  int i;

  if (n>0)
  {
    erosion(image, image_erodee);

    for(i=1; i<n; i++)
    {
      erosion(image_erodee, image_erodee);
    }
  }
}



void erodes_ultimes(Image image, Image image_erodes_ultimes)
{
  // érode automatiquement

  Image image_erodee = image_vide(image);

  Image image_residus = image_vide(image);

  Image image_reconstruite = image_vide(image);

  Image image_noire = image_vide(image);

  Image image_courante = copie_image(image);

  do {

    erosion(image_courante, image_erodee);

    free_image(image_reconstruite);

    image_reconstruite = reconstruction (image_courante, image_erodee);

    operation_xor(image_reconstruite, image_courante, image_residus);

    operation_or(image_residus, image_erodes_ultimes, image_erodes_ultimes);

    free_image(image_courante);

    image_courante = copie_image(image_erodee);

  } while(compare_images(image_courante, image_noire) == 0); // tant que les images sont différentes


  int i, nombre_dilatation = 2;

  for (i=0; i<nombre_dilatation; i++) // dilate l'image
  {
    dilatation(image_erodes_ultimes, image_erodes_ultimes);
  }

  free_image(image_erodee);
  free_image(image_residus);
  free_image(image_reconstruite);
  free_image(image_noire);
  free_image(image_courante);
}


void DFS(unsigned char** pixels, int ligne, int colonne, unsigned char** tableau_booleen)
{
  // parcourt les pixels blancs

  if (tableau_booleen[ligne][colonne] == 0)
  {
    if (pixels[ligne][colonne] == 255)
    {
      tableau_booleen[ligne][colonne] = 1;
      DFS(pixels, ligne-1, colonne, tableau_booleen);
      DFS(pixels, ligne+1, colonne, tableau_booleen);
      DFS(pixels, ligne, colonne-1, tableau_booleen);
      DFS(pixels, ligne, colonne+1, tableau_booleen);
    }
  }
}



int comptage(Image image, Image image_numerotee)
{
  // compte le nombre de composantes connexes

  int i;
  int j;

  unsigned char** tableau_booleen = NULL;

  tableau_booleen = allocation_dynamique(tableau_booleen, image.nombre_lignes, image.nombre_colonnes);

  int compteur = 0;

  for (i=0; i<image.nombre_lignes; i++)
  {
    for (j=0; j<image.nombre_colonnes; j++)
    {
      if (tableau_booleen[i][j] == 0 && image.pixels[i][j] == 255)
      {
        compteur += 1;
        numerotation(image_numerotee, compteur, i, j, image_numerotee); // numérote les cellules
      }

      DFS(image.pixels, i, j, tableau_booleen);
    }
  }

  free_pixels(tableau_booleen);

  return compteur;
}
