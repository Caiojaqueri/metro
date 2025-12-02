// indo para o trabalho me peguei pensando em como eu faria um programa simulando o metrô de São Paulo, então aqui estou eu, iniciando esse pequeno projeto, com o objetivo de colocar em prática meus conhecimentos em C e lógica de programação. 

#include <stdio.h> // vou usar para entrada e saída de dados
#include <string.h> // vou usar para manipulação de strings
#include <time.h> // vou usar para simular o tempo de espera nas estações

#define MAX_ESTACOES 10 
#define ESTACAO_FINAL 9
#define TEMPO_ESPERA 15 

#define PORTA_ABERTA 1
#define PORTA_FECHADA 0


int estacao_atual = 0;
int proxima_estacao = 1;
int estado_porta = PORTA_FECHADA;

void abrirPorta() {
    estado_porta = PORTA_ABERTA;
    printf("Porta aberta na estação %d\n", estacao_atual);
}

void fechar_porta() {
    estado_porta = PORTA_FECHADA;
    printf("Porta fechada na estação %d\n", estacao_atual);
}

void parar_estacao() {
    printf("Você chegou na estação %d\n", estacao_atual);
    abrirPorta();
    sleep(TEMPO_ESPERA);
    fechar_porta();
}

void movimento() {
    printf("Indo para a próxima estação: %d\n", estacao_atual + 1);
    sleep(5); // simula o tempo de viagem entre as estações
}

void linha() {
    while (estacao_atual < ESTACAO_FINAL) {
        movimento(); //viaja para a próxima
        estacao_atual++; //chegou e acrescenta 1 na estação atual
        parar_estacao(); //abre porta, espera, fecha porta
    }
    printf("Você chegou na estação final: %d\n", ESTACAO_FINAL);
    parar_estacao(); //parada final
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