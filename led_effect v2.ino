#define t 30
#define t1 20
#define t2 100
#define t3 50
int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {
// set up pins 2 to 13 as outputs
pinMode(10,INPUT_PULLUP);
pinMode(11,INPUT_PULLUP);
pinMode(12,INPUT_PULLUP);
pinMode(13,INPUT_PULLUP);

for (int i = 2; i <= 9; i++) {
pinMode(i, OUTPUT);
}
}
/////////////////////////////////////////////////////////////////////////////////Effect 1
void loop(){
  
buttonState = digitalRead(13);
if (buttonState == LOW) {
  effect_4();
}
buttonState2 = digitalRead(12);
if (buttonState2 == LOW) {
  effect_3();
}
buttonState3 = digitalRead(11);
if (buttonState3 == LOW) {
  effect_2();
}
buttonState4 = digitalRead(10);
if (buttonState4 == LOW) {
  effect_1();
}


}

//left to right and right to left
void effect_1()
{
for(int i=2; i<10; i++){
digitalWrite(i, HIGH);
delay(t1);
digitalWrite(i+1, HIGH);
delay(t1);
digitalWrite(i+2, HIGH);
delay(t1);
digitalWrite(i, LOW);
delay(t1);
digitalWrite(i+1, LOW);
delay(t1);
}
for(int i=9; i>1; i--){
digitalWrite(i, HIGH);
delay(t1);
digitalWrite(i-1, HIGH);
delay(t1);
digitalWrite(i-2, HIGH);
delay(t1);
digitalWrite(i, LOW);
delay(t1);
digitalWrite(i-1, LOW);
delay(t1);
}
reset();
}
/////////////////////////////////////////////////////////////////////////////////Effect 2
void effect_2()
{
int count = 9; // keeps track of second LED movement

// move first LED from left to right and second from right to left
for (int i = 2; i < 9; i++) {
clear();
digitalWrite(i, HIGH); // chaser 1
digitalWrite(count, HIGH); // chaser 2
count--;
// stop LEDs from appearing to stand still in the middle
if (count != 5) {
delay(t2);
}
}

// move first LED from right to left and second LED from left to right
for (int i = 9; i > 2; i--) {
clear();
digitalWrite(i, HIGH); // chaser 1
digitalWrite(count, HIGH); // chaser 2
count++;
// stop LEDs from appearing to stand still in the middle
if (count != 4) {
delay(t2);
}
}
clear();
}



void effect_3()
{
for(int j = 2; j <= 9; j++){
digitalWrite(j, HIGH);
delay(t2);
j=j+1;
}
for(int j = 2; j <= 9; j++){
digitalWrite(j, LOW);
delay(t2);
}

for(int k = 11; k > 2; k--){
digitalWrite(k, HIGH);
delay(t2);
k=k-1;
}
for(int k = 11; k > 2; k--){
digitalWrite(k, LOW);
delay(t2);
}
reset();
}




/////////////////////////////////////
void effect_4()
{
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin, HIGH);
delay(t1);
digitalWrite(pin+1, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+1, HIGH);
delay(t1);
digitalWrite(pin+2, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+2, HIGH);
delay(t1);
digitalWrite(pin+3, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+3, HIGH);
delay(t1);
digitalWrite(pin+4, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+4, HIGH);
delay(t1);
digitalWrite(pin+5, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+5, HIGH);
delay(t1);
digitalWrite(pin+6, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+6, HIGH);
delay(t1);
digitalWrite(pin+7, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+7, HIGH);
delay(t1);
digitalWrite(pin+8, LOW);
delay(t1);
}
for(int pin = 9; pin >= 2; pin--)
{
digitalWrite(pin+8, HIGH);
delay(t1);
digitalWrite(pin+9, LOW);
delay(t1);

for (int i = 2; i <= 9; i++) {
digitalWrite(i, LOW);
}
}
reset();

}


// function to switch all LEDs off
void clear(void)
{
for (int i = 2; i <= 9; i++) {
digitalWrite(i, LOW);
}
}
void reset() {
  // Include necessary header for assembly instruction
  #include <avr/io.h>

  // Cast 0 to a pointer to a function of type void with no arguments
  void (*reset_func) (void) = (void*)0;

  // Call the function pointer to trigger reset (effectively jumps to address 0)
  reset_func();
}
