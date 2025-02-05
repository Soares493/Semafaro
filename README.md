**Projeto de um Semáforo com Raspberry Pi Pico W RP2040**

**Descrição**

Este projeto tem como objetivo a implementação de um semáforo com temporização de 3 segundos para cada alteração de sinal utilizando o microcontrolador Raspberry Pi Pico W. O semáforo deve alternar entre as cores vermelha, amarela e verde, com cada cor sendo acesa por 3 segundos. A mudança de estado dos LEDs será controlada por um temporizador e implementada dentro de uma função de call-back, conforme o exemplo da rotina repeating_timer_callback() trabalhada na aula síncrona.

Além disso, a rotina principal do código irá imprimir uma mensagem a cada segundo, utilizando a porta serial, com a mensagem a ser definida pelo usuário.

**Componentes Utilizados**

Microcontrolador Raspberry Pi Pico W: Responsável por controlar a temporização e os LEDs.
LED Vermelho: Representa o sinal de "pare" no semáforo.
LED Amarelo: Representa o sinal de "atenção" no semáforo.
LED Verde: Representa o sinal de "prosseguir" no semáforo.
Resistores de 330 Ω: Protege os LEDs limitando a corrente elétrica.

**Objetivo**

Criar um sistema de semáforo controlado por um temporizador, com a alternância entre as cores vermelha, amarela e verde, com cada cor acesa por 3 segundos. O temporizador será configurado usando a função add_repeating_timer_ms() e a mudança de estado será implementada na função de call-back do temporizador.

Além disso, a cada 1 segundo, a rotina principal deve imprimir uma mensagem na porta serial.

" 3 segundos passou "


**A sequência do semáforo será a seguinte:**

LED Vermelho aceso por 3 segundos (Pare).
LED Verde aceso por 3 segundos (Siga).
LED Amarelo aceso por 3 segundos (Atenção).
A sequência se repete ciclicamente.

**Diagrama de Conexão dos Componentes**

LED Vermelho: Conectado ao pino GPIO 11.  
LED Amarelo: Conectado ao pino GPIO 12.  
LED Verde: Conectado ao pino GPIO 13.  
Resistores de 330 Ω: Cada LED deve ser conectado a um resistor de 330 Ω em série para limitar a corrente.
Requisitos do Projeto
Temporização de 3 segundos: O temporizador deve ser configurado para alterar o estado dos LEDs a cada 3 segundos.
Função repeating_timer_callback(): A mudança de estado dos LEDs deve ser implementada dentro desta função de call-back, que será chamada periodicamente pelo temporizador.
Impressão de Mensagens: A rotina principal deve imprimir uma mensagem a cada 1 segundo usando a porta serial.
Experimento com BitDogLab: Utilizar a ferramenta BitDogLab para testar o código com o LED RGB conectado aos pinos GPIO 11, 12 e 13.

**Instruções de Implementação**

**1. Configuração do Circuito**

LED Vermelho: Conecte o LED vermelho ao pino GPIO 15, com um resistor de 330 Ω em série.
LED Amarelo: Conecte o LED amarelo ao pino GPIO 14, com um resistor de 330 Ω em série.
LED Verde: Conecte o LED verde ao pino GPIO 13, com um resistor de 330 Ω em série.
Porta Serial: O Raspberry Pi Pico W será conectado ao computador para imprimir mensagens na porta serial.