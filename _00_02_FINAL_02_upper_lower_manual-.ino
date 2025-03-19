

#define STATE_IDLE 1
#define relay_up_on 2
#define relay_down_on 3
#define relay_left_on 4
#define relay_right_on 5

int Manual_Switch = 48;          // Digital Arduino Pin 48 is used to control Manual Function (ONLY REVOLUTION & DOWN SWITHES)
int Low_High_Switch = 49;        // Digital Arduino Pin 49 is used to control Lower OR Higher Level

int Relay_up = 5;                // Digital Arduino Pin 4 is used to control relay UP in Relay Shield
int Relay_down = 6;              // Digital Arduino Pin 5 is used to control relay DOWN in Relay Shield
int Relay_left = 4;              // Digital Arduino Pin 4 is used to control relay LEFT in Relay Shield
int Relay_Right = 7;             // Digital Arduino Pin 4 is used to control relay RIGHT in Relay Shield

int Input_Right_1_up = 53;       // Digital Arduino Pin 53 PCINT0 (PB0) is used to control PinChangeInterrupt from Input_Right_1_up
int Input_Right_1_midle = 52;    // Digital Arduino Pin 52 PCINT1 (PB1) is used to control PinChangeInterrupt from Input_Right_1_midle
int Input_Right_1_Down = 51;     // Digital Arduino Pin 51 PCINT2 (PB2) is used to control PinChangeInterrupt from Input_Right_1_Down

int Input_Right_2_up = 50;       // Digital Arduino Pin 50 PCINT3 (PB3) is used to control PinChangeInterrupt from Input_Right_2_up
int Input_Right_2_midle = 8;     // Digital Arduino Pin 8  from Input_Right_2_midle
int Input_Right_2_Down = 9;      // Digital Arduino Pin 9  from Input_Right_2_Down

int Input_Center_up = 10;        // Digital Arduino Pin 10  from Input_Center_up
int Input_Center_midle = 11;     // Digital Arduino Pin 11  from Input_Center_midle
int Input_Center_Down = 12;      // Digital Arduino Pin 12  from Input_Center_Down

int Input_Left_2_up = 14;        // Digital Arduino Pin 14 from Input_Left_2_up
int Input_Left_2_midle = 15;     // Digital Arduino Pin 15 from Input_Left_2_midle
int Input_Left_2_Down = 16;      // Digital Arduino Pin 16 from Input_Left_2_Down

int Input_Left_1_up = 17;        // Digital Arduino Pin 17 from Input_Left_1_up
int Input_Left_1_midle = 18;     // Digital Arduino Pin 18 from Input_Left_1_midle
int Input_Left_1_Down = 19;      // Digital Arduino Pin 19 from Input_Left_1_Down

// variables will change:

int Manual_Switch_buttonState = 0;           // variable for reading the Manual_Switch status

int Low_High_Switch_buttonState = 0;         // variable for reading the Low_High_Switch status


int Input_Right_1_up_buttonState = 0;       // variable for reading the Input_Right_1_up status
int Input_Right_1_midle_buttonState = 0;    // variable for reading the Input_Right_1_midle status
int Input_Right_1_Down_buttonState = 0;     // variable for reading the Input_Right_1_Down status

int Input_Right_2_up_buttonState = 0;        // variable for reading the Input_Right_2_up status
int Input_Right_2_midle_buttonState = 0;     // variable for reading the Input_Right_2_midle status
int Input_Right_2_Down_buttonState = 0;      // variable for reading the Input_Right_2_Down status

int Input_Center_up_buttonState = 0;         // variable for reading the Input_Center_up status
int Input_Center_midle_buttonState = 0;      // variable for reading the Input_Center_midle status
int Input_Center_Down_buttonState = 0;       // variable for reading the Input_Center_Down status

int Input_Left_2_up_buttonState = 0;         // variable for reading the Input_Left_2_up status
int Input_Left_2_midle_buttonState = 0;      // variable for reading the Input_Left_2_midle status
int Input_Left_2_Down_buttonState = 0;       // variable for reading the Input_Left_2_Down status

int Input_Left_1_up_buttonState = 0;         // variable for reading the Input_Left_1_up status
int Input_Left_1_midle_buttonState = 0;      // variable for reading the Input_Left_1_midle status
int Input_Left_1_Down_buttonState = 0;       // variable for reading the Input_Left_1_Down status


boolean Manual = false;
boolean Lower = false;

boolean A_1 = false;
boolean B_1 = false;
boolean C_1 = false;

