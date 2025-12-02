// indo para o trabalho me peguei pensando em como eu faria um programa simulando o metrô de São Paulo, então aqui estou eu, iniciando esse pequeno projeto, com o objetivo de colocar em prática meus conhecimentos em C e lógica de programação. 

#include <stdio.h> // vou usar para entrada e saída de dados
#include <string.h> // vou usar para manipulação de strings
#include <time.h> // vou usar para simular o tempo de espera nas estações

#define MAX_ESTACOES 10 
#define ESTACAO_FINAL 9
#define TEMPO_ESPERA 30 

#define PORTA_ABERTA 1
#define PORTA_FECHADA 0


int estacao_atual = 0;
int estado_porta = PORTA_FECHADA;

void abrirPorta() {
    estado_porta = PORTA_ABERTA;
    printf("Porta aberta na estação %d\n", estacao_atual);
}

void fechar_porta() {
    estado_porta = PORTA_FECHADA;
    printf("Porta fechada na estação %d\n", estacao_atual);
}

void espera(int segundos) {
    segundos = 30;
    sleep(segundos);
}




/* 
por enquanto eu penso em fazer a lógica dessa forma: 

enquanto: 
    o trem não chega até a estação final:
faça:
    pare em todas as estações
    abre a porta 
    espere 30 segundos
    feche a porta 
siga para a próxima estação
 */ 

int main() {

    return 0;
}