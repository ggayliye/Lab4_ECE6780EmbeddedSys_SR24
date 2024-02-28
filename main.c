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
	
	//Start with a function declaration that accepts a single character-type variable and returns nothing.
		void fxnAcceptsSingleCharTypeAndReturnNothing(char c);
	
	
	//To transmit strings, begin with a function declaration that accepts 
	//an array of characters, either in direct array form or as a pointer.
	// This function should loop over each character in the array and 
	//call your character transmit function.
	
	//THIS FUNCTION IS CREATED ON TOP, ABOVE THE MAIN FXN
	
	void fxnAcceptsArrayOfCharsAndReturnNothing(char arr[] ){
		
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
	
	}
	//char	x[] = {'c','c'};
//fxnAcceptsArrayOfCharsAndReturnNothing(x);
	
	
	
	
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
	
	// Selected pins: PB10 (USART3_TX) and PB11 (USART3_RX)
	// Set the selected pins into alternate function mode:
			RCC->AHBENR |= 0x80000; //For B port (TX and RX), "Bit 18 IOPBEN: I/O port B clock enable 
		//Set and cleared by software. 0: I/O port B clock disabled 1: I/O port B clock enabled". 18th bit position. 
		// We know 19th bit from data sheet RM0091 on page 122.
		// PB10 is connected to USART3_TX. 
		// PB11 is connected to USART3_RX.

		//Enable PB10 and PB11 pins to "10: Alternate function mode."
		
		GPIOC->MODER &= 0xFF0FFFFF; //reset pins 10 through 11 (MODER11[1:0] MODER10[1:0]).
		GPIOC->MODER |= 0xA00000; //set PB10 and PB11 to "10: Alternate function mode"

		GPIOC->OTYPER &= 0x0; //no OR (|) . GPIO port output type register

		GPIOC->OSPEEDR &= 0x0; //GPIO port output speed register to Low speed

		GPIOC->PUPDR &= 0x0; //GPIO port pull-up/pull-down register
		
		
	 // Program the correct alternate function number into the GPIO AFR registers:
	 //First, find the Alternate functions from the data sheet in a table.
	 // They should come from AF0 to AF7. ( found as AF4)
	 // Determine if the PB10 and PB11 are in the AFRL (will be coded as AFR[0]) or AFRH (will be coded as AFR[1]).
	 // PB10 and PB11 are in the AFRH becuase they are over "7" or over AFSEL7[3:0].
	 // They will be in the AFSEL11[3:0] and AFSEL10[3:0].
	
  	GPIOC->AFR[1] &= 0xFFFF00FF; //set them to "0" first. Then :"0100: AF4" for AFSEL11[3:0] and AFSEL10[3:0]. 
		GPIOC->AFR[1] |= 0x4400;
				
		// 1. Enable the system clock to the desired USART in the RCC peripheral.
		//
		RCC->APB1ENR |= 0x40000;  //Bit 18 USART3EN: USART3 clock enable. "1: USART3 clock enabled"
		
		//2. Set the Baud rate for communication to be 115200 bits/second.
		  //You may use the HAL_RCC_GetHCLKFreq() function to get the system clock frequency.
			// 8 bits = 1 byte; 115200 bits/second = 14,400 Byte//second = 14.4 kB/sec.
		
		//Bits 15:4 BRR[15:4] ; BRR[15:4] = USARTDIV[15:4]
		// USART_BRR
		
		USART3->BRR = HAL_RCC_GetHCLKFreq()/115200;
		
		
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
		 USART3->TDR='c';
		
		//3. There is no need to manually clear the status bit, it will be automatically modified by the
    //peripheral when you write into the transmit register.
		 
		 
		 
		char testArr[]={'h','o','w',' ','a','r','e',' ','y','o','u','?'};
		
		
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	// The character transmission will be handled in the main loop of the application using a blocking method.
	
		
		fxnAcceptsSingleCharTypeAndReturnNothing('a');
		
		HAL_Delay(400);
		
		//Once your string transmit function is complete, change your 
		//main application to transmit a short phrase instead of a 
		//single character. If you see large amounts of garbage 
		//printed in the terminal instead of your phrase, you 
		//probably have run off the end of your character 
		//array and are displaying the contents of the 
		//rest of the STM32F0’s memory.
		
		fxnAcceptsArrayOfCharsAndReturnNothing(testArr);
		
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
	
	
	//To transmit strings, begin with a function declaration that accepts 
	//an array of characters, either in direct array form or as a pointer.
	// This function should loop over each character in the array and 
	//call your character transmit function.
	
	//THIS FUNCTION IS CREATED ON TOP, ABOVE THE MAIN FXN

		
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
