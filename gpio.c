#include "gpio.h"


void GPIO_Clock_Enable(uint32_t *GPIOx)
{
  //An assertion is used to test the state of a variable or a memory area
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx  == GPIOC || GPIOx == GPIOD ); 
  //if the value stored there is inconsistent with what you expect, then your program will be terminated 
  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
 
  if ( GPIOx ==GPIOA )
    *RCCAHB1 |= (1<<0);
  else if ( GPIOx ==GPIOB )
    *RCCAHB1 |= (1<<1);
  else if ( GPIOx ==GPIOC )
    *RCCAHB1 |= (1<<2);
    else   if ( GPIOx ==GPIOD )
    *RCCAHB1 |= (1<<3);
 
}
void GPIO_Config (uint32_t *GPIOx, uint8_t Pin,  uint8_t Mode, uint8_t Type)
{ 
  assert(Pin == PIN0 || Pin == PIN1 || Pin == PIN2 || Pin == PIN3 || Pin == PIN4|| Pin == PIN5|| Pin == PIN6|| Pin == PIN7|| Pin == PIN8|| Pin == PIN9|| Pin == PIN10|| Pin == PIN11|| Pin == PIN12|| Pin == PIN13|| Pin == PIN14|| Pin == PIN15 );
  assert(Mode == INPUT || Mode == OUTPUT || Mode == ANALOG_INPUT || Mode == ALTERNATE);
  assert(Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN);
  
  uint32_t GPIOx_MODER = (uint8_t)(0X40020000);
 
  if (GPIOx_MODER == 00) 
{ 
  Mode = INPUT;
}
  if (GPIOx_MODER == 01)
{  
  Mode = OUTPUT;
}
  if (GPIOx_MODER == 10) 
{
  Mode = ALTERNATE;
}
  if (GPIOx_MODER == 11)
{   
  Mode = ANALOG_INPUT;    
}

  uint32_t GPIOx_TYPER = (uint32_t)(0X40020c00);
  
  if (GPIOx_TYPER== 0) 
{
  Type = OUTPUT_PUSH_PULL;
}
  if (GPIOx_TYPER == 1)
{
  Type = OUTPUT_OPEN_DRAIN;
  
}
}