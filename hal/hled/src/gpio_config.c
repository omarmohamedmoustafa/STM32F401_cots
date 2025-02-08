#include "bit_math.h"
#include "stdtypes.h"
#include "gpio_config.h"
#include "gpio_interface.h"
#include "gpio_private.h"

/**
 * typedef struct{
    MGPIO_enuPin_t Pin;
    MGPIO_enuPort_t Port;
    MGPIO_enuPinDirection_t Direction;
    MGPIO_enuSpeed_t Speed;
    MGPIO_enuInputType_t PullType;
    MGPIO_enuPinOutType_t OutputType;
}MGPIO_t;
 */
MGPIO_t MGPIO_ARR[USED_PINS_PER_PORT*USED_PORTS]={
    {MGPIO_PIN0,MGPIOA,MGPIO_enuOutput,MGPIO_enuLowSpeed,MGPIO_enuNoPull,MGPIO_enuPushPull},
    {MGPIO_PIN1,MGPIOA,MGPIO_enuOutput,MGPIO_enuLowSpeed,MGPIO_enuNoPull,MGPIO_enuPushPull}
};