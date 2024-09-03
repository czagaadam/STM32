/*
 * main.c
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *	main.c for LaserTest
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "gpio.h"
#include "Inc/vl53l0x.h"
#include "Inc/vl53l0x/vl53l0x_platform.h" //typedef VL53L0X_Dev_t
#include "Inc/vl53l0x/vl53l0x_api.h"
#include "Inc/vl53l0xHandlerClass.h"

void SystemClock_Config(void);

uint16_t sensor1_mm = 0;
uint16_t sensor2_mm = 0;

const uint8_t numofsensors = 1;

int main(void)
{
  //GPIOD->BSRR = (uint32_t)GPIO_PIN_15 << 16U;
  GPIOD->BSRR = (uint32_t)GPIO_PIN_14 << 16U;
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_I2C3_Init();
  //HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
  //memory allocation for VL53L0X_Dev_t structures and gpio pins
  VL53L0X_InitHandlerClass(numofsensors);
  //initialize VL53L0X_Dev_t structure, shutdown pin, comm type, speed, address
  //todo: return index number
  //VL53L0X_DefineAndPutDevice(GPIO_PIN_15, 1, 100, 0x60);
  HAL_Delay(500);
  VL53L0X_APPSConfigDevice(&hi2c3, GPIOD, GPIO_PIN_14, 1, 100, 0x22);
  HAL_Delay(500);
  //shutdown pins low state
  VL53L0X_APPSResetNodes();
  HAL_Delay(500);
  //set new address for 1st sensor
  //VL53L0X_ActiveNodeAddress(1);
  HAL_Delay(500);
  //initialize sensor with custom address
  //VL53L0X_APPStartCustomAddress(1);
  HAL_Delay(500);
  //set new address for 2nd sensor
  VL53L0X_APPSSetAddress(0);
  HAL_Delay(500);
  //initialize sensor with custom address
  VL53L0X_APPStartWithCustomAddress(0);
  HAL_Delay(500);
  while (1)
  {
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_9,GPIO_PIN_SET);
	  HAL_Delay(sensor1_mm);
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_9,GPIO_PIN_RESET);
	  HAL_Delay(sensor1_mm);
	  //sensor1_mm = VL53L0X_NodeMeasure(1);
	  //HAL_Delay(500);
	  sensor1_mm = VL53L0X_APPSNodeMeasure(0);
  }
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
