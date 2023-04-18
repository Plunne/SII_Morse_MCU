# Document de Tests de validation

- Test d'integration Timers
- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0
# TABLE DES MATIERES
- [Document de Tests](#document-de-tests)
- [TABLE DES MATIERES](#table-des-matieres)
- [Test validation Function Main()](#test_validation_function_main)
- [Test validation Function Mode()](#test_validation_function_main)

# Test validation Function Main()

Ref Spécification : a001 a002 a003 a004 a005(Specification.md)

**Resume du test :**  

Tester que le message saisi par l'utilisateur sur l'ordinateur soit traduit en morse à l'aide d'une LED sur une carte STM32 Nucleo-F103RBT6 via le protocole de communication UART

**Etat initial :**

- La carte est demarrée
- Le terminale et la commande de lancement du script sont lancé, en attente de la saisie de l'utilisateur

**Procedure d'execution :**
1. L'utilisateur saisit en texte les options et leurs arguments, si nécessaire, depuis l'invité de commande vers le microtroleurs.

**Vérification nécessaire :**
1. La LED renvoie en morse le message saisi par l'utilisateur.
2. Le message boucle en fonction du saisi de l'utilisateur.
3. La LED clignote selon des temps variés définis par timer1, timer2, timer3.


# Test validation Function Mode()

Ref Spécification : b001 b002 b003 b004(Specification.md)

**Resume du test :**  

Tester que le message boucle en continue ou par itération selon la saisie de l'utilisateur

**Etat initial :**
- La carte est demarrée
- Le terminale et la commande de lancement du script sont lancé, en attente de la saisie de l'utilisateur

**Procedure d'execution :**
1. L'utilisateur saisit dans la ligne le commande `-b` pour envoyer en continue le message
2. L'utilisateur saisit dans la ligne le commande `-n`pour répéter n fois le message 

**Vérification nécessaire :**
1. La LED répète en boucle le message morse.
2. La LED répète n fois le message morse.

# Test validation Function Commande

Ref Spécification : c001 c002 c003 c004 c005 c006 d001 d002(Specification.md)

**Resume du test :**  

Tester les différents options que peut saisir l'utilisateur

**Etat initial :**
- La carte est demarrée
- Le terminale et la commande de lancement du script sont lancé, en attente de la saisie de l'utilisateur

**Procedure d'execution :**
1. L'utilisateur saisit l'option `-m` avec le message textuel 
2. L'utilisateur saisit l'option `-t` avec la duree des temps courts, moyens et longs du message morse
3. L'utilisateur saisit l'option `-b` qui transmet en boucle le message morse
4. L'utilisateur saisit l'option `-n` avec le nombre de fois que le message morse est envoyé
5. L'utilisateur saisit l'option `-s` pour arrêter la transmission du message morse
6. L'utilisateur saisit l'option `-h` pour afficher l'aide de commande

**Vérification nécessaire :**
1. Avec un break point au niveau des fonctions du protocole UART, vérifier que le message est transmis  
2. Vérifier que la LED clignote selon la duree des temps courts, moyens et longs
3. Vérifier que la LED retranscrit le message morse en boucle
4. Vérifier que la LED retranscrit le message morse n fois
5. Vérifier lorsque d'une transmission bouclée ou itérative, `-s` pour arrêter la transmission
6. Vérifier l'affichage de l'aide des commande lors de la saisie de l'option  `-h`
7. Vérifier si le message est vide et que l'option `-s` n'est pas active, afficher un message d'erreurs
8. Vérifier que l’utilisateur ne puisse pas utiliser les options `-n` et `-b` en même temps.