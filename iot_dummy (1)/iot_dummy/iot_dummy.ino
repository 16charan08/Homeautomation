int pin = 11;
const int trigPin = 3;
const int echoPin = 4;
String readString;
long dur;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(pin, OUTPUT);
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
 // pinMode(ledPin, OUTPUT); 
}

void echo()
{ 
 
if(distance<20)
  { Serial.println("led on");
   digitalWrite(pin, HIGH);
   delay(100);
  }
  else
  {Serial.println("led off");
   digitalWrite(pin, LOW);
   delay(100);
  }
} 

void loop() {  

  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
dur = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= dur*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
  
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  if (readString.length() >0) {
    Serial.println(readString);
    if (readString == "1")     
    {
      digitalWrite(pin, HIGH);
    }
    //if (readString == "0")
    else
    { 
      echo(); 
      //digitalWrite(pin, LOW);
    }
    readString="";
  } 
}