boolean A_2 = false;
boolean B_2 = false;
boolean C_2 = false;

boolean A_3 = false;
boolean B_3 = false;
boolean C_3 = false;

boolean A_4 = false;
boolean B_4 = false;
boolean C_4 = false;

boolean A_5 = false;
boolean B_5 = false;
boolean C_5 = false;


 
// the setup routine runs once when you press reset:

void setup()  {

    pinMode(Relay_up, OUTPUT);           // declare pin 4 to be an output:
    pinMode(Relay_down, OUTPUT);         // declare pin 5 to be an output:
    pinMode(Relay_left, OUTPUT);         // declare pin 6 to be an output:
    pinMode(Relay_Right, OUTPUT);        // declare pin 7 to be an output:

    pinMode(Manual_Switch, INPUT);        // declare pin 48 to be an input:
    pinMode(Low_High_Switch, INPUT);      // declare pin 49 to be an input:

    pinMode(Input_Right_1_up, INPUT);      // declare pin 53 to be an input:
    pinMode(Input_Right_1_midle, INPUT);   // declare pin 52 to be an input:
    pinMode(Input_Right_1_Down, INPUT);    // declare pin 51 to be an input:

    pinMode(Input_Right_2_up, INPUT);      // declare pin 50 to be an input:
    pinMode(Input_Right_2_midle, INPUT);   // declare pin 8 to be an input:
    pinMode(Input_Right_2_Down, INPUT);    // declare pin 9 to be an input:

    pinMode(Input_Center_up, INPUT);       // declare pin 10 to be an input:
    pinMode(Input_Center_midle, INPUT);    // declare pin 11 to be an input:
    pinMode(Input_Center_Down, INPUT);     // declare pin 12 to be an input:
    
    pinMode(Input_Left_2_up, INPUT);       // declare pin 14 to be an input:
    pinMode(Input_Left_2_midle, INPUT);    // declare pin 15 to be an input:
    pinMode(Input_Left_2_Down, INPUT);     // declare pin 16 to be an input:

    pinMode(Input_Left_1_up, INPUT);       // declare pin 17 to be an input:
    pinMode(Input_Left_1_midle, INPUT);    // declare pin 18 to be an input:
    pinMode(Input_Left_1_Down, INPUT);     // declare pin 19 to be an input:
    
}
 
