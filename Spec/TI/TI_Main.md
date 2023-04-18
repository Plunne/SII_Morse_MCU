#Document de Tests d'Intégration

- Test d'integration Fonctions du main
- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0


# TABLE DES MATIERES
- [Document de Tests d'Intégration](#document-de-tests-dintegration)
- [TABLE DES MATIERES](#table-des-matieres)
- [Test Intégration Function Main()](#test-integration-function-main)

# Test Intégration Function Main()

Ref Spécification : a001 a002 a003 (Specification.md)

**Résumé du test :** 

Vérification selon le 'mode(MODE_ITERATE, MODE_LOOP)' de la transmission du message de PC à la carte STM32 Nucleo-F103RBT6

**Etat initiale :** 

- La carte STM32 Nucleo-F103RBT6 n'est pas alimentée
- Un breakpoint est positionné sur l'appel de la fonction 'SII_MORSE_MessageToMorse()'
- Un breakpoint est positionné sur l'appel de la fonction 'SII_MODES_GetMode()'
- Un breakpoint est positionné sur l'appel de la fonction 'SII_MODES_RunMode()'

**Procédure d'éxecution :** 
1. Alimenter la carte
2. Pour le mode MODE_LOOP, saisir la trame 01 00 10 50 100 3 ‘S’ ‘o’ ‘S’ ‘\n’
3. Arreter le programme
4. Pour le mode MODE_ITERATE, saisir la trame 00 02 10 50 100 3 ‘S’ ‘o’ ‘S’ ‘\n’

**Vérifications necessaire :**
1. Au breakpoint de la fonction 'SII_MORSE_MessageToMorse()', la variable 'SII_MORSE_Data.message' contient le message saisit par l'utilisateur
2. Au breakpoint de la fonction 'SII_MODES_GetMode()', la variable 'mode' vaut 'MODE_ITERATE'
3. Au breakpoint de la fonction 'SII_MODES_GetMode()', la variable 'mode' vaut 'MODE_LOOP'
4. Selon le cas 2 ou 3, la led renvoie le message selon le mode