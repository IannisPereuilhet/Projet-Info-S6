# Projet Programmation S6

## Compilation

Étapes pour compiler :

- Cloner le dossier _valejule-pereuili_.
- Ouvrir le terminal dans ce dossier.
- Écrire la commande _make_.

## Exécution

Le dossier présente alors trois programmes situés dans le fichiers _bin_ : _programme_, _seuillage_manuel_ et _seuillage_automatique_.

**Exécuter _programme_ :**

Il s'agit du programme prinipal qui compte le nombre de cellules présentes dans une image du type PGM. Il prend en paramètre une image du type PGM _image.pgm_ disponible dans le dossier _fichiers/images_.

La commande pour exéctuer _programme_ est donc : _./bin/programme fichiers/images/image.pgm_.


**Exécuter _seuillage_manuel_ :**

Il s'agit d'un algorithme qui seuille une image du type PGM en rensigant un seuil. Il prend en paramètre une image du type PGM _image.pgm_ disponible dans le dossier _fichiers/images_ et un entier _seuil_ compris entre 0 et 255.

La commande pour exéctuer _seuillage_manuel_ est donc : _./bin/_seuillage_manuel_ fichiers/images/image.pgm seuil_.


**Exécuter _seuillage_automatique_ :**

Il s'agit d'un algorithme qui seuille une image du type PGM sans renseigner le seuil. Il prend en paramètre une image du type PGM _image.pgm_ disponible dans le dossier _fichiers/images_.

La commande pour exéctuer _seuillage_automatique_ est donc : _./bin/_seuillage_automatique_ fichiers/images/image.pgm_.

## Résultats

**Résultats _programme_ :**

Lors de l'exécution de ce programme, le terminal affichera le nom des différentes images phares du traitement à trouver dans le dossier _fichiers/traitement_, ainsi que le nombre de cellules comptées de l'image renseignée en paramètre. De plus, il offre le choix d'utiliser la méthode d'érosion : soit l'érosion manuelle de la version minimale, soir l'érosion automatique de la version avancée. Vous pourez également visualiser les cellules numérotées avec la dernière image affichée dans le terminal.

**Résultats _seuillage_manuel_ :**

Lors de l'exécution de ce programme, le terminal affichera le nom de l'image initiale et de l'image seuillée selon le seuil renseigné en paramètre à touver dans le dossier _fichiers/traitement_ sous le nom de _image_seuillée_manuellement.pgm_.

**Résultats _seuillage_automatique_ :**

Lors de l'exécution de ce programme, le terminal affichera le nom de l'image initiale et de l'image seuillée à touver dans le dossier _fichiers/traitement_ sous le nom de _image_seuillée_automatiquement.pgm_.
