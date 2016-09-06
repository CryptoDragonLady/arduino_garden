//INCLUDES//////////////
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
/////END OF INCLUDES////

//GLOBAL VARIABLES//////

//Digital Pin///////////
int relayOne = 7;//light relay
int relayFive = 8;//pot one valve
int relaySix = 9;//pot two valve
int relaySeven = 10;//pot three valve
int relayEight = 11;//pot four valve
//End Digital Pin//////

//Analog Pins//////////
int potOneSoilSensor = 0;
int potTwoSoilSensor = 1;
int potThreeSoilSensor = 2;
int potFourSoilSensor = 3;
LiquidCrystal_I2C lcd(0x3f,20,4); // analog pins 4 and 5
//End Analog Pins//////
int oneSecond = 1000;
int moisturePotOne,moisturePotTwo,moisturePotThree,moisturePotFour = 1000;
int lightTime = 0;
int soilCheckTimer = 0;
boolean lightOn = false;
////END GLOBAL VARIABLES////


void setup() {
  Serial.begin(9600);
  light_setup();
  display_setup();
  valve_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  light_check_time();
  check_soil_moisture();
  delay(oneSecond);
}


/////////////MOISTURE SENSOR STUFf/////
void check_soil_moisture(){
  if(soilCheckTimer == (oneSecond * 60 * 60){
    
    for(int x  = 1; x <= 15; x++){
      moisturePotOne += analogRead(potOneSoilSensor);
      moisturePotTwo += analogRead(potTwoSoilSensor);
      moisturePotThree += analogRead(potThreeSoilSensor);
      moisturePotFour += analogRead(potFourSoilSensor);
    }
    moisturePotOne =   (moisturePotOne / 15);
    moisturePotTwo =   (moisturePotTwo / 15);
    moisturePotThree = (moisturePotThree / 15);
    moisturePotFour =  (moisturepotFour / 15);  
  
    Serial.print("p1: ");
    Serial.println(moisturePotOne);
    Serial.print("p2: ");
    Serial.println(moisturePotTwo);
    Serial.print("p3: ");
    Serial.println(moisturePotThree);
    Serial.print("p4: ");
    Serial.println(moisturePotFour;
  
    if(moisturePotOne <= 700)
      waterPot(1);
    if(moisturePotTwo <= 700)
      waterPot(2);
    if(moisturePotThree <= 700)
      waterPot(3);
    if(moisturePotFour <= 700)
      waterPot(4);
      
    check_soil_moisture = 0;
  }
  else
    check_soil_moisture++;
    
}
/// END MOISTURE SENSOR STUFF//////////

/////////////LIGHT STUFF///////////////
void light_setup(){
  pinMode(relayOne, OUTPUT);
  digitalWrite(relayOne,HIGH);
  lightTime = 0;
}

void light_check_time(){
  if(lightTime <= 60){
    digitalWrite(relayOne,HIGH);
    lightTime++;
  }
  else if(lightTime > 60 && lightTime < 120){
    digitalWrite(relayOne,LOW);
    lightTime++;
  }
  else{
    lightTime = 0;
  }
}
/////////////END LIGHT STUFF///////////

////////////VALVE STUFF////////////////
void valve_setup(){
  pinMode(relayFive,OUTPUT);
  pinMode(relaySix,OUTPUT);
  pinMode(relaySeven,OUTPUT);
  pinMode(relayEight,OUTPUT);
  digitalWrite(relayFive,HIGH);
  digitalWrite(relaySix,HIGH);
  digitalWrite(relaySeven,HIGH);
  digitalWrite(relayEight,HIGH);
}
void waterPot(int potToWater){
  if(potToWater == '1'){
    digitalWrite(relayFive, LOW);
    delay(oneSecond * 15);
    digitalWrite(relayFive, HIGH);
    Serial.println("pot one watered);
  }
    if(potToWater == '2'){
    digitalWrite(relaySix, LOW);
    delay(oneSecond * 15);
    digitalWrite(relaySix, HIGH);
    Serial.println("pot two watered);
  }
    if(potToWater == '3'){
    digitalWrite(relaySeven, LOW);
    delay(oneSecond * 15);
    digitalWrite(relaySeven, HIGH);
    Serial.println("pot three watered);
  }
    if(potToWater == '4'){
    digitalWrite(relayEight, LOW);
    delay(oneSecond * 15);
    digitalWrite(relayEight, HIGH);
    Serial.println("pot four watered);
  }
}
///////////END VALVE STUFF/////////////

//////////// DISPLAY STUFF ///////////
void display_setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("LCD BOOT SUCCESS");
  lcd.setCursor(0,1);
  lcd.print("Welcome Master! =)");
}

///////////END DISPLAY STUFF//////////


