#include <stdio.h>
#include <string.h>
#include <ctype.h>

// isso serve para definir o maximo de caracteres
#define TAM_CODIGO 4
#define TAM_NOME 50
#define TAM_ESTADO 30

struct Carta {
    char estado[TAM_ESTADO];  
    char codigo[TAM_CODIGO];  
    char nomeCidade[TAM_NOME]; 
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

void lerCarta(struct Carta *c) {
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
    
    // Calcula a densidade populacional e PIB per capita
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

void exibirCarta(struct Carta c) {
    printf("\n--- Carta ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    lerCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Comparação usando o atributo População
    printf("\n--- Comparação de cartas (Atributo: População) ---\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.codigo, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.nomeCidade, carta2.codigo, carta2.populacao);
    
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}