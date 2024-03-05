/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include "stdbool.h"
#include "stm32f0xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "tz_context.h"                 // CMSIS:CORE


volatile bool letterEntered=false;

volatile char readVal;
volatile int count=0;

char testArr[]={'h','o','w',' ','a','r','e',' ','y','o','u','?',' '};
 
 char redIsOn[]={'R','e','d',' ','L','E','D',' ','i','s',' ','O','N','\n',
 '-','-','-','-','-','-','-','-','-','-','-','\n'};
 char blueIsOn[]={'B','l','u','e',' ','L','E','D',' ','i','s',' ','O','N','\n',
 '*','*','*','*','*','*','*','*','*','*','*','\n'};
 char orangeIsOn[]={'O','r','a','n','g','e',' ','L','E','D',' ','i','s',' ','O','N','\n',
 '+','+','+','+','+','+','+','+','+','+','+','\n'};
 char greenIsOn[]={'G','r','e','e','n',' ','L','E','D',' ','i','s',' ','O','N','\n',
 '=','=','=','=','=','=','=','=','=','=','=','\n'};
 char errorMessageWrongButton[]={'I','n','c','o','r','r','e','c','t',' ',
 'b','u','t','t','o','n',' ','i','s',' ','c','l','i','c','k','e','d','\n',
	 'c','l','i','c','k',':','\n', '"','r','"',' ','f','o','r',' ','R','e','d','\n',
	 '"','b','"',' ','f','o','r',' ','B','l','u','e','\n',
  '"','o','"',' ','f','o','r',' ','O','r','a','n','g','e','\n',
  '"','g','"',' ','f','o','r',' ','G','r','e','e','n','\n',
 '%','%','%','%','%','%','%','%','%','%','%','\n'};
 //'W','A','R','N','I','N','G','!','\n',
		// PC6 is connected to RED LED. 
		// PC7 is connected to BLUE LED.
		// PC8 is connected to ORANGE LED.
		// PC9 is connected to GREEN LED.
	

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
	
	//Helper Function: USART3 Interrupt Handler
	//reset/make them off pins 6 through 9 LEDs (GPIOC->ODR & 0xFFFFFC3F)
	 void USART3_4_IRQHandler(){
	 
	 //letterLED='c';
	 letterEntered=true;
	 readVal=USART3->RDR;
	 
 };
	
 
	
	//Start with a function declaration that accepts a single character-type variable and returns nothing.
		void fxnAcceptsSingleCharTypeAndReturnNothing(char c){
			
			//"There are a number of choices to be made when writing code that interfaces with a 
			//communication peripheral. Typically you will be sending more data than will fit in 
			//a single transmission frame and you will need to wait while the interface alternates
			//between transmitting and requesting more data. A simple implementation of such a 
			//driver could simply poll the condition flags within the USART peripheral until the 
			//device becomes ready to continue. This style of driver is called blocking, because 
			//it stops the progression of the application thread until the transmission has completed. 
			//Depending on the timing of the main application, this may not be a problem. However, 
			//a blocking driver cannot be used in an interrupt because of the delays it causes.
			
			//Within this function implement the following:
			//1. Check and wait on the USART status flag that indicates the transmit register is empty
				// You can use an empty while loop which exits once the flag is set. 
				// Don’t use the USART “BUSY” status bit. 
				//Although this will appear to work properly, this bit depends on multiple 
				// conditions and will slow down your transmission.
				
				//USART interrupt and status register (USART_ISR)
				//Bit 7 TXE: Transmit data register empty
				// Using "OR" will copy down and comparing with 7th bit set to 0 has to be equal:
		while( (USART3->ISR  | 0x0)==(USART3->ISR  & 0xFFFFFF7F)){ //wait until it's set.
			 
		 }
		
		//2. Write the character into the transmit data register.
		   // printf("%c", 'c'); 
		 // Bits 8:0 TDR[8:0]: Transmit data value
		 //USART3->TDR='c';


		USART3->TDR=c;
	
		//3. There is no need to manually clear the status bit, it will be automatically modified by the
    //peripheral when you write into the transmit register.
			
			
		}
	
	//To transmit strings, begin with a function declaration that accepts 
	//an array of characters, either in direct array form or as a pointer.
	// This function should loop over each character in the array and 
	//call your character transmit function.
	
	void fxnAcceptsArrayOfCharsAndReturnNothing(char arr[] ){
	//	count=0;
		//1. Loop over each element in the character array
		//2. If the current element is not the null character use your character transmit function.
		//You can increment over the array by using a counter and array index or by incrementing the pointer. 
		//You can test for the null character by comparing the value against ‘\0’ or the numerical value 0. 
		//(remember characters are numbers in C) • If you use the pointer method, remember to dereference 
		//when testing for the null value and when calling the character transmit function. 
		//3. Return when the null character is encountered.
		
		int i;
		for(i=0; arr[i] !='\0'; i++){
			
			fxnAcceptsSingleCharTypeAndReturnNothing(arr[i]);
			
		}
	//	count++;
	//	USART3->RQR |=0x8; // RXFRQ flush
	//	readVal='\0';
	
	}

	// 4.9.4 Blocking Reception Exersice
	//1. Check and wait on the USART status flag that indicates the receive 
	//(read) register is not empty. [this part will be done in the 
	//functrion,fxnAcceptsSingleCharTypeAndReturnNothing, on top]
  //	You can use an empty while loop which exits once the flag is 
	//set or simply check each iteration of the main infinite loop. 
  //It may be helpful to carefully read the bit descriptions in the register map.
	
	//Helper function to toggle LED
	void toggleLEDWithTheFirstLetterOfTheColor(char c){
			
		// PC6 is connected to RED LED. 
		// PC7 is connected to BLUE LED.
		// PC8 is connected to ORANGE LED.
		// PC9 is connected to GREEN LED.
//if(c=='r'){
//	fxnAcceptsArrayOfCharsAndReturnNothing(redIsOn);
//}
// else{
//	fxnAcceptsArrayOfCharsAndReturnNothing(errorMessageWrongButton);
//	}
  // printf("red");
			//2. Write the character into the transmit data register.
		   // printf("%c", 'c'); 
		 // Bits 8:0 TDR[8:0]: Transmit data value
		 	// USART3->TDR='1';	
		//  printf(%d, "orange");
		//    printf("Error! Type:\n \"r\" or \"R\" for RED LED,\n\"b\" or \"B\" for BLUE LED,\n\"o\" or \"O\" for ORANGE LED,\n\"g\" or \"G\" for Green LED,\n");
//while(letterEntered){}
//switch (c) {
//case ('r'):
//fxnAcceptsArrayOfCharsAndReturnNothing(redIsOn);break;letterEntered=false;	
//case ('b'):
//fxnAcceptsArrayOfCharsAndReturnNothing(blueIsOn);break;	letterEntered=false;
//case ('o'):
//fxnAcceptsArrayOfCharsAndReturnNothing(orangeIsOn);break;letterEntered=false;
//case ('g'):
//fxnAcceptsArrayOfCharsAndReturnNothing(greenIsOn);break;letterEntered=false;
//default:
//fxnAcceptsArrayOfCharsAndReturnNothing(errorMessageWrongButton); 
//}
//GPIOC->BSRR |= 0x
if(c=='r'){
	GPIOC->ODR = (0x40 |(GPIOC->ODR & 0xFFFFFC3F));	
	fxnAcceptsArrayOfCharsAndReturnNothing(redIsOn);

}
else if(c=='b'){
	GPIOC->ODR = (0x80 |(GPIOC->ODR & 0xFFFFFC3F));	
	// GPIOC->ODR |= 0x80; //blue is on, PC7
	fxnAcceptsArrayOfCharsAndReturnNothing(blueIsOn);
}

else if(c=='o'){
	GPIOC->ODR = (0x100 |(GPIOC->ODR & 0xFFFFFC3F));	
	//GPIOC->ODR |= 0x100; //orange ON
	fxnAcceptsArrayOfCharsAndReturnNothing(orangeIsOn);
}
else if(c=='g'){
	GPIOC->ODR = (0x200 |(GPIOC->ODR & 0xFFFFFC3F));	
	//GPIOC->ODR &= 0x2FF; //Green On
	fxnAcceptsArrayOfCharsAndReturnNothing(greenIsOn);
}
else{
	GPIOC->ODR = (GPIOC->ODR & 0xFFFFFC3F);	
	fxnAcceptsArrayOfCharsAndReturnNothing(errorMessageWrongButton); 
}
//		if( (c !='r' | c !='R') | (c !='b' | c !='B') |(c !='o' | c !='O') | (c !='g' | c !='G') ){
//	//	printf();
//		
//	}
		
//The RXNE flag can also be cleared by writing 1 to the RXFRQ
//in the USART_RQR register. The RXNE bit must be cleared before the end of the
//reception of the next character to avoid an overrun error.

//USART request register (USART_RQR)
//Bit 3 RXFRQ: Receive data flush request
//Writing 1 to this bit clears the RXNE flag.
//This allows to discard the received data without reading it, and avoid an overrun condition.

//Bit 4 TXFRQ: Transmit data flush request
//Writing 1 to this bit sets the TXE flag.
//This allows to discard the transmit data. This bit must be used only in Smartcard mode,
//when data has not been sent due to errors (NACK) and the FE flag is active in the
//USART_ISR register.
//If the USART does not support Smartcard mode, this bit is reserved and must be kept at
//reset value.
//		readVal='\0';

//USART3->RQR |=0x8; // RXFRQ flush



	}
	
	
	
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */
	
	// Selected pins: PB10 transmitter (USART3_TX) and PB11 receiver (USART3_RX)
	// Peripheral clock enable register:
	RCC->AHBENR |= 0x40000; //For B port (TX and RX), "Bit 18 IOPBEN: I/O port B clock enable 
	 //Binary:00000000000001000000000000000000
		//Set and cleared by software. 0: I/O port B clock disabled 1: I/O port B clock enabled". 18th bit position. 
		// We know 18th bit from data sheet RM0091 on page 122.
		// PB10 is connected to USART3_TX. 
		// PB11 is connected to USART3_RX.
		
		
	// Set the selected pins(PB10&PB11) into alternate function mode:
	//Enable PB10 and PB11 pins to "10: Alternate function mode."
		
		GPIOB->MODER &= 0xFF0FFFFF; //reset pins(make them zero first) 10 through 11 (MODER11[1:0] MODER10[1:0]).
		//Binary: 11111111000011111111111111111111
		GPIOB->MODER |= 0xA00000; //set PB10 and PB11 to "10: Alternate function mode"
		//Binary: 00000000101000000000000000000000

		GPIOB->OTYPER &= 0x0; //no OR (|) . GPIO port output type register

		GPIOB->OSPEEDR &= 0x0; //GPIO port output speed register to Low speed

		GPIOB->PUPDR &= 0x0; //GPIO port pull-up/pull-down register
		
		
	 // Program the correct alternate function number into the GPIO AFR registers:
	 //First, find the Alternate functions from the data sheet in a table.
	 // PDF "STM32F072x8 STM32F072xB", page 45.
	 // They should come from AF0 to AF7. ( found as AF4)
	 // AF4 should be coded as :0100 (as binary)
	 // Determine if the PB10 and PB11 are in the AFRL (will be coded as AFR[0]) or AFRH (will be coded as AFR[1]).
	 // PB10 and PB11 are in the AFRH becuase they are over "7" or over AFSEL7[3:0].
	 // They will be in the AFSEL11[3:0] and AFSEL10[3:0].
	
  	GPIOB->AFR[1] &= 0xFFFF00FF; //set them to "0" first. Then :"0100: AF4" for AFSEL11[3:0] and AFSEL10[3:0]. 
		//Binary value: 11111111111111110000000011111111
		GPIOB->AFR[1] |= 0x4400; // now set them :0100. Binary val: 00000000000000000100010000000000
				
		// 1. Enable the system clock to the desired USART in the RCC peripheral.
		//
		RCC->APB1ENR |= 0x40000;  //Bit 18 USART3EN: USART3 clock enable. "1: USART3 clock enabled"
		
		//2. Set the Baud rate for communication to be 115200 bits/second.
		  //You may use the HAL_RCC_GetHCLKFreq() function to get the system clock frequency.
			// 8 bits = 1 byte; 115200 bits/second = 14,400 Byte//second = 14.4 kB/sec.
		
		//Bits 15:4 BRR[15:4] ; BRR[15:4] = USARTDIV[15:4]
		// USART_BRR
		
		USART3->BRR = HAL_RCC_GetHCLKFreq()/115200;
		//USART3->BRR = 8000000/115200;
		//USART3->BRR = 833;
		
		//3. The USART starts with portions of the peripheral disabled for low-power use. 
		//You will need to enable the transmitter and receiver hardware. //page 744
		
		//Bit 3 TE: Transmitter enable. "1: Transmitter is enabled".
		//Bit 2 RE: Receiver enable. "1: Receiver is enabled and begins searching for a start bit"
		
		USART3->CR1 |=0xC; // TX & RX enabled
		
				
		// 4. The USART has a peripheral enable/disable bit in its control register. 
		//Once the USART is enabled, many of the configuration bits become read-only.
		
		//Bit 0 UE: USART enable
		// When this bit is cleared, the USART prescalers and outputs are stopped immediately, 
		//and current operations are discarded. The configuration of the USART is kept, 
		//but all the status flags, in the USART_ISR are set to their default values. 
		//This bit is set and cleared by software.
		//1: USART enabled
		
		//Note: In order to go into low-power mode without generating errors on the line, 
		//the TE bit must be reset before and the software must wait for the TC bit in 
		//the USART_ISR to be set before resetting the UE bit. The DMA requests are 
		//also reset when UE = 0 so the DMA channel must be disabled before resetting the UE bit.
		
		USART3->CR1 |=0x1; //Bit 0 UE: USART enable
		
		//Transmitting a Character:
		
		//Start with a function declaration that accepts a single character-type variable and returns nothing.
		//THIS FUNCTION IS CREATED ON TOP, ABOVE THE MAIN FXN//THIS FUNCTION IS CREATED ON TOP, ABOVE THE MAIN FXN



		 
	//To transmit strings, begin with a function declaration that accepts 
	//an array of characters, either in direct array form or as a pointer.
	// This function should loop over each character in the array and 
	//call your character transmit function.
	//THIS FUNCTION IS CREATED ON TOP, ABOVE THE MAIN FXN
		 

	/* USER CODE END 2 */
	
	//4.9.4 Blocking Reception
	//For this task, there is a helper function,toggleLEDWithTheFirstLetterOfTheColor, on top
	
			//Enable ALL LEDs for "General purpose output mode, "01" as bits"
		RCC->AHBENR |= 0x80000; //For C port (LED ports), "Bit 19 IOPCEN: I/O port C clock enable". 19th bit position. 
		// We know 19th bit from data sheet RM0091 on page 122.
		// PC6 is connected to RED LED. 
		// PC7 is connected to BLUE LED.
		// PC8 is connected to ORANGE LED.
		// PC9 is connected to GREEN LED.
	
		GPIOC->MODER &= 0xFFF00FFF; //reset all LED pins, 6 through 9.
		GPIOC->MODER |= 0x55000; //set all LEDs, PC6 through PC9 to "01:General purpose output mode"

		GPIOC->OTYPER &= 0x0; //no OR (|) . GPIO port output type register

		GPIOC->OSPEEDR &= 0x0; //GPIO port output speed register to Low speed

		GPIOC->PUPDR &= 0x0; //GPIO port pull-up/pull-down register
	
	// GPIOC->ODR = (0x40 |(GPIOC->ODR & 0xFFFFFC3F));	
	
		//Bit 5 RXNEIE: RXNE interrupt enable
		//This bit is set and cleared by software.
		//0: Interrupt is inhibited
		//1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_ISR
		//register
	
			USART3->CR1 |=0x20; //Bit 5 RXNEIE: RXNE interrupt enable
			//Binary: 00000000000000000000000000100000
			// find USART3 handler from file : startup_stm32f072xb.s
			
            NVIC_EnableIRQ(USART3_4_IRQn); //
            NVIC_SetPriority(USART3_4_IRQn,1); // set priority
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */
	// The character transmission will be handled in the main loop of the application using a blocking method.

	
	//	fxnAcceptsSingleCharTypeAndReturnNothing('a');
		
