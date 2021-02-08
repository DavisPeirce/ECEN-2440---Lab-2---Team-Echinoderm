#include <msp430.h> 
#include <stdint.h>

/**
 * main.c
 */

int main(void){

    int a = 0;                                  //Initializing Variables
    int b = 0;
    uint16_t * memLoc;

	WDTCTL = WDTPW | WDTHOLD;	            // stop watchdog timer
                                           // Define a pointer that will iterate through the memory addresses
    memLoc = 0x2001000A;                   //Starting location

    for(memLoc; memLoc < 0x200103CC; memLoc++){   //For loop to look through each element in the desired memory range

        if(*memLoc == 0x0000ACCA){            //Scan for the desired half-word pattern
            a++;                            //Increment a
        }

        if(*memLoc == 0xABBAAFFA){          //Scan for the desired full-word pattern
            b++;                            //Increment b
        }
    }
	return 0;
}
