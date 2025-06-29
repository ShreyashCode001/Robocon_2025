void feedrelay() {
  if (ps5.Down()) {
    digitalWrite(feed_relay, HIGH);  // high input >> Active low input >> relay off >> for piston ON >> Normally closed circuit
    Serial.println("Feed piston ON");
  } else {
    digitalWrite(feed_relay, LOW); // Low input >> Active low input >> relay ON >> for piston OFF >> Normally closed circuit
    Serial.println("Feed piston OFF");
  }
}