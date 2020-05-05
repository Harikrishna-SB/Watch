void setup()   {
  pinMode(A3,OUTPUT);
  analogWrite(9,b_level);
  Serial.begin(9600);
//  attachInterrupt(digitalPinToInterrupt(2),isr,LOW);
  //Initialize Display

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    
  }
 // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  display.begin();
  

  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(57);
 randomSeed(analogRead(3));
  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,17);
  display.println("ELECTRO");
  display.display();
  delay(900);
  display.clearDisplay();
}
