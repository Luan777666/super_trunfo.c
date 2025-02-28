#include <stdio.h>
#include <string.h>
#include <ctype.h>

// isso serve para definir o maximo de caracteres
#define TAM_CODIGO 4
#define TAM_NOME 50
#define TAM_ESTADO 30

// aqui define os tipos das variaveis
typedef struct {
    char estado[TAM_ESTADO];  
    char codigo[TAM_CODIGO];  
    char nomeCidade[TAM_NOME]; 
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void lerCarta(Carta *c) {
    int numero;

    printf("Informe o nome do estado: ");
    scanf(" %[^\n]", c->estado);

    // aqui eu peguei a peimeira letra do estado
    char primeiraLetra = toupper(c->estado[0]);

    printf("Informe um número para a carta (1-4): ");
    scanf("%d", &numero);

    // Garante que o número esteja entre 1 e 4
    numero = (numero < 1 || numero > 4) ? 1 : numero;

    // Gera o código da carta 
    snprintf(c->codigo, TAM_CODIGO, "%c%02d", primeiraLetra, numero);

    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", c->nomeCidade);

    printf("Informe a população: ");
    scanf("%d", &c->populacao);

    printf("Informe a área (km²): ");
    scanf("%f", &c->area);

    printf("Informe o PIB: ");
    scanf("%f", &c->pib);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

void exibirCarta(Carta c) {
    printf("\n--- Carta ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    lerCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    return 0;
}