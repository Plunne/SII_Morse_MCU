# SII_Morse_MCU

Mini-projet Morse partie micro-controleur POEI SII

# MEMBRES

- Lena SAVY-LARIGALDIE
- Malik BERDIER
- Djibril BAH

# CONVENTION DE NOMMAGE

- Fonctions : `SII_MODULE_NomFonction()`
- Variables : `sii_module_nomVariable`
- Struct : `SII_MODULE_NomStructure`
- Types : `SII_MODULE_NomType_t`
- Enum : `SII_MODULE_NomEnum`
- Fichiers : `sii_module.c/h`

# OPTIONS DE COMMANDE

| Option |       Arguments       | Fonction                  |
|:------:|:---------------------:|:--------------------------|
|  `-m`  |      `"message"`      | Message a transcrire      |
|  `-b`  |                       | Mode boucle               |
|  `-n`  |        `0-255`        | Mode iteratif             |
|  `-t`  | `"0-255 0-255 0-255"` | Configuration des timers  |
|  `-s`  |                       | Arret de la transcription |

# TRAME

|          1           |       1       |          1          |          1           |          1           |         1         |         N          |  1   |
|:--------------------:|:-------------:|:-------------------:|:--------------------:|:--------------------:|:-----------------:|:------------------:|:----:|
|     Mode Boucle      | Nb Iterations |       Timer1        |        Timer2        |        Timer3        | Nombre de lettres | Lettres du Message | '\n' |
| 0=desactive 1=Active |     1-255     | centieme de seconde | centieme de secondes | centieme de secondes |       0-255       |    249 char max    | '\n' |