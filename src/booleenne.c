#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void operation_and(Image image1, Image image2, Image image_operation_and)
{
  // fait l'operation and entre image1 et image2

  int i, j;

  if ((image1.nombre_lignes != image2.nombre_lignes) || (image1.nombre_colonnes != image2.nombre_colonnes))
  {
    printf("Erreur taille\n");
    printf("\n");
    exit(1);
  }

  for (i=0; i<image1.nombre_lignes; i++)
  {
    for (j=0; j<image1.nombre_colonnes; j++)
    {
      if ((image1.pixels[i][j] == 255) && (image2.pixels[i][j] == 255))
      {
        image_operation_and.pixels[i][j] = 255;
      }
      else
      {
        image_operation_and.pixels[i][j] = 0;
      }
    }
  }
}



void operation_or(Image image1, Image image2, Image image_operation_or)
{
  // fait l'operation or entre image1 et image2

  int i, j;

  if ((image1.nombre_lignes != image2.nombre_lignes) || (image1.nombre_colonnes != image2.nombre_colonnes))
  {
    printf("Erreur taille\n");
    printf("\n");
    exit(1);
  }

  for (i=0; i<image1.nombre_lignes; i++)
  {
    for (j=0; j<image1.nombre_colonnes; j++)
    {
      if ((image1.pixels[i][j] == 0) && (image2.pixels[i][j] == 0))
      {
        image_operation_or.pixels[i][j] = 0;
      }
      else
      {
        image_operation_or.pixels[i][j] = 255;
      }
    }
  }
}



void operation_xor(Image image1, Image image2, Image image_operation_xor)
{
  // fait l'operation xor entre image1 et image2

  int i, j;

  if ((image1.nombre_lignes != image2.nombre_lignes) || (image1.nombre_colonnes != image2.nombre_colonnes))
  {
    printf("Erreur taille\n");
    printf("\n");
    exit(1);
  }

  for (i=0; i<image1.nombre_lignes; i++)
  {
    for (j=0; j<image1.nombre_colonnes; j++)
    {
      if (image1.pixels[i][j] == image2.pixels[i][j])
      {
        image_operation_xor.pixels[i][j] = 0;
      }
      else
      {
        image_operation_xor.pixels[i][j] = 255;
      }
    }
  }
}
