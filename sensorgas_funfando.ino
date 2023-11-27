#include <LiquidCrystal_I2C.h>


#include <Wire.h>



//Ligacoes de Hardware
#define LED 11
#define Buzzer 10
#define MQ2_Analog 0
#define MQ2_Digital 2
#define SensorLevel 500
#define col 16 
#define lin  2 
#define ende  0x27

LiquidCrystal_I2C lcd(ende,col,lin);

int digital_read = 0;
int analog_read = 0;


void setup()
{
  
  pinMode(MQ2_Digital, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight(); 
  lcd.clear();
  
}

void loop()
{
 
  digital_read = digitalRead(MQ2_Digital);
  analog_read = analogRead(MQ2_Analog);
  

  
  Serial.println("Saida Digital:");
  Serial.println(digital_read);
  Serial.println(" Saida Analogica:");
  Serial.println(analog_read);

  if (analog_read > SensorLevel)
  {
    
    lcd.clear();
    lcd.setCursor(1,0);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);
    lcd.print("Ar contaminado");
    delay(3000);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Nivel de Gas");
    lcd.setCursor(5,1);
    lcd.print(analog_read);
    lcd.setCursor(8,1);
    lcd.print("ppm");
    
    

  }
  else
  {
    
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Ar normal!");
    lcd.setCursor(5,1);
    lcd.print("Seguro");
    
    digitalWrite(Buzzer, LOW);
    digitalWrite(LED, LOW);
  }
  
  delay(2000);
}