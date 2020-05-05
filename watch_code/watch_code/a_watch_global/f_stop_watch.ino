void stopwatch()
{  
      int count=0;
      int secnd=0;
      int minte=0;
   start:display.clearDisplay();
  if(digitalRead(15)==0)
 {delay(100);
  st=!st;
 }
 
  if(digitalRead(16)==0)
  {delay(100);
    count=0;secnd=0;minte=0;}
  
  if(st==1)
  {  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(52,0);
  display.println("st/sp");
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(52,40);
  display.println("reset");
  display.display();
  delay(1);

    
   display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,19);
  if(count==100)
  {
    count=0;
    secnd=secnd+1;
    Serial.println(secnd);
  }
 
   if(secnd==60)
  {
    secnd=0;
    minte=minte+1;
  }
  display.print(minte);
  display.print(":");
  if(secnd<10)
  display.print("0");
  display.print(secnd);

  display.print(":");
  if(count<10)
  display.print("0");
  display.print(count);
  display.display();
  delay(2);
  delayMicroseconds(700);
  count=count+4;
  goto start;
  }

  if (st==0)
  {
     display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(52,0);
  display.println("st/sp");
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(52,40);
  display.println("reset");
  display.display();
  delay(1);

    
   display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,19);
  if(count==100)
  {
    count=0;
    secnd=secnd++;
    
  }
 
   if(secnd==60)
  {
    secnd=0;
    minte=minte++;
  }
  display.print(minte);
  display.print(":");
  if(secnd<10)
  display.print("0");
  display.print(secnd);

  display.print(":");
  if(count<10)
  display.print("0");
  display.print(count);
  display.display();
  delay(10);
   if(digitalRead(2)==0)
   back=1;
   if(back==1)
   {back=0;
    menu(); 
   }
  goto start;
  }
}
