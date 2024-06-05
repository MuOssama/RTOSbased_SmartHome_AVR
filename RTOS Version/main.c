/***********************************************/
/***********************************************/
/********   Author: Mustapha Ossama   **********/
/********   Date:   22/9/2022         **********/
/********   Title: RTOS Smart Home    **********/
/***********************************************/
/***********************************************/

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO_INTERFACE.h"
#include "MCAL/ADC/ADC_INTERFACE.h"
#include "MCAL/EXTI/EXT_INTERRUPT_INTERFACE.h"
#include "HAL/CLCD1602/CLCD_INTERFACE.h"
#include "MCAL/TIMER/TIMER_INTERFACE.h"
#include "MCAL/UART/UART_INTERFACE.h"
#include "HAL/BUZZER/BUZZER_INTERFACE.h"
#include "main.h"
#include "Config.h"
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

/************************************************/
/************************************************/
/*************   Declarations   *****************/
/************************************************/
/************************************************/

static char password_input[5], username_input[5], command[5];
static char ca;
static u8 usernum = 99, passnum = 99;
u16 Sensors[4] = {0, 0, 0, 0};

// Assuming `users` array is defined somewhere
extern user_t users[];

void BluetoothRead(char *array);
void SensorsReadings(void *pvParameters);
void SensorsDisplay1(void *pvParameters);
void SensorsDisplay2(void *pvParameters);
void Cases(void *pvParameters);
void UserDemand(void *pvParameters);

int main() {
    /* Initialize hardware and peripherals */
   /* Pin Directions */
    DDRA = 0b00000011;
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    DDRD = 0b11110010;

    // Pulling-up emergency buttons
    DIO_SetPin_Value(EmergencyBottomPORT, EmergencyBottomPIN, OUTPUT);
    DIO_SetPin_Value(EmergencyBottomPORT, EmergencyBottomPIN_STOP, OUTPUT);

    // Peripherals initialization
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
    // Entering the username (username phase)
    // Servo close (door)
    ServoAngle(closeangle);

    for (u8 j = 1; j < 4; j++) {
        LCD_Send_String("Enter your");
        LCD_GOTOXY(0, 1);
        LCD_Send_String("Username");
        _delay_ms(3000);
        LCD8Bit_Send_Command(0x01);
        LCD_Send_String("Username:");
        BluetoothRead(username_input);
        for (u8 i = 0; i < 10; i++) {
            if (strcmp(username_input, users[i].username) == 0) {
                LCD8Bit_Send_Command(0x01);
                LCD_Send_String("OK");
                usernum = i;
                _delay_ms(3000);
                break;
            }
        }
        if (usernum < 10 && usernum >= 0) {
            break;
        }
        if ((usernum > 9 || usernum < 0) && j < 3) {
            LCD8Bit_Send_Command(0x01);
            LCD_Send_String("Wrong Username");
            LCD_GOTOXY(0, 1);
            LCD_Send_Int(3 - j);
            LCD_Send_String(" tries left!");
            _delay_ms(5000);
            LCD8Bit_Send_Command(0x01);
        }
        if (j == 3 && (usernum > 9 || usernum < 0)) {
            LCD8Bit_Send_Command(0x01);
            LCD_Send_String("Wrong Username");
            LCD_GOTOXY(0, 1);
            LCD_Send_String("No tries left!");
            _delay_ms(5000);
            LCD8Bit_Send_Command(0x01);
            for (u8 o = 0; o < 10; o++) {
                LCD8Bit_Send_Command(0x01);
                LCD_Send_String("System Shutdown");
                LCD_GOTOXY(0, 1);
                LCD_Send_Int(10 - o);
                LCD_Send_String(" Seconds");
                _delay_ms(1000);
                LCD8Bit_Send_Command(0x01);
            }
        }
    }

    // Entering Password
    _delay_ms(1000);
    LCD8Bit_Send_Command(0x01);
    for (u8 j = 1; j < 4; j++) {
        LCD_Send_String("Enter your");
        LCD_GOTOXY(0, 1);
        LCD_Send_String("Password");
        _delay_ms(3000);
        LCD8Bit_Send_Command(0x01);
        LCD_Send_String("Password:");
        BluetoothRead(password_input);
        for (u8 i = 0; i < 10; i++) {
            if (strcmp(password_input, users[i].password) == 0) {
                LCD8Bit_Send_Command(0x01);
                LCD_Send_String("OK");
                passnum = i;
                _delay_ms(3000);
                break;
            }
        }
        if (passnum < 10 && passnum >= 0) {
            break;
        }
        if ((passnum > 9 || passnum < 0) && j < 3) {
            LCD8Bit_Send_Command(0x01);
            LCD_Send_String("Wrong Password");
            LCD_GOTOXY(0, 1);
            LCD_Send_Int(3 - j);
            LCD_Send_String(" tries left!");
            _delay_ms(5000);
            LCD8Bit_Send_Command(0x01);
        }
        if (j == 3 && (passnum > 9 || passnum < 0)) {
            LCD8Bit_Send_Command(0x01);
            LCD_Send_String("Wrong Password");
            LCD_GOTOXY(0, 1);
            LCD_Send_String("No tries left!");
            _delay_ms(5000);
            LCD8Bit_Send_Command(0x01);
            for (u8 o = 0; o < 10; o++) {
                LCD8Bit_Send_Command(0x01);
                LCD_Send_String("System Shutdown");
                LCD_GOTOXY(0, 1);
                LCD_Send_Int(10 - o);
                LCD_Send_String(" Seconds");
                _delay_ms(1000);
                LCD8Bit_Send_Command(0x01);
            }
        }
    }

    LCD8Bit_Send_Command(0x01);

    // Servo opens (door)
    ServoAngle(openangle);

    xLCD_Semaphore = xSemaphoreCreateMutex();

    /* Create tasks */
    xTaskCreate(SensorsReadings, "SensorsReadings", 100, NULL, 1, NULL);
    xTaskCreate(SensorsDisplay1, "SensorsDisplay1", 210, NULL, 2, NULL);
    xTaskCreate(SensorsDisplay2, "SensorsDisplay2", 210, NULL, 2, NULL);

    vTaskStartScheduler();

    while (1) {
        // Main loop, should not be reached
    }

    return 0;
}

