
//Déclaration

long portPushButton    = 13;  // Affectation port
//long portLED           = 2; // Port du LEd  
long portHP           = 2; // Port du LEd  


//Initialisation 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(portPushButton, INPUT_PULLUP);
  noTone(portHP);
  //pinMode(portLED, OUTPUT);
  //digitalWrite(portLED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Jappuie rien");

  if(digitalRead(portPushButton) == LOW){
    Serial.println("Jappuie le bouton");
    if(test()){
      Serial.println("Jappuie dois relacher le bouton");
      //digitalWrite(portLED, HIGH);
      tone(portHP, 10000);
    }
  }
  
  delay(1000);
  //digitalWrite(portLED, LOW);
  noTone(portHP);
 }

bool test(){
  for(int i=1; i<=5; i++)
  {
    if(digitalRead(portPushButton) == HIGH){
      Serial.println("Je suis relaché");
      return false;
    }
    Serial.println(i);
    delay(1000);
  }
  return true;
}
