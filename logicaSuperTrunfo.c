#include <stdio.h>

// Estrutura CARTA para armazenar as características de uma cidade
typedef struct {
    char carta[25];  // Nome ou código da cidade
    int populacao;   // Número de habitantes
    float area;      // Área total da cidade em km²
    float PIB;       // Produto Interno Bruto da cidade
    int pontos_turisticos;  // Número de pontos turísticos
    float densidade_populacional; // População por área
    float PIB_per_capita; // Renda média por habitante
    float super_poder; // Valor agregado das propriedades da cidade
} CARTA;

// Função para cadastrar uma cidade e preencher seus atributos
void cadastro(CARTA *cidade) {
    printf("\nCadastre uma nova carta de cidade\n");

    printf("Qual o código da carta?\n");
    scanf("%s", cidade->carta);

    printf("Qual a população?\n");
    scanf("%i", &cidade->populacao);

    printf("Qual a área?\n");
    scanf("%f", &cidade->area);

    printf("Qual o PIB?\n");
    scanf("%f", &cidade->PIB);

    printf("Quantos pontos turísticos a cidade tem?\n");
    scanf("%i", &cidade->pontos_turisticos);

    // Calcula a densidade populacional (habitantes por km²)
    cidade->densidade_populacional = (float) cidade->populacao / cidade->area;
    
    // Calcula o PIB per capita (PIB dividido pelo número de habitantes)
    cidade->PIB_per_capita = (float) cidade->PIB / cidade->populacao;

    // Super poder é a soma de várias propriedades da cidade
    cidade->super_poder = cidade->area + cidade->PIB +
        cidade->pontos_turisticos + cidade->populacao + cidade->PIB_per_capita;
}

// Função para imprimir os atributos de uma cidade
void imprimir(CARTA cidade) {
    printf("\nCódigo da carta: %s\nPopulação: %i\nÁrea(Km²): %.2f\nPIB: %.2f\nPontos turísticos: %i\nDensidade populacional(Hab/Km²): %.2f\nPIB per capita: %.2f\nSuper poder: %.2f\n",
        cidade.carta, cidade.populacao, cidade.area, cidade.PIB, cidade.pontos_turisticos,
        cidade.densidade_populacional, cidade.PIB_per_capita, cidade.super_poder);
}

// Função para comparar a densidade populacional entre duas cidades
void carta_vencedora_densidade_populacional(CARTA cidade1, CARTA cidade2) {
    if (cidade1.densidade_populacional > cidade2.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade1.carta);
    } else if (cidade2.densidade_populacional > cidade1.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

// Função para comparar todas as propriedades somadas entre duas cidades
void carta_vencedora_todas_propriedades(CARTA cidade1, CARTA cidade2) {
    if (cidade1.super_poder > cidade2.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER\n", cidade1.carta);
    } else if (cidade2.super_poder > cidade1.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

// Funções para comparar propriedades específicas entre duas cidades
void carta_vencedora_populacao(CARTA cidade1, CARTA cidade2) {
    if (cidade1.populacao > cidade2.populacao) {
        printf("\nCidade %s venceu em POPULAÇÃO\n", cidade1.carta);
    } else if (cidade2.populacao > cidade1.populacao) {
        printf("\nCidade %s venceu em POPULAÇÃO\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

void carta_vencedora_area(CARTA cidade1, CARTA cidade2) {
    if (cidade1.area > cidade2.area) {
        printf("\nCidade %s venceu em ÁREA\n", cidade1.carta);
    } else if (cidade2.area > cidade1.area) {
        printf("\nCidade %s venceu em ÁREA\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

void carta_vencedora_PIB(CARTA cidade1, CARTA cidade2) {
    if (cidade1.PIB > cidade2.PIB) {
        printf("\nCidade %s venceu em PIB\n", cidade1.carta);
    } else if (cidade2.PIB > cidade1.PIB) {
        printf("\nCidade %s venceu em PIB\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

void carta_vencedora_pontos_turisticos(CARTA cidade1, CARTA cidade2) {
    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
        printf("\nCidade %s venceu em PONTOS TURÍSTICOS\n", cidade1.carta);
    } else if (cidade2.pontos_turisticos > cidade1.pontos_turisticos) {
        printf("\nCidade %s venceu em PONTOS TURÍSTICOS\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

void carta_vencedora_PIB_per_capita(CARTA cidade1, CARTA cidade2) {
    if (cidade1.PIB_per_capita > cidade2.PIB_per_capita) {
        printf("\nCidade %s venceu em PIB PER CAPITA\n", cidade1.carta);
    } else if (cidade2.PIB_per_capita > cidade1.PIB_per_capita) {
        printf("\nCidade %s venceu em PIB PER CAPITA\n", cidade2.carta);
    } else {
        printf("\nResultado da comparação foi empate !!!");
    }
}

// Função para escolher uma propriedade específica para comparação
void propriedade_especifica(CARTA cidade1, CARTA cidade2, int opcao) {
    printf("\nEscolha a propriedade para comparar:\n[1] População\n[2] Área\n[3] PIB\n[4] Pontos turísticos\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: carta_vencedora_populacao(cidade1, cidade2); break;
        case 2: carta_vencedora_area(cidade1, cidade2); break;
        case 3: carta_vencedora_PIB(cidade1, cidade2); break;
        case 4: carta_vencedora_pontos_turisticos(cidade1, cidade2); break;
        case 5: carta_vencedora_PIB_per_capita(cidade1, cidade2); break;
        default: printf("Opção inválida!\n"); break;
    }
}

// Função para decidir qual propriedade será comparada entre duas cidades
void qual_propriedade_comparar(CARTA cidade1, CARTA cidade2, int opcao1, int opcao2) {
    printf("\nEscolha o tipo de comparação:\n[1] Densidade populacional\n[2] Soma das propriedades\n[3] Propriedade específica\n");
    scanf("%d", &opcao1);

    switch (opcao1) {
        case 1: carta_vencedora_densidade_populacional(cidade1, cidade2); break;
        case 2: carta_vencedora_todas_propriedades(cidade1, cidade2); break;
        case 3: propriedade_especifica(cidade1, cidade2, opcao2); break;
        default: printf("Opção inválida!\n"); break;
    }
}

// Função principal
int main() {
    printf("Bem-vindo ao Super Trunfo Países!\n");

    CARTA cidade[2];

    cadastro(&cidade[0]);
    cadastro(&cidade[1]);

    imprimir(cidade[0]);
    imprimir(cidade[1]);

    int opcao1, opcao2;
    qual_propriedade_comparar(cidade[0], cidade[1], opcao1, opcao2);

    return 0;
}
