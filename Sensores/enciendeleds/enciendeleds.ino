int ledV = 11;
int ledR = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledV,OUTPUT);
  pinMode(ledR,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledV,HIGH);
  delay(1000);
  digitalWrite(ledV,LOW);
  delay(1000);
  digitalWrite(ledR,HIGH);
  delay(1000);
  digitalWrite(ledR,LOW);
  delay(1000);
}
