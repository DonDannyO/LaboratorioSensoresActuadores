#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12,11,5,4,3,2);

float x = 0.0;
float F = 0.0;
double P = 0.0;
float V = 0.0;
double R = 0.0;

void setup()
{
  pinMode(A0,INPUT);
  lcd.begin(16,2);
}

void loop()
{
  x = analogRead(A0);
  V = (x*5)/1023;
  R = 1000*((5/V)-1);
  
  if(R > 8900)
  {
    F = pow((R/4379.8),(1/-1.168));
    P = ((F/9.81)*1000);
    imprimir();
  }
  else
  {
    F = pow((R/6002.7),(1/-0.7));
    P = ((F/9.81)*1000);
    imprimir();
  }
}

void imprimir()
{
  lcd.setCursor(0,0);
  lcd.print("Fuerza: ");
  lcd.print(F);
  lcd.print(" N");
  lcd.setCursor(0,1);
  lcd.print("Peso: ");
  lcd.print(P);
  lcd.print(" g");
  delay(500);
  lcd.clear();
}
