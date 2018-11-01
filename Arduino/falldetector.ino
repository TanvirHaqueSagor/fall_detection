 
#include <SPI.h>

 
int CS=10;
float a=4.2;
 
char POWER_CTL = 0x2D;  //Power Control Register
char DATA_FORMAT = 0x31;
char DATAX0 = 0x32; //X-Axis Data 0
char DATAX1 = 0x33; //X-Axis Data 1
char DATAY0 = 0x34; //Y-Axis Data 0
char DATAY1 = 0x35; //Y-Axis Data 1
char DATAZ0 = 0x36; //Z-Axis Data 0
char DATAZ1 = 0x37; //Z-Axis Data 1

 
char values[10];
 
int x,y,z,aaa=0;
boolean min,max;

void setup(){ 
 
  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  Serial.begin(9600);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  writeRegister(DATA_FORMAT, 0x01);
  writeRegister(POWER_CTL, 0x08);  //Measurement mode  
}

void loop(){
  
  readRegister(DATAX0, 6, values);
/*
 
  x = sqrt(((int)values[1]<<8)|(int)values[0]);
 
  y = sqrt(((int)values[3]<<8)|(int)values[2]);

  z = sqrt(((int)values[5]<<8)|(int)values[4]);

*/
 x =  (((int)values[1]<<8)|(int)values[0]);
 
  y = (((int)values[3]<<8)|(int)values[2]);

  z = (((int)values[5]<<8)|(int)values[4]);


  
  aaa=sqrt(x+y+z);
  /////////////////////////////////////////////////////////////////
  
  if (aaa>=6.0) {
      min=true;
      //mintime=System.currentTimeMillis();
    }

    if (min==true) {

      if(aaa<=13.5) {
        max=true;
      }
    }

    if (min==true && max==true) {
       //Serial.println("fall Detected");
       Serial.print('#');
       Serial.print(a);
       Serial.print('~');
       Serial.println();
       
     
      min=false;
      max=false;
    }

     
    
    /////////////////////////////////////////////////////////////////

 
  Serial.print(x, DEC);
  Serial.print(',');
  Serial.print(y, DEC);
  Serial.print(',');
  Serial.println(z, DEC);   

      
  delay(1000);
  
   
}

  
void writeRegister(char registerAddress, char value){
   
  digitalWrite(CS, LOW);
  
  SPI.transfer(registerAddress);
  
  SPI.transfer(value);
 
  digitalWrite(CS, HIGH);
}
 
void readRegister(char registerAddress, int numBytes, char * values){
  
  char address = 0x80 | registerAddress;
  
  if(numBytes > 1)address = address | 0x40;

 
  digitalWrite(CS, LOW);
 
  SPI.transfer(address);
   
  for(int i=0; i<numBytes; i++){
    values[i] = SPI.transfer(0x00);
  }
 
  digitalWrite(CS, HIGH);
}
