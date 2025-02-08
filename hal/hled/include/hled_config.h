#ifndef H_LED_CONFIG_H
#define H_LED_CONFIG_H

#include "gpio_interface.h"

#define HLED_LED_COUNT 8

#define HLED_u8Led0 0
#define HLED_u8Led0Port MGPIOA
#define HLED_u8Led0Pin MGPIO_PIN0

#define HLED_u8Led1 1
#define HLED_u8Led1Port MGPIOA
#define HLED_u8Led1Pin MGPIO_PIN1

#define HLED_u8Led2 2
#define HLED_u8Led2Port MGPIOA
#define HLED_u8Led2Pin MGPIO_PIN2

#define HLED_u8Led3 3
#define HLED_u8Led3Port MGPIOA
#define HLED_u8Led3Pin MGPIO_PIN3

#define HLED_u8Led4 4
#define HLED_u8Led4Port MGPIOA
#define HLED_u8Led4Pin MGPIO_PIN4

#define HLED_u8Led5 5
#define HLED_u8Led5Port MGPIOA
#define HLED_u8Led5Pin MGPIO_PIN5

#define HLED_u8Led6 6
#define HLED_u8Led6Port MGPIOA
#define HLED_u8Led6Pin MGPIO_PIN6

#define HLED_u8Led7 7
#define HLED_u8Led7Port MGPIOA
#define HLED_u8Led7Pin MGPIO_PIN7


typedef struct
{
    MGPIO_enuPin_t Pin;
    MGPIO_enuPort_t Port;
    MGPIO_enuPinDirection_t Direction;
    MGPIO_enuSpeed_t Speed;
    MGPIO_enuInputType_t PullType;
    MGPIO_enuPinOutType_t OutputType;
}HLED_t;











#endif // H_LED_CONFIG_H