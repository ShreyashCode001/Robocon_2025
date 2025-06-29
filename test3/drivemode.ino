void drivemode() {
  
  if (Ly > 30)  //fwd
  {
    z = mapping(Ly);
    drivelogic(6, z);
  } else if (Ly < -30)  //back
  {
    z = mapping(Ly);
    drivelogic(7, z);
  } else if (Lx < -30)  //left
  {
    z = mapping(Lx);
    drivelogic(1, z);
  } else if (Lx > 30)  //right
  {
    z = mapping(Lx);
    drivelogic(2, z);
  } else if (Rx > 30)  //clockwise
  {
    z = mapping(Rx);
    drivelogic(3, z);
  } else if (Rx < -30)  //anticlockwise
  {
    z = mapping(Rx);
    drivelogic(4, z);
  } else if (z > 0)  //stop (starts stoping gradually)
  {
    z = -10;
    drivelogic(5, z);
    delay(100);
  } else  //finally stops 
  {
    z = 0;
    drivelogic(5, z);
  }
}
