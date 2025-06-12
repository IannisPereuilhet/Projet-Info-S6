#include <stdio.h>
#include <stdlib.h>
#include "image.h"



unsigned char** allocation_dynamique(unsigned char** tab, int nombre_lignes, int nombre_colonnes)
{
  // alloue dynamiquement et de manière contigüe un tableau 2D

  int taille = nombre_lignes * nombre_colonnes;
  int i;

  tab = (unsigned char**) calloc(nombre_lignes, sizeof(unsigned char*));
  if (tab == NULL)
  {
    printf("Erreur allocation\n");
    printf("\n");
    exit(1);
  }

  tab[0] = (unsigned char*) calloc(taille, sizeof(unsigned char));
  if (tab[0] == NULL)
  {
    printf("Erreur allocation\n");
    printf("\n");
    exit(1);
  }

  for (i=0; i<nombre_lignes; i++)
  {
    tab[i] = *tab + nombre_colonnes*i;
  }

  return tab;
}



void creer_image(Image* image, int nombre_lignes, int nombre_colonnes, unsigned char** pixels)
{
  // crée une structure Image

  image -> nombre_lignes = nombre_lignes;
  image -> nombre_colonnes = nombre_colonnes;
  image -> pixels = pixels;
}



Image lecture_pgm(char* image_pgm)
{
  // lit une image type PGM

  Image image;
  int nombre_lignes, nombre_colonnes, profondeur, taille;
  char entete[5];
  unsigned char** pixels = NULL;

  FILE *fichier = fopen(image_pgm, "r");

  if (fichier == NULL)
  {
    printf("Erreur ouverture de fichier\n");
    printf("\n");
    exit(1);
  }

  fscanf(fichier, "%s ", entete); // lit l'entête

  fscanf(fichier, "%d %d ", &nombre_colonnes, &nombre_lignes); // lit la taille

  taille = nombre_lignes * nombre_colonnes;

  fscanf(fichier, "%d ", &profondeur); // lit la profondeur

  pixels = allocation_dynamique(pixels, nombre_lignes, nombre_colonnes);

  fread(pixels[0], sizeof(unsigned char), taille, fichier); // lit les pixels

  fclose(fichier);

  creer_image(&image, nombre_lignes, nombre_colonnes, pixels);

  return image;
}



void ecriture_pgm(Image image, char* image_pgm)
{
  // crée une image type PGM

  int taille = image.nombre_lignes * image.nombre_colonnes;

  FILE *fichier = fopen(image_pgm, "w");

  fprintf(fichier, "P5\n"); // écrit l'entête

  fprintf(fichier, "%d %d\n", image.nombre_colonnes, image.nombre_lignes); // on écrit la taille

  fprintf(fichier, "255\n"); // on écrit la profondeur

  fwrite(image.pixels[0], sizeof(unsigned char), taille, fichier); // on écrit les pixels

  fclose(fichier);
}



void free_pixels(unsigned char** tab)
{
  // libère un tableau

  free(tab[0]);
  free(tab);
}



void free_image(Image image)
{
  // libère une image
  
  free_pixels(image.pixels);
}
