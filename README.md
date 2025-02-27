# Controle de Velocidade de Motores DC com Arduino

Este projeto implementa um sistema de controle para dois motores DC utilizando Arduino. A velocidade e o sentido de rotação dos motores podem ser ajustados através de dois botões, permitindo aceleração e desaceleração progressivas.

## Componentes Utilizados
- Arduino (qualquer modelo compatível)
- Ponte H (L298N ou similar) para controle dos motores
- Dois motores DC
- Dois botões para ajuste de velocidade
- Fontes de alimentação adequadas para os motores e o Arduino

## Funcionamento

###Definição dos Pinos

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
