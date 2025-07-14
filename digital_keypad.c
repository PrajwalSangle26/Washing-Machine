#include <xc.h>
#include "digital_keypad.h"

void init_digital_keypad(void) {
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad(unsigned char mode) {
    static unsigned char once = 1;
    static unsigned char long_press = 1;
    unsigned char key = KEYPAD_PORT & INPUT_LINES;
    static unsigned char pre_key;
    if (key != ALL_RELEASED && once)//1st time switch pressed
    {
        once = 0;
        long_press = 0;
        pre_key = key;



    } else if (key == ALL_RELEASED && !once) {
        once = 1;
        if (long_press < 15)
            return pre_key; //short press
    } else if (!once && long_press <= 15) {
        long_press++;
    } else if (!once && long_press == 16 && key == SW4) {
        long_press++;
        return LPSW4; //long press
        
    }
    
    return ALL_RELEASED;
}



