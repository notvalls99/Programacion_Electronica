double tempMAX = 0;
double tempMIN = 1000;
double tempMED = 0;
int frec = 2000;


double tempR = 0;
int j=0;  
int k=0;
void setup() {
  Serial.begin(9600);
  pinMode (13,OUTPUT);
  pinMode (2,INPUT);
  pinMode (3,INPUT);
  pinMode (4,INPUT);
  pinMode (5,INPUT);
  pinMode (6,INPUT);
  pinMode (7,INPUT); 
  pinMode (8,INPUT); 
  pinMode (9,INPUT);
  
}

void loop() {
char p = 'o';

Serial.println ("a. Temperatura a tiempo real");
 Serial.println("\n");
Serial.println ("b. Temperatura Máxima y Mínima");
 Serial.println("\n");
Serial.println ("c. Temperatura media");
 Serial.println("\n");
Serial.println ("t. Sácame de aquí");

while (p != 'a', p != 'b' , p != 'c', p != 't')
{ 
  p = Serial.read();
  j++;
  digitalWrite (3,HIGH);
  double tempF = 0;
  for (int i=2;i<9+;i++)
  {
    if (digitalRead(i)==HIGH)
    {
      tempF = digitalRead(2)+digitalRead(3)*2+digitalRead(4)*4+digitalRead(5)*8+digitalRead(6)*16+digitalRead(7)*32+digitalRead(8)*64+digitalRead(9)*128;
    }
  }
  tempR = tempF;
 
  if (tempR > tempMAX)
  {
    tempMAX = tempR;
  }
  if (tempR < tempMIN)
  {
    tempMIN = tempR;
  }
  if (j == 10)
  {
    j=0;
    k++;
    tempMED = tempMED*(k-1)/k+tempR/k;
  }
  delay (frec);
  
  digitalWrite (3,LOW);

  if ( p == 'a')
  {
    Serial.print("Temperatura:");
    Serial.print(tempR); 
    Serial.println(" ºC");
  }
  if ( p == 'b')
  {
    Serial.print("Temperatura máxima:"); 
    Serial.print(tempMAX); 
    Serial.println(" ºC");
    
    Serial.print("Temperatura mínima:");
    Serial.print(tempMIN); 
    Serial.println(" ºC");
  }
  if ( p == 'c')
  {
    Serial.print("Temperatura media:"); 
    Serial.print(tempMED); 
    Serial.println(" ºC");
  }
    if ( p == 't')
  {
    break;
  }
  
  delay (frec);
  Serial.println("p");
  
}
  
  
  
  
}
