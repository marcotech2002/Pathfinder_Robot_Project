# Controle de Velocidade de Motores DC com Arduino

Este projeto implementa um sistema de controle para dois motores DC utilizando Arduino. A velocidade e o sentido de rotação dos motores podem ser ajustados através de dois botões, permitindo aceleração e desaceleração progressivas.

## Ferramentas Utilizadas

![Logo do Arduino](https://dl.flathub.org/media/cc/arduino/IDE2/27be89787ca1f54a511cefb1fbed7455/icons/128x128@2/cc.arduino.IDE2.png) ![Logo do C++](https://cdn-icons-png.flaticon.com/256/6132/6132222.png)

- IDE do Arduino
- Linguagem de programação C++

## Componentes Utilizados

- Arduino (qualquer modelo compatível) (foi utilizado o Arduino Uno)
- Ponte H (L298N ou similar) para controle dos motores
- Dois motores DC
- Dois botões para ajuste de velocidade
- Fontes de alimentação adequadas para os motores e o Arduino (foi utilizada uma bateria de 9V)

## Funcionamento

### Definição dos Pinos

- Os motores são controlados por meio de pinos digitais e PWM.
- Os botões de controle utilizam entradas digitais.

### Configuração Inicial (setup)

- Inicializa a comunicação serial para monitoramento.
- Define os pinos dos motores e botões como entradas/saídas.

### Laço Principal (loop)

- Se o botão 1 for pressionado, a velocidade aumenta até um limite máximo (+250).
- Se o botão 2 for pressionado, a velocidade diminui até um limite mínimo (-250).
- Dependendo do valor da velocidade:
  - Se for positiva, os motores giram para frente.
  - Se for zero, os motores param.
  - Se for negativa, os motores giram para trás.
- O ajuste da velocidade é feito via PWM nos pinos de controle dos motores.
  
### Observação

- O código usa um delay de 80 ms para evitar leituras erradas dos botões.
- A função abs(velocidade) garante que o PWM sempre receba valores positivos, independente do sentido de rotação.

## Circuito

- Imagem do circuito eletrônico junto aos arquivos na branch `development`

## Executar o projeto

1. Clone o repositório e acesse a branch correta:

    ```
    git clone <repo-url>
    cd nome-do-projeto
    git checkout development
    ```

2. Abra o Arduino IDE e conecte seu Arduino ao computador via cabo USB.
3. Abra o arquivo com a extensão `.ino`
4. Selecione a placa correta:
    - Vá em Ferramentas > Placa e escolha o modelo do seu Arduino (ex: "Arduino Uno").
5. Selecione a porta correta:
    - Vá em Ferramentas > Porta e selecione a porta COM correspondente ao seu Arduino.
6. Carregue o código clicando no botão Upload (seta para a direita).
7. Desconecte o cabo e monte o circuito seguindo o esquemático da imagem.

## Testar o Projeto

- Pressione Botão 1 para aumentar a velocidade dos motores.
- Pressione Botão 2 para reduzir a velocidade.
- Os motores devem girar para frente quando a velocidade for positiva e para trás quando for negativa.
- Acompanhe os valores de velocidade pelo Monitor Serial no Arduino IDE (9600 baud).
