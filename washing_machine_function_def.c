/*
 * File:   washing_machine_function_def.c
 * Author: Prajakta
 *
 * Created on 28 June, 2025, 3:28 PM
 */



#include "main.h"
extern unsigned char reset_flag; //reset_flag can be used in this file
char *washing_program[] = {"Daily", "Heavy", "Delicate", "Whites", "Stain Wash", "Ecocottons",
    "Woolens", "Wash Only", "Aqua Store", "Bedsheets", "Rinse+Dry", "Only Dry"};
unsigned char program_no = 0;
unsigned char level = 0;
unsigned char sec, min;
unsigned char total_time , wash_time , rinse_time , spin_time , time;
char *water_level[] = {"Auto", "Low", "Medium", "High", "Max"};
extern unsigned char operational_mode;
void power_on_screen(void) {
    for (unsigned int i = 0; i < 16; i++) {
        clcd_putch(BLOCK, LINE1(i));
        __delay_ms(100);
    }

    clcd_print("Powering ON", LINE2(1));
    clcd_print("Washing Machine", LINE3(1));

    for (unsigned int i = 0; i < 16; i++) {
        clcd_putch(BLOCK, LINE4(i));
        __delay_ms(100);
    }

    __delay_ms(1000);
}

void washing_program_display(unsigned char key) {
    if (reset_flag == RESET_WASH_PROGARAM_SCREEN) {
        clear_screen();
        reset_flag = RESET_NOTHING;

    }
    if (key == SW4) {
        clear_screen();
        program_no++;
        if (program_no == 12) {
            program_no = 0;

        }

    }

    clcd_print("WASHING PROGRAM", LINE1(0));
    clcd_putch('*', LINE2(0));
    if (program_no <= 9) {
        clcd_print(washing_program[program_no], LINE2(1));
        clcd_print(washing_program[program_no + 1], LINE3(1));
        clcd_print(washing_program[program_no + 2], LINE4(1));

    } else if (program_no == 10) {
        clcd_print(washing_program[program_no], LINE2(1));
        clcd_print(washing_program[program_no + 1], LINE3(1));
        clcd_print(washing_program[0], LINE4(1));

    } else if (program_no == 11) {
        clcd_print(washing_program[program_no], LINE2(1));
        clcd_print(washing_program[0], LINE3(1));
        clcd_print(washing_program[1], LINE4(1));

    }


}

void water_level_screen(unsigned char key) {
    if (reset_flag == WATER_LEVEL_SCREEN) {
        clear_screen();
        reset_flag = RESET_NOTHING;
    }
    if (key == SW4) {
        clear_screen();
        level++;
        if (level == 5) {
            level = 0;

        }
    }

    clcd_print("Water Level:", LINE1(0));
    clcd_putch('*', LINE2(0));
    clcd_print(water_level[level], LINE2(2));
    clcd_print(water_level[(level + 1) % 5], LINE3(2));
    clcd_print(water_level[(level + 2) % 5], LINE4(2));

}

void run_program(unsigned char key) 
{
    door_status_check();
    if (reset_flag == RESET_START_SCREEN) {
        clear_screen();
        clcd_print("Prog:", LINE1(0));
        clcd_print(washing_program[program_no], LINE1(0));
        clcd_print("Time:", LINE2(0));
        
        //int to ascii
        clcd_putch(min/10+'0',LINE2(6));
        clcd_putch(min%10+'0',LINE2(7));
        clcd_putch(':',LINE2(8));  
        clcd_putch(sec/10+'0',LINE2(9));
        clcd_putch(sec%10+'0',LINE2(10));
        reset_flag = RESET_NOTHING;
        
        
        __delay_ms(2000);
        
        clear_screen();
        clcd_print("Function:",LINE1(0));
        clcd_print("Time",LINE2(0));
        clcd_print("SW5:START ",LINE3(0));
        clcd_print("SW6:PAUSE",LINE4(0));
        
        
        total_time = time = min * 60 + sec;
        wash_time = (int) total_time*0.46;
        rinse_time = (int) total_time*0.12;
        spin_time = (int) total_time*0.42;
        
        
        TMR2ON = 1;
        FAN = ON;
    }
    
    if (key == SW6)
    {
        
        TMR2ON = 0;
        FAN =OFF;
        operational_mode = PAUSE;
    }
    
    total_time  = min*60+sec;
    if (program_no <= 7)
    {
        if (total_time>=(time - wash_time))
        {
            clcd_print("Wash",LINE1(10));
        }
        else if (total_time>=(time - wash_time - spin_time))
        {
            clcd_print("Rinse",LINE1(10));
        }
        else 
        {
            clcd_print("Spin",LINE1(10));
        }
    }
    
    else if (program_no == 8)
    {
        if (total_time >= (time - (0.4*time)))
        {
            clcd_print("Rinse",LINE1(10));
        }
        else 
        {
            clcd_print("Spin",LINE1(10));
        }
    }
    else if (program_no == 9)
         
        {
            clcd_print("Spin",LINE1(10));
        }
    else
    {
        clcd_print("Wash",LINE1(10));
    }
    
    clcd_putch(min/10+'0',LINE2(6));
        clcd_putch(min%10+'0',LINE2(7));
        clcd_putch(':',LINE2(8));  
        clcd_putch(sec/10+'0',LINE2(9));
        clcd_putch(sec%10+'0',LINE2(10));
        if(min == 0  && sec == 0)
        {
            clear_screen();
            FAN = OFF;
            BUZZER = ON;
            clcd_print("Program Complete",LINE1(0));
            clcd_print("Remove Clothes",LINE2(0));
            __delay_ms(3000);
            BUZZER = OFF;
             operational_mode = WASHING_PROGRAM_SCREEN;
             reset_flag = RESET_WASH_PROGARAM_SCREEN;
             clear_screen();
        }
}

