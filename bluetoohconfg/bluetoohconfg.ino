int pin=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  { char c=Serial.read();
     if(c=='1')
     { Serial.println("on1");
        digitalWrite(pin, HIGH);
     }
     if(c=='0')
     {
        Serial.println("off1");
        digitalWrite(pin, LOW);
     }
  }
}
