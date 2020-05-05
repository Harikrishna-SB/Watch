void date_time()
{
   DateTime now = rtc.now();
 
      seconds=now.second();
      hours=now.hour();
      days=now.day();   
      minutes=now.minute();
      months=now.month();
      years=now.year();

      Serial.print(days);Serial.print("d  ");Serial.print(hours);Serial.print("hrs  ");Serial.print(minutes);
      
      Serial.print("mins  ");Serial.print(seconds);Serial.println("sec");

    //  delay(950);
    if(alarm==0)
    {
      display.setTextColor(BLACK); // 'inverted' text
  display.setCursor(18,10);
  display.setTextSize(1);
  display.print(hours);
  display.print(":");
  display.print(minutes);
  display.print(":");
  display.print(seconds);
  display.display();
  

   display.setTextColor(BLACK); // 'inverted' text
  display.setCursor(15,25);
  display.setTextSize(1);
  display.print(days);
  display.print("/");
  display.print(months);
  display.print("/");
  display.print(years);
  display.display();
  delay(900);
  display.clearDisplay();
    }
}
