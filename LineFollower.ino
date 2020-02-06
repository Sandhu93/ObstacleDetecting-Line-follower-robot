int IR1 = 2;
int IR2 = 3;
int IR3 = 4;
int trigPin = 12;
int echoPin = 7;
int MOT_R1 = 10;
int MOT_R2 = 11;
int MOT_L1 = 9;
int MOT_L2 = 8;

// the setup routine runs once when you press reset:
void setup() {
    Serial.begin(9600);
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    pinMode(IR3, INPUT);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(MOT_R1, OUTPUT);
    pinMode(MOT_R2, OUTPUT);
    pinMode(MOT_L1, OUTPUT);
    pinMode(MOT_L2, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
    int right = digitalRead(IR1);
    int middle = digitalRead(IR2);
    int left = digitalRead(IR3);
    int out_put;
    out_put = ((!right&!middle)|(!middle&!left));
    if((distance>20)&&(right==1) && (middle==0) && (left==1))
    {
     forward();
     delay(10); 
    }
    else if((distance>20)&&(right==0) && (middle==1) && (left==1))
    {
     left_move();
     delay(10); 
    }
    else if((distance>20)&&(right==1) && (middle==1) && (left==0))
    {
     right_move();
     delay(10); 
    }
    else if(out_put==1)
    {
    while (m>0)
    {
      forward();
      m--;
      break;
    }
    while (m==0 && n>x)
    {
     turn(); 
     break;
    }
    while (m==0 && n!=x && n>0)
    {
      forward();
      n--;
      break;
    }
    }    
    
    else
    {
     stop_mot();
     delay(10); 
    }
    
     delay(100);        // delay in between reads for stability
}

void forward()
{
 digitalWrite(MOT_R1,HIGH);
 digitalWrite(MOT_R2,LOW);
 digitalWrite(MOT_L1,HIGH);
 digitalWrite(MOT_L2,LOW);
 delay(2); 
 return;
}
void left_move()
{
 digitalWrite(MOT_R1,HIGH);
 digitalWrite(MOT_R2,LOW);
 digitalWrite(MOT_L1,LOW);
 digitalWrite(MOT_L2,LOW);
 delay(2); 
 return;
}

void right_move()
{
 digitalWrite(MOT_R1,LOW);
 digitalWrite(MOT_R2,LOW);
 digitalWrite(MOT_L1,HIGH);
 digitalWrite(MOT_L2,LOW);
 delay(2); 
 return;
}

void stop_mot()
{
 digitalWrite(MOT_R1,LOW);
 digitalWrite(MOT_R2,LOW);
 digitalWrite(MOT_L1,LOW);
 digitalWrite(MOT_L2,LOW);
 delay(2); 
 return;
}

void turn()
{
 digitalWrite(MOT_R1,HIGH);
 digitalWrite(MOT_R2,LOW);
 digitalWrite(MOT_L1,HIGH);
 digitalWrite(MOT_L2,LOW);
 delay(2); 
 digitalWrite(MOT_R1,LOW);
 digitalWrite(MOT_R2,HIGH);
 digitalWrite(MOT_L1,LOW);
 digitalWrite(MOT_L2,LOW);
 delay(2); 
 return;
}

 
