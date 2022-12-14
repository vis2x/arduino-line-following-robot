#define leftSensor analogRead(A2)
#define middleSensor analogRead(A1)
#define rightSensor analogRead(A0)
#define threshold 100
#define motor_speed_pin 3
#define motor_speed 100

void forwardLeft(int speed){ // Turns left and moves forward
  analogWrite(3, speed); // updates the speed
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
}

void forwardRight(int speed){ // Turns right and moves forward
  analogWrite(3, speed); // updates the speed
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
}

void backLeft(int speed){ // Turns left and moves back
  analogWrite(3, speed); // updates the speed
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
}

void backRight(int speed){ // Turns right and moves back
  analogWrite(3, speed); // updates the speed
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
}

void stopLeft(int speed){ // Stops left side of the robot 
  analogWrite(3, speed); // updates the speed
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
}

void stopRight(int speed){ // Stops right side of the robot
  analogWrite(3, speed); // updates the speed
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}

void stop(){
  analogWrite(3, 0);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void setup() {
  analogWrite(3, motor_speed);
  Serial.begin(9600);
}

void loop() {
    if ((leftSensor < threshold) && (middleSensor < threshold) && (rightSensor < threshold)){
      while ((leftSensor < threshold) && (middleSensor < threshold) && (rightSensor < threshold)){        
        // LOST
        backLeft(70);
        backRight(70);
      }
    }

    if ((leftSensor < threshold) && (middleSensor < threshold) && (rightSensor > threshold)){
      while ((leftSensor < threshold) && (middleSensor < threshold) && (rightSensor > threshold)){
        // TURN RIGHT
        stopRight(100);
        forwardLeft(100);
      }
    }

    if ((leftSensor < threshold) && (middleSensor > threshold) && (rightSensor < threshold)){
      while ((leftSensor < threshold) && (middleSensor > threshold) && (rightSensor < threshold)){
        // GOES STRAIGHT
        forwardRight(100);
        forwardLeft(100);
      }
    }

    if ((leftSensor < threshold) && (middleSensor > threshold) && (rightSensor > threshold)){
      while ((leftSensor < threshold) && (middleSensor > threshold) && (rightSensor > threshold)){
        // HARD TURN RIGHT
        backRight(150);
        forwardLeft(150);
      }
    }

    if ((leftSensor > threshold) && (middleSensor < threshold) && (rightSensor < threshold)){
      while ((leftSensor > threshold) && (middleSensor < threshold) && (rightSensor < threshold)){
        // TURN LEFT
        stopLeft(100);
        forwardRight(100);
      }
    }

    if ((leftSensor > threshold) && (middleSensor < threshold) && (rightSensor > threshold)){
      while ((leftSensor > threshold) && (middleSensor < threshold) && (rightSensor > threshold)){
        // STANDING IN BETWEEN TWO LINES
        backLeft(80);
        backRight(80);
      }
    }

    if ((leftSensor > threshold) && (middleSensor > threshold) && (rightSensor < threshold)){
      while ((leftSensor > threshold) && (middleSensor > threshold) && (rightSensor < threshold)){
        // HARD TURN LEFT
        backLeft(150);
        forwardRight(150);
      }
    }

    if ((leftSensor > threshold) && (middleSensor > threshold) && (rightSensor > threshold)){
      while  ((leftSensor > threshold) && (middleSensor > threshold) && (rightSensor > threshold)){
        // STANDING ON TOP OF THE LINE => GO STRAIGHT
        forwardRight(100);
        forwardLeft(100);
      }
    }
}