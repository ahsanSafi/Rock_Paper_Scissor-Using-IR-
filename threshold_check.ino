int ifread1, ifread2;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  Serial.println("Sensor Ready. Monitoring...\n");
}

void loop() {
  ifread1 = analogRead(A0);
  ifread2 = analogRead(A2);
  Serial.println(A0);
  Serial.println(A2);
  delay(1000); 
}