#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

static const uint8_t PIN_MP3_TX = 2;  
static const uint8_t PIN_MP3_RX = 3;  
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
int switches[] = {2, 3, 4};
int tracks[] = {1, 2, 3};
DFRobotDFPlayerMini player;

void setup() 
{

  Serial.begin(9600);
  softwareSerial.begin(9600);
    for (int i = 0; i < 3; i++) 
    {
      pinMode(switches[i], INPUT); // Set each pin as input
    }
  if (player.begin(softwareSerial)) {
    Serial.println("OK");
 
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

/*void loop() 
{  
  if (digitalRead(switches[0]) == LOW)
  {
        Serial.print("Switch-");
        Serial.print("1");
        Serial.println("-pressed");
        player.volume(30);
        player.play(1);
        delay(9000); 
  }  
  else if (digitalRead(switches[1]) == LOW)
  {
        Serial.print("Switch-");
        Serial.print("2");
        Serial.println("-pressed");
        player.volume(30);
        player.play(2);
        delay(9000); 
  }  
   else if (digitalRead(switches[2]) == LOW)
  {
        Serial.print("Switch-");
        Serial.print("3");
        Serial.println("-pressed");
        player.volume(30);
        player.play(3);
        delay(9000); 
  }  
  else
  {
    Serial.print("invalid");
  }
}*/
void loop() 
{  
  for (int i = 0; i < 3; i++) {
    if (digitalRead(switches[i]) == LOW) {
      Serial.print("Switch-");
      Serial.print(i + 1);
      Serial.println("-pressed");
      player.play(i + 1);
      delay(3000); 
    }
  }
}
