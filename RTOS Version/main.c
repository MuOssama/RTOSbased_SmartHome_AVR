/***********************************************/
/***********************************************/
/********   Author: Mustapha Ossama   **********/
/********   Date:   22/9/2022         **********/
/********   Title: RTOS Smart Home    **********/
/***********************************************/
/***********************************************/

#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO_INTERFACE.H"
#include "MCAL/ADC/ADC_INTERFACE.h"
#include "MCAL/ADC/ADC_REG.h"
#include "MCAL/EXTI/EXT_INTERRUPT_INTERFACE.h"
#include "HAL/CLCD1602/CLCD_INTERFACE.h"
#include "MCAL/TIMER/TIMER_INTERFACE.h"
#include "MCAL/UART/UART_INTERFACE.h"
#include "MCAL/Timer/TIMER_INTERFACE.h"
#include "MCAL/Timer/TIMER_REG.h"
#include "HAL/BUZZER/BUZZER_INTERFACE.h"
#include "main.h"
#include "Config.h"
#include"RTOS/FreeRTOS.h"
#include"RTOS/task.h"
#ifndef NULL
#define NULL   ((void *) 0)
#endif
/************************************************/
/************************************************/
/*************   Declerations   *****************/
/************************************************/
/************************************************/

static char password_input[5],username_input[5],command[5], ca,
usernum = 99, passnum = 99 ;
u16 Sensors[4]= {0,0,0,0};
void BluetoothRead(char *array);
void SensorsReadings(u16* SensorsPtr);
void SensorsDisplay1(u16* SensorsPtr);
void SensorsDisplay2(u16* SensorsPtr);
void Cases(u16* SensorsPtr);
void UserDemand(char *command);
int main() {

	/*Pin Directions*/
	DDRA = 0b00000011;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11110010;
	//Pulling-up emergency bottoms
	DIO_SetPin_Value(EmergencyBottomPORT,EmergencyBottomPIN , OUTPUT);
	DIO_SetPin_Value(EmergencyBottomPORT,EmergencyBottomPIN_STOP , OUTPUT);


	//Peripherals initialization
	Globle_Intrrupt_Enable();
	INT0_init();
	INT1_init();
	LCD8Bit_init();
	UART_init();
	ADC_init();
    Timer1_init();
    Timer2_init();


	/***********************************************************/
	/******************   Enter the system   *******************/
	/***********************************************************/
	//Entering the username (username phase)

	//Servo close (door)
    ServoAngle(closeangle);

	for(u8 j=1;j<4;j++){
    LCD_Send_String("Enter your");
	LCD_GOTOXY(0,1);
    LCD_Send_String("Username");
    _delay_ms(3000);
    LCD8Bit_Send_Command(0x01);
    LCD_Send_String("Username:");
	BluetoothRead(username_input);
	for(u8 i = 0;i<10;i++){
	if(strcmp(username_input,users[i].username)==0){
	    LCD8Bit_Send_Command(0x01);
	    LCD_Send_String("OK");
	    usernum = i;
	    _delay_ms(3000);
	    break;
	    }
	  }
	if(usernum <10 && usernum>=0){

      break;

	 }
	if((usernum >9 ||usernum<0) && j<3){
	    LCD8Bit_Send_Command(0x01);
	    LCD_Send_String("Wrong Username");
		LCD_GOTOXY(0,1);
		LCD_Send_Int(3-j);
	    LCD_Send_String(" tries left!");
	    _delay_ms(5000);
	    LCD8Bit_Send_Command(0x01);

	 }
	if(j==3 &&(usernum >9 ||usernum<0)){
	    LCD8Bit_Send_Command(0x01);
	    LCD_Send_String("Wrong Username");
		LCD_GOTOXY(0,1);
	    LCD_Send_String("No tries left!");
	    _delay_ms(5000);
	    LCD8Bit_Send_Command(0x01);
	    for(u8 o = 0;o<10;o++){
		    LCD8Bit_Send_Command(0x01);
		    LCD_Send_String("System Shutdown");
			LCD_GOTOXY(0,1);
			LCD_Send_Int(10-o);
		    LCD_Send_String(" Seconds");
		    _delay_ms(1000);
		    LCD8Bit_Send_Command(0x01);

	    }
	  }
	}

	//Entering Password
    _delay_ms(1000);
    LCD8Bit_Send_Command(0x01);
	for(u8 j=1;j<4;j++){
	    LCD_Send_String("Enter your");
		LCD_GOTOXY(0,1);
	    LCD_Send_String("Password");
	    _delay_ms(3000);
	    LCD8Bit_Send_Command(0x01);
	    LCD_Send_String("Password:");
		BluetoothRead(password_input);
		for(u8 i = 0;i<10;i++){
		if(strcmp(password_input,users[i].password)==0){
		    LCD8Bit_Send_Command(0x01);
		    LCD_Send_String("OK");
		    passnum = i;
		    _delay_ms(3000);
		    break;
		    }
		  }
		if(passnum <10 && passnum>=0){
	      break;
		 }
		if((passnum >9 ||passnum<0) && j<3){
		    LCD8Bit_Send_Command(0x01);
		    LCD_Send_String("Wrong Password");
			LCD_GOTOXY(0,1);
			LCD_Send_Int(3-j);
		    LCD_Send_String(" tries left!");
		    _delay_ms(5000);
		    LCD8Bit_Send_Command(0x01);

		 }
		if(j==3 &&(passnum >9 ||passnum<0)){
		    LCD8Bit_Send_Command(0x01);
		    LCD_Send_String("Wrong Password");
			LCD_GOTOXY(0,1);
		    LCD_Send_String("No tries left!");
		    _delay_ms(5000);
		    LCD8Bit_Send_Command(0x01);
		    for(u8 o = 0;o<10;o++){
			    LCD8Bit_Send_Command(0x01);
			    LCD_Send_String("System Shutdown");
				LCD_GOTOXY(0,1);
				LCD_Send_Int(10-o);
			    LCD_Send_String(" Seconds");
			    _delay_ms(1000);
			    LCD8Bit_Send_Command(0x01);

		    }
		  }
		}

    LCD8Bit_Send_Command(0x01);


    	//Servo opens (door)
        ServoAngle(openangle);
    	xTaskCreate(&SensorsReadings,NULL,100,&Sensors,0,NULL);
        xTaskCreate(&SensorsDisplay1,NULL,210,&Sensors,0,NULL);
        xTaskCreate(&SensorsDisplay2,NULL,210,&Sensors,0,NULL);
        //xTaskCreate(&Cases,NULL,210,&Sensors,0,NULL);
        //xTaskCreate(&UserDemand,NULL,210,&command,0,NULL);


        vTaskStartScheduler();

    while(1){

    	/***********************************************************/
    	/******************   Sensors Readings   *******************/
    	/***********************************************************/



    	/***********************************************************/
    	/********************   User Demand   **********************/
    	/***********************************************************/



    	/***********************************************************/
    	/******************   Display Readings   *******************/
    	/***********************************************************/



	}

  }

