#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
const int Sensor1 = A0;
const int Sensor2 = A1;
void setup() 
{
  motor1.setSpeed(250);  //Velocidad estándar de 250, máxima velocidad posible 255
  motor2.setSpeed(250);  //Recuerda que puedes cambiar la velocidad estándar en el loop
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
}

void loop() 
{
  int sensor1State = digitalRead(Sensor1);
  int sensor2State = digitalRead(Sensor2);
  if (sensor1State == LOW && sensor2State == LOW) {
    // Mover hacia adelante
    moveForward();
  } else if (sensor1State == HIGH && sensor2State == LOW ) {
    // Mover hacia la Derecha
    turnright();
  } else if (sensor1State == LOW && sensor2State == HIGH ) {
    // Girar a la izquierda
    turnLeft();
  } else {
    // Detenerse si no se detecta la línea
    stopMoving();
  }
  
}
   //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
 
    //Puedes varias la velocidad de 0 como mínima a 255 como maxima
    //Sin embargo con velocidades menores a 100 generalmente el motor ya no tiene la potencia para mover un robot
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(250);
  motor2.setSpeed(250);
}



void turnright() {
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor1.setSpeed(250); 
}

void turnLeft() {
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor2.setSpeed(250); 
}

void stopMoving() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}




