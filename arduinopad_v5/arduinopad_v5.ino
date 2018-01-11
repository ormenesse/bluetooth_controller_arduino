
int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
int value1 = 0;                  // variable to read the value from the analog pin 0
int value2 = 0;
int BUT_0 = 2;
int BUT_1 = 3;
int BUT_2 = 4;
int BUT_3 = 5;
int BUT_4 = 6;
int BUT_5 = 7;
int BUT_6 = 8;
int BUT_7 = 9;
int BUT_8 = 10;
int BUT_9 = 11;
int BUT_10 = 12;
int BUT_11 = 13;
int d1=0,d2=0;
//this my struct to make easier to program

typedef struct PAD Padnew;
struct PAD{
	boolean CIMA;
	boolean BAIXO;
	boolean ESQUERDA;
	boolean DIREITA;
	boolean A;
	boolean B;
  boolean X;
  boolean Y;
	boolean START;
	boolean SELECT;
	boolean R1;
	boolean L1;
};

//I use this variable as a BUFFER
Padnew Pad;


int treatValue(int data) { //aqui tratamos o valor de 10 bits do joystick para um valor de 8 bits
  return (data*9/1024);
}
void setup() {
  // Here I have to program the serial in bluetooth hardware - A have a cheap HC-05/06
  Serial.begin(9600);
  delay(1000);
  Serial.write("AT+BAUD8");
  delay(1000);
  Serial.end();
  delay(1000);
  Serial.begin(115200);
  //configuring the pin modes
  pinMode(BUT_0,INPUT);
  pinMode(BUT_1,INPUT);  
  pinMode(BUT_2,INPUT);
  pinMode(BUT_3,INPUT);
  pinMode(BUT_4,INPUT);
  pinMode(BUT_5,INPUT);
  pinMode(BUT_6,INPUT);
  pinMode(BUT_7,INPUT);
  pinMode(BUT_8,INPUT);
  pinMode(BUT_9,INPUT);
  pinMode(BUT_10,INPUT);
  pinMode(BUT_11,INPUT);
  // i set everything as false
  Pad.CIMA = false;
  Pad.BAIXO = false;
  Pad.ESQUERDA = false;
  Pad.DIREITA = false;
  Pad.A = false;
  Pad.B = false;
  Pad.X = false;
  Pad.Y = false;
  Pad.START = false;
  Pad.SELECT = false;
  Pad.R1 = false;
  Pad.L1 = false;
 }

void loop() {
  // first of all i always read my analog d-pad.
  // till now i havent implemented analog anolog on android (i have no idea how to do it)
  // When we press the buttons...
  //now, here I do a FOR because i want to analyse all the pin buttons configured
  for (int i = 2; i < 14; i++){
    if (digitalRead(i) == HIGH){
      if(i == 2){
        Serial.write("d,19;");
        Pad.CIMA = true;
      }else if (i == 3){
        Serial.write("d,20;");
        Pad.BAIXO = true;
      }else if (i == 4){
        Serial.write("d,21;");
        Pad.ESQUERDA = true;
      }else if (i == 5){
        Serial.write("d,22;");
        Pad.DIREITA = true;
      }else if (i == 6){
        Serial.write("d,109;");        
        Pad.SELECT = true;
      }else if (i == 7){
        Serial.write("d,108;");
        Pad.START = true;
      }else if (i == 8){
        Serial.write("d,99;");
        Pad.X = true;
      }else if (i == 9){
        Serial.write("d,100;");
        Pad.Y = true;
      }else if (i == 10){
        Serial.write("d,96;");
        Pad.A = true;
      }else if (i == 11){
        Serial.write("d,97;");
        Pad.B = true;
      }else if (i == 12){
        Serial.write("d,102;");
        Pad.L1 = true;
      }else if (i == 13){
        Serial.write("d,103");
        Pad.R1 = true;
      }
    }
  }
  // When we release the buttons
  for (int i = 2; i < 14; i++){
    if (digitalRead(i) == LOW){
      if(i == 2){
      	if (Pad.CIMA == true){
        	Serial.write("u,19;");
        	Pad.CIMA= false;
      	}
      }else if (i == 3){
      	if (Pad.BAIXO == true){
        	Serial.write("u,20;");
        	Pad.BAIXO = false;
      	}
      }else if (i == 4){
      	if (Pad.ESQUERDA == true){
        	Serial.write("u,21;");
        	Pad.ESQUERDA = false;
      	}
      }else if (i == 5){
      	if (Pad.DIREITA == true){
        	Serial.write("u,22;");
        	Pad.DIREITA = false;
      	}
      }else if (i == 6){
      	if (Pad.SELECT == true){
        	Serial.write("u,109;");
        	Pad.SELECT = false;
      	}
      }else if (i == 7){
      	if(Pad.START == true){
        	Serial.write("u,108;");
        	Pad.START = false;
      	}
      }else if (i == 8){
        //Serial.write(0x6a); //analog button
        if(Pad.X == true){
        	Serial.write("u,99;");
        	Pad.X = false;
      	}
      }else if (i == 9){
      	if(Pad.Y == true){
        	Serial.write("u,100;");
        	Pad.Y = false;
      	}
      }else if (i == 10){
      	if(Pad.A == true){
        	Serial.write("u,96;");
        	Pad.A = false;
      	}
      }else if (i == 11){
      	if(Pad.B == true){
        	Serial.write("u,97;");
        	Pad.B = false;
      	}
      }else if (i == 12){
      	if(Pad.L1 == true){
        	Serial.write("u,102;");
        	Pad.L1 = false;
      	}
      }else if (i == 13){
      	if(Pad.R1 == true){
        	Serial.write("u,103;");
        	Pad.R1 = false;
      	}
      }
    }
  }
  
}
