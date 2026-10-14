#include <Otto.h>
Otto Otto;
#define LeftLeg 3 // left leg pin, servo[0]
#define RightLeg 5 // right leg pin, servo[1]
#define LeftFoot 6// left foot pin, servo[2]
#define RightFoot 9 // right foot pin, servo[3]
#define Buzzer 12 //buzzer pin
long ultrasound_distance_simple() {
 long duration, distance;
 digitalWrite(8,LOW);
 delayMicroseconds(2);
 digitalWrite(8, HIGH);
 delayMicroseconds(10);
 digitalWrite(8, LOW);
 duration = pulseIn(7, HIGH);
 distance = duration/58;
 return distance;
}
void setup() {
 Serial.begin(9600); // Initialize serial communication
 randomSeed(analogRead(0)); // Seed the random number generator with an analog 
pin's value
 Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
Otto.home();
 pinMode(8, OUTPUT); //trig
 pinMode(7, INPUT);//echo pin
}
void loop() {
 int randomNumber = random(0, 6); // Generate a random number between 1 and 10
 Serial.print("Random Number: ");
8
 Serial.println(randomNumber);
 switch (randomNumber) {
 case 1:
 // Do something for case 1
 Serial.println("Case 1: Action A");
 if (ultrasound_distance_simple() < 15 && ultrasound_distance_simple() !=0)
{
 Otto.moonwalker(4, 1500, 40, 1);
 Otto.walk(5,750,1); // FORWARD
 Otto.walk(5,750,-1);
 Otto.swing(2, 1000, 25);
 //Otto.jitter(2, 1000, 25);
 Otto.sing(S_superHappy);
 Otto.home();
 }
 break;
 case 2:
 // Do something for case 2
 Serial.println("Case 2: Action B");
 if (ultrasound_distance_simple() < 15 && ultrasound_distance_simple() !=0)
{
 Otto.turn(3,1000,1); //
 Otto.walk(5,750,1); // FORWARD
 Otto.walk(5,750,-2);
 // Otto.jitter(2, 1000, 25);
 Otto.ascendingTurn(5, 1000, 45);
 Otto.turn(3,750,-1); // LEFT
 Otto.sing(S_sleeping);
 Otto.home();
 }
 delay(500);
 break;
 case 3:
 // Do something for case 3
 Serial.println("Case 3: Action C");
 if (ultrasound_distance_simple() < 15 && ultrasound_distance_simple() !=0)
{
 Otto.walk(5,1000,1); // FORWARD
 
 Otto.sing(S_OhOoh2);
9
 Otto.walk(5,1000,-1); // BACKWARD
 // Otto.bend(1,1250,1);
 Otto.sing(S_OhOoh);
 // Otto.bend(1,1250,-1);
 
 Otto.home();
 }
 break;
 case 4:
 // Do something for case 4
 Serial.println("Case 4: Action D");
 if (ultrasound_distance_simple() < 15 && ultrasound_distance_simple() !=0)
{
 Otto.flapping(1, 1000, 25, 1);
 // Otto.flapping(1, 1000, 25, -1);
 Otto.sing(S_connection);
 Otto.swing(3, 1000, 25);
 
 Otto.updown(3, 1000, 25);
 Otto.tiptoeSwing(3, 1000, 25);
 Otto.sing(S_fart2);
 Otto.home();
 }
 break;
 case 5:
 // Do something for case 5
 Serial.println("Case 5: Action E");
 if (ultrasound_distance_simple() < 15 && ultrasound_distance_simple() !=0)
{
 Otto.walk(5,750,1); // FORWARD
 Otto.walk(5,750,-1); // BACKWARD
 Otto.sing(S_buttonPushed);
 Otto.moonwalker(2, 1500, 25, -1);
 delay(1000);
 Otto.swing(1, 1000, 25);
 Otto.sing(S_superHappy);
 //Otto.sing(PIRATES);
 Otto.home();
 }
 Otto.home();
 }
10
 delay(500); // Delay for 2 seconds before generating another random number
}


otto