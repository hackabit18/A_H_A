
int c,b=0,store=0;
String x="",h="",servo;
int y=0,z=0;
const int lederror1=A5;
const int lederror2=A4;
const int lederror3=A3;
const int lederror4=A2;
//const int lederror5=A1;
String error="";
unsigned long sec= 3000;
long int milli;

#include <Servo.h>      //including the library of servo motor 
Servo sg90;             //initializing a variable for servo named sg90
int initial_position = 80;   //Declaring the initial position at 90
int LDR1 = A0;          //Pin at which LDR is connected
int LDR2 = A1;          //Pin at which LDR is connected
int errorLDR = 5;          //initializing variable for error
int servopin=9;


void setup() {


  Serial.begin(9600);
  sg90.attach(servopin);  // attaches the servo on pin 9
  pinMode(LDR1, INPUT);   //Making the LDR pin as input
  pinMode(LDR2, INPUT);
  sg90.write(initial_position);   //Move servo at 90 degree
  delay(2000);   
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(5,INPUT);
pinMode(4,INPUT);
pinMode(lederror1,INPUT);
pinMode(lederror2,INPUT);
pinMode(lederror3,INPUT);
pinMode(lederror4,INPUT);
//pinMode(lederror5,INPUT);

//pinMode(A5,INPUT);
Serial.begin(9600);
}

void loop() {




  int count=0;
  /*while(i<10)
  {
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
  i++;
  }*/
int  d=digitalRead(4);
int sun=analogRead(LDR1);
Serial.println(sun);
if(d==1 or sun>370)
{
  //Serial.println(d);
//sending one
  digitalWrite(7,HIGH);
  
  milli=millis();
  
  while(true)
  {
    c=digitalRead(5);
    
    if(c==1)
    {
      while(count==0)
      {
        if(analogRead(lederror1)<200)
        {
          Serial.print(analogRead(lederror1));
          
          error+="one ";
        }
        if(analogRead(lederror2)<200)
        {
          error+="two ";
        }
        if(analogRead(lederror3)<200)
        {
          error+="three ";
        }
        if(analogRead(lederror4)<200)
        {
          error+="four ";
        }
        /*if(analogRead(lederror5)<200)
        {
          error+="five ";
        }*/
        count++;
      }
      //Serial.println(c);
      //digitalWrite(13,HIGH);
      delay(10);
      milli=millis();
      //Serial.println(milli);
      
      b++;
    }
    if((millis()-milli)>1000)
    {
      
      Serial.println("hello");
      digitalWrite(7,LOW);
      break;
      
    }
    
  }
  /*int j=0;
  while(j<6)
  {
  
    if(c==1)
    {
      b++;
      delay(200);
    }
    
    c=digitalRead(3);
    j++;
  }*/
  delay(500);
  digitalWrite(7,LOW);
  Serial.println(b);
  store=b;
  b=0;



if(error=="")
{
  x="LED(err)=0";
}
else
{
  x="LED(err)-";
 
//Serial.print("LED error::");
//Serial.println(error);
}
if(store==6)
{
  //Serial.println("No Ultrasound error");
  h="No Ultra";
}
else
{
  h=" Ultra-"+(String)store;
  //z=store;
  //Serial.print("ultra sound error::");
  //Serial.print(store);
}


  
while(true)
{

int R1 = analogRead(LDR1); // reading value from LDR 1
  int R2 = analogRead(LDR2); // reading value from LDR 2
  R2=R2-130;
  Serial.print("r1::");
  Serial.println(R1);
  Serial.print("r2::");
  Serial.println(R2);
  int diff1= abs(R1 - R2);   // Calculating the difference between the LDR's
  int diff2= abs(R2 - R1);
  
  if((diff1 <= errorLDR) || (diff2 <= errorLDR)) {
    //if the difference is under the error then do nothing
  } else {    
    if(R1 > R2)
    {
      initial_position = --initial_position;  //Move the servo towards 0 degree
    }
    if(R1 < R2) 
    {
      initial_position = ++initial_position; //Move the servo towards 180 degree
    }
  }
 /* if (diff1>190)
  {
    servo=" SERVO ERROR";
    break;
  }
  else
  {
    servo="servo ok";
  }*/
  if(initial_position<110 && initial_position>50)
  {
  sg90.write(initial_position); // write the position to servo
  delay(100);
  }

  if(digitalRead(4)==1 or R1<150)
  {
    
    Serial.println("break");
    delay(50);
    digitalWrite(7,HIGH);
    delay(10);
    digitalWrite(7,LOW);
    delay(1000);
    int pos;
    for (pos = initial_position; pos <= 110; pos += 1) { // goes from 180 degrees to 0 degrees
    sg90.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
    


}
initial_position=pos-10;
    break;
    
  }
}
String last=x+error+h;
Serial.println(last);

Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+918582960476\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println(last);//the content of the message
  delay(300);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);  



  
 /* //b=1;
  c=digitalRead(3);
  if(c==1)
  {
  
  
  delay(200);
  //b++;
  //if(b==27)
  //{
    Serial.println(b);
    //b=1;
  }
  //else
  //{
     b++;*/
  //}
  }
}
 
  //Serial.println(analogRead(A5));
  //delay(500);y
  // put your main code here, to run repeatedly:


