#include "stdtypes.h"
#include "bit_math.h"
#include "hled_config.h"
#include "hled_private.h"
#include "gpio_interface.h"


HLED_t HLED_arr[HLED_LED_COUNT] = {
    {MGPIO_PIN0, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN1, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN2, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN3, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN4, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN5, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN6, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull},
    {MGPIO_PIN7, MGPIOA, MGPIO_enuOutput, MGPIO_enuLowSpeed, MGPIO_enuNoPull, MGPIO_enuPushPull}
};