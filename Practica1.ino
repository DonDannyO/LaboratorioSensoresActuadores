float v = 0.0;
float T = 0.0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  //Comunicación con la computadora a una velocidad serial de 9600 bits por segundo (baudios)
}

void loop()
{
  v = analogRead(A0);
  T = (v*80)/1023;
  Serial.print("Temperatura actual: ");
  Serial.print(T);
  Serial.println(" grados C");
  delay(1000);
}
