# SPECIFICATION

Mini-projet Morse

> **IMPORTANT!** Il faut minimum un design par fonctionnalite.

# TABLE DES MATIERES
- [SPECIFICATION](#specification)
- [TABLE DES MATIERES](#table-des-matieres)
- [Exigences A - General](#exigences-a---general)
- [Exigences B - Modes](#exigences-b---modes)
- [Exigences C - Commande PC](#exigences-c---commande-pc)
- [Exigences D - Erreurs](#exigences-d---erreurs)
- [Exigences E - Trame](#exigences-e---trame)

# Exigences A - General

| id   | version | description                                                                 |
|------|---------|-----------------------------------------------------------------------------|
| a001 | v1.0    | 2 unites, un PC et une carte STM32 Nucleo-F103RBT6                          |
| a002 | v1.0    | Communication entre les 2 unites via protocole UART                         |
| a003 | v1.0    | Le PC doit transmettre un message vers la carte                             |
| a004 | v1.0    | La carte doit traduire le message recu en MORSE                             |
| a005 | v1.0    | La carte doit transcrire le message traduit a l'aide de la LED built-in PA5 |

# Exigences B - Modes

| id   | version | description                                                                                           |
|------|---------|-------------------------------------------------------------------------------------------------------|
| b001 | v1.0    | Il y a les modes `boucle` et `nombre`                                                                 |
| b002 | v1.0    | Le mode `boucle` repete la transcription morse en boucle                                              |
| b003 | v1.0    | Le mode `nombre` fait repeter la transcription morse un nombre de fois renseigne avec l'argument `-n` |
| b004 | v1.0    | Les modes `boucle` et `nombre` ne peuvent etre utilises ensembles                                     |

# Exigences C - Commande PC

| id   | version | description                                                                                                      |
|------|---------|------------------------------------------------------------------------------------------------------------------|
| c001 | v1.0    | L'utilisateur du PC doit saisir avec l'argument `-m` le message textuel                                          |
| c002 | v1.0    | L'utilisateur du PC peut saisir avec l'argument `-t` la duree des temps courts, moyens et longs du message morse |
| c003 | v1.0    | L'utilisateur du PC peut saisir l'argument `-b` qui transmet le mode `boucle`                                    |
| c004 | v1.0    | L'utilisateur du PC peut saisir avec l'argument `-n` le mode `nombre`                                            |
| c005 | v1.0    | L'utilisateur du PC peut saisir l'argument `-s` qui transmet l'arret de la transcription                         |
| c006 | v1.0    | L'utilisateur du PC peut saisir avec l'argument `-h` pour afficher l'aide de la commande                         |

# Exigences D - Erreurs

| id   | version | description                                                                                 |
|------|---------|---------------------------------------------------------------------------------------------|
| d001 | v1.0    | Si le message est vide et que l'option `-s` n'est pas active, afficher un message d'erreurs |
| d002 | v1.0    | Si le message avec plus grand que 256 octets, refuser la commande de l'utilisateur          |

# Exigences E - Trame

**Exigence e001 :**

La trame doit respecter le format suivant.

|          1           |       1       |          1          |          1           |          1           |         1         |         N          |  1   |
|:--------------------:|:-------------:|:-------------------:|:--------------------:|:--------------------:|:-----------------:|:------------------:|:----:|
|     Mode Boucle      | Nb Iterations |       Timer1        |        Timer2        |        Timer3        | Nombre de lettres | Lettres du Message | '\n' |
| 0=desactive 1=Active |     1-255     | centieme de seconde | centieme de secondes | centieme de secondes |       0-255       |    249 char max    | '\n' |

**Exigence e002 :**

Trame par defaut.

|      1      |       1       |   1    |   1    |   1    |         1         |         N          |  1   |
|:-----------:|:-------------:|:------:|:------:|:------:|:-----------------:|:------------------:|:----:|
| Mode Boucle | Nb Iterations | Timer1 | Timer2 | Timer3 | Nombre de lettres | Lettres du Message | '\n' |
|      0      |       1       | 100ms  | 500ms  | 1000ms |        TBD        |        TBD         | '\n' |

