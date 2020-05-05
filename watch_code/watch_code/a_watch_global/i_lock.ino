void advanced_setting()
{
  delay(100);
  locky();
}
void locky()
{
  float  x = random(10000, 100000) ; // this is the number you want to convert
Serial.println(x);
int  v[4] ;          // this is the result.   The least significant digit goes in position 0
int i=0 ;            // index
int y ;
while ( x > 0 )
{
    y=x/10 ;
    v[4-i] = x-(10*y) ;
    x=y ;
    i++ ;
}
for(int k=0;k<5;k++)
{
Serial.println(v[k]);
}
  delay(500);
//   Serial.println();
  for(int i=0;i<=4;i++)
  {//Serial.println("hello ");
    for(int j=0;j<=4;j++)
    { if(v[i]<j)
     lock[i][j]=(10+v[i]-j+i);
     else
     lock[i][j]=(v[i]-j+i);
     delay(1);
     lock[i][j]=lock[i][j]%10;
     Serial.print(lock[i][j]);
     delay(2);
     Serial.print(" ");
    }
    Serial.println();
    delay(2);
  }
  
Serial.println("hello ");
//delay(1000);
for(int i=0;i<5;i++)
 {
  for(int j=0;j<5;j++)
  {
   // lock[j][i]=lock[i][j];
    Serial.print(lock[j][i]);
    delay(5);
    Serial.print(" ");
  }
  Serial.println();
 }
  Serial.println();
 
int unlo=lock[0][0]+lock[1][1]+lock[2][2]+lock[3][3]+lock[4][4];
int unlock[]={unlo,unlo+lock[1][1],unlo+lock[2][2]+lock[1][1],unlo+lock[3][3]+lock[1][1]+lock[2][2],unlo+lock[4][4]+lock[1][1]+lock[2][2]+lock[3][3]};
for(int i=0;i<5;i++)
{
unlock[i]=unlock[i]%10;
un[i]=unlock[i];
Serial.print(unlock[i]);
Serial.print(" ");
}
matrix();
}
void matrix()
{ 
 h=1;
Serial.println();
top:
 if(h==6)
 {
  display.clearDisplay();  
display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,0);
  display.println("PROCESSING....");
 // display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(4,24);
  display.println(">");
  display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(72,24);
  display.println("<");
  //display.display();
  display.setTextColor(BLACK);
for(int i=0;i<5;i++)
 {
  for(int j=0;j<5;j++)
  { if(j!=(h-1))
  {
    delay(1);
    display.setCursor((14+j*12),(8+i*8));
    display.print(lock[j][i]);
   // display.display();
  }
  }
 // Serial.print(" ");
 }
 display.display();
 delay(1000);
 display.clearDisplay();
 bool pass=1;
 int passcode[]={lock[0][2],lock[1][2],lock[2][2],lock[3][2],lock[4][2]};
for(int k=0;k<5;k++)
{
  if(passcode[k]!= un[k])
   pass=0;
  
}
if(pass==1)
{goto unlock;
Serial.print("unlocked");
}
  else
  goto lock;
  Serial.print("Access Denied");
 
 }

display.clearDisplay();  
display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("ENTER PIN :");
 // display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(4,24);
  display.println(">");
  display.setTextSize(1);
  display.setTextColor(WHITE,BLACK);
  display.setCursor(72,24);
  display.println("<");
  //display.display();
  display.setTextColor(BLACK);
for(int i=0;i<5;i++)
 {
  for(int j=0;j<5;j++)
  { if(j!=(h-1))
  {
    delay(1);
    display.setCursor((14+j*12),(8+i*8));
    display.print(lock[j][i]);
   // display.display();
  }
  }
 // Serial.print(" ");
 }

  for(int i=0;i<5;i++)
  {if(i==2)
  {
    delay(1);
    display.setTextColor(WHITE,BLACK);
    display.setCursor((14+(h-1)*12),(8+i*8));
    display.print(lock[(h-1)][i]);
   // display.display();
  }
  else
  {
    delay(1);
    display.setTextColor(BLACK);
    display.setCursor((14+(h-1)*12),(8+i*8));
    display.print(lock[(h-1)][i]);
    display.display();
  }
  }
 
  pinv=inv;
  poll: 
  point(6);
  if(inc()>dec())
  { inv=!inv;
    for(int i=0;i<5;i++)
    lock[h-1][i]=(lock[h-1][i]+1)%10;
     }
  if(inc()<dec())
  { inv=!inv;
    for(int i=0;i<5;i++)
    {if(lock[h-1][i]==0)
    lock[h-1][i]=10;
    lock[h-1][i]=(lock[h-1][i]-1)%10;
    }
  }
  if(pinv!=inv)
goto top;
else
goto poll;
lock:
   display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,10);
  display.println("ACCESS");
  display.setCursor(0,26);
  display.println("DENIED");
  display.display();
  delay(2000);
  menu();
unlock:
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK);
 display.setCursor(0,10);
  display.println("ACCESS");
  display.setCursor(0,26);
  display.println("GRANTED");
  display.display();
  delay(1000);
 // settings();
  
}
void point(int w)
{
   if(digitalRead(14)==0)
     {if(h==w)
     h=1;
     else
     h++; 
     inv=!inv;
     delay(100);
     }
    
     }
