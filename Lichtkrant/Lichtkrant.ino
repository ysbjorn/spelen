#include <CScrollKrant.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int deVertraging=200;
long timer = 0;
int minHelft = 482;//onder deze waarde [0,1023] false
int maxHelft = 542;//boven deze waarde [0,1023] true
int tijdTussenMeting = 200;//voorkom dat een enkele joystick beweging
                           //meerdere signalen doorgeeft

unsigned int joyHorizontaal = 0;//analoge pin van joystick-x
unsigned int joyVerticaal = 1;//analoge pint van joystick-y

CScrollKrant deScrollKrant("En om een lang verhaal kort te maken, gaan we hier een lange tekst laten zien", 16, deVertraging, 5);
int count=0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello World");
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:  
  int versnel = analogRead(joyHorizontaal);
  //Serial.print("horizontaal: ");
  //Serial.println(versnel);
  if (millis()-timer>tijdTussenMeting)  {
    if (versnel<minHelft) {
      deScrollKrant.vertraag();
      timer=millis();
    }
    if (versnel>maxHelft) {
      deScrollKrant.versnel();
      timer=millis();
    }
    
  }
//  delay(100);//vertraing nodig omdat de waarde van de analoge pins anders gelijk is
  int richting = analogRead(joyVerticaal);
  if (millis()-timer>tijdTussenMeting) {
    if (richting < minHelft) {
      deScrollKrant.setVoorwaarts(false);
      timer=millis();
    }
    if (richting > maxHelft) {
      deScrollKrant.setVoorwaarts(true);
      timer=millis();
    }
  }
  //Serial.print("verticaal: ");
  //Serial.println(richting);
  
  lcd.setCursor(0,0);
  if (millis()/deScrollKrant.getVertraging()>count) {
    count++;
    lcd.print(deScrollKrant.getVolgende());
  }
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  lcd.setCursor(8,1);
  lcd.print("s=");
  lcd.print(deScrollKrant.getVertraging());
}
