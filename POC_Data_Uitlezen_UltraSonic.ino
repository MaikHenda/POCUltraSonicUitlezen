
 //  Ultrasonic sensor Pins:
 //       VCC: +5VDC
 //       Trig : Trigger (INPUT) - Pin11
 //       Echo: Echo (OUTPUT) - Pin 12
 //        GND: GND
 
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Defineer inputs en outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // De sensor wordt getriggerd door een high pulse van 10 of meer microseconden.
  // Ik geef een korte low pulse door om te verzekeren dat ik een clean high pulse krijg.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Lees het signaal van de sensor: een HIGH puls waarvan
  // Lees het signaal van de ultrasone sensor.
  // duur de tijd is (in microseconden) vanaf het verzenden
  // van de ping tot de ontvangst van de echo van een object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Zet de tijd om in een afstand
  cm = (duration/2) / 29.1;     // Delen door 29,1 of vermenigvuldigen met 0,0343
  inches = (duration/2) / 74;   // Delen door 74 of vermenigvuldigen met 0,0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