//Emergency Fire Bottom on Interrupt 0
void __vector_1 (void) __attribute__((signal));
void __vector_1(void){
	DIO_SetPin_Value(EmergencyLEDPORT,EmergencyLEDPIN,HIGH);
	BuzzerON();


}

//Emergency Stop Bottom on Interrupt 1
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	DIO_SetPin_Value(EmergencyLEDPORT,EmergencyLEDPIN,LOW);
	BuzzerOFF();


}

//Bluetooth Get word
void BluetoothRead(char *array){
	    u8 i = 0;
	    ca = '/';
		while (ca!='*') {
		ca = UART_Receive();

		if (ca >= '1' && ca <= 'z'){
		LCD8Bit_Send_Data(ca);
		array[i] = ca;
        i++;
		}
		if(ca == '*'){
		for(u8 i =0;i<4;i++)
			LCD8Bit_Send_Data(array[i]);

		}
    }
}
// Servo Function (interpolations)
void ServoAngle(s8 angle){
	if(angle>= -90 && angle <= 90)
    OCR1A = ((1000.0/180.0)*(angle+90.0))+1000.0;
    if(OCR1A == 2000)
    	OCR1A = 1999;
    if(OCR1A == -90)
    	OCR1A = 1001;
}

//RTOS Functions
void SensorsReadings(u16* Sensors){
	while(1){
		Sensors[0] = ADC_Read_Sych(2)* 500UL/65536UL; //LM35
		Sensors[1] = (ADC_Read_Sych(3)*5000UL)/ 65536UL;//photoresistor_reading
	    Sensors[2] = (ADC_Read_Sych(4) * 5000UL) / 65536UL;//infrared_reading
	    Sensors[3] = ADC_Read_Sych(5) * 5UL / 65536UL;//potentiometer_reading
		//Temperature
	    if(Sensors[0] > MAX_TEMP){
	    	BuzzerTOGGLE(1);
	    }
	    //Light System
	    if(Sensors[1] < MIN_LIGHT){
	    	DIO_SetPin_Value(lamp220PORT,lamp220PIN,HIGH);
	    }
	    if(Sensors[1] >= MIN_LIGHT){
	    	DIO_SetPin_Value(lamp220PORT,lamp220PIN,LOW);

	    }

	    //Emergency
	    /*Emergency is done by interrupt*/

	    //Set motor fan of lm35
	    if(Sensors[0]>30 ){
	    	DIO_SetPin_Value(GroupB,PIN3,HIGH);
	    }
	    if (Sensors[0]<30){
	    	DIO_SetPin_Value(GroupB,PIN3,LOW);
	    }

	    //Set motor fan by Variable Resitor
	    OCR2_REG = Sensors[3]*60UL;
	    vTaskDelay(400);

	}


}

