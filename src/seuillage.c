#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void seuillage_manuel(Image image, int seuil, Image image_seuillee)
{
  // seuille une image manuellement

  int i, j;

  for (i=0; i<image.nombre_lignes; i++)
  {
    for (j=0; j<image.nombre_colonnes; j++)
    {
      if (image.pixels[i][j] >= seuil)
      {
        image_seuillee.pixels[i][j] = 255;
      }
      else
      {
        image_seuillee.pixels[i][j] = 0;
      }
    }
  }
}




void histogramme(Image image, float tableau_histogramme[256])
{
  // crée l'histogramme d'une image

  int k, i, j, compteur;

  int taille = image.nombre_lignes * image.nombre_colonnes;

  for (k=0; k<256; k++)
  {
    compteur = 0;

    for (i=0; i<image.nombre_lignes; i++)
    {
      for (j=0; j<image.nombre_colonnes; j++)
      {
        if (image.pixels[i][j] == k)
        {
          compteur++; // compte le nombre de pixels égal à k
        }
      }
    }
    tableau_histogramme[k] = compteur /(float) taille; // prend la répartition des pixels
  }
}



int seuil_Otsu(Image image)
{
  // calcul le seuil d'une image

  float tableau_histogramme[256];
  float variance, variance_max = 0;

  int s, i;
  int seuil = 0;

  histogramme(image, tableau_histogramme);

  for (s=0; s<256; s++) // calcul de la variance inter-classe
  {
    float probabilite_0 = 0, probabilite_1 = 0;
    float moyenne_0 = 0, moyenne_1 = 0;

    for (i=0; i<s; i++) // calculs des probabilités de classe
    {
      probabilite_0 += tableau_histogramme[i];
    }

    for (i=s; i<256; i++)
    {
      probabilite_1 += tableau_histogramme[i];
    }

    for (i=0; i<s; i++) // calculs des moyennes empiriques de classe
    {
      if (probabilite_0 != 0)
      {
        moyenne_0 += i * tableau_histogramme[i] /(float) probabilite_0;
      }
    }

    for (i=s; i<256; i++)
    {
      if (probabilite_1 != 0)
      {
        moyenne_1 += i * tableau_histogramme[i] /(float) probabilite_1;
      }
    }

    variance = probabilite_0 * probabilite_1 * (moyenne_0 - moyenne_1) * (moyenne_0 - moyenne_1);

    if (variance >= variance_max) // recherche du maximum de la variance inter-classe
    {
      variance_max = variance;
      seuil = s;
    }
  }

  return seuil;
}



void seuillage_automatique(Image image, Image image_seuillee)
{
  // seuille une image automatiquement
  
  int seuil = seuil_Otsu(image);

  int i, j;

  for (i=0; i<image.nombre_lignes; i++)
  {
    for (j=0; j<image.nombre_colonnes; j++)
    {
      if (image.pixels[i][j] >= seuil)
      {
        image_seuillee.pixels[i][j] = 255;
      }
      else
      {
        image_seuillee.pixels[i][j] = 0;
      }
    }
  }
}
