//Test General de componentes Tomassito V0.9

  //Sensor ultrasonico

  #define echoPin 14
  #define trigPin 12

  long duration;
  int distance; 

  // Motor dirección

  int MB2 = 2;
  int MB1 = 4;
  int MA2 = 0;
  int MA1 = 5;

  //Led

  int led2 = 15;
  int led1 = 16;

  //Buzzer
  
  int buzzer = 13;
  int cuarto = 1000 / 4;
  int octavo = 1000 / 8;
  double pausa = 1.30;
  int NOTA_A1 = 55; 
  int NOTA_F6 = 1479;
  int NOTA_E5 = 659; 
  int NOTA_C3 = 130; 

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  
  Serial.println("Test General ...");
  Serial.println("Tomasitto V0.9");
  
  pinMode(MB2, OUTPUT);     
  pinMode(MB1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MA1, OUTPUT);
  
  pinMode(led1 , OUTPUT); 
  pinMode(led2 , OUTPUT);
  
  pinMode(buzzer, OUTPUT);
}

void loop() {

  // Test ultrasonido
  
  Serial.print("Test ultrasonido - ");
  delay(1000);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(5000);

  //test buzzer
  
  Serial.println("Test buzzer");
  tone(buzzer, NOTA_A1, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_A1, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_F6, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_E5, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_A1, octavo);
  delay(octavo*pausa);
  noTone(buzzer);
  delay(125);
  tone(buzzer, NOTA_C3, cuarto);
  delay(cuarto*pausa);
  tone(buzzer, NOTA_A1, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_A1, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_F6, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_E5, octavo);
  delay(octavo*pausa);
  tone(buzzer, NOTA_A1, octavo);
  delay(octavo*pausa);
  noTone(buzzer);
  delay(125);
  tone(buzzer, NOTA_F6, cuarto);
  delay(cuarto*pausa);
  delay(1000);

  // Test leds
  
  Serial.println("Test Led 1");
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  Serial.println("Test Led 2");
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  
  //Tes motores
    
  //avanza
  Serial.println("Test Motores Adelante");
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
  delay(1000); 
   
  //STOP
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  delay(500);

  //Retroceso
  Serial.println("Test Motores Retroceso");
  digitalWrite(MA1, HIGH);                 
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, HIGH);                              
  digitalWrite(MB2, HIGH); 
  delay(1000);

  //STOP
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  delay(500);

  //Giro 1
  Serial.println("Test Motores Giro 1");
  digitalWrite(MA1, HIGH);           
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);                           
  digitalWrite(MB2, HIGH);
  delay(1000); 

  //STOP
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  delay(500);
     
  //Giro 2
  Serial.println("Test Motores Giro 2");
  digitalWrite(MA1, HIGH);               
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, HIGH);                            
  digitalWrite(MB2, LOW); 
  delay(1000); 
   
  //STOP
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  delay(500);
   
  }
  
