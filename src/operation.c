#include <stdio.h>
#include <stdlib.h>
#include "image.h"



Image copie_image(Image image)
{
  // crée une copie de l'image
  
  Image image_copie;

  unsigned char** pixels = NULL;

  pixels = allocation_dynamique(pixels, image.nombre_lignes, image.nombre_colonnes);

  creer_image(&image_copie, image.nombre_lignes, image.nombre_colonnes, pixels);

  int i, j;

  for (i=0; i<image_copie.nombre_lignes; i++)
  {
    for (j=0; j<image_copie.nombre_colonnes; j++)
    {
      image_copie.pixels[i][j] = image.pixels[i][j];
    }
  }

  return image_copie;
}


Image image_vide(Image image)
{
  // crée une image noire

  int i, j;

  Image image_noire = copie_image(image);

  for (i=0; i<image.nombre_lignes; i++)
  {
    for (j=0; j<image.nombre_colonnes; j++)
    {
      image_noire.pixels[i][j] = 0;
    }
  }
  return image_noire;
}



void cadre_blanc(Image image, Image image_cadre_blanc)
{
  //crée un cadre blanc

  int i, j;

  for (i=0; i<image.nombre_lignes; i++)
  {
    for (j=0; j<image.nombre_colonnes; j++)
    {
      if ((i == 0)  || (j == 0) || (i == image.nombre_lignes - 1) || (j == image.nombre_colonnes - 1))
      {
        image_cadre_blanc.pixels[i][j] = 255;
      }
      else
      {
        image_cadre_blanc.pixels[i][j] = 0;
      }
    }
  }
}



void inverse_image(Image image, Image image_inversee)
{
  // inverse les pixels noirs et blancs d'une image

  int i, j;

  for (i=0; i<image.nombre_lignes; i++)
  {
    for (j=0; j<image.nombre_colonnes; j++)
    {
      if (image.pixels[i][j] == 0)
      {
        image_inversee.pixels[i][j] = 255;
      }
      else
      {
        image_inversee.pixels[i][j] = 0;
      }
    }
  }
}


void composition_images(Image image_mere, Image image_fille, int ligne, int colonne, Image image_composee)
{
  // crée une images composée à partir de l'image mère et image fille

  int i, j, k, l;

  for (i=0; i<image_mere.nombre_lignes; i++)
  {
    for (j=0; j<image_mere.nombre_colonnes; j++)
    {
      if ((i == ligne) && (j == colonne))
      {
        for (k=0; k<image_fille.nombre_lignes; k++)
        {
          for (l=0; l<image_fille.nombre_colonnes; l++)
          {
            if (image_fille.pixels[k][l] == 0)
            {
              image_composee.pixels[i+k][j+l] = image_fille.pixels[k][l];
            }
          }
        }
      }
    }
  }
}


int compare_images(Image image1, Image image2)
{
  // compare deux images et renvoie 1 si identiques, 0 sinon

  if ((image1.nombre_lignes == image2.nombre_lignes) && (image1.nombre_colonnes == image2.nombre_colonnes))
  {
    int i, j;

    for (i=0; i<image1.nombre_lignes; i++)
    {
      for (j=0; j<image1.nombre_colonnes; j++)
      {
        if (image1.pixels[i][j] != image2.pixels[i][j])
        {
          return 0;
        }
      }
    }

    return 1;
  }

  return 0;
}



int puissance_entier(int x, int n)
{
  // calcul x**n

  int i, y = 1;

  for (i=0; i<n; i++)
  {
    y = y * x;
  }

  return y;
}


void inverse_tab_entier(int* tab, int taille)
{
  // inverse les éléments d'un tableau d'entiers

  int i, x, n;

  if (taille%2 == 0)
  {
    n = taille / 2;
  }

  else
  {
    n = (taille-1)/2;
  }

  for (i=0;i<n;i++)
  {
    x = tab[i];

    tab[i] = tab[taille-1-i];

    tab[taille-1-i] = x;
  }
}

int nombre_de_chiffres(int n)
{
  // calcul le nombre de chiffres qui composent le nombre

  int i = 1;

  if (n == 0)
  {
    return i;
  }

  else
  {
    while (puissance_entier(10, i) <= n)
    {
      i++;
    }
  }

  return i;
}

void decomposition_entier(int n, int* tab)
{
  // décompose le nombre en puissance de 10 dans le tableau

  int i = nombre_de_chiffres(n);
  int a = 0;

  if (n == 0)
  {
    tab[i-1] = a;
  }

  else
  {
    if (i-1 == 0)
    {
      while (n-a != 0)
      {
        a++;
      }
      tab[i-1] = a;
    }


    else
    {
      while (n >= (a+1)*puissance_entier(10, i-1))
      {
        a++;
      }
      tab[i-1] = a;
      decomposition_entier(n-a*puissance_entier(10, i-1), tab);
    }

  }
}
