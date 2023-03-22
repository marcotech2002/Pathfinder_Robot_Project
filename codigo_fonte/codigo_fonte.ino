// Inclui biblioteca de funções matematicas
#include <math.h>

//Definindo os pinos para o motor A
#define IN1   7
#define IN2   5
#define VEL_A 6

//Definindo os pinos para o motor B
#define IN3   4
#define IN4   2
#define VEL_B 3

//Definindo os pinos para os botões 
#define BUTTON_1 11
#define BUTTON_2 10

//variavel auxiliar
int velocidade = 0;


void setup()
{
  // Inicializa a serial do arduino
  Serial.begin(9600);

  // Inicializa os pinos do motor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(VEL_A,OUTPUT);
  pinMode(VEL_B,OUTPUT);

  // Inicializa os pinos dos botões
  pinMode(BUTTON_1,INPUT);
  pinMode(BUTTON_2,INPUT);
}


void loop()
{
  // Verifica se o botão 1 foi pressionado
  if(digitalRead(BUTTON_1) == HIGH && velocidade < 250){
    // Incrementa a velocidade do motor
    velocidade += 10;
    // Espera 80 ms
    delay(80); 
  }
  
  // Verifica se o botão 2 foi pressionado
  if(digitalRead(BUTTON_2) == HIGH && velocidade > -250){
    // Decrementa a velocidade do motor
    velocidade -= 10;
    // Espera 80 ms
    delay(80); 
  }

  // Se a velocidade for positiva, o motor gira em um sentido
  if(velocidade > 0)
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  // Se a velocidade for zero, o motor para
  else if (velocidade == 0)
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);   
  }
  // Se a velocidade for negativa, o motor gira em outro sentido
  else if (velocidade < 0)
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
  // Gera saida no pino de controle de velocidade com PWM
  analogWrite(VEL_A,abs(velocidade));
  analogWrite(VEL_B,abs(velocidade));
  // Espera 80 ms
  delay(50);
}