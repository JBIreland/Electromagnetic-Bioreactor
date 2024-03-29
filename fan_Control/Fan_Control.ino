int sensorPin = A0;
int PWM = 3;
int sensorValue;
int PWMValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(PWM, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //this code prints sensor value to the console
  Serial.println(sensorValue);
  delay(1000);

  //read sensor value and set upper limit cap
  sensorVal = analogRead(sensorPin);
  if(sensorValue >800){
    sensorValue = 800;
  }

  //map and assign pwm values to the fan output 0 to 255 corresponds to 0 to 100%
  PWMValue = map(sensorValue, 450, 800, 26, 255);

  //set 450 as out cutout or cut in limit where the fan switches from off to the lower PWM limit
  if(sensorValue <450){
    PWMValue = 0;
  }

  //write the PWM value to the pwm output pin
  analogWrite(PWM, PWMValue);

}
