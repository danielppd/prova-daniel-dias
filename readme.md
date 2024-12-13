# Semáforos Inteligentes
O desafio dessa prova foi desenvolver um código para o desenvolvimento de um semáforo inteligente, capaz de identificar quando está à noite e ativar seu modo noturno (o LED amarelo ficar piscando a cada 1 segundo) e funcionar normalmente durante o dia, com exceção de um controle inteligente para abrir o sinal verde ao pressionar um botão, quando o sinal estiver no vermelho.

## Estado normal

<div align="center">
<sub>LED Verde Aceso</sub><br>
<img src="ledVerde.png" width="80%"><br>
</div>

<div align="center">
<sub>LED Amarelo Aceso</sub><br>
<img src="ledAmarelo.png" width="80%"><br>
</div>

<div align="center">
<sub>LED Vermelho Aceso</sub><br>
<img src="ledVermelho.png" width="80%"><br>
</div>

## Modo noturno
Defini o limite para o modo noturno ser ativado com uma luminosidade abaixo de 500 e inseri uma mensagem no monitor serial para ficar claro quando o modo noturno estiver ativado, sendo assim, temos:

<div align="center">
<sub>LED Vermelho Aceso</sub><br>
<img src="modoNoturno.png" width="80%"><br>
</div>

## Botão pressionado
Adicionei uma lógica com millis() para remover o boucing do botão, mas não consegui cumprir o objetivo de fazer ele acender o LED verde enquanto estivesse com o LED vermelho aceso.

<div align="center">
<sub>Botão</sub><br>
<img src="botao.png" width="80%"><br>
</div>

