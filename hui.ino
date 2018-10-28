const int trigPin1 = 4; 
const int echoPin1 = A5;
int count1=0;
int n=0;
int resetcount=0;
const int trigPin2 = 7; 
const int echoPin2 = A4;
int count2=0;

const int trigPin3 = 8; 
const int echoPin3 = A3;
int count3=0;

const int trigPin4 = 12; 
const int echoPin4 = A2;
int count4=0;

const int trigPin5 = 13; 
const int echoPin5 = A1;
int count5=0;

//const int trigPin6 = 4; 
//const int echoPin6 = A0;

const int ledpin1 = 3;
const int ledpin2 = 5;
const int ledpin3 = 6;
const int ledpin4 = 9;
const int ledpin5 = 10;
//const int ledpin6 = 3;


// defines variables 
long duration1; 
int distance1;

long duration2; 
int distance2;

long duration3; 
int distance3;

long duration4; 
int distance4;

long duration5; 
int distance5;

//long duration6; 
//int distance6;






void setup() { 

  pinMode(A0,OUTPUT);
  pinMode(11,INPUT);
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input 

pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin2, INPUT);

pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin3, INPUT);

pinMode(trigPin4, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin4, INPUT);

pinMode(trigPin5, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin5, INPUT);

//pinMode(trigPin6, OUTPUT); // Sets the trigPin as an Output 
//pinMode(echoPin6, INPUT);

pinMode(ledpin1 , OUTPUT);
pinMode(ledpin2 , OUTPUT);
pinMode(ledpin3 , OUTPUT);
pinMode(ledpin4 , OUTPUT);
pinMode(ledpin5 , OUTPUT);
//pinMode(ledpin6 , OUTPUT);
Serial.begin(9600); // Starts the serial communication 
} 
 
void loop() { 


Serial.println("loop");
n=digitalRead(11);
Serial.println(n);
delay(50);
if(n==1)
{
  analogWrite(ledpin1,255);
  analogWrite(ledpin2,255);
  analogWrite(ledpin3,255);
  analogWrite(ledpin4,255);
  analogWrite(ledpin5,255);


  /*Serial.println(count1);
  delay(300);

    Serial.println(count2);
  delay(300);

    Serial.println(count3);
  delay(300);

    Serial.println(count4);
  delay(300);

    Serial.println(count5);
  delay(300);
*/

int mean=(count1+count2+count3+count4+count5)/5;

int md1=(count1-mean)*(count1-mean);
int md2=(count2-mean)*(count2-mean);
int md3=(count3-mean)*(count3-mean);
int md4=(count4-mean)*(count4-mean);
int md5=(count5-mean)*(count5-mean);
Serial.println("mean deviation");
Serial.println(md1);
Serial.println(md2);
Serial.println(md3);
Serial.println(md4);
Serial.println(md5);
count1=count2=count3=count4=count5=0;
int mdarr[5]={md1,md2,md3,md4,md5};
int index[5]={0,1,2,3,4};
int highest=md1;
int i=1;
int temp=0;
int tempindex=0;
for(int i=0;i<4;i++)
{
  for (int j=0;j<5-i-1;j++)
  {
    if (mdarr[j]>mdarr[j+1])
  {
    tempindex=index[j];
    index[j]=index[j+1];
    index[j+1]=tempindex;
    temp=mdarr[j];
    mdarr[j]=mdarr[j+1];
    mdarr[j+1]=temp;
  }
  }
  
}

if (mdarr[3]*2<mdarr[4])
{
  Serial.println(index[4]);
  int i=0;
  while(i<index[4]+1)
  {
    digitalWrite(A0,HIGH);
    delay(2);
    //delay(200);
    digitalWrite(A0,LOW);
    delay(500);
    i++;
  }
  
}
else
{
  int i=0;
  while(i<6)
  {
    digitalWrite(A0,HIGH);
    delay(2);
    //delay(200);
    digitalWrite(A0,LOW);
    delay(500);
    i++;
  }
  Serial.println("all ok");
}



  analogWrite(ledpin1,0);
  analogWrite(ledpin2,0);
  analogWrite(ledpin3,0);
  analogWrite(ledpin4,0);
  analogWrite(ledpin5,0);
  delay(600);
  while(true)
  {
    n=digitalRead(11);
    //Serial.println("while");
    
    if(n==1)
    {
      delay(50);
      Serial.println("break");
      break;
    }
  }
  
}
// Clears the trigPin 
else
{
  

digitalWrite(trigPin1, LOW); 
delayMicroseconds(2);

digitalWrite(trigPin2, LOW); 
delayMicroseconds(2);

digitalWrite(trigPin3, LOW); 
delayMicroseconds(2);

digitalWrite(trigPin4, LOW); 
delayMicroseconds(2);

digitalWrite(trigPin5, LOW); 
delayMicroseconds(2);

//digitalWrite(trigPin6, LOW); 
//delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds 
digitalWrite(trigPin1, HIGH);
delayMicroseconds(1000); 
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);

digitalWrite(trigPin2, HIGH);
delayMicroseconds(1000); 
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);


