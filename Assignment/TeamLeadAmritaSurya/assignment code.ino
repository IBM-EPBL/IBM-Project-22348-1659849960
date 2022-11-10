float temp = A5;
int buzzer = 10;

int trigPin = 8;
int echoPin = 7;

int LED = 11;

void setup()
{
  pinMode (A5,INPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode (10,OUTPUT);
  pinMode(11, OUTPUT); //red
  Serial.begin(9600);
}

void loop()
{
  temp = analogRead(A5);
  temp=(temp/1024.0)*5.0;
  temp=(temp-.5)*100.0;
  
  Serial.print(temp);
  Serial.println("c");
  
  long duration, Distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Distance = (duration/2) / 74;
  
  Serial.print(Distance);
  Serial.println(" inches");
  
  if (Distance >= 55)
  {
	digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
    if (temp < 40)
  	{
	digitalWrite(11, LOW);
	digitalWrite(10, LOW);
  	}
  
  if (Distance < 55)
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
  }
    if (temp >= 40)
  	{
    digitalWrite(11, HIGH);
	digitalWrite(10, HIGH);
  	}
  
  delay(500);
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  