void SensorsDisplay1(u16* Sensors){
	while(1){
		LCD8Bit_Send_Command(0x01);
		LCD_Send_String("Temperature:");
		LCD_Send_Int(Sensors[0]);
		LCD_GOTOXY(0,1);
		LCD_Send_String("Fan Speed:");
		LCD_Send_Int(Sensors[3]);
	    vTaskDelay(1000);

	}
}
void SensorsDisplay2(u16* Sensors){
	while(1){
		LCD8Bit_Send_Command(0x01);
		LCD_Send_String("LDR:");
		LCD_Send_Int(Sensors[1]);
		LCD_GOTOXY(0,1);
		LCD_Send_String("Infrared:");
		LCD_Send_Int(Sensors[2]);
	    vTaskDelay(1200);

	}
}
/*void UserDemand(char * command){
   while(1){
    //Check if the user wants Something
    ca = UART_Receive();
    if(ca == '-'){
    _delay_ms(100);
    LCD8Bit_Send_Command(0x01);
    LCD_Send_String("I'm Here");
    LCD_GOTOXY(0,1);
    LCD_Send_String("Sir");
    _delay_ms(1000);
    LCD8Bit_Send_Command(0x01);
    LCD_Send_String("Command:");
	BluetoothRead(command);
    LCD8Bit_Send_Command(0x01);
    if(strcmp(command,shutdoor)==0){
       LCD_Send_String("Closing");
       LCD_GOTOXY(0,1);
       LCD_Send_String("the door...");
       ServoAngle(closeangle);
       _delay_ms(1000);
       LCD8Bit_Send_Command(0x01);
       }
    if(strcmp(command,opendoor)==0){
              LCD_Send_String("Opening");
              LCD_GOTOXY(0,1);
              LCD_Send_String("the door...");
              ServoAngle(openangle);
              _delay_ms(1000);
              LCD8Bit_Send_Command(0x01);
              }
    if(strcmp(command,heavyload1)==0){
       LCD_Send_String("Heavy load 1");
       LCD_Save_Character(0,1);
       LCD_Send_String("Switched");
       TOG_BIT(PORTB,2);
       _delay_ms(1000);
       LCD8Bit_Send_Command(0x01);
       }
    if(strcmp(command,heavyload2)==0){
       LCD_Send_String("Heavy load 2");
       LCD_Save_Character(0,1);
       LCD_Send_String("Switched");
       TOG_BIT(PORTD,6);
       _delay_ms(1000);
       LCD8Bit_Send_Command(0x01);
       }
    if(strcmp(command,heavyload3)==0){
       LCD_Send_String("Heavy load 3");
       LCD_Save_Character(0,1);
       LCD_Send_String("Switched");
       TOG_BIT(PORTB,7);
       _delay_ms(1000);
       LCD8Bit_Send_Command(0x01);
       }
    if(strcmp(command,heavyload4)==0){
       LCD_Send_String("Heavy load");
       LCD_Save_Character(0,1);
       LCD_Send_String("Switched");
       TOG_BIT(PORTD,4);
       _delay_ms(1000);
       LCD8Bit_Send_Command(0x01);
       }
    if(strcmp(command,heavyloadALLOFF)==0){
       LCD_Send_String("Heavy loads");
       LCD_Save_Character(0,1);
       LCD_Send_String("are OFF");
       CLR_BIT(PORTB,2);
       CLR_BIT(PORTD,6);
       CLR_BIT(PORTB,7);
       CLR_BIT(PORTD,4);
       _delay_ms(1000);
       LCD8Bit_Send_Command(0x01);
       }
    }
    //vTaskDelay(1000);
   }
}*/
void Cases(u16* SensorsPtr){
	while(1){
		//Temperature
	    if(Sensors[0] > MAX_TEMP){
	    	BuzzerTOGGLE(1);
	    }
	    //Light System
	    if(Sensors[1] < MIN_LIGHT){
	    	DIO_SetPin_Value(lamp220PORT,lamp220PIN,HIGH);
	    }
	    if(Sensors[1] >= MIN_LIGHT){
	    	DIO_SetPin_Value(lamp220PORT,lamp220PIN,LOW);

	    }

	    //Emergency
	    /*Emergency is done by interrupt*/

	    //Set motor fan of lm35
	    if(Sensors[0]>30 ){
	    	DIO_SetPin_Value(GroupB,PIN3,HIGH);
	    }
	    if (Sensors[0]<30){
	    	DIO_SetPin_Value(GroupB,PIN3,LOW);
	    }

	    //Set motor fan by Variable Resitor
	    OCR2_REG = Sensors[3]*60UL;
	    vTaskDelay(500);

	}
}
