#Document de Tests d'Intégration

- Test d'integration Timers
- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0


# TABLE DES MATIERES
- [Document de Tests d'Intégration](#document-de-tests-dintegration)
- [TABLE DES MATIERES](#table-des-matieres)
- [Test Intégration Function SII\_TIMERS\_Delays\_ms()](#test-integration-function-sii_timers_delays_ms)
- [Test Intégration Function SII\_TIMERS\_Blink\_Led()](#test-integration-function-sii_timers_delays_ms)


# Test Intégration Function SII_TIMERS_Delays_ms()

Ref Spécification : a005 (Specification.md)

**Résumé du test :** 

Vérification de la détection du tick d’horloge

**Etat initiale :** 
- La carte n'est pas alimentée
- La variable `timer_ms` prend la valeur du temps en ms
- Un breakpoint est positionné à l'appel de la fonction `SII_TIMERS_Delays_ms()`

**Procédure d'éxecution :** 
- Continuer l’exécution sur les breakpoints `SII_TIMERS_Delays_ms()` et enregistrer l’intervalle entre deux

**Vérifications necessaire :**
1. Vérifier que l’intervalle entre deux breakpoints correspond a 1seconde (~1000ms)


# Test Intégration Function SII_TIMERS_Blink_Led()

Ref Spécification : a005 (Specification.md)

**Résumé du test :** 

Vérification de la détection du tick d’horloge

**Etat initiale :** 
- La carte n'est pas alimentée
- La variable `timer_ms` prend la valeur du temps en ms
- Un breakpoint est positionné à l'appel de la fonction SII_`TIMERS_Blink_Led()`

**Procédure d'éxecution :** 
- Enregistrer l’intervalle entre deux clignotements de l'intervalle

**Vérifications necessaire :**
1. Vérifier que l’intervalle de clignotement correspond a 1seconde (~1000ms)