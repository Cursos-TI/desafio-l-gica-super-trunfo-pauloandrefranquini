#include <stdio.h>

typedef struct {
    char carta[25];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
    float densidade_populacional;
    float PIB_per_capita;
    float super_poder;
} CARTA;

void cadastro(CARTA *cidade) {
    printf("\nCadastre uma nova carta de cidade\n");

    printf("Qual o código da carta?\n");
    scanf("%s", &cidade->carta);

    printf("Qual a população?\n");
    scanf("%i", &cidade->populacao);

    printf("Qual a área?\n");
    scanf("%f", &cidade->area);

    printf("Qual o PIB?\n");
    scanf("%f", &cidade->PIB);

    printf("Quantos pontos turísticos a cidade tem?\n");
    scanf("%i", &cidade->pontos_turisticos);

    cidade->densidade_populacional = (float) cidade->populacao / cidade->area;
    cidade->PIB_per_capita = (float) cidade->PIB / cidade->populacao;
    cidade->super_poder = (float) cidade->area + cidade->PIB + 
        cidade->pontos_turisticos + cidade->populacao + cidade->PIB_per_capita;


}

void imprimir(CARTA cidade) {
    printf("\nCódigo da carta: %s\nPopulação: %i\nÁrea(Km²): %.2f\nPIB: %.2f\nPontos turísticos: %i\nDensidade populacional(Hab/Km²): %.2f\nPIB per capita: %.2f\nSuper poder: %.2f\n",
        cidade.carta, cidade.populacao, cidade.area, cidade.PIB, cidade.pontos_turisticos,
        cidade.densidade_populacional, cidade.PIB_per_capita, cidade.super_poder);
}


void carta_vencedora_densidade_populacional(CARTA cidade1, CARTA cidade2) {
    if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade1.carta);
    } else if (cidade2.densidade_populacional < cidade1.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}


void carta_vencedora_todas_propriedades(CARTA cidade1, CARTA cidade2) {
    if (cidade1.super_poder > cidade2.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER", cidade1.carta);
    } else if (cidade2.super_poder > cidade1.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}



void carta_vencedora_populacao(CARTA cidade1, CARTA cidade2) {
    if (cidade1.populacao > cidade2.populacao) {
        printf("\nCidade %s venceu em POPULAÇÃO", cidade1.carta);
    } else if (cidade2.populacao > cidade1.populacao) {
        printf("\nCidade %s venceu em POPULAÇÃO", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}


void carta_vencedora_area(CARTA cidade1, CARTA cidade2) {
    if (cidade1.area > cidade2.area) {
        printf("\nCidade %s venceu em ÁREA", cidade1.carta);
    } else if (cidade2.area > cidade1.area) {
        printf("\nCidade %s venceu em ÁREA", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}


void carta_vencedora_PIB(CARTA cidade1, CARTA cidade2) {
    if (cidade1.PIB > cidade2.PIB) {
        printf("\nCidade %s venceu em PIB", cidade1.carta);
    } else if (cidade2.PIB > cidade1.PIB) {
        printf("\nCidade %s venceu em PIB", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}


void carta_vencedora_pontos_turisticos(CARTA cidade1, CARTA cidade2) {
    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
        printf("\nCidade %s venceu em PONTOS TURÍSTICOS", cidade1.carta);
    } else if (cidade2.pontos_turisticos > cidade1.pontos_turisticos) {
        printf("\nCidade %s venceu em PONTOS TURÍSTICOS", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}


void carta_vencedora_PIB_per_capita(CARTA cidade1, CARTA cidade2) {
    if (cidade1.PIB_per_capita > cidade2.PIB_per_capita) {
        printf("\nCidade %s venceu em PIB PER CAPITA", cidade1.carta);
    } else if (cidade2.PIB_per_capita > cidade1.PIB_per_capita) {
        printf("\nCidade %s venceu em PIB PER CAPITA", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}

void propriedade_especifica(CARTA cidade1, CARTA cidade2, int opcao){


    printf("\nVocê quer escolher a carta vencedora por meio da comparação da:"
        "\n[1]População\n"
        "[2]Área\n"
        "[3]PIB\n"
        "[4]Pontos turísticos\n");

    scanf("%d",&opcao);

    switch (opcao){
        case 1:
            carta_vencedora_populacao(cidade1,cidade2);
            break;
    
        case 2:
            carta_vencedora_area(cidade1,cidade2);
            break;
        
        case 3:
            carta_vencedora_PIB(cidade1,cidade2);
            break;

        case 4:
            carta_vencedora_pontos_turisticos(cidade1,cidade2);
            break;

        case 5:
            carta_vencedora_PIB_per_capita(cidade1,cidade2);
            break;

        default:
            printf("Você fez uma escolha incorreta !!!");
            break;
    };
}

void qual_propriedade_comparar(CARTA cidade1, CARTA cidade2, int opcao1, int opcao2) {

    printf("\nQual propriedade específica você quer fazer a comparação:"
        "\n[1]Densidade populacional\n"
        "[2]Somatória das outras propriedades\n"
        "[3]Uma propriedade específica\n");

    scanf("%d",&opcao1);

    switch (opcao1){
        case 1:
            carta_vencedora_densidade_populacional(cidade1,cidade2);
            break;
    
        case 2:
            carta_vencedora_todas_propriedades(cidade1,cidade2);
            break;

        case 3:
            propriedade_especifica(cidade1,cidade2,opcao2);
            break;

        default:
            printf("Você fez uma escolha incorreta !!!");
            break;
            };
}

int main() {
    
    printf("Bem vindo ao Super Trunfo Países!\n");


    CARTA cidade[2];
    

    cadastro(&cidade[0]);
    cadastro(&cidade[1]);


    imprimir(cidade[0]);
    imprimir(cidade[1]);

    int opcao1;

    int opcao2;


    qual_propriedade_comparar(cidade[0], cidade[1], opcao1, opcao2);


    
    
    return 0;
}