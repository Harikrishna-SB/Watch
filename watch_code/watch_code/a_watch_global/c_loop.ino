
void loop() {
  
going_to_sleep();
for(i=0 ;i<10;i++)
{
date_time();

if(modee()==1)
{
  flag=1;
}
if(flag==1)
{
  Serial.print("mode");
  delay(400);
  flag=0;
  //void mod();
  menu(); 
  //i=10;
}
}  
}



void menu()
{{
  gh: 
 display.clearDisplay();

  for(int j=0;j<6;j++)
 {
  if(j!=(m-1)) 
  {
display.setTextColor(BLACK);
display.setCursor(0,(8*j));
display.setTextSize(1);
for(int k=0;k<14;k++)
display.print(mode[j][k]);
display.println("");
display.display();
delay(1);
  }
else
 { 

 display.setTextColor(WHITE,BLACK); 
 display.setCursor(0,(8*(m-1)));
 display.setTextSize(1);
 for(int k=0;k<14;k++)
 display.print(mode[m-1][k]);
 display.display();
 delay(1);
 }
 }
 lb: 
  p=m;
if(inc()>dec())
  {delay(200);
    m++;
  if(m==7)
  m=1;}
//if(digitalRead(15)<digitalRead(16))
if(inc()<dec())
 {delay(200);
  m--;
  if(m==0)
  m=6;}
 // modee(flag);
 if(modee()==1)
{ delay(1000);
 flag=1;
}
if(flag==1)
 { flag=0;
  goto sw;
 }
  if(m!=p)
  goto gh;
 goto lb;
}
sw:
      switch (m) {
  case 1:
    //stop_watch
    {  
      stopwatch();
    }
     break;
  case 2:
  {
    //count_down();
  }
    break;
  case 3:
  { 
    brightness();
  }break;
   case 4:
    {
      //alarm();
    }
    break; 
   case 5:
    //snake();
    break;
  case 6:
    advanced_setting();
    break;  
  default:
    // if nothing else matches, do the default
    // default is optional
    break;

  
  }}
