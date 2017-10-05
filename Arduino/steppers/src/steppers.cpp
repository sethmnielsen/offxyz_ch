#include "Arduino.h"

#define ledPin 13
#define step   11
#define dir0   32
#define dir1   33
#define dir2   38
#define dir3   39
#define ena0   30
#define ena1   31
#define ena2   36
#define ena3   37

int cnt = 0;
int pos = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(step, OUTPUT);
  pinMode(dir0, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(ena0, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(ena3, OUTPUT);

  // initialize Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 625;
  // 312.5 ~= 1 rev/sec at 3200 pulse/rev

  // WGM = Wave Generation Mode: control overall mode of the timer
  // CS = Clock Select: control clock prescaler
  TCCR1B = _BV(WGM12) // CTC mode
         | _BV(CS11);
  TIMSK1 = _BV(OCIE1A); // enable timer compare interrupt

  digitalWrite(step, 0);

  digitalWrite(dir0, 1);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 1);

  digitalWrite(ena0, 1);
  digitalWrite(ena1, 1);
  digitalWrite(ena2, 1);
  digitalWrite(ena3, 1);
}

void loop()
{
  pos = cnt / 10;
  if (cnt >= 32000) {
    digitalWrite(ena0, 0);
    digitalWrite(ena1, 0);
    digitalWrite(ena2, 0);
    digitalWrite(ena3, 0);
  }
}

ISR(TIMER1_COMPA_vect) { // timer compare interrupt service routine
  digitalWrite(step, !digitalRead(step)); // toggle LED pin
  cnt++;
}
