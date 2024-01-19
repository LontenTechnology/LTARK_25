#define D_a 2
#define D_b 3
#define D_c 4
#define D_d 5
#define D_e 6
#define D_f 7
#define D_g 8
#define D_h 9

#define COM1 10
#define COM2 11
#define COM3 12
#define COM4 13

bool Digital_tube_number[18][8] = {
  {0,0,0,0,0,0,1,1},//0
  {1,0,0,1,1,1,1,1},//1
  {0,0,1,0,0,1,0,1},//2
  {0,0,0,0,1,1,0,1},//3
  {1,0,0,1,1,0,0,1},//4
  {0,1,0,0,1,0,0,1},//5
  {0,1,0,0,0,0,0,1},//6
  {0,0,0,1,1,1,1,1},//7
  {0,0,0,0,0,0,0,1},//8
  {0,0,0,0,1,0,0,1},//9
  {0,0,0,1,0,0,0,0},//A10
  {0,0,0,0,0,0,0,0},//B11
  {0,1,1,0,0,0,1,0},//C12
  {0,0,0,0,0,0,1,0},//D13
  {0,1,1,0,0,0,0,0},//E14
  {0,1,1,1,0,0,0,0},//F15
  {0,1,0,0,0,0,1,0},//G16
  {1,1,1,1,1,1,1,0},//decimal point.
};

int delay_time = 2;

void setup() {
  // put your setup code here, to run once:
  for(int i=D_a;i<=D_h;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=COM1;i<=COM4;i++){
    pinMode(i,OUTPUT);
  }
  Digital_tube_display_sametime(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  Digital_tube_dynamic_display(1,2,3,4,6,1);
  Digital_tube_dynamic_display(3,6,5,8,6,1);
  Digital_tube_dynamic_display(10,11,12,13,6,1);
}

/* dynamic display
*Display on digital tube 1, display on digital tube 2, display on digital tube 3, display on digital tube 4,
*time1 visual persistence minimum time, time2 dynamic time
 */
void Digital_tube_dynamic_display(int a,int b,int c,int d,int time1,float time2)
{
  if(time1>6){
    time1 = 6;
  }
  for(int i=0;i<time2*250/time1;i++){
    Digital_tube_display(1,a);
    delay(time1);
    Digital_tube_display(2,b);
    delay(time1);
    Digital_tube_display(3,c);
    delay(time1);
    Digital_tube_display(4,d);
    delay(time1);
  }
}
void Digital_tube_display_sametime(int number)
{
  digitalWrite(COM1,HIGH);
  digitalWrite(COM2,HIGH);
  digitalWrite(COM3,HIGH);
  digitalWrite(COM4,HIGH);
  for(int i=0;i<8;i++){
    digitalWrite(2+i,Digital_tube_number[number][i]);
  }
}

void Digital_tube_display(int com,int number)
{
  for(int i=COM1;i<=COM4;i++){
    digitalWrite(i,LOW);
  }
  switch(com){
    case 1:
      digitalWrite(COM1,HIGH);
      break;
    case 2:
      digitalWrite(COM2,HIGH);
      break;
    case 3:
      digitalWrite(COM3,HIGH);
      break;
    case 4:
      digitalWrite(COM4,HIGH);
      break;
  }
  for(int i=0;i<8;i++){
    digitalWrite(2+i,Digital_tube_number[number][i]);
  }
}
