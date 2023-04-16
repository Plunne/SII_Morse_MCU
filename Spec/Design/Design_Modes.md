# DESIGN - MODES

- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0

# TABLE DES MATIERES
- [DESIGN - MODES](#design---modes)
- [TABLE DES MATIERES](#table-des-matieres)
- [Type SII\_MODES\_Mode\_t](#type-sii_modes_mode_t)
- [Function SII\_MODES\_GetMode()](#function-sii_modes_getmode)
- [Function SII\_MODES\_RunMode()](#function-sii_modes_runmode)
- [Function SII\_MODES\_Loop()](#function-sii_modes_loop)
- [Function SII\_MODES\_Iterate()](#function-sii_modes_iterate)


# Type SII_MODES_Mode_t

- Ref : b001 (Specification.md)
- Input :
- Output :

```
SII_MODES_Mode_t = { MODE_ITERATE, MODE_LOOP }
```

# Function SII_MODES_GetMode()

- Ref : b001 b002 b003 b004 (Specification.md)
- Input : `SII_MODES_Data`
- Output : `SII_MODES_Mode_t` 

```
if SII_MODES_Data.loop == 1
|   return MODE_LOOP
else if SII_MODES_Data.interate >= 1
|   return MODE_INTERATE
```

# Function SII_MODES_RunMode()

- Ref : b001 b002 b003 b004 (Specification.md)
- Input : `sii_modes_mode`
- Output : `SII_MODES_Loop()` , `SII_MODES_Iterate()`

```
if sii_modes_mode == MODE_LOOP
|   do SII_MODES_Loop()
else if sii_modes_mode == MODE_ITERATE
|   do SII_MODES_Iterate()
```

# Function SII_MODES_Loop()

- Ref : b001 b002 b003 b004 (Specification.md)
- Input : `sii_morse_message`
- Output :

```
SII_MORSE_MorseSignal(sii_morse_message)
```

# Function SII_MODES_Iterate()

- Ref : b001 b002 b003 b004 (Specification.md)
- Input : `sii_morse_message` , `SII_MORSE_Data.iterate`
- Output :

```
if sii_morse_iterateCounter is >= 1 and <= 255
|   SII_MORSE_MorseSignal(sii_morse_message)
|   SII_MORSE_Data.iterate--
```