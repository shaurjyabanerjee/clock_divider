//Arduino Clock Divider for Modular Synthesis 
//Shaurjya Banerjee & Ness Morris 2016

int pin_1 = 7; 
int pin0  = 8;
int pin1  = 9;
int pin2  = 10;
int pin3  = 11;
int pin4  = 12;
int pin5  = 13;

volatile bool out_1 = false;
volatile bool out0  = false;
volatile bool out1  = false;
volatile bool out2  = false;
volatile bool out3  = false;
volatile bool out4  = false;
volatile bool out5  = false;

volatile int count = 0;

void setup() {
    pinMode(pin_1, OUTPUT);
    pinMode(pin0,  OUTPUT);
    pinMode(pin1,  OUTPUT);
    pinMode(pin2,  OUTPUT);
    pinMode(pin3,  OUTPUT);
    pinMode(pin4,  OUTPUT);
    pinMode(pin5,  OUTPUT);
    
    attachInterrupt(1, divide, RISING);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(pin_1, pin_1);
    digitalWrite(pin0,  out0);
    digitalWrite(pin1,  out1);
    digitalWrite(pin2,  out2);
    digitalWrite(pin3,  out3);
    digitalWrite(pin4,  out4);
    digitalWrite(pin5,  out5);
}

void divide() {
 
  out_1 = !out_1;
  out0  = !out0;
  if(count%3 == 0) { out1 = !out1; }
  if(count%4 == 0) { out2 = !out2; }
  if(count%5 == 0) { out3 = !out3; }
  if(count%6 == 0) { out4 = !out4; }
  if(count%7 == 0) { out5 = !out5; }
  
  count++;
  
  //Modulo equal to by the LCM of all clock divisions to reset counter 
  count %= 420;
  
  Serial.print("\n");
}
