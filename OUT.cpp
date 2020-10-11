#include <iostream>
#include <unistd.h>  
#include <wiringPi.h>
#include <ncurses.h>

using namespace std;

const int led_Blue_Output = 0;

void init(){
	wiringPiSetup();
    pinMode(led_Blue_Output, OUTPUT);
}

void setLed(int ledNumber, bool value){
    digitalWrite(ledNumber, value);
}

int main(){
	init();
	bool led_Blu_Status = true;
	setLed(led_Blue_Output, led_Blu_Status);
	initscr();
    // cbreak();
    while(1){
        cout << "premi qualsiasi tasto per uscire" << endl;
        if(getchar()){
            break;
        }
    }
    endwin();
    led_Blu_Status = false;
	setLed(led_Blue_Output, led_Blu_Status);
    return 0;
}