digitalWrite(trigPin3, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);

digitalWrite(trigPin4, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin4, LOW);
duration4 = pulseIn(echoPin4, HIGH);

digitalWrite(trigPin5, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin5, LOW);
duration5 = pulseIn(echoPin5, HIGH);
 
/*digitalWrite(trigPin6, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin6, LOW); 
duration6 = pulseIn(echoPin6, HIGH);
*/
// Reads the echoPin, returns the sound wave travel time in microseconds 





 
// Calculating the distance 
distance1= duration1*0.034/2;
distance2= duration2*0.034/2;
distance3= duration3*0.034/2;
distance4= duration4*0.034/2;
distance5= duration5*0.034/2;
//distance6= duration6*0.034/2; 

// Prints the distance on the Serial Monitor 
if (distance1<10)
{
  analogWrite(ledpin1,255);
  analogWrite(ledpin2,255);
  analogWrite(ledpin3,255);
  analogWrite(ledpin4,25);
  analogWrite(ledpin5,25);
  //analogWrite(ledpin6,1);
  count1++;
  
}
else if(distance2<10)
{
  analogWrite(ledpin1,25);
  analogWrite(ledpin2,255);
  analogWrite(ledpin3,255);
  analogWrite(ledpin4,255);
  analogWrite(ledpin5,25);
  //analogWrite(ledpin6,1);
  count2++;
}
else if(distance3<10)
{
  analogWrite(ledpin1,25);
  analogWrite(ledpin2,25);
  analogWrite(ledpin3,255);
  analogWrite(ledpin4,255);
  analogWrite(ledpin5,255);
  //analogWrite(ledpin6,1);
  count3++;
}
else if(distance4<4)
{
  analogWrite(ledpin1,25);
  analogWrite(ledpin2,25);
  analogWrite(ledpin3,25);
  analogWrite(ledpin4,255);
  analogWrite(ledpin5,255);
  //analogWrite(ledpin6,255);
  count4++;
  
}
else if(distance5<10)
{
  analogWrite(ledpin1,25);
  analogWrite(ledpin2,25);
  analogWrite(ledpin3,25);
  analogWrite(ledpin4,25);
  analogWrite(ledpin5,255);
  count5++;
  //analogWrite(ledpin6,255);
  
}
/*else if(distance6<15)
{
  analogWrite(ledpin1,255);
  analogWrite(ledpin2,255);
  analogWrite(ledpin3,1);
  analogWrite(ledpin4,1);
  analogWrite(ledpin5,1);
  //analogWrite(ledpin6,255);
  
}*/
else
{
  analogWrite(ledpin1,25);
  analogWrite(ledpin2,25);
  analogWrite(ledpin3,25);
  analogWrite(ledpin4,25);
  analogWrite(ledpin5,25);
  //analogWrite(ledpin6,1);

}

Serial.print("Distance1: "); 
Serial.println(distance1);
Serial.print("Distance2: "); 
Serial.println(distance2);
Serial.print("Distance3: "); 
Serial.println(distance3);
Serial.print("Distance4: "); 
Serial.println(distance4);
Serial.print("Distance5: "); 
Serial.println(distance5);
//Serial.print("Distance6: "); */
//Serial.println(distance6); 
} 
}
