#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


typedef enum{
    MGPIOA  ,
    MGPIOB  ,
    MGPIOC  ,
    MGPIOD  ,
    MGPIOE  ,
    MGPIOH
}MGPIO_enuPort_t;
typedef enum
{
    MGPIO_PIN0,
    MGPIO_PIN1,
    MGPIO_PIN2,
    MGPIO_PIN3,
    MGPIO_PIN4,
    MGPIO_PIN5,
    MGPIO_PIN6,
    MGPIO_PIN7,
    MGPIO_PIN8,
    MGPIO_PIN9,
    MGPIO_PIN10,
    MGPIO_PIN11,
    MGPIO_PIN12,
    MGPIO_PIN13,
    MGPIO_PIN14,
    MGPIO_PIN15
}MGPIO_enuPin_t;


typedef enum
{
    MGPIO_enuOK = 0,
    MGPIO_enuPortError,
    MGPIO_enuPinNumberError,
    MGPIO_enuPinValueError,
    MGPIO_enuPinDirectionError
}MGPIO_enuErrorStatus_t;

typedef enum
{
    MGPIO_enuInput = 0,
    MGPIO_enuOutput,
    MGPIO_enuAF,
    MGPIO_enuAnalog
}MGPIO_enuPinDirection_t;

typedef enum
{
    MGPIO_enuPushPull = 0,
    MGPIO_enuOpenDrain,
    MGPIO_enuNONE
}MGPIO_enuPinOutType_t;

typedef enum
{
    MGPIO_enuLowSpeed = 0,
    MGPIO_enuMediumSpeed,
    MGPIO_enuHighSpeed,
    MGPIO_enuVeryHighSpeed
}MGPIO_enuSpeed_t;

typedef enum
{
    MGPIO_enuNoPull = 0,
    MGPIO_enuPullUp,
    MGPIO_enuPullDown
}MGPIO_enuInputType_t;
typedef enum
{
    MGPIO_enuLow = 0,
    MGPIO_enuHigh
}MGPIO_enuValue_t;
typedef struct{
    MGPIO_enuPin_t Pin;
    MGPIO_enuPort_t Port;
    MGPIO_enuPinDirection_t Direction;
    MGPIO_enuSpeed_t Speed;
    MGPIO_enuInputType_t PullType;
    MGPIO_enuPinOutType_t OutputType;
}MGPIO_t;


MGPIO_enuErrorStatus_t GPIO_enumInit(void);
MGPIO_enuErrorStatus_t GPIO_enuSetPinDirection  (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuPinDirection_t Copy_enuDirection);
MGPIO_enuErrorStatus_t GPIO_enuSetPinValue      (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, u8 Copy_u8Value);
MGPIO_enuErrorStatus_t GPIO_enuGetPinValue      (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, u8 *Copy_pu8Value);
MGPIO_enuErrorStatus_t GPIO_enuSetPinSpeed      (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuSpeed_t Copy_enuSpeed);
MGPIO_enuErrorStatus_t GPIO_enuSetPinPullType   (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuInputType_t Copy_enuPullType);
MGPIO_enuErrorStatus_t GPIO_enuSetPinOutputType (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuPinOutType_t Copy_enuOutputType);
MGPIO_enuErrorStatus_t GPIO_enuTogglePinValue   (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin);
#endif    