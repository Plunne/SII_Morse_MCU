# DESIGN - MORSE

- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0

# TABLE DES MATIERES
- [DESIGN - MORSE](#design---morse)
- [TABLE DES MATIERES](#table-des-matieres)
- [Type SII\_MORSE\_Data\_t](#type-sii_morse_data_t)
- [Function SII\_MORSE\_CharToMorse()](#function-sii_morse_chartomorse)
- [Function SII\_MORSE\_MessageToMorse()](#function-sii_morse_messagetomorse)
- [Function SII\_MORSE\_SignalOutput()](#function-sii_morse_signaloutput)
- [Function SII\_MORSE\_SignalCharacter()](#function-sii_morse_signalcharacter)
- [Function SII\_MORSE\_MorseSignal()](#function-sii_morse_morsesignal)


# Type SII_MORSE_Data_t

- Ref : e001 (Specification.md)
- Input :
- Output :

```
SII_MORSE_Data_t = {
    BYTE loop
    BYTE iterate
    BYTE timer1
    BYTE timer2
    BYTE timer3
    BYTE msgSize
    BYTE message[249]
    BYTE endChar
}
```
 
# Function SII_MORSE_CharToMorse()

- Ref : a004 (Specification.md)
- Input : `letter`
- Output : `sii_morse_morseList`

```
i = 0
while i < size of sii_morse_letterList
|   if letter == sii_morse_letterList[i]
|   |   return sii_morse_morseList[i]
|   else
|   |   i++
return 0
```

# Function SII_MORSE_MessageToMorse()

- Ref : a004 (Specification.md)
- Input : `sii_morse_morseMessage` , `SII_MORSE_Data.message`
- Output :

```
for_each char in SII_MORSE_Data.message
|   sii_morse_morseMessage[i * 5] = SII_MORSE_CharToMorse(SII_MORSE_Data.message[i])
```

# Function SII_MORSE_SignalOutput()

- Ref : a005 (Specification.md)
- Input : `timer` , `output_state`
- Output : `LED`

```
set LED as output_state
SII_TIMER_Delay(timer)
```

# Function SII_MORSE_SignalCharacter()

- Ref : a005 (Specification.md)
- Input : `character`
- Output :

```
if character == "     "
|   SII_MORSE_SignalOutput(Timer3, LOW)
else
|   for each in character
|   |   switch(character[i])
|   |   |   case '.'
|   |   |   |   SII_MORSE_SignalOutput(Timer1, HIGH)
|   |   |   |   break
|   |   |   case '_'
|   |   |   |   SII_MORSE_SignalOutput(Timer2, HIGH)
|   |   |   |   break
|   |   |   default
|   |   |   |   return 0
|   |   if i < 4
|   |   |   if character[i+1] == ( "." or "_" )
|   |   |   |   SII_MORSE_SignalOutput(Timer1, LOW)
|   |   |   else
|   |   |   |   SII_MORSE_SignalOutput(Timer2, LOW)
```

# Function SII_MORSE_MorseSignal()

- Ref : a005 (Specification.md)
- Input : `sii_morse_morseMessage`
- Output :

```
for each in sii_morse_morseMessage
|   SII_MORSE_SignalCharacter(sii_morse_morseMessage[i])
```