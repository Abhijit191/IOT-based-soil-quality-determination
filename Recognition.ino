#define s0 8        //Module pins wiring
#define s1 9
#define s2 10
#define s3 11
#define out 12

int Red=0, Blue=0, Green=0;  //RGB values 

void setup() 
{
   pinMode(s0,OUTPUT);    //pin modes
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);

   Serial.begin(9600);   //intialize the serial monitor baud rate
   
   digitalWrite(s0,HIGH); //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100% (recommended)
   digitalWrite(s1,HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is  2%
   
}

void loop(){
 
  GetColors();                                     //Execute the GetColors function to get the value of each RGB color
                                                   //Depending of the RGB values given by the sensor we can define the color and displays it on the monitor

//  if (Red <=15 && Green <=15 && Blue <=15)         //If the values are low it's likely the white color (all the colors are present)
//      Serial.println("White");                    
      
// phosphorous recognition of color
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

      
  else if (Green<Red && Green-Blue<= 8)           //Green it was a little tricky, you can do it using the same method as above (the lowest), but here I used a reflective object
      Serial.println("Green");                    //which means the blue value is very low too, so I decided to check the difference between green and blue and see if it's acceptable

  else
     Serial.println("Unknown");                  //if the color is not recognized, you can add as many as you want


  delay(2000);                                   //2s delay you can modify if you want
  
  
  
}


void GetColors()  
{    
  digitalWrite(s2, LOW);                                           //S2/S3 levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH is for Blue and HIGH/HIGH is for green 
  digitalWrite(s3, LOW);                                           
  Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);       //here we wait until "out" go LOW, we start measuring the duration and stops when "out" is HIGH again, if you have trouble with this expression check the bottom of the code
  delay(20);  
  digitalWrite(s3, HIGH);                                         //Here we select the other color (set of photodiodes) and measure the other colors value using the same techinque
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  
  digitalWrite(s2, HIGH);  
  Green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  
}

//Here's an example how to understand that expression above,
//""digitalRead(out) == HIGH ? LOW : HIGH"" this whole expression is either HIGH or LOW as pulseIn function requires a HIGH/LOW value on the second argument

//led_Status = led_Status == HIGH ? LOW : HIGH;  
//
//if(led_Status == HIGH) 
//{ 
//led_Status =LOW; 
//} 
//else 
//{ 
//led_Status = HIGH; 
//}
