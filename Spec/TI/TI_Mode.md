#Document de Tests d'Intégration

- Test d'integration Mode
- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0


# TABLE DES MATIERES
- [Document de Tests d'Intégration](#document-de-tests-dintegration)
- [TABLE DES MATIERES](#table-des-matieres)
- [Test Intégration Function SII\_MODES\_GetMode()](#test-integration-sii_modes_getmode)
- [Test Intégration Function SII\_MODES\_RunMode()](#test-integration-sii_modes_runmode)
- [Test Intégration Function SII\_MODES\_Loop()](#test-integration-sii_modes_loop)
- [Test Intégration Function SII\_MODES\_Iterate()](#test-integration-sii_modes_iterate)

# Test Intégration Function SII_MODES_GetMode()

Ref Spécification : b001 b002 b003 b004 (Specification.md)

**Résumé du test :** 

Vérification de la renvoie du mode associée '(MODE_ITERATE, MODE_LOOP)'

**Etat initiale :** 

- Fin du test integration Test Intégration Function Main()

**Procédure d'éxecution :** 
- ????

**Vérifications necessaire :**
1. Au breakpoint de la fonction 'SII_MODES_GetMode()', si la variable 'SII_MODES_Data.loop' vaut 1 renvoie 'MODE_LOOP'
2. Au breakpoint de la fonction 'SII_MODES_GetMode()', si la variable 'SII_MODES_Data.loop' différent de 1 renvoie ??
3. Au breakpoint de la fonction 'SII_MODES_GetMode()', si la variable 'SII_MODES_Data.interate' à pour valeur supérieur ou égale à 1 renvoie 'MODE_INTERATE'
4. Au breakpoint de la fonction 'SII_MODES_GetMode()', si la variable 'SII_MODES_Data.interate' à pour valeur inférieur à 1 renvoie ??


# Test Intégration Function SII_MODES_RunMode()

Ref Spécification : b001 b002 b003 b004 (Specification.md)

**Résumé du test :** 

Vérification de la sélection entre les différents modes '(MODE_ITERATE, MODE_LOOP)'

**Etat initiale :** 

- Fin du test integration Test Intégration Function Main()

**Procédure d'éxecution :** 
1. Alimenter la carte
2. Un breakpoint est positionné sur l'appel de la fonction 'SII_MODES_RunMode()'

**Vérifications necessaire :**
1. Si la variable sii_modes_mode vaut 'MODE_LOOP' lance l'appel à la fonction Function SII_MODES_Loop()
2. Si la variable sii_modes_mode vaut 'MODE_ITERATE' lance l'appel à la fonction Function SII_MODES_ITERATE()


# Test Intégration Function SII_MODES_Loop()

Ref Spécification : b001 b002 b003 b004 (Specification.md)

**Résumé du test :** 

Vérification de l'envoie en boucle du message 'sii_morse_message'

**Etat initiale :** 

- Fin du test integration Test Intégration Function SII_MODES_RunMode()

**Procédure d'éxecution :** 
1. Alimenter la carte
2. Un breakpoint est positionné sur l'appel de la fonction 'SII_MODES_Loop()'

**Vérifications necessaire :**
1. La led du microcontroleur renvoi en continue le message en morse saisi par l'utilisateur


# Test Intégration Function SII_MODES_Iterate()

Ref Spécification : b001 b002 b003 b004 (Specification.md)

**Résumé du test :** 

Vérification de l'envoie en boucle du message 'sii_morse_message'

**Etat initiale :** 

- Fin du test integration Test Intégration Function SII_MODES_RunMode()

**Procédure d'éxecution :** 
1. Alimenter la carte
2. Un breakpoint est positionné sur l'appel de la fonction 'SII_MODES_Iterate()'

**Vérifications necessaire :**
1. La led du microcontroleur renvoie un nombre X de fois le message en morse saisi par l'utilisateur