//	HAL_Delay(10);
		
		//Once your string transmit function is complete, change your 
		//main application to transmit a short phrase instead of a 
		//single character. If you see large amounts of garbage 
		//printed in the terminal instead of your phrase, you 
		//probably have run off the end of your character 
		//array and are displaying the contents of the 
		//rest of the STM32F0’s memory.
		
		
	//	fxnAcceptsArrayOfCharsAndReturnNothing(testArr);
	
		
		//Goal is to develop an application that toggles the correct 
		//LED whenever the character matching the first letter of the color is pressed
		
				//USART receive data register (USART_RDR)
	     //Bits 8:0 RDR[8:0]: Receive data value
			//PDF name:RM0091. Page 764.
	   // USART3->RDR;
// while(letterEntered==false){
// }

	//if(letterEntered==true){}
		
//	char	letterLED=USART3->RDR;

			 //1. Check and wait on the USART status flag that indicates the 
		//receive (read) register is not empty.		
				//USART interrupt and status register (USART_ISR)
				//Bit 5 RXNE: Read data register not empty
//This bit is set by hardware when the content of the RDR shift register has been transferred
//to the USART_RDR register. It is cleared by a read to the USART_RDR register. The RXNE
//flag can also be cleared by writing 1 to the RXFRQ in the USART_RQR register.
//An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
//0: data is not received
//1: Received data is ready to be read.
				// Using "OR" will copy down "set" values 
		//and comparing with the 5th bit set to 0 has to be equal:
	//	count=0;
		//HAL_Delay(10);
		readVal='\0';
    USART3->RQR |=0x8; // RXFRQ flush
		while( (USART3->ISR  & 0xFFFFFFFF)==(USART3->ISR | 0x0)){ //wait until it's set.(Bit 5 RXNE: Read data register not empty)
			 
		 }
		
	
	
	//		while(count==0){ 
	if(letterEntered){
	letterEntered=false;
  	//USART3->CR1 &=0xFFFFFFFB;
		toggleLEDWithTheFirstLetterOfTheColor(readVal);
		
		
	//	readVal='\0';
	}	 

		 
//	  readVal='\0';
//		USART3->RQR |=0x8; // RXFRQ flush
		 
		//	}
//		letterEntered=false;
		
    /* USER CODE BEGIN 3 */
		
			//115200 Baurd rate
  }
	
	
	
  /* USER CODE END 3 */
	



		
	};
	
			

	



	
	
	
	
	






/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
