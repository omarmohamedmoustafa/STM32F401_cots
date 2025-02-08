#include "bit_math.h"
#include "stdtypes.h"
#include "rcc_interface.h"
#include "gpio_interface.h"
#include "gpio_private.h"
#include "systick_interface.h" // Include the SysTick header

int main()
{
    // Initialize the system clock
    RCC_voidInitSysClock();

    // Enable GPIOA clock
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);

    // Initialize GPIO
    GPIO_enumInit();

    // Configure GPIO Pin 0 as output
    GPIO_enuSetPinDirection(MGPIOA, MGPIO_PIN0, MGPIO_enuOutput);

    // Initialize SysTick
    SysTick_Init();

    // Set an initial value for the LED (optional)
    GPIO_enuSetPinValue(MGPIOA, MGPIO_PIN0, LOGIC_HIGH);

    while (1)
    {
        // Toggle the LED every 500ms using SysTick delay
        GPIO_enuSetPinValue(MGPIOA, MGPIO_PIN0, LOGIC_HIGH);
        SysTick_Delay(500);
        GPIO_enuSetPinValue(MGPIOA, MGPIO_PIN0, LOGIC_LOW);
        SysTick_Delay(500);
    }

    return 0;
}