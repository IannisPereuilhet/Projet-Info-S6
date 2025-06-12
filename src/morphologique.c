#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "operation.h"
#include "booleenne.h"



Image miroir(Image image)
{
  // crée l'image miroir d'une image (de dimension augmentée de 2)

  Image image_miroir;

  unsigned char** pixels = NULL;

  pixels = allocation_dynamique(pixels, image.nombre_lignes + 2, image.nombre_colonnes +2);

  creer_image(&image_miroir, image.nombre_lignes + 2, image.nombre_colonnes + 2, pixels);

  int i, j;

  for (i=0; i<image_miroir.nombre_lignes; i++)
  {
    for (j=0; j<image_miroir.nombre_colonnes; j++)
    {
      // pixel en haut à gauche
      if ((i == 0) && (j == 0))
      {
        image_miroir.pixels[i][j] = image.pixels[i][j];
      }

      // pixel en haut à droite
      else if ((i == 0) && (j == image_miroir.nombre_colonnes - 1))
      {
        image_miroir.pixels[i][j] = image.pixels[i][j-2];
      }

      // pixel en bas à gauche
      else if ((i == image_miroir.nombre_lignes - 1) && (j == 0))
      {
        image_miroir.pixels[i][j] = image.pixels[i-2][j];
      }

      // pixel en bas à droite
      else if ((i == image_miroir.nombre_lignes - 1) && (j == image_miroir.nombre_colonnes - 1))
      {
        image_miroir.pixels[i][j] = image.pixels[i-2][j-2];
      }

      // pixels première ligne
      else if ((i == 0) && ((1 <= j) && (j <= image_miroir.nombre_colonnes - 2)))
      {
        image_miroir.pixels[i][j] = image.pixels[i][j-1];
      }

      // pixels dernière ligne
      else if ((i == image_miroir.nombre_lignes - 1) && ((1 <= j) && (j <= image_miroir.nombre_colonnes - 2)))
      {
        image_miroir.pixels[i][j] = image.pixels[i-2][j-1];
      }

      // pixels première colonne
      else if (((1 <= i) && (i <= image_miroir.nombre_lignes - 2)) && (j == 0))
      {
        image_miroir.pixels[i][j] = image.pixels[i-1][j];
      }

      // pixels dernière colonne
      else if (((1 <= i) && (i <= image_miroir.nombre_lignes - 2)) && (j == image_miroir.nombre_colonnes - 1))
      {
        image_miroir.pixels[i][j] = image.pixels[i-1][j-2];
      }

      else
      {
        image_miroir.pixels[i][j] = image.pixels[i-1][j-1];
      }
    }
  }

  return image_miroir;
}



void erosion(Image image, Image image_erodee)
{
  // érode l'image

  Image image_miroir = miroir(image);

  int nb_l = image_miroir.nombre_lignes;
  int nb_c = image_miroir.nombre_colonnes;

  int i, j;

  for (i=1; i<nb_l-1; i++)
  {
    for (j=1; j<nb_c-1; j++)
    {
      // 3x3 pixels
      if ( image_miroir.pixels[i-1][j-1] + image_miroir.pixels[i-1][j] + image_miroir.pixels[i-1][j+1]
         + image_miroir.pixels[i][j-1]   + image_miroir.pixels[i][j]   + image_miroir.pixels[i][j+1]
         + image_miroir.pixels[i+1][j-1] + image_miroir.pixels[i+1][j] + image_miroir.pixels[i+1][j+1] < 9*255 ) // si il y a au moins 1 pixel noir
      {
        image_erodee.pixels[i-1][j-1] = 0;
      }

      else
      {
        image_erodee.pixels[i-1][j-1] = 255;
      }
    }
  }

  free_image(image_miroir);
}



void dilatation(Image image, Image image_dilatee)
{
  // dilate l'image

  Image image_miroir = miroir(image);

  int nb_l = image_miroir.nombre_lignes;
  int nb_c = image_miroir.nombre_colonnes;

  int i, j;

  for (i=1; i<nb_l-1; i++)
  {
    for (j=1; j<nb_c-1; j++)
    {
      // 3x3 pixels
      if (image_miroir.pixels[i-1][j-1] + image_miroir.pixels[i-1][j] + image_miroir.pixels[i-1][j+1]
        + image_miroir.pixels[i][j-1]   + image_miroir.pixels[i][j]   + image_miroir.pixels[i][j+1]
        + image_miroir.pixels[i+1][j-1] + image_miroir.pixels[i+1][j] + image_miroir.pixels[i+1][j+1] > 0) // si il y a au moins 1 pixel blanc
      {
        image_dilatee.pixels[i-1][j-1] = 255;
      }

       else
       {
         image_dilatee.pixels[i-1][j-1] = 0;
       }
     }
   }

   free_image(image_miroir);
 }



Image reconstruction(Image image, Image graine)
{
  // fait croître la graine dans l'image

  Image image_dilatee = copie_image(image);
  Image image_operation_and = copie_image(image);
  Image image_reconstruite = copie_image(image);

  dilatation(graine, image_dilatee);

  operation_and(image, image_dilatee, image_operation_and);

  do {

    free_image(image_reconstruite);

    image_reconstruite = copie_image(image_operation_and);

    dilatation(image_operation_and, image_dilatee);

    operation_and(image, image_dilatee, image_operation_and);

  } while(compare_images(image_operation_and, image_reconstruite) == 0); // tant que les deux images sont différentes

  free_image(image_dilatee);
  free_image(image_operation_and);

  return image_reconstruite;
}
