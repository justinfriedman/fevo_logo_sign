//button inputs
#define b1 A0
#define b2 A1
#define b3 A2
#define b4 A3
//color pins - zone 0
#define red0 9
#define green0 10
#define blue0 11
//color pins - zone 1
#define red1 3
#define green1 5
#define blue1 6

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
//R[0] value goes with G[0] and B[0] and so on, simply add or replace values in each array for new colors 
int R[] = {3, 95, 115, 255, 255, 199,255, 64};
  int G[] = {61, 25, 0, 43, 100, 0,171,178};
  int B[] = {255, 195, 180, 0, 0, 219,0,255};

  int currentR;
  int currentG;
  int currentB;
  int looper = 0;

void setup() {
  Serial.begin(9600);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);

  pinMode(red0, OUTPUT);
  pinMode(green0, OUTPUT);
  pinMode(blue0, OUTPUT);  
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);  

  
  
}

void loop() {

  
  looper = looper % 8;
  currentR = R[looper];
  currentG = G[looper];
  currentB = B[looper];

  setColor(currentR,currentG,currentB);
  
  
  buttonState1 = analogRead(b1);
  buttonState2 = analogRead(b2);
  buttonState3 = analogRead(b3);
  buttonState4 = analogRead(b4);

  if (buttonState3 > 100) {
    delay(250);
    looper = looper + 1;
  }
  if (buttonState2 > 100) {
    delay(250);
    looper = looper - 1;
  }

 
  
 
  

}


void setColor(int red, int green, int blue)
{
  
  analogWrite(red0, red);
  analogWrite(green0, green);
  analogWrite(blue0, blue);  
  analogWrite(red1, red);
  analogWrite(green1, green);
  analogWrite(blue1, blue);  
}
