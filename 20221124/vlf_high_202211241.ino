// C++ code
//
#define F_Sonar 8
#define R_Sonar 10
#define L_Sonar 11

float Front_Sonar(){
  float duration=0;
  float distance=0;
  pinMode(F_Sonar,OUTPUT);
  digitalWrite(F_Sonar,LOW);
  digitalWrite(F_Sonar,HIGH);
  delay(10);
  digitalWrite(F_Sonar,LOW);
  pinMode(F_Sonar,INPUT);  
  duration = pulseIn(F_Sonar,HIGH);
  distance = (duration*340)/2/1000;
  
  return distance;
}

float Right_Sonar(){
  float duration=0;
  float distance=0;
  pinMode(R_Sonar,OUTPUT);
  digitalWrite(R_Sonar,LOW);
  digitalWrite(R_Sonar,HIGH);
  delay(10);
  digitalWrite(R_Sonar,LOW);
  pinMode(R_Sonar,INPUT);  
  duration = pulseIn(R_Sonar,HIGH);
  distance = (duration*340)/2/1000;
  
  return distance;
}

float Left_Sonar(){
  float duration=0;
  float distance=0;
  pinMode(L_Sonar,OUTPUT);
  digitalWrite(L_Sonar,LOW);
  digitalWrite(L_Sonar,HIGH);
  delay(10);
  digitalWrite(L_Sonar,LOW);
  pinMode(L_Sonar,INPUT);  
  duration = pulseIn(L_Sonar,HIGH);
  distance = (duration*340)/2/1000;
  
  return distance;
}



void setup(){
  pinMode( F_Sonar, OUTPUT);
  pinMode( R_Sonar, OUTPUT);
  pinMode( L_Sonar, OUTPUT);
  Serial.begin(115200); 
}

float robot_width =200; //차량의 폭
float mazor_width = 500; //미로의 폭
float mazor_width_tolerance=40; //오차 범위
int flag_mazor_1=0; //1번 구간에 내가 위치해 있다

void loop(){
  float L_distance, R_distance, F_distance;
  float  measure_width;
  L_distance = Left_Sonar();
  F_distance = Front_Sonar();
  R_distance = Right_Sonar();
  
 /*Serial.print("L"); Serial.print("F"); Serial.print("R");*/
   Serial.print(L_distance);
  Serial.print("L_distance");
   Serial.print(R_distance);
  Serial.print("R_distance");
   Serial.print(F_distance);
  Serial.print("F_distance");
  
 measure_width= L_distance + robot_width + R_distance;
  if((measure_width >= (mazor_width - mazor_width_tolerance))&&(measure_width <= (mazor_width + mazor_width_tolerance)))
     {
       if((F_distance>mazor_width)&&(F_distance<mazor_width + 400))
       {
         flag_mazor_1=1;
         Serial.print("flag_mazor_1 set");
       }
     }
     else
     {
       flag_mazor_1=0;
     }

}