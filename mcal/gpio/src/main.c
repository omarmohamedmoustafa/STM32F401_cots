#include "bit_math.h"
#include "stdtypes.h"
#include "rcc_interface.h"
#include "gpio_interface.h"
#include "gpio_private.h"

int main(){
        // Initialize the system clock
        RCC_voidInitSysClock();

        RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);

        GPIO_enumInit();

        GPIO_enuSetPinValue(MGPIOA, MGPIO_PIN0, LOGIC_HIGH);
    while(1){
        // Infinite loop to keep the program running
    }
    return 0;
}
