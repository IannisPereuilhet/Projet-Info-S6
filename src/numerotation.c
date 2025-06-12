#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "operation.h"

#define LIGNES 8
#define COLONNES 5


Image nombre_image(int lignes, int colonnes)
{
  // crée une image nombre blanche

  Image image_nombre;

  unsigned char** pixels = NULL;

  pixels = allocation_dynamique(pixels, lignes, colonnes);

  creer_image(&image_nombre, lignes, colonnes, pixels);

  int i, j;

  for (i=0; i<image_nombre.nombre_lignes; i++)
  {
    for (j=0; j<image_nombre.nombre_colonnes; j++)
    {
      image_nombre.pixels[i][j] = 255;
    }
  }

  return image_nombre;
}


Image numerotation_0(Image image_nombre)
{
  // crée une image 0

  Image image_0 = copie_image(image_nombre);

  image_0.pixels[0][1] = 0;
  image_0.pixels[0][2] = 0;
  image_0.pixels[0][3] = 0;
  image_0.pixels[7][1] = 0;
  image_0.pixels[7][2] = 0;
  image_0.pixels[7][3] = 0;
  image_0.pixels[1][0] = 0;
  image_0.pixels[2][0] = 0;
  image_0.pixels[3][0] = 0;
  image_0.pixels[4][0] = 0;
  image_0.pixels[5][0] = 0;
  image_0.pixels[6][0] = 0;
  image_0.pixels[1][4] = 0;
  image_0.pixels[2][4] = 0;
  image_0.pixels[3][4] = 0;
  image_0.pixels[4][4] = 0;
  image_0.pixels[5][4] = 0;
  image_0.pixels[6][4] = 0;

  return image_0;
}

Image numerotation_1(Image image_nombre)
{
  // crée une image 1

  Image image_1 = copie_image(image_nombre);

  image_1.pixels[0][2] = 0;
  image_1.pixels[1][1] = 0;
  image_1.pixels[2][0] = 0;
  image_1.pixels[1][2] = 0;
  image_1.pixels[2][2] = 0;
  image_1.pixels[3][2] = 0;
  image_1.pixels[4][2] = 0;
  image_1.pixels[5][2] = 0;
  image_1.pixels[6][2] = 0;
  image_1.pixels[7][0] = 0;
  image_1.pixels[7][1] = 0;
  image_1.pixels[7][2] = 0;
  image_1.pixels[7][3] = 0;
  image_1.pixels[7][4] = 0;

  return image_1;
}

Image numerotation_2(Image image_nombre)
{
  // crée une image 2

  Image image_2 = copie_image(image_nombre);

  image_2.pixels[0][1] = 0;
  image_2.pixels[0][2] = 0;
  image_2.pixels[0][3] = 0;
  image_2.pixels[1][0] = 0;
  image_2.pixels[1][4] = 0;
  image_2.pixels[2][4] = 0;
  image_2.pixels[3][3] = 0;
  image_2.pixels[4][2] = 0;
  image_2.pixels[5][1] = 0;
  image_2.pixels[6][0] = 0;
  image_2.pixels[7][0] = 0;
  image_2.pixels[7][1] = 0;
  image_2.pixels[7][2] = 0;
  image_2.pixels[7][3] = 0;
  image_2.pixels[7][4] = 0;

  return image_2;
}

Image numerotation_3(Image image_nombre)
{
  // crée une image 3

  Image image_3 = copie_image(image_nombre);

  image_3.pixels[0][1] = 0;
  image_3.pixels[0][2] = 0;
  image_3.pixels[0][3] = 0;
  image_3.pixels[1][0] = 0;
  image_3.pixels[1][4] = 0;
  image_3.pixels[2][4] = 0;
  image_3.pixels[3][2] = 0;
  image_3.pixels[3][3] = 0;
  image_3.pixels[4][4] = 0;
  image_3.pixels[5][4] = 0;
  image_3.pixels[6][4] = 0;
  image_3.pixels[6][0] = 0;
  image_3.pixels[7][1] = 0;
  image_3.pixels[7][2] = 0;
  image_3.pixels[7][3] = 0;

  return image_3;
}

Image numerotation_4(Image image_nombre)
{
  // crée une image 4

  Image image_4 = copie_image(image_nombre);

  image_4.pixels[0][3] = 0;
  image_4.pixels[1][3] = 0;
  image_4.pixels[1][2] = 0;
  image_4.pixels[2][3] = 0;
  image_4.pixels[2][1] = 0;
  image_4.pixels[3][3] = 0;
  image_4.pixels[3][0] = 0;
  image_4.pixels[4][0] = 0;
  image_4.pixels[4][1] = 0;
  image_4.pixels[4][2] = 0;
  image_4.pixels[4][3] = 0;
  image_4.pixels[4][4] = 0;
  image_4.pixels[5][3] = 0;
  image_4.pixels[6][3] = 0;
  image_4.pixels[7][3] = 0;

  return image_4;
}

Image numerotation_5(Image image_nombre)
{
  // crée une image 5

  Image image_5 = copie_image(image_nombre);

  image_5.pixels[0][0] = 0;
  image_5.pixels[0][1] = 0;
  image_5.pixels[0][2] = 0;
  image_5.pixels[0][3] = 0;
  image_5.pixels[0][4] = 0;
  image_5.pixels[1][0] = 0;
  image_5.pixels[2][0] = 0;
  image_5.pixels[3][0] = 0;
  image_5.pixels[3][1] = 0;
  image_5.pixels[3][2] = 0;
  image_5.pixels[3][3] = 0;
  image_5.pixels[4][4] = 0;
  image_5.pixels[5][4] = 0;
  image_5.pixels[6][4] = 0;
  image_5.pixels[6][0] = 0;
  image_5.pixels[7][1] = 0;
  image_5.pixels[7][2] = 0;
  image_5.pixels[7][3] = 0;

  return image_5;
}