//"Daily", "Heavy", "Delicate", "Whites", "Stain Wash", "Ecocottons",
//   "Woolens", "Wash Only", "Aqua Store", "Bedsheets", "Rinse+Dry", "Only Dry"

void set_time(void) {
    switch (program_no) {
        case 0: //daily
            switch (level) {

                case 1:
                    min = 0;
                    sec = 33;
                    break;
                case 0:
                case 2:
                    min = 0;
                    sec = 41;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 45;
                    break;
            }
            break;
        case 1: //heavy
            switch (level) {

                case 1:
                    min = 0;
                    sec = 43;
                    break;
                case 0:
                case 2:
                    min = 0;
                    sec = 50;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 57;
                    break;
            }
            break;
        case 2://delicate
            switch (level) {

                case 1:
                    min = 0;
                    sec = 26;
                    break;
                case 0:
                case 2:
                    min =0;
                    sec = 26;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 31;
                    break;
            }
            break;
        case 3://whites
            switch (level) {

                case 1:
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 1;
                    sec = 16;
                    break;
            }
            break;
        case 4://stain wash
            switch (level) {

                case 1:
                    min = 1;
                    sec = 36;
                    break;
                case 0:
                case 2:
                    min = 1;
                    sec = 36;
                    break;
                case 3:
                case 4:
                    min = 1;
                    sec = 36;
                    break;
            }
            break;
        case 5://ecocottons
             switch (level) {

                case 1:
                    
                case 0:
                case 2:
                   min = 0;
                    sec = 31;
                case 3:
                case 4:
                    min = 0;
                    sec = 36;
                    break;
            }
            break;
        case 6:
            switch (level) {

                case 1:
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 29;
                    break;
            }
            break;
        case 7:
            switch (level) {

                case 1:
                    min = 0;
                    sec = 46;
                    break;
                case 0:
                case 2:
                    min = 0;
                    sec = 53;
                    break;
                case 3:
                case 4:
                    min = 1;
                    sec = 0;
                    break;
            }
            break;
        case 8:
             switch (level) {

                case 1:
                    min = 0;
                    sec = 18;
                    break;
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 20;
                    break;
            }
            break;
        case 9:
             switch (level) {

                case 1:
                    min = 0;
                    sec = 15;
                    break;
                case 0:
                case 2:
                    min = 0;
                    sec = 20;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 25;
                    break;
            }
            break;
        case 10:
             switch (level) {

                case 1:
                    min = 0;
                    sec = 25;
                    break;
                case 0:
                case 2:
                    min = 0;
                    sec = 35;
                    break;
                case 3:
                case 4:
                    min = 1;
                    sec = 45;
                    break;
            }
            break;
        case 11:
             switch (level) {

                case 1:
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 50;
                    break;
            }
            break;


    }



}

void door_status_check()
{
    if(RB0  == 0)//door is open-sw is pressed
    {
        FAN = OFF;
        TMR2ON = 0;
        BUZZER = ON;
        clear_screen();
        clcd_print("Door is Open",LINE1(0));
        clcd_print("Pls Close Door",LINE2(0));
        //door is close-sw is released
        while (RB0 == 0)
        {
            ;//waiting until door is close
            
        }
         FAN = ON;
        TMR2ON = 1;
        BUZZER = OFF;
        clear_screen();
        clcd_print("Function:",LINE1(0));
        clcd_print("Time",LINE2(0));
        clcd_print("SW5:START ",LINE3(0));
        clcd_print("SW6:PAUSE",LINE4(0));
        
    }
}

void clear_screen(void) {
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}



