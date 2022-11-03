#include <IRremote.h>

#define PREV 118811
#define NEXT 11899
#define PLAY 118900

int receiver_IR = 10;

IRrecv remot(receiver_IR);
decode_results data_remot;

void setup() {
  // put your setup code here, to run once:
remot.enableIRIn();
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(remot.decode(&data_remot)==1)
 {
  Serial.println(data_remot.value);
  remot.resume();
 }

}
