#DESIGN - TIMERS

- Morse  Mini-Project (Board Side)
- STM32 Nucleo-F103RBT6
- V1.0

# TABLE DES MATIERES
- [DESIGN - TIMERS](#design---timers)
- [TABLE DES MATIERES](#table-des-matieres)
- [Function SII\_TIMERS\_Delays\_ms()](#function-sii_timers_timer2_init)
- [Function SII\_TIMERS\_Blink\_Led()](#function-sii_timers_timer2_init)


# Function SII_TIMERS_Delays_ms
- Ref : a005 (Specification.md)
- Input : `timer_ms`
- Output : `Delay`

```
while timer_ms > 0
|   timer_ms --
|   set_timer_counter = 0   
|   while get_timer_counter < 1000

```

# Function SII_TIMERS_Blink_Led
- Ref : a005 (Specification.md)
- Input : `timer_ms`
- Output : `LED` `Delay`

```
set LED as output_state
SII_TIMERS_Delays_ms(timer)

```