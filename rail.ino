int c;
int d;
int x;
int z;
int pw;
int on;
int off;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  // pinMode(5, OUTPUT); //reset, change the fuse if IO
  d=100;
}

void loop() {
  right();
  flash();
  left();
  flash();
  glow();
}

void right() {
  for (z = 0; z<6; z++) {
    digitalWrite(z, HIGH);
    delay(d);
    digitalWrite(z, LOW);
    delay(d);
  }
}

void left() {
  for (z = 5; z>=0; z--) {
    digitalWrite(z, HIGH);
    delay(d);
    digitalWrite(z, LOW);
    delay(d);
  }
}

void glow() {
  for (c=0; c<2; c++) {
    for (pw = 20; pw <= 100; pw++ ) {
      on = pw;
      off = (100 - pw) * 20;
      for (x = 0; x < 10; x++) { 
        allon();
        delayMicroseconds(on);
        alloff();
        delayMicroseconds(off);
        }
    }
    for (pw = 100; pw > 20; pw-- ) {
      on = pw;
      off = (100 - pw) * 20;
      for (x = 0; x < 10; x++) { 
        allon();
        delayMicroseconds(on);
        alloff();
        delayMicroseconds(off);
        }
    }
  }
}

void flash() {
  for (z = 0; z<6; z++) {
    digitalWrite(z, HIGH);
  }
  delay(d);
  for (z = 0; z<6; z++) {
    digitalWrite(z, LOW);
  }
  delay(d);
}

void allon() {
  for (z = 0; z<6; z++) {
    digitalWrite(z, HIGH);
  }
}

void alloff() {
  for (z = 0; z<6; z++) {
    digitalWrite(z, LOW);
  }
}
