/*
**************************************************************************************************
**
** @file            : STM32F401xCTx_Startup.ld
**
** @auther          : Muhammed Ali Ibrahim Ahmed
**
** @linkedIn        : https://www.linkedin.com/in/muhammedalii9/
**
** @breif           : Start Up Code for STM43F401xC Microcontroller From STM32F4 Series
**
** @Target          :  STM32F4 Microcontrollers
**
**************************************************************************************************
*/

/* --------------------------------- Includes Section Start --------------------------------- */
#include "Platform_Types.h"
/* --------------------------------- Includes Section End ----------------------------------- */

#define NULL    0

extern void main(void);
extern uint32 _stext, _etext, _srodata, _erodata, _sdata, _edata, _sidata, _sbss, _ebss, _estack;
/**
 * [Description] : Initialize Main Stack Pointer
 */
uint32 *const _MSP = (uint32 *)&_estack;

void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMonitor_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Systick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IM1_CC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_RV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_Handler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SDIO_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void) __attribute__((weak, alias("Default_Handler")));
void FPU_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI4_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32 *Vector_Table[] __attribute__((section(".isr_vector"))) = {
    (uint32 *)_MSP,               /* Main Stack Pointer */
    (uint32 *)Reset_Handler,      /* Reset */
    (uint32 *)NMI_Handler,        /* Non maskable interrupt, Clock Security System*/
    (uint32 *)HardFault_Handler,  /* All class of fault */
    (uint32 *)MemManage_Handler,  /* Memory management */
    (uint32 *)BusFault_Handler,   /* Pre-fetch fault, memory access fault */
    (uint32 *)UsageFault_Handler, /* Undefined instruction or illegal state */
    0,
    0,
    0,
    0,
    (uint32 *)SVCall_Handler,       /* System Service call via SWI instruction */
    (uint32 *)DebugMonitor_Handler, /* Debug Monitor */
    0,
    (uint32 *)PendSV_Handler,             /* Pendable request for system service */
    (uint32 *)Systick_Handler,            /* System tick timer */
    (uint32 *)WWDG_Handler,               /* Window Watchdog interrupt */
    (uint32 *)PVD_Handler,                /* PVD through EXTI line detection interrupt */
    (uint32 *)TAMP_STAMP_Handler,         /* Tamper and TimeStamp interrupts through the EXTI line*/
    (uint32 *)RTC_WKUP_Handler,           /* RTC Wakeup interrupt through the EXTI line */
    (uint32 *)FLASH_Handler,              /* Flash global interrupt */
    (uint32 *)RCC_Handler,                /* RCC global interrupt */
    (uint32 *)EXTI0_Handler,              /* EXTI Line0 interrupt */
    (uint32 *)EXTI1_Handler,              /* EXTI Line1 interrupt */
    (uint32 *)EXTI2_Handler,              /* EXTI Line2 interrupt */
    (uint32 *)EXTI3_Handler,              /* EXTI Line3 interrupt */
    (uint32 *)EXTI4_Handler,              /* EXTI Line4 interrupt */
    (uint32 *)DMA1_Stream0_Handler,       /* DMA1 Stream0 global interrupt */
    (uint32 *)DMA1_Stream1_Handler,       /* DMA1 Stream1 global interrupt */
    (uint32 *)DMA1_Stream2_Handler,       /* DMA1 Stream2 global interrupt */
    (uint32 *)DMA1_Stream3_Handler,       /* DMA1 Stream3 global interrupt */
    (uint32 *)DMA1_Stream4_Handler,       /* DMA1 Stream4 global interrupt */
    (uint32 *)DMA1_Stream5_Handler,       /* DMA1 Stream5 global interrupt */
    (uint32 *)DMA1_Stream6_Handler,       /* DMA1 Stream6 global interrupt */
    (uint32 *)ADC_Handler,                /* ADC1 global interrupts */
    (uint32 *)EXTI9_5_Handler,            /* EXTI Line[9:5] interrupts */
    (uint32 *)TIM1_BRK_TIM9_Handler,      /* TIM1 Break interrupt and TIM9 global interrupt */
    (uint32 *)TIM1_UP_TIM10_Handler,      /* TIM1 Update interrupt and TIM10 global interrupt */
    (uint32 *)TIM1_TRG_COM_TIM11_Handler, /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    (uint32 *)IM1_CC_Handler,             /* TIM1 Capture Compare interrupt */
    (uint32 *)TIM2_Handler,               /* TIM2 global interrupt */
    (uint32 *)TIM3_Handler,               /* TIM3 global interrupt */
    (uint32 *)TIM4_Handler,               /* TIM4 global interrupt */
    (uint32 *)I2C1_EV_Handler,            /* I2C1 event interrupt */
    (uint32 *)I2C1_ER_Handler,            /* I2C1 error interrupt */
    (uint32 *)I2C2_EV_Handler,            /* I2C2 event interrupt */
    (uint32 *)I2C1_RV_Handler,            /* I2C2 error interrupt */
    (uint32 *)SPI1_Handler,               /* SPI1 global interrupt */
    (uint32 *)SPI2_Handler,               /* SPI2 global interrupt */
    (uint32 *)USART1_Handler,             /* USART1 global interrupt */
    (uint32 *)USART2_Handler,             /* USART2 global interrupt */
    (uint32 *)EXTI15_10_Handler,          /* EXTI Line[15:10] interrupts */
    (uint32 *)RTC_Alarm_Handler,          /* RTC Alarms (A and B) through EXTI line interrupt */
    (uint32 *)OTG_FS_WKUP_Handler,        /* USB On-The-Go FS Wakeup through EXTI line interrupt */
    (uint32 *)DMA1_Stream7_Handler,       /* DMA1 Stream7 global interrupt */
    (uint32 *)SDIO_Handler,               /* SDIO global interrupt */
    (uint32 *)TIM5_Handler,               /* TIM5 global interrupt */
    (uint32 *)SPI3_Handler,               /* SPI3 global interrupt */
    (uint32 *)DMA2_Stream0_Handler,       /* DMA2 Stream0 global interrupt */
    (uint32 *)DMA2_Stream1_Handler,       /* DMA2 Stream1 global interrupt */
    (uint32 *)DMA2_Stream2_Handler,       /* DMA2 Stream2 global interrupt */
    (uint32 *)DMA2_Stream3_Handler,       /* DMA2 Stream3 global interrupt */
    (uint32 *)DMA2_Stream4_Handler,       /* DMA2 Stream4 global interrupt */
    (uint32 *)OTG_FS_Handler,             /* USB On The Go FS global interrupt */
    (uint32 *)DMA2_Stream5_Handler,       /* DMA2 Stream5 global interrupt */
    (uint32 *)DMA2_Stream6_Handler,       /* DMA2 Stream6 global interrupt */
    (uint32 *)DMA2_Stream7_Handler,       /* DMA2 Stream7 global interrupt */
    (uint32 *)USART6_Handler,             /* USART6 global interrupt */
    (uint32 *)I2C3_EV_Handler,            /* I2C3 event interrupt */
    (uint32 *)I2C3_ER_Handler,            /* I2C3 error interrup */
    (uint32 *)FPU_Handler,                /* FPU global interrupt */
    (uint32 *)SPI4_Handler                /* SPI 4 global interrupt */
};

