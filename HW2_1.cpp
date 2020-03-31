#include "mbed.h"
#include <stdio.h>

AnalogOut Aout(DAC0_OUT);

AnalogIn Ain(A0);

float ADCdata[100];

BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);

char table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

DigitalIn  Switch(SW3);

DigitalOut redLED(LED1);

DigitalOut greenLED(LED2);

int sample = 100;

int flag = 0;

int times =0;

int main(){

  for(int i = 0 ; i<sample ; i++){

    ADCdata[i] = Ain;

    Aout = ADCdata[i];

    wait(0.0001); // period = 100*0.0001 , freqency = 100 

  }

  while(1){

    if( Switch == 1 && (times%2) == 0){
      
      flag = 1;

      times = times + 1;

    }

    else if(Switch == 1 && (times%2) == 1){

      flag = 0;

    }

    if( flag == 1){
      
      greenLED = 0;

      redLED = 1;
    
      display = table[1];

      wait(0.99);

      display = table[0];

      wait(0.99);

      display = table[0];

      wait(0.99);    

    }

    else if( flag == 0 ){

      redLED = 0;

      greenLED = 1;      

    }

  }

}