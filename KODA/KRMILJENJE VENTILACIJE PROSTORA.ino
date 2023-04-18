#define swVklop 7
#define swMode 6
#define nmos 5
#define pot A1
#define temp A2
#define zelena 4
#define rdeca 3

void setup()
{
  pinMode(swVklop, INPUT);
  pinMode(swMode, INPUT);
  pinMode(pot, INPUT);
  pinMode(temp, INPUT);
  pinMode(nmos, OUTPUT);
  pinMode(zelena, OUTPUT);
  pinMode(rdeca, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(swVklop) == HIGH) //vklop
  {
    if(digitalRead(swMode) == HIGH) //ročno
  {
      digitalWrite(rdeca, HIGH);
      digitalWrite(zelena, LOW);
      int potVal = analogRead(pot);
      int hitrost = 1023 - potVal;
      digitalWrite(nmos, HIGH);
      delayMicroseconds(hitrost);
      digitalWrite(nmos, LOW);
      delayMicroseconds(potVal);
    }
    else if (digitalRead(swMode) == LOW) //avtomatsko
    {
      digitalWrite(zelena, HIGH);
      digitalWrite(rdeca, LOW);
      int tempVal = analogRead(temp);
      float tempHitrost = tempVal*5;
      tempHitrost /= 1023;
      float temperatura =(tempHitrost-0.5)*100;
      if(temperatura <= 25)
      {
    analogWrite(nmos,50); //nizka hitrost
   }
      else if(temperatura>25 && temperatura<50)
      {
    analogWrite(nmos,100); //srednja hitrost
      }
      else
      {
    analogWrite(nmos,255); //polna hitrost
   }
    }
  }
  else
  {
  digitalWrite(nmos, LOW);
  digitalWrite(zelena, LOW);
  }
}
