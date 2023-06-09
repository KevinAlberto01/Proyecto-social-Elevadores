
#include <Servo.h> //librerias

Servo servo; //se declara un objeto 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //iniciamos el codigo serial 
  servo.attach(8); //se declara el pin del servo

}

void loop() {

    for(int i=0;i<180;i++){ //se definen las rotaciones
      servo.write(i);
      delay (5);
    }
    delay(100);
    for(int i=180;i>0;i--){//se definen las rotaciones
      servo.write(i);
      delay (5);
    }
    delay(100);
  
}
