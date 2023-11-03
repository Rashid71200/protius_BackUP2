const int ledPin =  13;  // Built-in LED
const int EnTxPin =  2;  // HIGH:Transmitter, LOW:Receiver
void setup() 
{ 
  Serial.begin(9600);
  Serial.setTimeout(100);  
  pinMode(ledPin, OUTPUT);
  pinMode(EnTxPin, OUTPUT);
  digitalWrite(ledPin, LOW); 
  digitalWrite(EnTxPin, HIGH);
  pinMode(4, OUTPUT); 
  digitalWrite(4, LOW);
} 
 
void loop() 
{   

  
  digitalWrite(EnTxPin, LOW); //RS485 as receiver

  if(Serial.find("I"))
  {
    
      int data=Serial.parseInt(); 
      if(Serial.read()=='F') //finish reading
       {
         onLED(data);  
                 
      }
      
  }
  digitalWrite(EnTxPin, HIGH); //RS485 as transmitter
  
} 

void onLED(int data)
{
  if(data>170){
         digitalWrite(ledPin, HIGH); 
     digitalWrite(4, HIGH);
  }

  else {
         digitalWrite(ledPin, LOW); 
     digitalWrite(4, LOW);
  }

}