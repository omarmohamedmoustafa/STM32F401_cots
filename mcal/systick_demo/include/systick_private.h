#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS 0xE000E010

typedef struct
{
    volatile u32 CTRL;  // Control and Status Register
    volatile u32 LOAD;  // Reload Value Register
    volatile u32 VAL;   // Current Value Register
    volatile u32 CALIB; // Calibration Value Register
} SysTick_Type;

#define SysTick ((SysTick_Type *)SYSTICK_BASE_ADDRESS)

// CTRL Register Bits
#define SYSTICK_CTRL_ENABLE (1 << 0)
#define SYSTICK_CTRL_TICKINT (1 << 1)
#define SYSTICK_CTRL_CLKSOURCE (1 << 2)
#define SYSTICK_CTRL_COUNTFLAG (1 << 16)

#endif // SYSTICK_PRIVATE_H