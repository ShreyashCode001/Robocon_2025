void relay()   //gripper
{
  
    // L1 Button Controls Relay 1 jaw open
    if (ps5.Up()) 
    {
      digitalWrite(relay1, LOW);
      Serial.println("Open");
    } else 
    {
      digitalWrite(relay1, HIGH);
    }

    // L2 Button Controls Relay 2
    if (ps5.Down()) 
    {
      digitalWrite(relay2, LOW);
      Serial.println("Close");
    } else 
    {
      digitalWrite(relay2, HIGH);
    }
  
}