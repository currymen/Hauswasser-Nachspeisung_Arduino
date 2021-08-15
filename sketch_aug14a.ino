void setup() {
  // put your setup code here, to run once:

// variable declaration and init

const int debounce_counter_measuring = 10;  // debouncing of distance measurement to avoid peaks/disturbances
int switch_main_redundand = 0;        // switch to decide between main sensor and redundand sensor for control 0=only one sensor (main), 1=main (redundand), 2=(main) redundand, 3 only one sensor (redundand)
const int time_loop_measure = 5000;         // loop for measuring intervall
const int time_shift_measure = 100;         // delay of second measurement redundand with safety margin to avoid disturbances
float raw_result_measure1 = 90;         // raw measurement result main sensor
float raw_result_measure2 = 90;         // raw measurement result redundand sensor
float level_evaluated = 0;              // level of water in tank after evaluation
int count_refill_event = 0;           // counter for refill events since start of program
int err_status = 0;                 // error status: 0 = no error; 1 = main sensor defect; 2 = redundand sensor defect; 3 = sensors unplausible;  
int status_refill = 0;                // status message for refill valve 0 = off, 1 = on

// define pining
const int TrigPin = 2;
const int EchoPin = 3;
const int SetSw = 4;
const int UpSw = 5;
const int DownSw = 6;
const int FwdSw = 7;
const int BkwSw = 8;
const int LCDBL = 10;
const int I2CO = 11;
const int I2CI = 12;
const int Relais = 14;
const int EmerSw = 15;

//#include NewPing.h
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
 
// define pin modes
pinMode(TrigPin, OUTPUT); // output for trigger distance measurement
pinMode(EchoPin, INPUT);  // input for distance
pinMode(SetSw, INPUT);// input for set switch
pinMode(UpSw, INPUT);// input for up-switch
pinMode(DownSw, INPUT);// input for down-switch
pinMode(FwdSw, INPUT);// input for forward-switch
pinMode(BkwSw, INPUT);// input for backward-switch
pinMode(LCDBL, OUTPUT); // output for LCD-backlight
pinMode(I2CO, OUTPUT); // output for I2C-bus
pinMode(I2CI, INPUT);// input for I2C-bus
pinMode(Relais, OUTPUT); // output for power-relais
pinMode(EmerSw, INPUT);// input for emergency-switch

Serial.begin(9600);//Set the serial port baud rate to 9600kbps
}

void loop() {
  // put your main code here, to run repeatedly:

// display next info to user
//printf("Fehlerstatus: ", error_status);   //error status
//printf("Sensorkonfig: ", switch_main_redundand); //sensor config
Serial.print("Fehlerstatus: ");
Serial.print(err_status);
Serial.println();
Serial.print("Sensorkonfig: ");
Serial.print(switch_main_redundand);
Serial.println();

delay(10000); //wait for 10 sec to switch to next screen

// display next info to user
//printf("Rohwert(main): ", raw_result_measure1); //level raw main
//printf("Rohwert(redundand): ", raw_result_measure2); //level raw redundand
Serial.print("Rohwert(main): ");
Serial.print(raw_result_measure1);
Serial.println();
Serial.print("Rohwert(redundand): ");
Serial.print(raw_result_measure2);
Serial.println();
delay(10000); //wait for 10 sec to switch to next screen

// display info to user
//printf("Pegel: ", level_evaluated);       //Level in tank
//printf("Nachspeisung: ", status_refill);  //status of refilling
Serial.print("Pegel: ");
Serial.print(level_evaluated);
Serial.println();
Serial.print("Nachspeisung: ");
Serial.print(status_refill);
Serial.println();
read_sensors
check for plausibility


delay(5000000);  // wait for 5 min to repeat loop


}
