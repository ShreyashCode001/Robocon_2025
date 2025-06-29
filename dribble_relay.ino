void dribblerelay() {
  if (ps5.Up()) {
    digitalWrite(dribble_relay, HIGH); // high input >> Active low input >> relay off >> for piston ON >> Normally closed circuit
    Serial.println("Dribble piston ON");
  } else {
    digitalWrite(dribble_relay, LOW);  // Low input >> Active low input >> relay ON >> for piston OFF >> Normally closed circuit
    Serial.println("Dribble piston OFF");
  }
}