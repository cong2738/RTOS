/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Button.h"
#include "LedBar.h"
#include "my_queue.h"
#include <LCD.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
enum{BTN_LED1, BTN_LED2, BTN_LED3};
typedef struct{
	int id;
}btn_led_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

osMailQId btnMail;
osMailQDef(btnMail, 4, btn_led_t);

Button_Handler_t hBtnLed1;
Button_Handler_t hBtnLed2;
Button_Handler_t hBtnLed3;

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myButtonTaskHandle;
osThreadId myLedTaskHandle;
osMessageQId btnLedQueueHandle;
osMutexId lcdMutexHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
btn_led_t btnData;
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartButtonTask(void const * argument);
void StartLedTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
	*ppxIdleTaskStackBuffer = &xIdleStack[0];
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
	/* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* definition and creation of lcdMutex */
  osMutexDef(lcdMutex);
  lcdMutexHandle = osMutexCreate(osMutex(lcdMutex));

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of btnLedQueue */
  osMessageQDef(btnLedQueue, 16, uint16_t);
  btnLedQueueHandle = osMessageCreate(osMessageQ(btnLedQueue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  btnMail = osMailCreate(osMailQ(btnMail), NULL);
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myButtonTask */
  osThreadDef(myButtonTask, StartButtonTask, osPriorityNormal, 0, 128);
  myButtonTaskHandle = osThreadCreate(osThread(myButtonTask), NULL);

  /* definition and creation of myLedTask */
  osThreadDef(myLedTask, StartLedTask, osPriorityNormal, 0, 128);
  myLedTaskHandle = osThreadCreate(osThread(myLedTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartButtonTask */
/**
 * @brief Function implementing the myButtonTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartButtonTask */
void StartButtonTask(void const * argument)
{
  /* USER CODE BEGIN StartButtonTask */
	Button_Init(&hBtnLed1, GPIOB, GPIO_PIN_10);
	Button_Init(&hBtnLed2, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnLed3, GPIOB, GPIO_PIN_3);

	LCD_Init(&hi2c1);
	//	MyQue_Init(&qBtnLed, sizeof(btn_led_t));
	btn_led_t* btnData;
	uint32_t cnt_btn = 0;
	/* Infinite loop */
	for(;;)
	{
		if (Button_GetState(&hBtnLed1) == ACT_RELEASED) {
			btnData = osMailAlloc(btnMail, osWaitForever);
			btnData->id = BTN_LED1;
			osMailPut(btnMail, btnData);
			//			MyenQue(&qBtnLed, &btnData);
			osMutexWait(lcdMutexHandle, osWaitForever);
			osMutexRelease(lcdMutexHandle);
		} else if(Button_GetState(&hBtnLed2) == ACT_RELEASED){
			btnData = osMailAlloc(btnMail, osWaitForever);
			btnData->id = BTN_LED2;
			osMailPut(btnMail, btnData);
			//			MyenQue(&qBtnLed, &btnData);
			osMutexWait(lcdMutexHandle, osWaitForever);
			osMutexRelease(lcdMutexHandle);
		} else if(Button_GetState(&hBtnLed3) == ACT_RELEASED){
			btnData = osMailAlloc(btnMail, osWaitForever);
			btnData->id = BTN_LED3;
			osMailPut(btnMail, btnData);
			//			MyenQue(&qBtnLed, &btnData);
			osMutexWait(lcdMutexHandle, osWaitForever);
			osMutexRelease(lcdMutexHandle);
		}
		osDelay(10);
	}
  /* USER CODE END StartButtonTask */
}

/* USER CODE BEGIN Header_StartLedTask */
/**
 * @brief Function implementing the myLedTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartLedTask */
void StartLedTask(void const * argument)
{
  /* USER CODE BEGIN StartLedTask */
	/* Infinite loop */
	btn_led_t* btnData;
	osEvent evt;
	uint8_t ledData = 0;
	uint32_t curCnt = 0, prevCnt = 0;
	for(;;)
	{
		curCnt = HAL_GetTick();
		if(curCnt - prevCnt > 500) {
			prevCnt = curCnt;
			ledData ^= (1U << 0);
			LedBar_Write(ledData);
		}
		evt = osMailGet(btnMail, osWaitForever);
		if(evt.status == osEventMail) {
			btnData = evt.value.p;
			if (btnData->id == BTN_LED1) {
				ledData ^= (1<<1);
				LedBar_Write(ledData);
				osMutexWait(lcdMutexHandle, osWaitForever);
				osMutexRelease(lcdMutexHandle);
			} else if (btnData->id == BTN_LED2) {
				ledData ^= (1<<2);
				LedBar_Write(ledData);
				osMutexWait(lcdMutexHandle, osWaitForever);
				osMutexRelease(lcdMutexHandle);
			} else if (btnData->id == BTN_LED3) {
				ledData ^= (1<<3);
				LedBar_Write(ledData);
				osMutexWait(lcdMutexHandle, osWaitForever);
				osMutexRelease(lcdMutexHandle);
			}
			osMailFree(btnMail, btnData);
		}
		osDelay(1);
	}
  /* USER CODE END StartLedTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
