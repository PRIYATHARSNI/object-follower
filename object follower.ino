#define trigF 2
#define echoF 3
#define trigS 4
#define echoS 5

#define in1 6
#define in2 7
#define in3 8
#define in4 9

long durationF, distanceF;
long durationS, distanceS;

void setup() {
  pinMode(trigF, OUTPUT);
  pinMode(echoF, INPUT);
  pinMode(trigS, OUTPUT);
  pinMode(echoS, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  
  // Test Motor A (left motor)
	//digitalWrite(in1, HIGH);
	//digitalWrite(in2, LOW);

// Test Motor B (right motor)
	//digitalWrite(in3, HIGH);
	//digitalWrite(in4, LOW);

  Serial.begin(9600);
}

void loop() {
  // FRONT SENSOR
  digitalWrite(trigF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigF, LOW);
  durationF = pulseIn(echoF, HIGH);
  distanceF = durationF * 0.034 / 2;

  // SIDE SENSOR
  digitalWrite(trigS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigS, LOW);
  durationS = pulseIn(echoS, HIGH);
  distanceS = durationS * 0.034 / 2;

  Serial.print("Front: ");
  Serial.print(distanceF);
  Serial.print(" cm\t Side: ");
  Serial.print(distanceS);
  Serial.println(" cm");

  if (distanceF < 15 && distanceS > 10) {
    // Move Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else {
    // Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  delay(300);
}