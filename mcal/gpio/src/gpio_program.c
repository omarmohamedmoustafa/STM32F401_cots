#include "stdtypes.h"
#include "bit_math.h"
#include "gpio_interface.h"
#include "gpio_private.h"
#include "gpio_config.h"
extern MGPIO_t MGPIO_ARR[USED_PINS*USED_PORTS];
MGPIO_enuErrorStatus_t GPIO_enumInit(void){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    for(u8 i = 0; i < USED_PINS*USED_PORTS; i++){
        if(MGPIO_ARR[i].Port > 5){
            Local_enuErrorStatus = MGPIO_enuPortError;
        }
        else if(MGPIO_ARR[i].Pin > 15){
            Local_enuErrorStatus = MGPIO_enuPinNumberError;
        }
        else{
            GPIO_enuSetPinDirection(MGPIO_ARR[i].Port, MGPIO_ARR[i].Pin, MGPIO_ARR[i].Direction);
            GPIO_enuSetPinOutputType(MGPIO_ARR[i].Port, MGPIO_ARR[i].Pin, MGPIO_ARR[i].OutputType);
            GPIO_enuSetPinSpeed(MGPIO_ARR[i].Port, MGPIO_ARR[i].Pin, MGPIO_ARR[i].Speed);
        }
    }
    return Local_enuErrorStatus;
}
MGPIO_enuErrorStatus_t GPIO_enuSetPinDirection (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuPinDirection_t Copy_enuDirection){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = MGPIO_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = MGPIO_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuDirection == MGPIO_enuInput){
                    CLR_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuOutput){
                    SET_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAF){
                    CLR_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAnalog){
                    SET_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 1:
                if(Copy_enuDirection == MGPIO_enuInput){
                    CLR_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuOutput){
                    SET_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAF){
                    CLR_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAnalog){
                    SET_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 2:
                if(Copy_enuDirection == MGPIO_enuInput){
                    CLR_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuOutput){
                    SET_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAF){
                    CLR_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAnalog){
                    SET_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 3:
                if(Copy_enuDirection == MGPIO_enuInput){
                    CLR_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuOutput){
                    SET_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAF){
                    CLR_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAnalog){
                    SET_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 4:
                if(Copy_enuDirection == MGPIO_enuInput){
                    CLR_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuOutput){
                    SET_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAF){
                    CLR_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAnalog){
                    SET_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 5:
                if(Copy_enuDirection == MGPIO_enuInput){
                    CLR_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuOutput){
                    SET_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    CLR_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAF){
                    CLR_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == MGPIO_enuAnalog){
                    SET_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;

        }


}
return Local_enuErrorStatus;
}

MGPIO_enuErrorStatus_t GPIO_enuSetPinValue (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, u8 Copy_u8Value){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = MGPIO_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = MGPIO_enuPinNumberError;
    }
    else if(Copy_u8Value > 1){
        Local_enuErrorStatus = MGPIO_enuPinValueError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_u8Value == 0){
                    CLR_BIT(GPIOA_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOA_ODR, Copy_u8Pin);
                }
                break;
            case 1:
                if(Copy_u8Value == 0){
                    CLR_BIT(GPIOB_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOB_ODR, Copy_u8Pin);
                }
                break;
            case 2:
                if(Copy_u8Value == 0){
                    CLR_BIT(GPIOC_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOC_ODR, Copy_u8Pin);
                }
                break;
            case 3:
                if(Copy_u8Value == 0){
                    CLR_BIT(GPIOD_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOD_ODR, Copy_u8Pin);
                }
                break;
            case 4:
                if(Copy_u8Value == 0){
                    CLR_BIT(GPIOE_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOE_ODR, Copy_u8Pin);
                }
                break;
            case 5:
                if(Copy_u8Value == 0){
                    CLR_BIT(GPIOH_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOH_ODR, Copy_u8Pin);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}

MGPIO_enuErrorStatus_t GPIO_enuGetPinValue (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, u8 *Copy_pu8Value){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = MGPIO_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = MGPIO_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                *Copy_pu8Value = GET_BIT(GPIOA_IDR, Copy_u8Pin);
                break;
            case 1:
                *Copy_pu8Value = GET_BIT(GPIOB_IDR, Copy_u8Pin);
                break;
            case 2:
                *Copy_pu8Value = GET_BIT(GPIOC_IDR, Copy_u8Pin);
                break;
            case 3:
                *Copy_pu8Value = GET_BIT(GPIOD_IDR, Copy_u8Pin);
                break;
            case 4:
                *Copy_pu8Value = GET_BIT(GPIOE_IDR, Copy_u8Pin);
                break;
            case 5:
                *Copy_pu8Value = GET_BIT(GPIOH_IDR, Copy_u8Pin);
                break;
        }
    }
    return Local_enuErrorStatus;
}

MGPIO_enuErrorStatus_t GPIO_enuSetPinSpeed (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuSpeed_t Copy_enuSpeed){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = MGPIO_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = MGPIO_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuSpeed == MGPIO_enuLowSpeed){
                    CLR_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuMediumSpeed){
                    SET_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuHighSpeed){
                    CLR_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuVeryHighSpeed){
                    SET_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 1:
                if(Copy_enuSpeed == MGPIO_enuLowSpeed){
                    CLR_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuMediumSpeed){
                    SET_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuHighSpeed){
                    CLR_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuVeryHighSpeed){
                    SET_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 2:
                if(Copy_enuSpeed == MGPIO_enuLowSpeed){
                    CLR_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuMediumSpeed){
                    SET_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuHighSpeed){
                    CLR_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuVeryHighSpeed){
                    SET_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 3:
                if(Copy_enuSpeed == MGPIO_enuLowSpeed){
                    CLR_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuMediumSpeed){
                    SET_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuHighSpeed){
                    CLR_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuVeryHighSpeed){
                    SET_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 4:
                if(Copy_enuSpeed == MGPIO_enuLowSpeed){
                    CLR_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuMediumSpeed){
                    SET_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuHighSpeed){
                    CLR_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuVeryHighSpeed){
                    SET_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 5:
                if(Copy_enuSpeed == MGPIO_enuLowSpeed){
                    CLR_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuMediumSpeed){
                    SET_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuHighSpeed){
                    CLR_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == MGPIO_enuVeryHighSpeed){
                    SET_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}

MGPIO_enuErrorStatus_t GPIO_enuSetPinPullType (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuInputType_t Copy_enuPullType){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = MGPIO_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = MGPIO_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuPullType == MGPIO_enuNoPull){
                    CLR_BIT(GPIOA_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOA_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullUp){
                    SET_BIT(GPIOA_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOA_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullDown){
                    CLR_BIT(GPIOA_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 1:
                if(Copy_enuPullType == MGPIO_enuNoPull){
                    CLR_BIT(GPIOB_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOB_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullUp){
                    SET_BIT(GPIOB_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOB_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullDown){
                    CLR_BIT(GPIOB_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 2:
                if(Copy_enuPullType == MGPIO_enuNoPull){
                    CLR_BIT(GPIOC_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOC_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullUp){
                    SET_BIT(GPIOC_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOC_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullDown){
                    CLR_BIT(GPIOC_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 3:
                if(Copy_enuPullType == MGPIO_enuNoPull){
                    CLR_BIT(GPIOD_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOD_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullUp){
                    SET_BIT(GPIOD_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOD_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullDown){
                    CLR_BIT(GPIOD_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 4:
                if(Copy_enuPullType == MGPIO_enuNoPull){
                    CLR_BIT(GPIOE_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOE_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullUp){
                    SET_BIT(GPIOE_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOE_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullDown){
                    CLR_BIT(GPIOE_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 5:
                if(Copy_enuPullType == MGPIO_enuNoPull){
                    CLR_BIT(GPIOH_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOH_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullUp){
                    SET_BIT(GPIOH_PUPDR, Copy_u8Pin * 2);
                    CLR_BIT(GPIOH_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == MGPIO_enuPullDown){
                    CLR_BIT(GPIOH_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}

MGPIO_enuErrorStatus_t GPIO_enuSetPinOutputType (MGPIO_enuPort_t Copy_u8Port, MGPIO_enuPin_t Copy_u8Pin, MGPIO_enuPinOutType_t Copy_enuOutputType){
    MGPIO_enuErrorStatus_t Local_enuErrorStatus = MGPIO_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = MGPIO_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = MGPIO_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuOutputType == MGPIO_enuPushPull){
                    CLR_BIT(GPIOA_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == MGPIO_enuOpenDrain){
                    SET_BIT(GPIOA_OTYPER, Copy_u8Pin);
                }
                break;
            case 1:
                if(Copy_enuOutputType == MGPIO_enuPushPull){
                    CLR_BIT(GPIOB_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == MGPIO_enuOpenDrain){
                    SET_BIT(GPIOB_OTYPER, Copy_u8Pin);
                }
                break;
            case 2:
                if(Copy_enuOutputType == MGPIO_enuPushPull){
                    CLR_BIT(GPIOC_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == MGPIO_enuOpenDrain){
                    SET_BIT(GPIOC_OTYPER, Copy_u8Pin);
                }
                break;
            case 3:
                if(Copy_enuOutputType == MGPIO_enuPushPull){
                    CLR_BIT(GPIOD_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == MGPIO_enuOpenDrain){
                    SET_BIT(GPIOD_OTYPER, Copy_u8Pin);
                }
                break;
            case 4:
                if(Copy_enuOutputType == MGPIO_enuPushPull){
                    CLR_BIT(GPIOE_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == MGPIO_enuOpenDrain){
                    SET_BIT(GPIOE_OTYPER, Copy_u8Pin);
                }
                break;
            case 5:
                if(Copy_enuOutputType == MGPIO_enuPushPull){
                    CLR_BIT(GPIOH_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == MGPIO_enuOpenDrain){
                    SET_BIT(GPIOH_OTYPER, Copy_u8Pin);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}
