int Green = 3;
int Yellow = 4;
int Red = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  

}


char c;
String voice;

void loop() {
  if (Serial.available()>0)
  {
    voice="";
    voice=Serial.readString();
    Serial.print(voice+'\n');
  }

  if(voice=="green")
  {
    digitalWrite(Green,HIGH);
  } else if(voice=="green off")
  {
    digitalWrite(Green,LOW);
  }

    if(voice=="yellow")
  {
    digitalWrite(Yellow,HIGH);
  } else if(voice=="Yellow off")
  {
    digitalWrite(Yellow,LOW);
  }

  
  if(voice=="red")
  {
    digitalWrite(Red,HIGH);
  } else if(voice=="red off")
  {
    digitalWrite(Red,LOW);
  }

}
