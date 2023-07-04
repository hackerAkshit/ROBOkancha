//YouTube|Tech at Home

//Receiver signal pins
double ch1_pin = 3;  //PWM pin


// motor driver 1 pins
int R_EN_right = 2; 
int L_EN_right = 4;
int R_PWM_right = 6; //PWM pin
int L_PWM_right = 9; //PWM pin

// motor driver 2  pins
int R_EN_left = 7; 
int L_EN_left = 8;
int R_PWM_left = 10; //PWM pin
int L_PWM_left = 11; //PWM pin

// ---**---   Rx threshold values - Update based on your TX values
//FWD
int Ch1_start_Fwd = 1050;
int Ch1_End_Fwd = 1950;
//BACK
//int Ch1Ch2_start_Bac = 1460;
//int Ch1Ch2_End_Bac = 960;

// ---------***---------------***----------

void setup()
{
  Serial.begin(9600);
  //for signal
  pinMode(3,INPUT);
//  pinMode(5,INPUT);
  //for driver 1
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT); //pwm out
  pinMode(9,OUTPUT);//pwm out
  //for driver 2
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT); //pwm out
  pinMode(11,OUTPUT);//pwm out
}

void loop()
{
//Receiver signal pins data
double ch1 = pulseIn(3,HIGH);

//Speed mapping for right motor driver
int spdFwd = map(ch1, Ch1_start_Fwd, Ch1_End_Fwd, 8 , 250);   
Serial.print("ch1: ");
Serial.println(spdFwd);  

digitalWrite(R_EN_right, HIGH);
digitalWrite(L_EN_right, HIGH);
digitalWrite(R_EN_left, HIGH);
digitalWrite(L_EN_left, HIGH);

if(ch1==0)
{     
analogWrite(R_PWM_right,0);
analogWrite(L_PWM_right,0);
analogWrite(R_PWM_left,0);
analogWrite(L_PWM_left,0);
}
//start forward code 
else if(ch1>Ch1_start_Fwd)
{     
analogWrite(R_PWM_right,spdFwd);
analogWrite(L_PWM_right,0);
analogWrite(R_PWM_left,spdFwd);
analogWrite(L_PWM_left,0); 
}

else
{     
analogWrite(R_PWM_right,0);
analogWrite(L_PWM_right,0);
analogWrite(R_PWM_left,0);
analogWrite(L_PWM_left,0);
}

}
