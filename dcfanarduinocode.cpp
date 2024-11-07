 #include<LiquidCrystal.h>
 LiquidCrystal lcd(12,11,5,4,3,2);
 int val;
int tempPin = A0;
int fan=7 ;
void setup()
{
  lcd.begin(16,2);
Serial.begin(9600);
pinMode(fan,OUTPUT);
digitalWrite(fan,LOW);
lcd.setCursor(0,0);
  lcd.print("Welcome in");
  lcd.setCursor(0,2);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp controlled");
  lcd.setCursor(0,2);
  lcd.print("cooling System");
  delay(2000);
  lcd.clear();
}
void loop()
{
  
  
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
lcd.setCursor(0,0);
lcd.print("TEMPRATURE = ");
lcd.print(cel);
lcd.setCursor(0,2);
lcd.print("*C");
delay(1000);


if(cel>40)
{
  digitalWrite(fan,HIGH);
}
else
{ digitalWrite(fan,LOW);
}


}