// the loop routine runs over and over again forever:

    void loop()  {
  
    // read the state of the input value:

    Manual_Switch_buttonState = digitalRead(Manual_Switch);             // if the Manual_Switch is closed, the Low_High_Switch_buttonState is HIGH:
    if (Manual_Switch_buttonState==1) Manual = 1; else Manual=0;        // set bolean Lower to TRUE OR FALSE
    
    Low_High_Switch_buttonState = digitalRead(Low_High_Switch);          // if the Low_High_Switch is closed, the Low_High_Switch_buttonState is HIGH:
    if (Low_High_Switch_buttonState==1) Lower = 1; else Lower=0;        // set bolean Lower to TRUE OR FALSE

    
 
    Input_Right_1_up_buttonState = digitalRead(Input_Right_1_up);          // if the switch is closed, the Input_Right_1_up_buttonState is HIGH:
    if (Input_Right_1_up_buttonState==1) A_1 = 1; else A_1=0;    // set bolean A_1 to TRUE OR FALSE
         
    Input_Right_1_midle_buttonState = digitalRead(Input_Right_1_midle);    // if the switch is closed, the Input_Right_1_midle_buttonState is HIGH:
    if (Input_Right_1_midle_buttonState==true) B_1 = true; else B_1=false; // set bolean B_1 to TRUE OR FALSE
        
    Input_Right_1_Down_buttonState = digitalRead(Input_Right_1_Down);      // if the switch is closed, the Input_Right_1_Down_buttonState is HIGH:
    if (Input_Right_1_Down_buttonState==true) C_1 = true; else C_1=false;  // set bolean C_1 to TRUE OR FALSE
    
    Input_Right_2_up_buttonState = digitalRead(Input_Right_2_up);          // if the switch is closed, the Input_Right_2_up_buttonState is HIGH:
    if (Input_Right_2_up_buttonState==true) A_2 = true; else A_2=false;   // set bolean A_2 to TRUE OR FALSE
    
    Input_Right_2_midle_buttonState = digitalRead(Input_Right_2_midle);    // if the switch is closed, the Input_Right_2_midle_buttonState is HIGH:
    if (Input_Right_2_midle_buttonState==true) B_2 = true; else B_2=false; // set bolean B_2 to TRUE OR FALSE
    
    Input_Right_2_Down_buttonState = digitalRead(Input_Right_2_Down);      // if the switch is closed, the Input_Right_2_Down_buttonState is HIGH:
    if (Input_Right_2_Down_buttonState==true) C_2 = true; else C_2=false;  // set bolean C_2 to TRUE OR FALSE

    Input_Center_up_buttonState = digitalRead(Input_Center_up);           // if the switch is closed, the Input_Center_up_buttonState is HIGH:
    if (Input_Center_up_buttonState==true) A_3 = true; else A_3=false;    // set bolean A_3 to TRUE OR FALSE
    
    Input_Center_midle_buttonState = digitalRead(Input_Center_midle);     // if the switch is closed, the Input_Center_midle_buttonState is HIGH:
    if (Input_Center_midle_buttonState==true) B_3 = true; else B_3=false; // set bolean B_3 to TRUE OR FALSE
    
    Input_Center_Down_buttonState = digitalRead(Input_Center_Down);       // if the switch is closed, the Input_Center_Down_buttonState is HIGH:
    if (Input_Center_Down_buttonState==true) C_3 = true; else C_3=false;  // set bolean C_3 to TRUE OR FALSE

    Input_Left_2_up_buttonState = digitalRead(Input_Left_2_up);           // if the switch is closed, the Input_Left_2_up_buttonState is HIGH:
    if (Input_Left_2_up_buttonState==true) A_4 = true; else A_4=false;    // set bolean A_4 to TRUE OR FALSE
    
    Input_Left_2_midle_buttonState = digitalRead(Input_Left_2_midle);     // if the switch is closed, the Input_Left_2_midle_buttonState is HIGH:
    if (Input_Left_2_midle_buttonState==true) B_4 = true; else B_4=false; // set bolean B_4 to TRUE OR FALSE
    
    Input_Left_2_Down_buttonState = digitalRead(Input_Left_2_Down);       // if the switch is closed, the Input_Left_2_Down_buttonState is HIGH:
    if (Input_Left_2_Down_buttonState==true) C_4 = true; else C_4=false;  // set bolean C_4 to TRUE OR FALSE
    
    Input_Left_1_up_buttonState = digitalRead(Input_Left_1_up);           // check if the switch is closed, the Input_Left_1_up_buttonState is HIGH:
    if (Input_Left_1_up_buttonState==true) A_5 = true; else A_5=false;    // set bolean A_5 to TRUE OR FALSE
    
    Input_Left_1_midle_buttonState = digitalRead(Input_Left_1_midle);     // check if the switch is closed, the Input_Left_1_midle_buttonState is HIGH:
    if (Input_Left_1_midle_buttonState==true) B_5 = true; else B_5=false; // set bolean B_5 to TRUE OR FALSE
    
    Input_Left_1_Down_buttonState = digitalRead(Input_Left_1_Down);         // check if the switch is closed, the Input_Left_1_Down_buttonState is HIGH:
     if ( Input_Left_1_Down_buttonState==true) C_5 = true; else C_5=false;  // set bolean C_5 to TRUE OR FALSE

    
    
    static int state = STATE_IDLE; // initial state is 1, the "idle" state.

    state = (STATE_IDLE);



//  THE MANUAL_SWITCH IS HIGH


     // STATE_IDLE: IF   Manual=1 
     
    if (Manual == HIGH) {
    // IDLE STATE:
     state = (STATE_IDLE);
     }
    
    // LEFT: IF    Manual=1 & A1+A2=0 & (A4 OR A5)>0

    if ((Manual == HIGH) & (A_1 == LOW) & (A_2 == LOW) & (A_3 >= LOW) & ((A_4 > LOW) || (A_5 > LOW))) {
    
    // turn Relay_left on:
    state = (relay_left_on);
        }

    // LEFT: IF  Manual=1 &  B1+B2=0 & (B4+B5)>0

    if ((Manual == HIGH) & (B_1 == LOW) & (B_2 == LOW) & (B_3 >= LOW) & ((B_4 > LOW) || (B_5 > LOW))) {
    // turn Relay_left on:
     state = (relay_left_on);
     }

    // RIGHT: IF  Manual=1 &  (A1 OR A2) > 0 & (A4,A5)=0

    if ((Manual == HIGH) & ((A_1 > LOW) || (A_2 > LOW)) & (A_3 >= LOW) & (A_4 == LOW) & (A_5 == LOW)) {
      
    // turn Relay_Right on:
    state = (relay_right_on);
    } 

    // RIGHT: IF  Manual=1 &  (B1 OR B2) > 0 & (B4,B5)=0

    if ((Manual == HIGH) & ((B_1 > LOW) || (B_2 > LOW)) & (B_3 >= LOW) & (B_4 == LOW) & (B_5 == LOW)) {
      
    // turn Relay_Right on:
    state = (relay_right_on);
    } 

                
    // UP: IF  Manual=1 &  C1 or C2 or C3 or C4 or C5 = 1 CODE OK
    
    if ((Manual == HIGH) & ((C_1 == HIGH) || (C_2 == HIGH) || (C_3 == HIGH) || (C_4 == HIGH) || (C_5 == HIGH)))  {
    // turn Relay_Right on:
    state = (relay_up_on);
    }






    

    // //  THE LOWER SWITCH IS HIGH
    
    // DOWN: IF Lower=1 & Manual=0 & A1+A2+A3+A4+A5=0 & B1,B2,B3,B4,B5=0 

    if ((Lower == HIGH) & (Manual == LOW) & (A_1 == LOW) & (A_2 == LOW) & (A_3 == LOW) & (A_4 == LOW) & (A_5 == LOW) & (B_1 == LOW)  & (B_2 == LOW) & (B_3 == LOW) & (B_4 == LOW) & (B_5 == LOW)) {
    // turn relay down on:
    state = (relay_down_on);
    }

    // DOWN: IF  Lower=1 & Manual=0 &  A3=1 & A1+A2+A4+A5=0 & B1,B2,B3,B4,B5=0 Q4

    if ((Lower == HIGH) & (Manual == LOW) & (A_1 == LOW) & (A_2 == LOW) & (A_3 == HIGH) & (A_4 == LOW) & (A_5 == LOW) & (B_1 == LOW)  & (B_2 == LOW) & (B_3 == LOW) & (B_4 == LOW) & (B_5 == LOW)) {
    // turn relay down on:
    state = (relay_down_on);
    }
       
    // LEFT: IF    Lower=1 & Manual=0 & A1+A2=0 & (A4 OR A5)>0

    if ((Lower == HIGH) & (Manual == LOW) & (A_1 == LOW) & (A_2 == LOW) & (A_3 >= LOW) & ((A_4 > LOW) || (A_5 > LOW))) {
    
    // turn Relay_left on:
    state = (relay_left_on);
        }

    // LEFT: IF  Lower=1 & Manual=0 &  B1+B2=0 & (B4+B5)>0

    if ((Lower == HIGH) & (Manual == LOW) & (B_1 == LOW) & (B_2 == LOW) & (B_3 >= LOW) & ((B_4 > LOW) || (B_5 > LOW))) {
    // turn Relay_left on:
     state = (relay_left_on);
     }

    // RIGHT: IF  Lower=1 & Manual=0 &  (A1 OR A2) > 0 & (A4,A5)=0

    if ((Lower == HIGH) & (Manual == LOW) & ((A_1 > LOW) || (A_2 > LOW)) & (A_3 >= LOW) & (A_4 == LOW) & (A_5 == LOW)) {
      
    // turn Relay_Right on:
    state = (relay_right_on);
    } 

    // RIGHT: IF  Lower=1 & Manual=0 &  (B1 OR B2) > 0 & (B4,B5)=0

    if ((Lower == HIGH) & (Manual == LOW) & ((B_1 > LOW) || (B_2 > LOW)) & (B_3 >= LOW) & (B_4 == LOW) & (B_5 == LOW)) {
      
    // turn Relay_Right on:
    state = (relay_right_on);
    } 

    // DOWN: IF  Lower=1 & Manual=0 &   (A1 OR A2 =1) & A3>=0 & (A4 OR A5 =1) & (B1 TO B5 =0)

    if ((Lower == HIGH) & (Manual == LOW) & ((A_1 == HIGH) || (A_2 == HIGH)) & (A_3 >= LOW) & ((A_4 == HIGH) || (A_5 == HIGH)) & (B_1 == LOW)  & (B_2 == LOW) & (B_3 == LOW) & (B_4 == LOW) & (B_5 == LOW)) {
    // turn relay down on:
    state = (relay_down_on);
    }
    
            
    // STATE_IDLE: IF   Lower=1 & Manual=0 &   B1 to b5 = 0 &  ( A1+A2>0 & A4+A5>0)

    if ((Lower == HIGH) & (Manual == LOW) & ((B_1 > LOW) || (B_2 > LOW)) & (B_3>=0) & ((B_4 > LOW) || (B_5 > LOW))) {
    // IDLE STATE:
     state = (STATE_IDLE);
     }

// UP: IF  Lower=1 & Manual=0 &  C1 or C2 or C3 or C4 or C5 = 1 CODE OK
    
    if ((Lower == HIGH) & (Manual == LOW) & ((C_1 == HIGH) || (C_2 == HIGH) || (C_3 == HIGH) || (C_4 == HIGH) || (C_5 == HIGH)))  {
    // turn Relay_Right on:
    state = (relay_up_on);
    }






// NOW THE LOWER SWITCH IS LOW



    // DOWN: IF Lower=0 & Manual=0 & A1+A2+A3+A4+A5=0

    if ((Lower == LOW) & (Manual == LOW) & (A_1 == LOW) & (A_2 == LOW) & (A_3 == LOW) & (A_4 == LOW) & (A_5 == LOW)) {
    // turn relay down on:
    state = (relay_down_on);
    }

    // DOWN: IF  Lower=0 & Manual=0 & A3=1 & A1+A2+A4+A5=0

    if ((Lower == LOW) & (Manual == LOW) & (A_1 == LOW) & (A_2 == LOW) & (A_3 == HIGH) & (A_4 == LOW) & (A_5 == LOW)) {
    // turn relay down on:
    state = (relay_down_on);
    }
       
    // LEFT: IF    Lower=0 & Manual=0 & A1+A2=0 & (A4 OR A5)>0

    if ((Lower == LOW) & (Manual == LOW) & (A_1 == LOW) & (A_2 == LOW) & (A_3 >= LOW) & ((A_4 > LOW) || (A_5 > LOW))) {
    
    // turn Relay_left on:
    state = (relay_left_on);
        }

    // RIGHT: IF  Lower=0 & Manual=0 &  (A1 OR A2) > 0 & (A4,A5)=0

    if ((Lower == LOW) & (Manual == LOW) & ((A_1 > LOW) || (A_2 > LOW)) & (A_3 >= LOW) & (A_4 == LOW) & (A_5 == LOW)) {
      
    // turn Relay_Right on:
    state = (relay_right_on);
    } 

    // STATE_IDLE: IF   Lower=0 & Manual=0 &   B1 to b5 = 0 &  ( A1+A2>0 & A4+A5>0)

    if ((Lower == LOW) & (Manual == LOW) & ((B_1 > LOW) || (B_2 > LOW)) & (B_3>=0) & ((B_4 > LOW) || (B_5 > LOW))) {
    // IDLE STATE:
     state = (STATE_IDLE);
     }

    // UP: IF  Lower=0 & Manual=0 &  (B1 or B2 or B3 or B4 or B5 or C1 or C2 or C3 or C4 or C5) 
    
    if ((Lower == LOW) & (Manual == LOW) & ((B_1 == HIGH) || (B_2 == HIGH) || (B_3 == HIGH) || (B_4 == HIGH) || (B_5 == HIGH) || (C_1 == HIGH) || (C_2 == HIGH) || (C_3 == HIGH) || (C_4 == HIGH) || (C_5 == HIGH)))  {
    // turn Relay_Right on:
    state = (relay_up_on);
    }




    switch(state)
  {
    case STATE_IDLE:
      // We don't need to do anything here, waiting for a forced state change.
   digitalWrite(Relay_left, LOW);
   digitalWrite(Relay_Right, LOW);
   digitalWrite(Relay_down, LOW);
   digitalWrite(Relay_up, LOW);
      break;
    
   case relay_up_on:
   digitalWrite(Relay_left, LOW);
   digitalWrite(Relay_Right, LOW);
   digitalWrite(Relay_down, LOW);
   digitalWrite(Relay_up, HIGH);
break;

 case relay_down_on:
   digitalWrite(Relay_up, LOW);
   digitalWrite(Relay_left, LOW);
   digitalWrite(Relay_Right, LOW);
   digitalWrite(Relay_down, HIGH);
break;

case relay_left_on:
   digitalWrite(Relay_up, LOW);
   digitalWrite(Relay_Right, LOW);
   digitalWrite(Relay_down, LOW);
   digitalWrite(Relay_left, HIGH);
break;

   case relay_right_on:
   digitalWrite(Relay_up, LOW);
   digitalWrite(Relay_left, LOW);
   digitalWrite(Relay_down, LOW);
   digitalWrite(Relay_Right, HIGH);
break;

  }}

