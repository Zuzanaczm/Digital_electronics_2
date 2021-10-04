# Lab 2: Zuzana Czmelová

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/02-Leds](https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/02-Leds)


### Active-low and active-high LEDs

1. Complete tables according to the AVR manual.

| **DDRB** | **Description** |
| :-: | :-- |
| 0 | input pin |
| 1 | output pin |

| **PORTB** | **Description** |
| :-: | :-- |
| 0 | output low value |
| 1 | output high value |

| **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
| :-: | :-: | :-: | :-: | :-- |
| 0 | 0 | input | no | Tri-state, high-impedance |
| 0 | 1 | input | yes | Pxn will source current if ext. pulled low|
| 1 | 0 | output| no | output Low (Sink)|
| 1 | 1 | output | no | Ootput High (Source)|

2. Part of the C code listing with syntax highlighting, which blinks alternately with a pair of LEDs; let one LED is connected to port B and the other to port C:

```c
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define LED_RED   PC4
#define BLINK_DELAY 500

int main(void)
{
    DDRB = DDRB | (1<<LED_GREEN);
    // ...and turn LED off in Data Register
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Configure the second LED at port C
    DDRC = DDRC | (1<<LED_RED);
    PORTC = PORTC | (1<<LED_RED);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);

	PORTB = PORTB ^ (1<<LED_GREEN);
        PORTC = PORTC ^ (1<<LED_RED);
    }

    // Will never reach this
    return 0;
}
```
