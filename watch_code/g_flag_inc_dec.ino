int modee()
{
  if(digitalRead(14)==0)
  {
    delay(100);
     return 1;
  }
  else 
    return 0;
}

int inc()
{
  if(digitalRead(15)==0)
  {
    delay(100);
    return 1;
  }
  else 
  return 0;
}

int dec()
{
  if(digitalRead(16)==0)
  {
    delay(100);
    return 1;
  }
  else 
  return 0;
}

int backk()
{
  if(digitalRead(2)==0)
  {
    delay(100);
    return 1;
  }
  else 
  return 0;
}
