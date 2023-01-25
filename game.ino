#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int arrValuesMin[] = {1003, 910, 830, 770, 710, 660, 620, 580, 550, 520, 490, 470};
int arrValuesMax[] = {1043, 950, 870, 810, 750, 700, 659, 619, 579, 549, 519, 489};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Try to memorize ");
  lcd.setCursor(2, 1);
  lcd.print("the numbers");
  delay(3000);
  lcd.clear();
  lcd.print("Level 1");
  delay(2000);
}

int currentVal = 0;
const int EXPECTING = 0;
const int GENERATING = 1;
const int CHECK = 2;
const int WIN = 3;
const int LOSS = 4;
const int NEWGAME = 5;
const int FINISHED = 6;

int zustand = GENERATING;

int lvl = 1;
int sol[15];
int guess = 0;
int guessNr = 0;

void loop() {
  switch(zustand) {
    case EXPECTING:
      currentVal = analogRead(A1);
      for(int i = 1; i < 13; i++){
        if((currentVal > arrValuesMin[i-1]) && (currentVal < arrValuesMax[i-1])) {
          lcd.print(i);
          guess = i;
          zustand = CHECK;
        }
      }
    break;

    case CHECK:
      delay(700);
      lcd.clear();
      guessNr++;
      if(guess == sol[guessNr-1]){
        delay(1000);
        lcd.clear();
        if(guessNr == (2 + lvl)){
          if(lvl == 20){
            zustand = FINISHED;
          }
          zustand = WIN;
        }else{
          zustand = EXPECTING;
        }
      }
      else{
        lcd.print("Wrong!!");
        delay(2000);
        lcd.clear();
        zustand = LOSS;
      }
  
    break;

    case GENERATING:
      for(int i = 0; i < (2 + lvl); i++){
        int num = rand() % 12 + 1;
        sol[i] = num;
        delay(2000);
        lcd.clear();
        lcd.print(num);
      }
      delay(2000);
      lcd.clear();
      zustand = EXPECTING;
    break; 

    case WIN:
      lvl++;
      guessNr = 0;
      for(int i = 0; i < 15; i++){
        sol[i] = 0;
      }
      lcd.clear();
      lcd.print("Congrats!       ");
      lcd.setCursor(2, 1);
      lcd.print("Now:            ");
      delay(2000);
      lcd.clear();
      lcd.print("Level " + String(lvl));
      delay(3000);
      lcd.clear();
      zustand = GENERATING;
    break;

    case LOSS:
      lcd.clear();
      lcd.print("Level: " + String(lvl));
      lcd.setCursor(2, 1);
      lcd.print("Score: " + String(guessNr-1) +  "/" + String(2 + lvl));
      delay(4500);
      lcd.clear();
      zustand = NEWGAME;
    break;

    case NEWGAME:
      lcd.print("Press 1 for     ");
      lcd.setCursor(2, 1);
      lcd.print("new game        ");
      currentVal = analogRead(A1);
      if((currentVal > arrValuesMin[0]) && (currentVal < arrValuesMax[0])) {
        lcd.clear();
        lcd.print("Try to memorize ");
        lcd.setCursor(2, 1);
        lcd.print("the numbers");
        delay(3000);
        lcd.clear();
        lcd.print("Level 1");
        delay(2000);
        lcd.clear();
        for(int i = 0; i < 15; i++){
          sol[i] = 0;
        }
        guessNr = 0;
        lvl = 1;
        zustand = GENERATING;
      }  
      break;

      case FINISHED:
        lcd.clear();
        lcd.print("Well done!      ");
        lcd.print("You made it!    ");
        delay(5000);
        lcd.clear();
        zustand = NEWGAME;
      break;
  }
}
