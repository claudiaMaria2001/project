int ro1=12;//
int ro2=11;
int ve1=10;
int ve2=9;
int ga1=8;
int ga2=7;
int buz=4;
int buton=3;
int led_pin =2;
int dy=300;//
int timp =0;



void setup() {

Serial.begin(9600);

 Serial.println("start semafor");
 pinMode(ro1, OUTPUT);
 pinMode(ro2, OUTPUT);
 pinMode(ve1, OUTPUT);
 pinMode(ve2, OUTPUT);
 pinMode(ga1, OUTPUT);
 pinMode(ga2, OUTPUT);
 pinMode(buz, OUTPUT);
 pinMode(buton, INPUT);
 pinMode(led_pin,OUTPUT);
 digitalWrite(led_pin, HIGH);
 

}

void loop() {
bu:

 if(digitalRead(buton) == LOW){
    digitalWrite(led_pin, HIGH);delay(dy);
  }
  if(digitalRead(buton) == LOW){
    digitalWrite(led_pin, LOW);delay(dy);
  }

if (digitalRead(led_pin)==LOW){
  defectiune();
  goto bu;
   };

  
if ((timp>=0) and (timp <=30)){ digitalWrite(ro1, HIGH); digitalWrite(ve2, HIGH); delay(dy);digitalWrite(ga1, LOW); };//v2r1
if ((timp>=31) and (timp <=39)){ digitalWrite(ga2, HIGH); digitalWrite(ve2, LOW);delay(dy);};//aprinde galben2
if ((timp>=40) and (timp <=70)){ digitalWrite(ro2, HIGH); digitalWrite(ve1, HIGH); digitalWrite(ga2, LOW); digitalWrite(ro1, LOW);delay(dy);};//
if ((timp>=71) and (timp <=79)){ digitalWrite(ga1, HIGH); digitalWrite(ve1, LOW);delay(dy);};//
if ((timp>=80) and (timp <=100)){digitalWrite(ro2, LOW); digitalWrite(ga1, LOW); };//





Serial.println(timp);
timp=timp+1;
if (timp>=81){timp=0;};

}

 void defectiune(){ 
digitalWrite(ve1, LOW);
digitalWrite(ve2, LOW);
digitalWrite(ro2, LOW);
digitalWrite(ro1, LOW);
digitalWrite(ga2, HIGH);
digitalWrite(ga1, LOW);
digitalWrite(buz, HIGH);
delay(dy);
digitalWrite(ga2, LOW);
digitalWrite(ga1, HIGH);
digitalWrite(buz, LOW);
delay(dy);
timp=0;
Serial.println("semafor defect");

 }