/*######################*/
/*######################*/
/*###   Interrupts   ###*/
/*######################*/
/*######################*/

// Emergency Fire Button on Interrupt 0
void __vector_1(void) __attribute__((signal));
void __vector_1(void) {
    DIO_SetPin_Value(EmergencyLEDPORT, EmergencyLEDPIN, HIGH);
    BuzzerON();
}

// Emergency Stop Button on Interrupt 1
void __vector_2(void) __attribute__((signal));
void __vector_2(void) {
    DIO_SetPin_Value(EmergencyLEDPORT, EmergencyLEDPIN, LOW);
    BuzzerOFF();
}


void BluetoothRead(char *array) {
  u8 i = 0;
    char ca = '/';
    while (ca != '*') {
        ca = UART_Receive();
        if (ca >= '1' && ca <= 'z') {
            LCD8Bit_Send_Data(ca);
            array[i] = ca;
            i++;
        }
        if (ca == '*') {
            for (u8 i = 0; i < 4; i++) {
                LCD8Bit_Send_Data(array[i]);
            }
            _delay_ms(2000);
            LCD8Bit_Send_Command(0x01);
            break;
        }
    }
  }

void SensorsReadings(void *pvParameters) {
    
        // Read sensor values
        if (xSemaphoreTake(xLCD_Semaphore, portMAX_DELAY) == pdTRUE) {
            Sensors[0] = ADC_Read_Sych(2) * 500UL / 65536UL; // LM35
            Sensors[1] = (ADC_Read_Sych(3) * 5000UL) / 65536UL; // photoresistor_reading
            Sensors[2] = (ADC_Read_Sych(4) * 5000UL) / 65536UL; // infrared_reading
            Sensors[3] = ADC_Read_Sych(5) * 5UL / 65536UL; // potentiometer_reading
            xSemaphoreGive(xLCD_Semaphore);
        }
        vTaskDelay(400);
    
}

void SensorsDisplay1(void *pvParameters) {
    
        if (xSemaphoreTake(xLCD_Semaphore, portMAX_DELAY) == pdTRUE) {
            LCD8Bit_Send_Command(0x01);
            LCD_Send_String("Temperature:");
            LCD_Send_Int(Sensors[0]);
            LCD_GOTOXY(0, 1);
            LCD_Send_String("Fan Speed:");
            LCD_Send_Int(Sensors[3]);
            xSemaphoreGive(xLCD_Semaphore);
        }
        vTaskDelay(1000);
    
}

void SensorsDisplay2(void *pvParameters) {
    
        if (xSemaphoreTake(xLCD_Semaphore, portMAX_DELAY) == pdTRUE) {
            LCD8Bit_Send_Command(0x01);
            LCD_Send_String("LDR:");
            LCD_Send_Int(Sensors[1]);
            LCD_GOTOXY(0, 1);
            LCD_Send_String("Infrared:");
            LCD_Send_Int(Sensors[2]);
            xSemaphoreGive(xLCD_Semaphore);
        }
        vTaskDelay(1200);
    
}
