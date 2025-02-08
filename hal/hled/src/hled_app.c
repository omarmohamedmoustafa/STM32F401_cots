#include "stdtypes.h"
#include "bit_math.h"
#include "gpio_interface.h"
#include "hled_private.h"
#include "hled_config.h"
#include "hled_interface.h"

extern HLED_t HLED_arr[HLED_LED_COUNT];
void HLED_voidInit(void)
{
    for(u8 i=0; i<HLED_LED_COUNT; i++)
    {
            GPIO_enuSetPinDirection(HLED_arr[i].Port, HLED_arr[i].Pin, HLED_arr[i].Direction);
            GPIO_enuSetPinOutputType(HLED_arr[i].Port, HLED_arr[i].Pin, HLED_arr[i].OutputType);
            GPIO_enuSetPinSpeed(HLED_arr[i].Port, HLED_arr[i].Pin, HLED_arr[i].Speed);
    }
}

void HLED_voidOn(u8 Copy_u8Led)
{
    if(Copy_u8Led <= HLED_LED_COUNT)
    {
        GPIO_enuSetPinValue(HLED_arr[Copy_u8Led].Port, HLED_arr[Copy_u8Led].Pin, MGPIO_enuHigh);
    }
}

void HLED_voidOff(u8 Copy_u8Led)
{
    if(Copy_u8Led <= HLED_LED_COUNT)
    {
        GPIO_enuSetPinValue(HLED_arr[Copy_u8Led].Port, HLED_arr[Copy_u8Led].Pin, MGPIO_enuLow);
    }
}

void HLED_voidToggle(u8 Copy_u8Led)
{
    if(Copy_u8Led <= HLED_LED_COUNT)
    {
        GPIO_enuTogglePinValue(HLED_arr[Copy_u8Led].Port, HLED_arr[Copy_u8Led].Port);
    }
}

