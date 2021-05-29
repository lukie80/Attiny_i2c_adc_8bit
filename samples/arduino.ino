#include <Wire.h>

byte CHIP_ADDRESS=0x13;
byte COMMAND_ADDRESS=0x00;
byte ADC_ADDRESS=0x02;

uint8_t getdata(){
  //send command 0x02 (ADC#) to register 0x00 on device 0x13
  Wire.beginTransmission(CHIP_ADDRESS);  
  Wire.write(COMMAND_ADDRESS);
  Wire.write(ADC_ADDRESS);
  if(Wire.endTransmission()!=0){
      Serial.println("ERROR");
  }
  delay(200);
  // read ADC register 0x02
  Wire.beginTransmission(CHIP_ADDRESS);
  Wire.write(ADC_ADDRESS);
  if(Wire.endTransmission()!=0){
      Serial.println("ERROR");
  }
  Wire.requestFrom(CHIP_ADDRESS, 1);
  byte val = Wire.read();
  return val;
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  byte raw = getdata();
  Serial.println(raw);
  delay(500);
}
