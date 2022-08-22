 int i;
 int IRpin = 0;
 int LED = 3;

 int n = 12;
 int sample[12];
 int value = 0;  
 int count;

void setup() 
{
     pinMode(IRpin,INPUT);
     pinMode(LED,OUTPUT);
     Serial.begin(9600);
}

void loop() 
{
    value = 0;

    int j;
    for(j=0; j<n; j++)
    {
       i = analogRead(IRpin);
       sample[j] = i;
       delay(50);      
    }
    
    count=0;
    for(j=0; j<n; j++)
    {
      value += sample[j];
      
      if(sample[j]>150) {  count++; }           
    }
  
    value /= n;
    Serial.println(value);

   
 
  if(count<=2)
  {}

  else if (count<=5)
  {
    analogWrite(LED, LOW);
  }
  

  else
  {  
    if ((value < 650) && (value >= 480))
    {
      analogWrite(LED, 255);
      //delay(30);
    }
     
    else if ((value < 500) && (value >= 400))
    { 
      //for (int k=255 ; k >= 190; k -= 5) 
      {
        analogWrite(LED, 180);
        //delay(30);
      }
    }

    else if ((value < 400) && (value >= 300))
    {
      //for (int k=190 ; k >= 125; k -= 5)
      {
        analogWrite(LED, 105);
        //delay(30);
      }
    }

    else if ((value < 300) && (value >= 180))
    {
      //for (int k=125 ; k >= 160; k -= 5) 
      {
        analogWrite(LED, 30);
        //delay(30);
      }

    }
  }  
 }
