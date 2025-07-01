#include "AP_main.h"

typedef enum {
	OFF,
	SHIFT_LEFT,
	SHIFT_RIGHT
}led_state_e;

button_handler_t hBtnLeft;
button_handler_t hBtnRight;
button_handler_t hBtOnOff;

int ap_run(){
	uint8_t data = 1;
	led_state_e led_state = OFF;
	while(1){
		int Btn1_state = Button_GetState(&hBtnLeft);
		int Btn2_state = Button_GetState(&hBtnRight);
		int Btn3_state = Button_GetState(&hBtOnOff);
		switch (led_state) {
			case OFF:
				if(Btn1_state == ACT_PUSHED) led_state = SHIFT_LEFT;
				else if (Btn2_state == ACT_PUSHED) led_state = SHIFT_RIGHT;
				LedBar_Write(0);
				break;
			case SHIFT_LEFT:
				if(Btn3_state == ACT_PUSHED) led_state = OFF;
				else if (Btn2_state == ACT_PUSHED) led_state = SHIFT_RIGHT;
				LedBar_Write(data);
				data = (data<<1) | (data>>7);
				break;
			case SHIFT_RIGHT:
				if(Btn3_state == ACT_PUSHED) led_state = OFF;
				else if (Btn1_state == ACT_PUSHED) led_state = SHIFT_LEFT;
				LedBar_Write(data);
				data = (data>>1) | (data<<7);
				break;
		}delay(100);

	}
	return 0 ;
}

void ap_init(){
	SystemClock_init();
	LedBar_Init(); // ledBar set OutputMode
	Button_Init(&hBtnLeft, GPIOB, 5);
	Button_Init(&hBtnRight, GPIOB, 3);
	Button_Init(&hBtOnOff, GPIOA, 10);
}