Image numerotation_6(Image image_nombre)
{
  // crée une image 6

  Image image_6 = copie_image(image_nombre);

  image_6.pixels[0][2] = 0;
  image_6.pixels[0][3] = 0;
  image_6.pixels[1][1] = 0;
  image_6.pixels[2][0] = 0;
  image_6.pixels[3][0] = 0;
  image_6.pixels[3][1] = 0;
  image_6.pixels[3][2] = 0;
  image_6.pixels[3][3] = 0;
  image_6.pixels[4][0] = 0;
  image_6.pixels[4][4] = 0;
  image_6.pixels[5][0] = 0;
  image_6.pixels[5][4] = 0;
  image_6.pixels[6][0] = 0;
  image_6.pixels[6][4] = 0;
  image_6.pixels[7][1] = 0;
  image_6.pixels[7][2] = 0;
  image_6.pixels[7][3] = 0;

  return image_6;
}

Image numerotation_7(Image image_nombre)
{
  // crée une image 7

  Image image_7 = copie_image(image_nombre);

  image_7.pixels[0][0] = 0;
  image_7.pixels[0][1] = 0;
  image_7.pixels[0][2] = 0;
  image_7.pixels[0][3] = 0;
  image_7.pixels[0][4] = 0;
  image_7.pixels[1][4] = 0;
  image_7.pixels[2][3] = 0;
  image_7.pixels[3][3] = 0;
  image_7.pixels[4][2] = 0;
  image_7.pixels[5][2] = 0;
  image_7.pixels[7][1] = 0;
  image_7.pixels[6][1] = 0;

  return image_7;
}

Image numerotation_8(Image image_nombre)
{
  // crée une image 8

  Image image_8 = copie_image(image_nombre);

  image_8.pixels[0][1] = 0;
  image_8.pixels[0][2] = 0;
  image_8.pixels[0][3] = 0;
  image_8.pixels[1][0] = 0;
  image_8.pixels[1][4] = 0;
  image_8.pixels[2][0] = 0;
  image_8.pixels[2][4] = 0;
  image_8.pixels[3][1] = 0;
  image_8.pixels[3][2] = 0;
  image_8.pixels[3][3] = 0;
  image_8.pixels[4][0] = 0;
  image_8.pixels[4][4] = 0;
  image_8.pixels[5][0] = 0;
  image_8.pixels[5][4] = 0;
  image_8.pixels[6][0] = 0;
  image_8.pixels[6][4] = 0;
  image_8.pixels[7][1] = 0;
  image_8.pixels[7][2] = 0;
  image_8.pixels[7][3] = 0;

  return image_8;
}

Image numerotation_9(Image image_nombre)
{
  // crée une image 9

  Image image_9 = copie_image(image_nombre);

  image_9.pixels[0][1] = 0;
  image_9.pixels[0][2] = 0;
  image_9.pixels[0][3] = 0;
  image_9.pixels[1][0] = 0;
  image_9.pixels[1][4] = 0;
  image_9.pixels[2][0] = 0;
  image_9.pixels[2][4] = 0;
  image_9.pixels[3][0] = 0;
  image_9.pixels[3][4] = 0;
  image_9.pixels[4][1] = 0;
  image_9.pixels[4][2] = 0;
  image_9.pixels[4][3] = 0;
  image_9.pixels[4][4] = 0;
  image_9.pixels[5][4] = 0;
  image_9.pixels[6][3] = 0;
  image_9.pixels[7][2] = 0;
  image_9.pixels[7][1] = 0;

  return image_9;
}


Image numerotation_image(Image image_nombre, int n)
{
  // crée un image nombre en fonction du nombre

  Image image_numero;

  if (n == 0)
  {
    image_numero = numerotation_0(image_nombre);
  }

  else if (n == 1)
  {
    image_numero = numerotation_1(image_nombre);
  }

  else if (n == 2)
  {
    image_numero = numerotation_2(image_nombre);
  }

  else if (n == 3)
  {
    image_numero = numerotation_3(image_nombre);
  }

  else if (n == 4)
  {
    image_numero = numerotation_4(image_nombre);
  }

  else if (n == 5)
  {
    image_numero = numerotation_5(image_nombre);
  }

  else if (n == 6)
  {
    image_numero = numerotation_6(image_nombre);
  }

  else if (n == 7)
  {
    image_numero = numerotation_7(image_nombre);
  }

  else if (n == 8)
  {
    image_numero = numerotation_8(image_nombre);
  }

  else if (n == 9)
  {
    image_numero = numerotation_9(image_nombre);
  }

  return image_numero;
}



void numerotation(Image image, int nombre, int ligne, int colonne, Image image_numerotee)
{
  // compte le nombre de cellules

  int n = nombre_de_chiffres(nombre);
  int i;

  int* tab = (int*) calloc(n, sizeof(int));

  decomposition_entier(nombre, tab); // décompose le nombre en puissance de 10 dans le tableau
  inverse_tab_entier(tab, n);

  Image image_nombre = nombre_image(LIGNES, COLONNES);

  Image image_mere = copie_image(image);

  for (i=0; i<n; i++)
  {
    Image image_numero = numerotation_image(image_nombre, tab[i]);

    composition_images(image_mere, image_numero, ligne - LIGNES/2, colonne - (COLONNES+1)*(n-1)/2 + (COLONNES+1)*i, image_numerotee); // crée une image composée

    free_image(image_mere);
    free_image(image_numero);

    image_mere = copie_image(image_numerotee);
  }

  free_image(image_mere);
  free_image(image_nombre);
  free(tab);
}
