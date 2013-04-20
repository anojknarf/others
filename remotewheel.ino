void setup()  
 {  
  pinMode(15,INPUT); // TSOP is connected on the 15ht pin  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);  
 }  
 void loop()  
 {  
  int rermote_val = remote();  
  if(rermote_val>0)  
  {  
   Serial.println(rermote_val);  
   delay(200); // A remote press will normally generate 3 signal trains. This is to avoid reading duplicates  
  if(rermote_val==191)
  digitalWrite(4,HIGH);
  else if(rermote_val==184)
  digitalWrite(5,HIGH);
  else if(rermote_val==186)
  {digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);}
    else
  {digitalWrite(4,LOW);
   digitalWrite(5,LOW);
  }
  }  
  }  
 int remote()  
 {  
  int value = 0;  
  int time = pulseIn(15,LOW);  
  if(time>2000) // Checking if the Start Bit has been received. Start Bit Duration is 2.4ms  
  {  
   for(int counter1=0;counter1<12;counter1++) // A loop to receive the next 12 bits  
   {  
    if(pulseIn(15,LOW)>1000) // checking the duration of each pulse, if it is a '1' then we use it in our binary to decimal conversion, '0's can be ignored.  
    {  
     value = value + (1<< counter1);// binary to decimail conversion. 1<< i is nothing but 2 raised to the power of i  
    }  
   }  
  }  
  return value;  
 }  
