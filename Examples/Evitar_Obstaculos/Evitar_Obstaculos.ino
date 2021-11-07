/*
La distancia de 50 cm definido en el IF puede ser adecuado según requerimientos
Los delay de los movimientos de los motores pueden ajustarse para mejorar el funcionamiento

*/ 


//Evitar obstaculos

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

int led1 = 15;
int led2 = 16;

//Buzzer

int buzzer = 13;



void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  
  Serial.println("Sensor HC-SR04");
  Serial.println("Tomasitto");
  
  pinMode(MB2, OUTPUT);     
  pinMode(MB1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MA1, OUTPUT);
  
  pinMode(led1 , OUTPUT); 
  pinMode(led2 , OUTPUT);
  
  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  
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
  
  if (distance > 50)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    
    //avanza
    digitalWrite(MA1, HIGH);
    digitalWrite(MA2, LOW);
    digitalWrite(MB1, HIGH);
    digitalWrite(MB2, LOW);
    delay(500);  

  }

  if (distance < 50)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzer, 500);
    delay(250);        
    noTone(buzzer);   
    delay(250);
    tone(buzzer, 800);
    delay(250);        
    noTone(buzzer);   
    delay(250);     
    
    //STOP
    digitalWrite(MA1, LOW);
    digitalWrite(MA2, LOW);
    digitalWrite(MB1, LOW);
    digitalWrite(MB2, LOW);
    delay(500);

    //retroceso
    digitalWrite(MA1, HIGH);                 
    digitalWrite(MA2, HIGH);
    digitalWrite(MB1, HIGH);                              
    digitalWrite(MB2, HIGH); 
    delay(500);

    //STOP 
    digitalWrite(MA1, LOW);
    digitalWrite(MA2, LOW);
    digitalWrite(MB1, LOW);
    digitalWrite(MB2, LOW);
    delay(500);

    //giro
    digitalWrite(MA1, HIGH);                  
    digitalWrite(MA2, LOW);  
    digitalWrite(MB1, HIGH);                               
    digitalWrite(MB2, HIGH);   
    delay(500);
    
  }

}
