#include <LiquidCrystal.h> //llama libreria
LiquidCrystal lcd (7,6,5,4,3,2); //objeto lcd con los pines (RS,E,D3,D2,D1,D0)

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //indica el tamano lcd (16 columnas y 2 lineas)
}
void loop() {
  // put your main code here, to run repeatedly:
  //lcd.setCursor(0,0); //Para indicar el cursor escribir (columna,fila)
  //lcd.print("Hola, han pasado"); //Para escribir el texto
  //lcd.setCursor(0,1); //Para escribir en la siguiente linea
  //lcd.print(millis() / 1000);// millis es para devolver el tiempo en milisegundos y se divide en mil para que sea en segundos
  //lcd.print("seg.");//Para mostrar el texto 
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Bienvenido al");
  lcd.setCursor(1,1);
  lcd.print("elevador par");
  delay (5000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Ha que piso");
  lcd.setCursor(2,1);
  lcd.print("desea llegar");
  delay (5000);
  lcd.clear();
  lcd.setCursor(1,0); 
  lcd.print("Hemos llegado");
  lcd.setCursor(3,1); 
  lcd.print("Al piso 6");
  delay (5000);


  
}
