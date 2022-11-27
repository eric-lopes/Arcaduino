//Biblioteca presente na pasta Bibliotecas. Adcionar ao ambiente Arduino utilizando seu método favorito!    
#include "Joystick.h"

/* Joystick Arcade de 8 botões e um direcional, baseado no padrão de botões do Super Nintendo. Funciona em todos os jogos MAME e FBA/FBNeo.
   Código apresenta, também, as cores dos fios usados para a conexão entre os switchs e o arduino.
   Esquema de montagem apresentado a seguir.

 _______________________________
|                               |
|   C         O      O          |
|   =         Se     St         |
|E === D      O      O      O   |
|   =         Y      X      L   |
|   B         O      O      O   |
|             B      A      R   |
|_______________________________|

*/


//Criando um Joystick Personalizado
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  10, 0,                  // Botões, Hat Switch
  true, true, false,      // Eixos X, Y e Z
  false, false, false,    // Rx, Ry e Rz
  false, false,           // Rudder e Trottle
  false, false, false);   // Acelerador, Freio e Volante

//Definição dos Direcionais
//GND é o pino 14   //Preto
const int DB=13;    //Verde
const int DD=12;    //Amarelo
const int DC=11;    //Azul
const int DE=10;    //Branco

//Definição dos Botões
const int BSt=9;    //Vermelho
const int BSe=8;    //Laranja
const int BR=5;     //Verde
const int BL=4;     //Amarelo
const int BX=7;     //Azul
// Botão X era pra estar no pino 3, porém, por algum motivo, minha placa estava acionando pinos 2 e 3 simultaneamente, tive de trocar para o pino 7. Mas você pode tentar colocar no pino 3!
const int BY=2;     //Branco
const int BA=1;     //Cinza
const int BB=0;     //Roxo

//Definição dos Eixos Analógicos
const int EixoX=0;
const int EixoY=1;

void setup() {
  pinMode(DE,INPUT_PULLUP);
  pinMode(DB,INPUT_PULLUP);
  pinMode(DD,INPUT_PULLUP);
  pinMode(DC,INPUT_PULLUP);
  pinMode(BSt,INPUT_PULLUP);
  pinMode(BSe,INPUT_PULLUP);
  pinMode(BR,INPUT_PULLUP);
  pinMode(BL,INPUT_PULLUP);
  pinMode(BX,INPUT_PULLUP);
  pinMode(BY,INPUT_PULLUP);
  pinMode(BA,INPUT_PULLUP);
  pinMode(BB,INPUT_PULLUP);
  
  Joystick.begin(false);                //Inicia Desligado
  Joystick.setXAxisRange(-100, 100);    //Limites do Eixo X
  Joystick.setYAxisRange(-100, 100);    //Limites do Eixo Y
}

void loop() {
  
  //Lê o botão direcional e transforma em eixo analógico
  Joystick.setYAxis(-10);
  Joystick.setXAxis(10);
  
  if(digitalRead(DB)==LOW){
    Joystick.setYAxis(100);
  }
  if(digitalRead(DC)==LOW){
    Joystick.setYAxis(-100);
  }
  if(digitalRead(DE)==LOW){
    Joystick.setXAxis(-100);
  }
  if(digitalRead(DD)==LOW){
    Joystick.setXAxis(100);
  }

  //Lê os botões 
  if(digitalRead(BB)==LOW){
    Joystick.setButton(0, 1);  
  }else{
    Joystick.setButton(0, 0);  
  }
  if(digitalRead(BA)==LOW){
    Joystick.setButton(1, 1);  
  }else{
    Joystick.setButton(1, 0);  
  }
  if(digitalRead(BY)==LOW){
    Joystick.setButton(2, 1);  
  }else{
    Joystick.setButton(2, 0);  
  }
  if(digitalRead(BX)==LOW){
    Joystick.setButton(3, 1);  
  }else{
    Joystick.setButton(3, 0);  
  }
  if(digitalRead(BL)==LOW){
    Joystick.setButton(4, 1);  
  }else{
    Joystick.setButton(4, 0);  
  }
  
  if(digitalRead(BR)==LOW){
    Joystick.setButton(5, 1);  
  }else{
    Joystick.setButton(5, 0);  
  }
  
  if(digitalRead(BSe)==LOW){
    Joystick.setButton(8, 1);  
  }else{
    Joystick.setButton(8, 0);  
  }
  
  if(digitalRead(BSt)==LOW){
    Joystick.setButton(9, 1);
  }else{
    Joystick.setButton(9, 0);  
  }
  
  //Envia o status por USB
  Joystick.sendState();
  delay(10); 
}
