/***********************************************************************
 * 
 * Seven-segment display library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-2021 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000
#endif
#include <util/delay.h>
#include "gpio.h"
#include "segment.h"

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: SEG_init()
 * Purpose:  Configure SSD signals LATCH, CLK, and DATA as output.
 * Returns:  none
 **********************************************************************/
void SEG_init(void)
{
    /* Configuration of SSD signals */
    GPIO_config_output(&DDRD, SEGMENT_LATCH);
    GPIO_config_output(&DDRD, SEGMENT_CLK);
    GPIO_config_output(&DDRB, SEGMENT_DATA);
}

/// Active-low digit 0 to 9
uint8_t segment_value[] = {
    // abcdefgDP
    0b00000011,          // Digit 0
    0b10011111,          // Digit 1
    0b00100101,          // Digit 2
    0b00001101,          // Digit 3
    0b10011001,          // Digit 4
    0b01001001,          // Digit 5
    0b01001001,          //Digit 6
    0b00011111,          //Digit 7
    0b00000001,          //Digit 8
    0b00001001,           //Digit 9
};

// Active-high position 0 to 3
uint8_t segment_position[] = {
    // p3p2p1p0....
    0b00010000,     // Position 0
    0b00100000,     // Position 1
    0b01000000,          // Postiton 2
    0b10000000,              // Postiton 3
};


/*--------------------------------------------------------------------*/
void SEG_update_shift_regs(uint8_t segments, uint8_t position)
{
    uint8_t bit_number;

    GPIO_write_low(&PORTD, SEGMENT_LATCH);
    GPIO_write_low(&PORTD, SEGMENT_CLK);
    GPIO_write_low(&PORTB, SEGMENT_DATA);
    
   _delay_us(1);
    // Loop through the 1st byte (segments)
    // a b c d e f g DP (active low values)
    for (bit_number = 0; bit_number < 8; bit_number++)
    {
        // Test LSB of "segments" by & (faster) or % (slower) and... 
        // ...output DATA value
      if (segments & 1)
      {   GPIO_write_high(&PORTD, SEGMENT_DATA);
          } 
         
      
      else 
           GPIO_write_low(&PORTD, SEGMENT_DATA);
          
          
        _delay_us(1);
       
          GPIO_write_high(&PORTD, SEGMENT_CLK);

        _delay_us(1);

         GPIO_write_low(&PORTD, SEGMENT_CLK);
       
        // Shift "segments"
        segments = segments >> 1;
    }

    // Loop through the 2nd byte (position)
    // p3 p2 p1 p0 . . . . (active high values)
    for (bit_number = 0; bit_number < 8; bit_number++)
    {
          if (position & 1)
          { GPIO_write_high(&PORTD, SEGMENT_DATA);     
             }
          
          
          else
              
            GPIO_write_low(&PORTD, SEGMENT_DATA);
              
         
     _delay_us(1);

    GPIO_write_high(&PORTD, SEGMENT_CLK);

    _delay_us(1);

    GPIO_write_low(&PORTD, SEGMENT_CLK);

        // Shift "position"
        position = position >> 1;
    }

     GPIO_write_high(&PORTD, SEGMENT_LATCH);

    _delay_us(1);

}

/**********************************************************************
 * Function: SEG_clear()
 **********************************************************************/

/**********************************************************************
 * Function: SEG_clk_2us()
 **********************************************************************/