#include <VirtualWire.h>

int controller = 0;
char* chardata;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(10);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  controller = digitalRead(12);
  if(controller == 1){
    digitalWrite(13, HIGH);
    chardata = "1";
  }
  else{
    digitalWrite(13, LOW);
    chardata = "0";
  }
  vw_send((uint8_t *)chardata, strlen(chardata));
  vw_wait_tx(); // Wait until the whole message is gone
}
