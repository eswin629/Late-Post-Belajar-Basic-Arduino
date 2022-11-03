#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define OUT_PIN_GREEN 6
#define OUT_PIN_RED 7
#define NUMBER_OF_KEYS 2

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Array mit den zugelassenen RFID-UIDs
static unsigned short code[NUMBER_OF_KEYS][4] = { {100, 200, 300, 400},{111, 222, 333, 444} };

void setup()
{

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode (OUT_PIN_GREEN, OUTPUT);
  pinMode (OUT_PIN_RED, OUTPUT);

}


void loop()
{
  // Wenn eine RFID-Karte in der Nähe ist:
  if (mfrc522.PICC_IsNewCardPresent())
  {
    unsigned short doOpen = checkID();
    if (doOpen != 0) {

      digitalWrite (OUT_PIN_GREEN, HIGH);
      delay (5000);
      digitalWrite (OUT_PIN_GREEN, LOW);
    }else{

      digitalWrite (OUT_PIN_RED, HIGH);
      delay (5000);
      digitalWrite (OUT_PIN_RED, LOW);
    }
  }

}

/**
   mfrc522.PICC_IsNewCardPresent() muss zuvor überprüft werden.
   @return 0 wenn false, 1 wenn true
*/
unsigned short checkID() {
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }

  Serial.print("Groesse: "); Serial.println(mfrc522.uid.size);
  Serial.print("UID 1: "); Serial.println( mfrc522.uid.uidByte[0]);
  Serial.print("UID 2: "); Serial.println( mfrc522.uid.uidByte[1]);
  Serial.print("UID 3: "); Serial.println( mfrc522.uid.uidByte[2]);
  Serial.print("UID 4: "); Serial.println( mfrc522.uid.uidByte[3]);

  short doOpen = 0, i;
  for(i=0; i<NUMBER_OF_KEYS; i++){
    if(mfrc522.uid.uidByte[0]==code[i][0] && mfrc522.uid.uidByte[1]==code[i][1] && mfrc522.uid.uidByte[2]==code[i][2] && mfrc522.uid.uidByte[3]==code[i][3]){
      doOpen = 1;
      Serial.println("Code akzeptiert!");
      break;
    }
  }
  
  mfrc522.PICC_HaltA(); // Stop reading
  return doOpen;
}
