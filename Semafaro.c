#include <stdio.h> 
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define LED_PIN_RED 11    // Pino GPIO para o LED vermelho
#define LED_PIN_YELLOW 12 // Pino GPIO para o LED amarelo
#define LED_PIN_GREEN 13  // Pino GPIO para o LED verde

int current_led = 0; // Controla o LED atual (0: vermelho, 1: amarelo, 2: verde)
bool led_on = false; // Estado do LED (ligado ou desligado)

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    
    printf("3 segundos passou\n");
    
    // Desliga todos os LEDs
    gpio_put(LED_PIN_RED, false);
    gpio_put(LED_PIN_YELLOW, false);
    gpio_put(LED_PIN_GREEN, false);

    // Acende o próximo LED de acordo com o estado de 'current_led'
    if (current_led == 0) {
        gpio_put(LED_PIN_RED, true);   // Acende o LED vermelho
    } else if (current_led == 1) {
        gpio_put(LED_PIN_YELLOW, true); // Acende o LED amarelo
    } else if (current_led == 2) {
        gpio_put(LED_PIN_GREEN, true);  // Acende o LED verde
    }

    // Atualiza o índice do LED a ser aceso (sequência: vermelho -> amarelo -> verde)
    current_led = (current_led + 1) % 3;

    // Retorna true para continuar chamando a função de callback a cada 3 segundos
    return true;
}

int main() {
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializa os pinos GPIO
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Declaração de uma estrutura de temporizador de repetição.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos (3000 ms)
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução
    while (true) {
        // Aqui, o loop principal não faz nada, pois a lógica de controle dos LEDs é gerenciada pelo temporizador.
        tight_loop_contents(); // Função que ajuda a economizar CPU em loops vazios

         // Pausa de 10 segundos para reduzir o uso da CPU.
        sleep_ms(10000);
        printf("rotina de repetição\n");
    }

    return 0;
}
