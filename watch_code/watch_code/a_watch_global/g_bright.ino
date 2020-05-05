void pointer(int w)
{
   if(digitalRead(15)==0)
     {if(h==w)
     h=1;
     else
     h++; 
     delay(100);
     }
     if(digitalRead(16)==0)
     {if(h==1)
     h=w;
     else
     h--;
     delay(100);
     }
}

void brightness()
{
     // int h=1;

xy:     display.clearDisplay();
    delay(10);
    
    pointer(2);
  if(h==2)
  {
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,8);
  display.println("BRIGHTNESS");
  display.display();
  //delay(90);
  display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,24);
  display.println("CONTRAST");
  display.display();
  delay(9);
  if(modee()==1)
  { 
  htwo:    
   display.clearDisplay();   
   display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,32);
  display.print("VALUE = ");
  display.print(c_level);
  display.display();
   display.setContrast(c_level);
 // pointer();
  if(inc()>dec())
  c_level+=2;
  if(inc()<dec())
  c_level-=2;
  if(backk()==1)
  goto xy;
  else
  goto htwo;
  }
  }
  if(h==1)
  {
  display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,8);
  display.println("BRIGHTNESS");
  display.display();
  //delay(90);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,24);
  display.println("CONTRAST");
  display.display();
  delay(90);
  if(modee()==1)
  {
  hone: 
    display.clearDisplay(); 
    display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,16);
  display.print("VALUE = ");
  display.print(b_level);
  display.display();
  analogWrite(9,b_level);
  //pointer();
 
  if(inc()>dec())
  { if(b_level==250)
   b_level=0;
   else
  b_level+=10;
  }
  if(inc()<dec())
  {if(b_level==0)
   b_level=250;
   else
  b_level-=10;
  }
  if(backk()==1)
  goto xy;
  else
  goto hone;
  }

  }
if(backk()==1)
    menu();
  goto xy;
}
