#include <LiquidCrystal.h>
#include <stdio.h>

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
 unsigned char rcv,count,gchr,gchr1,robos='s';
 //char pastnumber[11]="";

 int tempc=0;
char data_temp=0, RFID_data[13],read_count=0;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int sti=0;

int red_led   = 8;
int green_led = 9;
int buzzer    = 13;



int val1 = 0,val2 = 0;
unsigned char rfidst='x';

unsigned char sts1=0,sts2=0,sts3=0;
unsigned int pr1=0,pr2=0,pr3=0,total=0;


void okcheck()
{
  unsigned char rcr;
  do{
      rcr = Serial.read();
    }while(rcr != 'K');
}
void beep()
{
    digitalWrite(buzzer, LOW);delay(2500);digitalWrite(buzzer, HIGH);
}
void setup() 
{
  // initialize serial:
  Serial.begin(9600);serialEvent();
//    serialEvent();
  
  
  pinMode(red_led, OUTPUT);pinMode(green_led, OUTPUT);pinMode(buzzer, OUTPUT);

  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(buzzer, HIGH);
  
  lcd.begin(16, 2);
  lcd.print("RFID Bluetooth");
  lcd.setCursor(0,1);
  lcd.print("Tourist Service");
      delay(1500);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  
  //serialEvent();
}

void loop() 
{
  lcd.setCursor(0,1);
  lcd.print("Swip Card  ");
   if(stringComplete)
     {lcd.clear();lcd.print(inputString);
       if(inputString == "55007FB5D24D")
         {
          lcd.clear();lcd.print("Valid Entry");
          digitalWrite(red_led, HIGH);
          digitalWrite(green_led, LOW);
         }
      if(inputString == "55007B49C6A1")
         {
           lcd.clear();lcd.print("Invalid Entry");
          digitalWrite(red_led, LOW);
          digitalWrite(green_led, HIGH);beep();
         }
       
       sti=0;
       inputString = "";
       stringComplete = false;         
             delay(1000);
     }
}          


void RecieveData()
{
if(Serial.available() > 0)
  {
   data_temp = Serial.read();
   RFID_data[read_count] = data_temp;
   read_count++;
  }
}


int readSerial(char result[]) 
{
  int i = 0;
  while (1) 
  {
    while (Serial.available() > 0) 
    {
      char inChar = Serial.read();
      if (inChar == '\n') 
         {
          result[i] = '\0';
          Serial.flush();
          return 0;
         }
      if (inChar != '\r') 
         {
          result[i] = inChar;
          i++;
         }
    }
  }
}



void converts(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   Serial.write(a);
   Serial.write(c);
   Serial.write(e); 
   Serial.write(g);
   Serial.write(h);
}

void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   //lcd.write(a);
   lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}


void serialEvent() 
{
  while (Serial.available()) 
        {
         
         char inChar = (char)Serial.read();
              inputString += inChar;
              sti++;
          if(sti == 12)
            {sti=0;
              stringComplete = true;      
            }
        }
}


/*
   sensorValue = analogRead(analogInPin);
   sensorValue = (sensorValue/9.31);
   lcd.setCursor(1,1); //rc
   lcd.print(sensorValue);
   Serial.print(sensorValue);
 */
