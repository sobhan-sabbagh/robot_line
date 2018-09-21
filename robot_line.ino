/*
  introdution to Arduino

  FaraDars Robot Final Codes

  ==> Faradars.Org <==
  Author: Zahedi
*/


//Sensor
int s1 = 2; //Sensor1 ==> Pin2
int s2 = 3; //Sensor2 ==> Pin3
int s3 = 4; //Sensor3 ==> Pin4
int s4 = 5; //Sensor4 ==> Pin5
boolean sens1, sens2, sens3, sens4; // Variables for Sensor


// Motor & L298
//Channel A
int IN1 = 7; // IN1 ==> Pin7
int IN2 = 8; // IN2 ==> Pin8
int ENA = 9; // Enable A ==> Pin9

//Channel B
int IN3 = 13; // IN3 ==> 13
int IN4 = 12; // IN4 ==> 12
int ENB = 11; // Enable B ==> Pin11

int MotorSpeedA = 0;
int MotorSpeedB = 0;

void setup() {
  //Activate Serial Monitor
  Serial.begin(9600);

  //Sensor Setting
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  //L298 Setting
  //Channel A  Motor in Right Side
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  digitalWrite(ENA, LOW);
  //Channel B  Motor in Left Side
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, LOW);

}

bool r;
bool l;

void loop() {

  SensorDigitalRead();

  //if You Want to Show Sensor Result
  //SensorPrint();


  //Move forward ==> Sensor1 and Sensor2 are in Black line
  //Sensors in White line ==> 0 Value
  //Sensors in Black line ==> 1 Value

  if ( sens3 && !sens2) {
    TurnRight_L();
  }
  else if ( !sens3 && sens2) {
    TurnLeft_L();
  }
  //Robot Turn a little ro Right
  else if ( sens4 && !sens1) {
    TurnRight();
    r = 1;
  }

  //Robot Turn a little ro Left
  else if ( !sens4 && sens1 ) {
    TurnLeft();
    l = 1;
  }

  else if ( sens2 && sens3) {
    MoveForward();
  }

  else if ( !sens1 && !sens2 && !sens3 && !sens4) {
    MoveForward_l();
  }
  
  while ( sens1 && sens2 && sens3 && sens4 && r == 1) {
    TurnRight();
    SensorDigitalRead();
  }
  
  r = 0 ;
   while ( sens1 && sens2 && sens3 && sens4 && l == 1) {
    TurnLeft();
    SensorDigitalRead();
  }
  l = 0 ;

  /* else if ( (sens2 || sens3) &&  !sens1 && !sens4) {
     MoveBackWard();
    }

    //MoveBack When all sensor in White Area
    else if ( !sens1 && !sens2 && !sens3 && !sens4) {
     analogWrite(ENA, 0);
     analogWrite(ENB, 0);
     MoveBackWard();
    }*/
}


// Read Value From All Sensor
int SensorDigitalRead() {
  sens1 = digitalRead(s1);
  sens2 = digitalRead(s2);
  sens3 = digitalRead(s3);
  sens4 = digitalRead(s4);
  return sens1, sens2, sens3, sens4;
}

// Print Sensors Value on Screen
void SensorPrint() {
  Serial.print("S1= ");
  Serial.print(sens1);
  Serial.print(" S2= ");
  Serial.print(sens2);
  Serial.print(" S3= ");
  Serial.print(sens3);
  Serial.print(" S4= ");
  Serial.print(sens4);
  Serial.println();

  delay(200);
}

//Function for Moving Forward
void MoveForward() {

  MotorSpeedA = 200;
  MotorSpeedB = 200;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);
}

void MoveForward_l() {

  MotorSpeedA = 100;
  MotorSpeedB = 100;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);
}

//function for Moving BackWard
void MoveBackWard() {
  MotorSpeedA =  150;
  MotorSpeedB = 150;
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);

}

// Function for Turning Robot to left
void TurnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  MotorSpeedA = 150;
  MotorSpeedB = 150;

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);
}

// Function For Turning Robot to Right
void TurnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  MotorSpeedA = 150;
  MotorSpeedB = 150;

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);
}

// Function for Turning Robot to left
void TurnLeft_L() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  MotorSpeedA = 150;
  MotorSpeedB = 150;

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);
}

// Function For Turning Robot to Right
void TurnRight_L() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  MotorSpeedA = 150;
  MotorSpeedB = 150;

  analogWrite(ENA, MotorSpeedA);
  analogWrite(ENB, MotorSpeedB);
}
