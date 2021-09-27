# Lab 1: Zuzana Czmelová

Link to your `Digital-electronics-2` GitHub repository:

   [GitHub link - 01-tools](https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/01-tools)


### Blink example

1. What is the meaning of the following binary operators in C?
   * `|`  - Bit Or
   * `&`  - Bit And
   * `^`  - Bit Xor
   * `~`  - Bit Nor
   * `<<` - Bit Left Shift
   * `>>` - Bit Right Shift

2. Complete truth table with operators: `|`, `&`, `^`, `~`

| **b** | **a** |**b or a** | **b and a** | **b xor a** | **not b** |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |


### Morse code

1. Listing of C code with syntax highlighting which repeats one "dot" and one "comma" on a LED:

```c
#define LED_GREEN   PB5 // AVR pin where green LED is connected
#define DOT_DELAY 100 // Delay in milliseconds
#define COMMA_DELAY 300 // Delay in milliseconds
#define SHORT_DELAY 100 // Delay in milliseconds
#ifndef F_CPU           // Preprocessor directive allows for conditional
                        // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000 // CPU frequency in Hz required for delay
#endif                  // The #ifndef directive must be closed by #endif

/* Includes ----------------------------------------------------------*/
/* Include another C language file into the current file at the location
 * of the #include statement prior to compiling the source code.
 */
#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop

    while (1)
    {
        // Pause several milliseconds
        //_delay_ms(SHORT_DELAY);

        // Invert LED in Data Register
        // PORTB = PORTB xor 0010 0000
		
		//D
		
        PORTB = PORTB ^ (1<<LED_GREEN);       
		_delay_ms(COMMA_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);              //pause
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
		//E
		PORTB = PORTB ^ (1<<LED_GREEN);  
		_delay_ms(DOT_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
	    //2
		PORTB = PORTB ^ (1<<LED_GREEN);  
		_delay_ms(DOT_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
		PORTB = PORTB ^ (1<<LED_GREEN);  
		_delay_ms(DOT_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(COMMA_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
		PORTB = PORTB ^ (1<<LED_GREEN); 
		_delay_ms(COMMA_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
		PORTB = PORTB ^ (1<<LED_GREEN); 
		_delay_ms(COMMA_DELAY);
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_DELAY);
		
    }

```


2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![scheme](Labs/scheme.png)
