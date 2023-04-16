# DESIGN - MAIN

- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0

# TABLE DES MATIERES
- [DESIGN - MAIN](#design---main)
- [TABLE DES MATIERES](#table-des-matieres)
- [Function Main()](#function-main)


# Function Main()


- Ref : a001 a002 a003 (Specification.md)
- Input : `sii_morse_message` , `SII_MORSE_Data.iterate`
- Output :

```
while(1)
|   receive UART into SII_MORSE_Data with interrupt
|
|   sii_morse_message = SII_MORSE_MessageToMorse(SII_MORSE_Data.message)
|   transmit UART to PC sii_morse_message
|
|   SII_MODES_Mode_t sii_modes_mode = SII_MODES_GetMode(SII_MORSE_Data)
|
|   SII_MODES_RunMode(sii_modes_mode)
```