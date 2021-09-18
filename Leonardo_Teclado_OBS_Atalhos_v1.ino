/* *************************
 *  Projeto Bacana - 09/2021
 *  www.projetobacana.com.br
 *  Júlio Vansan Gonçalves
 *  
 *  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
 *  
 *  ************************
 */

#include "Keyboard.h"

const int LED=13;

const int bt01=7;
const int bt02=8;
const int bt03=9;
const int bt04=10;
const int bt05=11;
const int bt06=12;


void setup() {
  Serial.begin(9600); // Habilita a comunicação serial
  pinMode(LED,OUTPUT);
  pinMode(bt01,INPUT_PULLUP);
  pinMode(bt02,INPUT_PULLUP);
  pinMode(bt03,INPUT_PULLUP);
  pinMode(bt04,INPUT_PULLUP);
  pinMode(bt05,INPUT_PULLUP);
  pinMode(bt06,INPUT_PULLUP);
  
  
  Keyboard.begin();
Serial.println("Iniciando");
}

void loop() {
   if (digitalRead(bt01) == LOW) {
      enviaMacro('1',bt01);
    }//Botão 1
   if (digitalRead(bt02) == LOW) {
    enviaMacro('2',bt02);
  }//Botão 2
   if (digitalRead(bt03) == LOW) {
    enviaMacro('3',bt03);
  }//Botão 3
  if (digitalRead(bt04) == LOW) {
    enviaMacro('4',bt04);
  }//Botão 4
  if (digitalRead(bt05) == LOW) {
    enviaMacro('5',bt05);
  }//Botão 5
  
  
 if (digitalRead(bt06) == LOW) {
    enviaMacro(']',bt06);
  }//Botão 6
  
  delay(30);

}//loop

void enviaMacro(char teclaFuncao, int porta){
    digitalWrite(LED,HIGH);     
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(teclaFuncao);
    delay(100);
    Keyboard.releaseAll();
    Serial.print(teclaFuncao);
    Serial.println(" Enviada");
    while(digitalRead(porta) == LOW) {
      delay(30);
    }
    digitalWrite(LED,LOW);
}//enviaMacro
