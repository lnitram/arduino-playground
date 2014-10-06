#include <LiquidCrystal.h>
#define RIGHT  0
#define UP     1
#define DOWN   2
#define LEFT   3
#define SELECT 4
#define NONE   5

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// for keys pressed on lcd-shield
int key = 0;
int key_raw = 0;


int secretNumber = 0;
int userNumber = 0;
int keyPressed = 0;
int add = 0;
int tries = 0;
int gameStarted = 0;

// read the buttons
int readButtons() {
 key_raw = analogRead(0);   
 if (key_raw > 1000) return NONE; 
 if (key_raw < 50)   return RIGHT;  
 if (key_raw < 250)  return UP; 
 if (key_raw < 450)  return DOWN; 
 if (key_raw < 650)  return LEFT; 
 if (key_raw < 850)  return SELECT;  
 return NONE; 
}

void setup() {
 lcd.begin(16, 2); 
 stopGame();
}

void startGame() {
  randomSeed((int)millis()/1000); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Zahl zw. 1-100?");
  secretNumber = random(0, 100);
  gameStarted = 1;
  add = 0;
  tries = 0;
}

void stopGame() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Zahlenraten");
    lcd.setCursor(0,1);
    lcd.print("Start mit SELECT");
    secretNumber = random(0, 100); 
    userNumber = 0;
    gameStarted = 0; 
}

void cursorPressed(int value) {
   keyPressed = 1; 
   add = value;
}

void selectPressed() {
  if (gameStarted == 0) {
    startGame();
    delay(100);
  } else {
         tries++;
         if (userNumber < secretNumber) {
           lcd.setCursor(5,1);
           lcd.print("Zu klein");
           delay(1000);
       } else if (userNumber > secretNumber) {
          lcd.setCursor(5,1);
          lcd.print("Zu gross ");
           delay(1000);
       } else if (userNumber == secretNumber) {
           lcd.setCursor(5,1);
           lcd.print("RICHTIG  "); 
            delay(1000);
           lcd.setCursor(5,1);
           lcd.print(tries);
           lcd.print(" Versuche");
           delay(1000);
           stopGame();
       }
    }
}

 
void loop() {
 lcd.setCursor(0,1);          
 key = readButtons();

 switch (key)
 {
   case RIGHT: { cursorPressed(10);  break;  }
   case LEFT:  { cursorPressed(-10); break;  }
   case UP:    { cursorPressed(1);   break;  }
   case DOWN:  { cursorPressed(-1);  break;  }
   case SELECT: { selectPressed(); break; }
   case NONE: {
     if (keyPressed == 1) {
       userNumber += add;
       keyPressed = 0; 
     }
     break;
   } 
 }
 
 if (gameStarted) {
      lcd.setCursor(0,1);
      if (userNumber > 100) userNumber = 100;
      if (userNumber < 0) userNumber = 0;
      if (userNumber < 100) lcd.print(0);
      if (userNumber < 10) lcd.print(0);
      lcd.print(userNumber);
 }
}
