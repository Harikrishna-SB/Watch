void going_to_sleep()
{Serial.println("going to sleep");
  sleep_enable();//enabling sleep mode
  attachInterrupt(0,wakeup,LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  delay(1000);
  sleep_cpu();

  Serial.println("wokeup");
}


void wakeup()
{
  Serial.println("interrupt fired");
  sleep_disable();
  detachInterrupt(0);
}
