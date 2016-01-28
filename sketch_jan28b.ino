const int R_PIN = 3;
const int G_PIN = 5;
const int B_PIN = 6;
const int B2_PIN = 9;
const int R2_PIN = 11;
int count = 0;

void light() {
  digitalWrite(R_PIN, (count & 0b001) ? HIGH : LOW);
  digitalWrite(G_PIN, (count & 0b010) ? HIGH : LOW);
  digitalWrite(B_PIN, (count & 0b100) ? HIGH : LOW);
  digitalWrite(B2_PIN, (count & 0b1000) ? HIGH : LOW);
  digitalWrite(R2_PIN, (count & 0b10000) ? HIGH : LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(R_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B2_PIN, OUTPUT);
  pinMode(R2_PIN, OUTPUT);
}

void loop() {
  count = (count + 1) % 31;
  light();
  delay(100);
}

