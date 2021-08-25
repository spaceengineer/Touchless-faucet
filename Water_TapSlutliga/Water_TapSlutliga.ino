/* Motion Sensor water tap using a solenoid valve
 *  - Aditya
 */

const int IR1 = 1; 
const int IR2 = 2;
const int IR4 = 4;// This the pin for the IR Sensor
int solenoidPin = 6;    //This is the output pin on the Arduino we are using
int val1 =0; 
int val2 =0; 
int val4 =0; 
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
pinMode(IR1,INPUT);
pinMode(IR2,INPUT);
pinMode(IR4,INPUT);
  pinMode(solenoidPin, OUTPUT);           //Sets the pin as an output
}
 
void loop() {
  val1 = analogRead(IR1);
  val2 = analogRead(IR2);
  val4 = analogRead(IR4);//obtains analog value from sensor in the range of 0 to 1024
  Serial.print(val1);
  
  if(val1 < 500|| val2 < 500 || val4 < 500)   // If a hand is detected by the IR sensor 
  {  
  digitalWrite(solenoidPin, LOW);    //Switch Solenoid ON
  Serial.print("Relay is ON ");
  delay(2000); //Wait for 7 Second
  }
  else
  digitalWrite(solenoidPin, HIGH);  //Switch Solenoid OFF
  Serial.print("Relay is OFF ");   
  //delay(2000);       
}
