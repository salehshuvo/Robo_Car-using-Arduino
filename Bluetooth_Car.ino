int MotorA1=9;
int MotorA2=8;
int MotorB3=7;
int MotorB4=4;
int MotorA_PWM=10;
int MotorB_PWM=5;
int spd=150;
char sms;
int hstate, bstate;

#define HL1a 12
#define HL1b 13
#define HL2a A4
#define HL2b A5

#define BL1a A0
#define BL1b A1
#define BL2a A2
#define BL2b A3

// HL=Head Light  BL=Back Light
void setup()
{
	pinMode(MotorA1, OUTPUT);
	pinMode(MotorA2, OUTPUT);
	pinMode(MotorB3, OUTPUT);
	pinMode(MotorB4, OUTPUT);
	pinMode(MotorA_PWM, OUTPUT);
	pinMode(MotorB_PWM, OUTPUT);
 pinMode(HL1a, OUTPUT);
 pinMode(HL1b, OUTPUT);
 pinMode(HL2a, OUTPUT);
 pinMode(HL2b, OUTPUT);
 pinMode(BL1a, OUTPUT);
 pinMode(BL1b, OUTPUT);
 pinMode(BL2a, OUTPUT);
 pinMode(BL2b, OUTPUT);
 
 digitalWrite(HL1b, LOW);
 digitalWrite(HL2b, LOW);
 digitalWrite(BL1b, LOW);
 digitalWrite(BL2b, LOW);

	Serial.begin(9600);
}

void loop()
{
	if(Serial.available())
	sms=Serial.read();
	
  analogWrite(MotorA_PWM, spd);
  analogWrite(MotorB_PWM, spd);
    
	if(sms=='S')
{
	Stop();
}
	
	if(sms=='F')
{
	Forward();
}
	
	if(sms=='B')
{
	Backward();
}
	
	if(sms=='L')
{
	Left();
}
	
	if(sms=='R')
{
	Right();
}
	
	if(sms=='0')
{
	spd=0;
}
	
	if(sms=='1')
{
	spd=28;
}
	
	if(sms=='2')
{
	spd=56;
}
	
	if(sms=='3')
{
	spd=85;
}
	
	if(sms=='4')
{
	spd=113;
}
	
	if(sms=='5')
{
	spd=142;
}
	
	if(sms=='6')
{
	spd=170;
}
	
	if(sms=='7')
{
	spd=199;
}
	
	if(sms=='8')
{
	spd=228;
}
	
	if(sms=='9')
{
	spd=255;
}

if(sms=='W')
{
    HeadLight1();
    hstate=1;
}

if(sms=='w')
{
    HeadLight0();
    hstate=0;
}

if(sms=='U')
{
    BackLight1();
    bstate=1;
}

if(sms=='u')
{
    BackLight0();
    bstate=0;
}
}

void Forward()
{
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB3, HIGH);
    digitalWrite(MotorB4, LOW);

    digitalWrite(BL1a, LOW);
    digitalWrite(BL2a, LOW);

    delay(100);
}

void Backward()
{
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB3, LOW);
    digitalWrite(MotorB4, HIGH);

    digitalWrite(BL1a, LOW);
    digitalWrite(BL2a, LOW);

    delay(100);
}

void Left()
{
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB3, HIGH);
    digitalWrite(MotorB4, LOW);

    digitalWrite(HL1a, HIGH);
    digitalWrite(HL2a, LOW);
    digitalWrite(BL1a, HIGH);
    digitalWrite(BL2a, LOW);

    delay(60);
}

void Right()
{
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB3, LOW);
    digitalWrite(MotorB4, HIGH);

    digitalWrite(HL1a, LOW);
    digitalWrite(HL2a, HIGH);
    digitalWrite(BL1a, LOW);
    digitalWrite(BL2a, HIGH);

    delay(60);
}

void Stop()
{
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB3, LOW);
    digitalWrite(MotorB4, LOW);

if(hstate==1)
{
    digitalWrite(HL1a, HIGH);
    digitalWrite(HL2a, HIGH);
}
if(hstate==0)
{
    digitalWrite(HL1a, LOW);
    digitalWrite(HL2a, LOW);
}

if(bstate==1)
{
    digitalWrite(BL1a, HIGH);
    digitalWrite(BL2a, HIGH);
}
if(bstate==0)
{
    digitalWrite(BL1a, LOW);
    digitalWrite(BL2a, LOW);
}
}

void HeadLight1()
{
    digitalWrite(HL1a, HIGH);
    digitalWrite(HL2a, HIGH);
}

void HeadLight0()
{
    digitalWrite(HL1a, LOW);
    digitalWrite(HL2a, LOW);
}

void BackLight1()
{
    digitalWrite(BL1a, HIGH);
    digitalWrite(BL2a, HIGH);
}

void BackLight0()
{
    digitalWrite(BL1a, LOW);
    digitalWrite(BL2a, LOW);
}