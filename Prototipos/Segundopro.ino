#include <SPI.h> //librerias
#include <MFRC522.h> //librerias
#include <Servo.h> //librerias
#include <LiquidCrystal.h> //llama libreria


#define RST_PIN 9 //variables
#define SS_PIN 10 //variables
#define ledV  11 //variables
#define ledR  12 //variables
MFRC522 mfrc522(SS_PIN, RST_PIN); //crean el objeto con las dos constantes
byte LecturaUID[4];//almacena el valor leido 
byte acceso[4]={0xA3, 0x86, 0x68, 0xAD}; // tarjeta con accesso 
Servo servo; //se declara un objeto 
LiquidCrystal lcd (7,6,5,4,3,2); //objeto lcd con los pines (RS,E,D3,D2,D1,D0)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //iniciamos el codigo serial 
  SPI.begin(); // 
  mfrc522.PCD_Init(); //inia el modulo lector
  Serial.println("Listo"); //para poder mostrar que esta listo 
  pinMode(ledV,OUTPUT); //se declara como salida
  pinMode(ledR,OUTPUT); //se declara como salida 
  servo.attach(8); //se declara el pin del servo
  lcd.begin(16,2); //indica el tamano lcd (16 columnas y 2 lineas)
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  digitalWrite(ledV,LOW); //prende verde
  digitalWrite(ledR,LOW); //apaga rojo
  lcd.setCursor(1,0);
  lcd.print("Bienvenido al");
  lcd.setCursor(1,1);
  lcd.print("elevador par");
  if(! mfrc522.PICC_IsNewCardPresent()) //condicional para ver si esta presente cerca 
    return;

  if (!mfrc522.PICC_ReadCardSerial()) //obtener la informacion de la tarjeta
    return;

  Serial.print("UID:"); //texto 
  for(byte i = 0; i < mfrc522.uid.size; i++){ //obtener el identificador unico (mfrc522 tiene una funcion que permite obtener el tamano del uid de 4 bits pero hay de 7 bits ) 
    if(mfrc522.uid.uidByte[i] < 0x10){ //consulta y checa si es menor a 10 en hexa 
      Serial.print(" 0");//se agrega un 0 y un espacio en blanco 
    }
    else{
      Serial.print(" "); //separar el bite 
    }
    Serial.print(mfrc522.uid.uidByte[i],HEX); //guarda el texto y los guarda en hexadeciamal 
    LecturaUID[i]=mfrc522.uid.uidByte[i]; //almacena el codigo en la variable 
  }
  Serial.println("\t"); //Dejara un espacio de tabulacion entre el uid y el texto que sigue
  if (comparaUID(LecturaUID, acceso)){ //llama la funcion comparaUID para poder comprar 
    //PONER AQUI TODAS LAS ACCIONES QUE SE QUIERE REALIZAR 
    Serial.println("Verde - Tiene acceso");
    digitalWrite(ledV,HIGH); //prende verde 
    digitalWrite(ledR,LOW);//apaga rojo 
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
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Bienvenido al");
    lcd.setCursor(1,1);
    lcd.print("piso 6");
    delay (5000);
  }
  else{
    //PONER AQUI TODAS LAS ACCIONES QUE SE QUIERE REALIZAR 
    Serial.println("Rojo - No tiene acceso");
    digitalWrite(ledV,LOW); //prende verde
    digitalWrite(ledR,HIGH); //apaga rojo
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("No tiene acceso");
    lcd.setCursor(1,1);
    lcd.print("------");
    //delay(1000);
  mfrc522.PICC_HaltA(); //llamar la funcion para indicar que no obtenga mas informacion 
    delay (5000);
  }
}
  
boolean comparaUID(byte lectura[], byte acceso[]){ //declaramos el nombre utiliza las variables localares
  for (byte i=0; i < mfrc522.uid.size; i++){
   if(lectura[i] != acceso[i]){ //compara los accesos
    return (false);
   }
   return(true);
  }
}
