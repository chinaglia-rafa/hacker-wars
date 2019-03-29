/**
**	Sigla: crd
**	Lib responsavel por gerenciar as estruturas e funcoes dos cards
**
*/

#include <string.h>

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
			printf("\nERRO: Card vazio ou com dados incompletos! Verifique os dados.\n");
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
**    Retorna o valor da caracteristica na posicao escolhida
**    @param struct Card: card escolhido
**    @param int pos: posicao da característica escolhida no card [1, 5]
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
float crd_get_value_at(struct Card card, int pos) {
	//	Verifica se o card enviado esta corretamente formatado e se a posicao esta no range
	if (!crd_is_valid(card)) {
		printf("\nERRO: Card vazio ou com dados incompletos! Verifique os dados.\n");
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
