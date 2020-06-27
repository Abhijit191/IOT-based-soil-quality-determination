#define s0 8        
#define s1 9
#define s2 10
#define s3 11
#define out 12

int Red=0, Blue=0, Green=0;   

void setup() 
{
   pinMode(s0,OUTPUT);    
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);

   Serial.begin(9600);   
   
   digitalWrite(s0,HIGH); 
   digitalWrite(s1,HIGH); 
   
}

void loop(){
 
  GetColors();                                     
                                                   

//  if (Red <=15 && Green <=15 && Blue <=15)         
//      Serial.println("White");                    
      
// phosphorous recognition of color is done
   if (Blue<Green && Blue<Red && Blue<=26 && Blue>=13)    
      Serial.println("phosphorous is HIGH");

  else if (Blue<Green && Blue<Red && Blue<=13 && Blue>=8)
      Serial.println("phosphorous is Medium");

  else if (Blue<Green && Blue<Red && Blue<=8 && Blue>=6)
      Serial.println("phosphorous is Low");

  else if (Blue<Green && Blue<Red && Blue<=6)
      Serial.println("phosphorous is Very Low");

  //nitrogen recognition of color
      
  else if (Red<Blue && Blue<Green && Green<=27 && Green>=21 )
      Serial.println("Nitrogen is High");

  else if (Red<Green && Blue<Green && Green<=16 && Green>=9)
      Serial.println("Nitrogen is Medium");

  else if (Red<Green && Blue<Green && Green<=9)
      Serial.println("Nitrogen is Low");

  // potash recognition of color
  
  else if (Red<Blue && Red<Green && Red<=21 && Red>=16 )
      Serial.println("potash is high");

  else if (Red<Blue && Red<Green && Red<=16 && Red>=6 )
      Serial.println("potash is medium");

//  else if (Red<Blue && Red<Green && Red<=16 && Red>=12 )
//      Serial.println("potash is low");

      
  else if (Green<Red && Green-Blue<= 8)           
      Serial.println("Green");                   

  else
     Serial.println("Unknown");                  


  delay(2000);                                   
  
  
  
}


void GetColors()  
{    
  digitalWrite(s2, LOW);                                          
  digitalWrite(s3, LOW);                                           
  Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);      
  delay(20);  
  digitalWrite(s3, HIGH);                                         
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  
  digitalWrite(s2, HIGH);  
  Green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  
}
