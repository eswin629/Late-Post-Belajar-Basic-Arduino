/*void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  if(Serial.available()>0)
  {
    char data = Serial.read();
    if (data == 'a')
    {
      digitalWrite(13,HIGH);
    }
    else if(data == 'b')
    {
      digitalWrite(13,LOW);
    }
  }

}*/


/*
void setup() {
Serial.begin(9600);
 pinMode(13, OUTPUT); // put your setup code here, to run once:

 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': digitalWrite(13, HIGH);break; // when a is pressed on the app on your smart phone
        case 'b': digitalWrite(13, LOW);break; // when d is pressed on the app on your smart phone
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
*/

int OnOffLock = 13;
int Yellow = 4;
int Red = 5;

void setup() {
  Serial.begin(9600);
  pinMode(OnOffLock,OUTPUT);
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

  if(voice=="on")
  {
    digitalWrite(OnOffLock,HIGH);
  } else if(voice=="off")
  {
    digitalWrite(OnOffLock,LOW);
  }

}
