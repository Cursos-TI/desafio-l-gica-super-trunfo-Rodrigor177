#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de cidade
typedef struct {
    char estado[40];
    int codigo;
    char nome[40];
    long int populacao;
    double area;
    double pib;
    int pontos_turisticos;
} CartaCidade;

// Função auxiliar para exibir uma carta
void exibirCarta(CartaCidade carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %ld\n", carta.populacao);
    printf("Área: %.2lf km²\n", carta.area);
    printf("PIB: %.2lf bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

// Função de comparação (exemplo: comparar por população, maior vence)
int compararCartas(CartaCidade c1, CartaCidade c2, int atributo) {
    // atributo: 1-população, 2-área, 3-PIB, 4-pontos turísticos
    if (atributo == 1) {
        if (c1.populacao > c2.populacao)
            return 1;
        else if (c1.populacao < c2.populacao)
            return 2;
        else
            return 0;
    } else if (atributo == 2) {
        if (c1.area > c2.area)
            return 1;
        else if (c1.area < c2.area)
            return 2;
        else
            return 0;
    } else if (atributo == 3) {
        if (c1.pib > c2.pib)
            return 1;
        else if (c1.pib < c2.pib)
            return 2;
        else
            return 0;
    } else if (atributo == 4) {
        if (c1.pontos_turisticos > c2.pontos_turisticos)
            return 1;
        else if (c1.pontos_turisticos < c2.pontos_turisticos)
            return 2;
        else
            return 0;
    }
    return 0;
}

int main() {
    CartaCidade carta1, carta2;
    int atributo;

    printf("Cadastro da carta 1:\n");
    printf("Estado: "); fgets(carta1.estado, 40, stdin); carta1.estado[strcspn(carta1.estado, "\n")] = 0;
    printf("Código: "); scanf("%d", &carta1.codigo); getchar();
    printf("Cidade: "); fgets(carta1.nome, 40, stdin); carta1.nome[strcspn(carta1.nome, "\n")] = 0;
    printf("População: "); scanf("%ld", &carta1.populacao);
    printf("Área (km²): "); scanf("%lf", &carta1.area);
    printf("PIB (bilhões): "); scanf("%lf", &carta1.pib);
    printf("Pontos turísticos: "); scanf("%d", &carta1.pontos_turisticos); getchar();

    printf("\nCadastro da carta 2:\n");
    printf("Estado: "); fgets(carta2.estado, 40, stdin); carta2.estado[strcspn(carta2.estado, "\n")] = 0;
    printf("Código: "); scanf("%d", &carta2.codigo); getchar();
    printf("Cidade: "); fgets(carta2.nome, 40, stdin); carta2.nome[strcspn(carta2.nome, "\n")] = 0;
    printf("População: "); scanf("%ld", &carta2.populacao);
    printf("Área (km²): "); scanf("%lf", &carta2.area);
    printf("PIB (bilhões): "); scanf("%lf", &carta2.pib);
    printf("Pontos turísticos: "); scanf("%d", &carta2.pontos_turisticos);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\nAtributo: ");
    scanf("%d", &atributo);

    printf("\nCarta 1:\n");
    exibirCarta(carta1);
    printf("\nCarta 2:\n");
    exibirCarta(carta2);

    int vencedor = compararCartas(carta1, carta2, atributo);

    printf("\nResultado da comparação:\n");
    if (vencedor == 1)
        printf("Carta 1 (%s) venceu!\n", carta1.nome);
    else if (vencedor == 2)
        printf("Carta 2 (%s) venceu!\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}
