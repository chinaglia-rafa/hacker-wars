﻿/**
**	Sigla: crd
**	Lib responsavel por gerenciar as estruturas e funcoes dos cards
**
*/

#include <string.h>

#define CRD_FULL_CARDS 0
#define CRD_NAME_ONLY 1

struct Card {
	char name[25];
	float destructive_power;
	float security;
	float efficiency;
	float affected_data;
	float stealth;
};

/**
**    Cria uma nova struct do tipo Card e a retorna com os dados preenchidos
**    @param char *name: nome do card (tam. 25)
**    @param float destructive_power: poder destrutivo do card
**    @param float security: nivel de seguranca do card
**    @param float efficiency: nivel de eficiencia do card
**    @param float affected_data: quantidade de Tb afetados pelo card
**    @param float stealth: furtividade do card
**
**    @return struct Card: uma variavel do tipo struct Card contendo os dados do novo Card
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
struct Card crd_make_card(char *name, float destructive_power, float security, float efficiency, float affected_data, float stealth){
	struct Card new_card;
	strcpy(new_card.name, name);
	new_card.destructive_power = destructive_power;
	new_card.security = security;
	new_card.efficiency = efficiency;
	new_card.affected_data = affected_data;
	new_card.stealth = stealth;

	return new_card;
}

/**
**    Verifica se um card esta corretamente preenchido
**    @param struct Card: card a ser verificado
**
**	  @return Boolean: 1 se estiver correto, 0 caso contrario
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
short crd_is_valid(struct Card card) {
	if (strcmp(card.name, "") == 0 || card.destructive_power < 0 || card.security < 0 ||
		card.efficiency <= 0 || card.affected_data < 0 || card.stealth < 0) {
			return 0;
	}
	return 1;
}

/**
**    Imprime um card e seus dados na tela (32x11)
**    @param struct Card: card a ser impresso
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void crd_print_card(struct Card card) {
	//	Verifica se o card enviado está corretamente formatado
	if (!crd_is_valid(card)) {
			printf("\n(crd_print_card) ERRO: Card vazio ou com dados incompletos! Verifique os dados.\n");
			return;
	}
	printf(" ______________________________ \n");
	printf("/                              \\\n");
	printf("|   %25s  |\n", card.name);
	printf("|______________________________|\n");
	printf("|                              |\n");
	printf("| [1]      Destruicao:    %3.0f%% |\n", card.destructive_power);
	printf("| [2]       Seguranca:    %3.0f%% |\n", card.security);
	printf("| [3]      Eficiencia:     %2.1f |\n", card.efficiency);
	printf("| [4]  Dados afetados: %4.0f Tb |\n", card.affected_data);
	printf("| [5]     Furtividade:    %3.0f%% |\n", card.stealth);
	printf("|______________________________|\n");
}

/**
**    Imprime dois cards e seus dados na tela (32x11)
**    @param struct Card: cards 1 a ser impresso
**    @param struct Card: cards 2 a ser impresso
**    @param short: modo de impressao (CRD_FULL_CARDS, CRD_NAME_ONLY)
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void crd_print_2_cards(struct Card card1, struct Card card2, short print_mode) {
	//	Verifica se o card enviado está corretamente formatado
	if (!crd_is_valid(card1) || !crd_is_valid(card2)) {
			printf("\n(crd_print_2_cards) ERRO: Card vazio ou com dados incompletos! Verifique os dados.\n");
			return;
	}

	if (print_mode == CRD_NAME_ONLY) {
		printf(" ______________________________ ");
		printf("          ");
		printf(" ______________________________ \n"); // break-line
		printf("/                              \\");
		printf("          ");
		printf("/                              \\\n"); // break-line
		printf("|   %25s  |", card1.name);
		printf("          ");
		printf("|   %25s  |\n", card2.name);
		printf("|______________________________|");
		printf("          ");
		printf("|______________________________|\n");

		return;
	}
	printf(" ______________________________ ");
	printf("          ");
	printf(" ______________________________ \n"); // break-line
	printf("/                              \\");
	printf("          ");
	printf("/                              \\\n"); // break-line
	printf("|   %25s  |", card1.name);
	printf("          ");
	printf("|   %25s  |\n", card2.name);
	printf("|______________________________|");
	printf("          ");
	printf("|______________________________|\n");
	printf("|                              |");
	printf("          ");
	printf("|                              |\n");
	printf("| [1]      Destruicao:    %3.0f%% |", card1.destructive_power);
	printf("          ");
	printf("| [1]      Destruicao:    %3.0f%% |\n", card2.destructive_power);
	printf("| [2]       Seguranca:    %3.0f%% |", card1.security);
	printf("          ");
	printf("| [2]       Seguranca:    %3.0f%% |\n", card2.security);
	printf("| [3]      Eficiencia:     %2.1f |", card1.efficiency);
	printf("          ");
	printf("| [3]      Eficiencia:     %2.1f |\n", card2.efficiency);
	printf("| [4]  Dados afetados: %4.0f Tb |", card1.affected_data);
	printf("          ");
	printf("| [4]  Dados afetados: %4.0f Tb |\n", card2.affected_data);
	printf("| [5]     Furtividade:    %3.0f%% |", card1.stealth);
	printf("          ");
	printf("| [5]     Furtividade:    %3.0f%% |\n", card2.stealth);
	printf("|______________________________|");
	printf("          ");
	printf("|______________________________|\n");
}

/**
**    Imprime tres card e seus dados na tela (32x11)
**
**    @param struct Card: card 1 a ser impresso
**    @param struct Card: card 2 a ser impresso
**    @param struct Card: card 3 a ser impresso
**    @param short: modo de impressao (CRD_FULL_CARDS, CRD_NAME_ONLY)
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void crd_print_3_cards(struct Card card1, struct Card card2, struct Card card3, short print_mode) {
	//	Verifica se o card enviado está corretamente formatado
	if (!crd_is_valid(card1) || !crd_is_valid(card2) || !crd_is_valid(card3)) {
			printf("\n(crd_print_3_cards) ERRO: Card vazio ou com dados incompletos! Verifique os dados.\n");
			return;
	}
	if (print_mode == CRD_NAME_ONLY) {
		printf(" ______________________________ ");
		printf("          ");
		printf(" ______________________________ ");
		printf("          ");
		printf(" ______________________________ \n"); // break-line
		printf("/                              \\");
		printf("          ");
		printf("/                              \\");
		printf("          ");
		printf("/                              \\\n"); // break-line
		printf("|   %25s  |", card1.name);
		printf("          ");
		printf("|   %25s  |", card2.name);
		printf("          ");
		printf("|   %25s  |\n", card3.name);
		printf("|______________________________|");
		printf("          ");
		printf("|______________________________|");
		printf("          ");
		printf("|______________________________|\n");
		return;
	}

	printf(" ______________________________ ");
	printf("          ");
	printf(" ______________________________ ");
	printf("          ");
	printf(" ______________________________ \n"); // break-line
	printf("/                              \\");
	printf("          ");
	printf("/                              \\");
	printf("          ");
	printf("/                              \\\n"); // break-line
	printf("|   %25s  |", card1.name);
	printf("          ");
	printf("|   %25s  |", card2.name);
	printf("          ");
	printf("|   %25s  |\n", card3.name);
	printf("|______________________________|");
	printf("          ");
	printf("|______________________________|");
	printf("          ");
	printf("|______________________________|\n");
	printf("|                              |");
	printf("          ");
	printf("|                              |");
	printf("          ");
	printf("|                              |\n");
	printf("| [1]      Destruicao:    %3.0f%% |", card1.destructive_power);
	printf("          ");
	printf("| [1]      Destruicao:    %3.0f%% |", card2.destructive_power);
	printf("          ");
	printf("| [1]      Destruicao:    %3.0f%% |\n", card3.destructive_power);
	printf("| [2]       Seguranca:    %3.0f%% |", card1.security);
	printf("          ");
	printf("| [2]       Seguranca:    %3.0f%% |", card2.security);
	printf("          ");
	printf("| [2]       Seguranca:    %3.0f%% |\n", card3.security);
	printf("| [3]      Eficiencia:     %2.1f |", card1.efficiency);
	printf("          ");
	printf("| [3]      Eficiencia:     %2.1f |", card2.efficiency);
	printf("          ");
	printf("| [3]      Eficiencia:     %2.1f |\n", card3.efficiency);
	printf("| [4]  Dados afetados: %4.0f Tb |", card1.affected_data);
	printf("          ");
	printf("| [4]  Dados afetados: %4.0f Tb |", card2.affected_data);
	printf("          ");
	printf("| [4]  Dados afetados: %4.0f Tb |\n", card3.affected_data);
	printf("| [5]     Furtividade:    %3.0f%% |", card1.stealth);
	printf("          ");
	printf("| [5]     Furtividade:    %3.0f%% |", card2.stealth);
	printf("          ");
	printf("| [5]     Furtividade:    %3.0f%% |\n", card3.stealth);
	printf("|______________________________|");
	printf("          ");
	printf("|______________________________|");
	printf("          ");
	printf("|______________________________|\n");
}

/**
**    Imprime um valor float formatado de acordo com a caracteristica
**    @param float value : valor a ser formatado
**    @param int caracteristica: caracteristica para formatar
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void crd_print_formatted_value_at(float value, int pos) {
	switch (pos) {
		case 1:
		  printf("%3.0f%%", value);
			break;
		case 2:
			printf("%3.0f%%", value);
			break;
		case 3:
			printf("%2.1f", value);
			break;
		case 4:
			printf("%4.0f Tb", value);
			break;
		case 5:
			printf("%3.0f%%", value);
			break;
	}
}

/**
**    Retorna o valor da caracteristica na posicao escolhida
**    @param struct Card: card escolhido
**    @param int pos: posicao da característica escolhida no card [1, 5]
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
float crd_get_value_at(struct Card card, int pos) {
	//	Verifica se o card enviado esta corretamente formatado e se a posicao esta no range
	if (!crd_is_valid(card)) {
		printf("\n(crd_get_value_at) ERRO: Card vazio ou com dados incompletos! Verifique os dados.\n");
		return -1;
	} else if (pos > 5 || pos < 1) {
		printf("\nERRO: Pos out of range.\n");
		return -1;
	}

	switch (pos) {
		case 1:
			return card.destructive_power;
			break;
		case 2:
			return card.security;
			break;
		case 3:
			return card.efficiency;
			break;
		case 4:
			return card.affected_data;
			break;
		case 5:
			return card.stealth;
			break;
	}
}

/**
**    Debuga um card, mostrando seus dados para fins de desenvolvimento
**    @param struct Card: card a ser debugado
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void crd_debug_card(struct Card card) {
	printf("\n== debugando Card ==\n");
	printf("  card.name = \"%s\"\n", card.name);
	printf("  card.destructive_power = %.2f%%\n", card.destructive_power);
	printf("  card.security = %.2f%%\n", card.security);
	printf("  card.efficiency = %.2f\n", card.efficiency);
	printf("  card.affected_data = %.0fTb\n", card.affected_data);
	printf("  card.stealth = %.2f%%\n", card.stealth);
	printf("====================\n");
}
