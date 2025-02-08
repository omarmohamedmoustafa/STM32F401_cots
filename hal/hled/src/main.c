#include "stdtypes.h"
#include "bit_math.h"
#include "rcc_interface.h"

#include "gpio_interface.h"
#include "hled_interface.h"

#include "hled_config.h"
#include "gpio_config.h"

void delay_ms(u32 delay) {
    volatile u32 i;
    for (volatile u32 i = 0; i < delay * 1000; i++);
}

int main()
{
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);
    HLED_voidInit();
    u8 direction = 1;   
    u8 currentLed = 0;  
    while (1) {
        HLED_voidOff(HLED_u8Led0);
        HLED_voidOff(HLED_u8Led1);
        HLED_voidOff(HLED_u8Led2);
        HLED_voidOff(HLED_u8Led3);
        HLED_voidOff(HLED_u8Led4);
        HLED_voidOff(HLED_u8Led5);
        HLED_voidOff(HLED_u8Led6);
        HLED_voidOff(HLED_u8Led7);


        HLED_voidOn(currentLed);  

        delay_ms(80);  

        if (currentLed == HLED_LED_COUNT - 1) {
            direction = -1;  
        } else if (currentLed == 0) {
            direction = 1;   
        }
        currentLed += direction;
    }
}