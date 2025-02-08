#include "bit_math.h"
#include "stdtypes.h"
#include "gpio_config.h"
#include "gpio_interface.h"
#include "gpio_private.h"

MGPIO_t MGPIO_ARR[USED_PINS*USED_PORTS]={
    {MGPIO_PIN0,MGPIOA,MGPIO_enuOutput,MGPIO_enuLowSpeed,MGPIO_enuNoPull,MGPIO_enuPushPull}
};