void Reset_Handler(void)
{
    uint32 SEC_SIZE = 0;   // Section Size
    uint32 *SRCADD = NULL; // Point to Source Address
    uint32 *DESADD = NULL; // Point to Destination Address
    /* ___________________ Initialize .data Section in RAM ___________________ */
    SEC_SIZE = (uint32 *)&_edata - (uint32 *)&_sdata; // Calcuate Size of Data
    SRCADD = (uint32 *)&_sidata;                      // @brief : Start Address of .data section in FLASH (LMA)
    DESADD = (uint32 *)&_sdata;                       // @brief : Start Address of .data section in RAM   (VMA)
    // @brief : Copy Data From Source Address ( FLash ) to Destination Address ( RAM )
    for (uint32 Counter = 0; Counter < SEC_SIZE; Counter++)
    {
        *DESADD++ = *SRCADD++;
    }
    /* ___________________ Initialzie bss Section ___________________ */
    SEC_SIZE = (uint32 *)&_ebss - (uint32 *)&_sbss; // Calculate Size of bss Section
    DESADD = (uint32 *)&_sbss;                      // @brief : Start Address of bss section in RAM
    for (uint32 Counter = 0; Counter < SEC_SIZE; Counter++)
    {
        *DESADD++ = 0; // Initialize bss section by zero
    }
    /* Call Main Function */
    main();
}

void Default_Handler(void)
{
    /* Nothing */
}