const int trigPin = 3;                  //Trig Pin
const int echoPin = 2;                  //Echo Pin

long duration, cm, inches;
//void car_initial();
void forward();
void turn_left();
void still();
const int a1 = 5;
const int b1 = 6;
const int a2 = 10;
const int b2 = 9;

void setup() {
  Serial.begin (9600);             // Serial Port begin
  pinMode(trigPin, OUTPUT);        //Define inputs and outputs 
  pinMode(echoPin, INPUT);
//  car_initial();
  pinMode(a1, OUTPUT); 
  pinMode(b1, OUTPUT); 
  pinMode(a2, OUTPUT); 
  pinMode(b2, OUTPUT); 
  still();
//  still();
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);             // 讀取 echo 的電位
  duration = pulseIn(echoPin, HIGH);   // 收到高電位時的時間
 
  cm = (duration/2) / 29.1;         // 將時間換算成距離 cm 或 inch  
  inches = (duration/2) / 74; 

  if(cm <= 20){
    turn_left();
    }else{
      forward();
      }

void still(){
  digitalWrite(a1, 0);
  digitalWrite(b1, 0);
  digitalWrite(a2, 0);
  digitalWrite(b2, 0);
  }
void forward(){
  digitalWrite(a1, 0);
  digitalWrite(b1, 255);
  digitalWrite(a2, 255);
  digitalWrite(b2, 0);
  }
void turn_left(){
  digitalWrite(a1, 50);
  digitalWrite(b1, 0);
  digitalWrite(a2, 0);
  digitalWrite(b2, 0);
  }

  
