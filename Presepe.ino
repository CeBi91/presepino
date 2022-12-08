int DEL = 100;
int DEL2 = 20;
int t=DEL;


int led_fire = 6;
int led_dawn =9;
int led_day = 10;
int led_sunset = 11;

int brightness = 0;   
int brig1 = 0;
int brig2 = 0;
int brig3 = 0;
int i=0;

void setup() {
  
  pinMode(led_fire, OUTPUT);
  pinMode(led_dawn, OUTPUT);
  pinMode(led_day, OUTPUT);
  pinMode(led_sunset, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

    //Alba
    for(brig1=0;brig1<255;brig1++){
      analogWrite(led_dawn, brig1);
      if(brig1==100){t=DEL2;}
      delay(t);
      //if(brig1==100){analogWrite(led_fire,0);}
    }
    t=DEL;

    //Giorno
    for(brig2=0;brig2<255;brig2++){
      analogWrite(led_day, brig2);
      analogWrite(led_dawn, brig1);
      if(brig1!=0){brig1--;}
      if(brig2==100){t=DEL2;}
      delay(t);
    }
    t=DEL;
    analogWrite(led_dawn, 0);

    //Tramonto
    for(brig3=0;brig3<255;brig3++){
      analogWrite(led_sunset, brig3);
      analogWrite(led_day, brig2);
      if(brig3==100){t=DEL2;}
      if(brig2!=0){brig2--;}
      delay(t);
    }
    t=DEL;
    analogWrite(led_day, 0);

    //Notte
    for(i=0;i<1000;i++){
      analogWrite(led_sunset, brig3);
      if(brig3!=0){brig3--;}
      fire();
      //delay(t);
    }
    analogWrite(led_fire,0);
   
}

void fire(){
   brightness=random(10,255);
   analogWrite(led_fire, brightness);
   delay(random(30,70));
  }
