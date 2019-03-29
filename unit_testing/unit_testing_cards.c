#include <stdio.h>
#include <locale.h>
#include "../libs/Cards.h"
#include "../libs/Helper.h"

void main () {
	setlocale(LC_ALL, "");

	struct Card hand[3];
	//	vetor de cards
	hand[0] = crd_make_card("Enviar vírus", 85, 20, 3, 500, 60);
	hand[1] = crd_make_card("Aapagando Las Luces (EMP)", 30, 50, 5, 1000, 0);
	hand[2] = crd_make_card("Be The ONE", 100, 100, 5, 1000, 100);

	//	debugar card
	crd_debug_card(hand[0]);
	//	imprimir card
	crd_print_card(hand[1]);
	//	imprimir card sem dados (deveria causar erro)
	struct Card t;
	crd_print_card(t);

	//	Convertendo ints em strings (labels) e buscando valor de caracteristica no card
	printf("\nO %s do primeiro card na mão do jogador é %.0f.", hlp_label_at_pos(1, FORMAT_LOWER), crd_get_value_at(hand[0], 1));
	printf("\nA %s do primeiro card na mão do jogador é %.0f.", hlp_label_at_pos(2, FORMAT_UPPER), crd_get_value_at(hand[0], 2));
	printf("\nA %s do primeiro card na mão do jogador é %.0f.", hlp_label_at_pos(3, FORMAT_CAP), crd_get_value_at(hand[0], 3));
	printf("\nO total de %s do primeiro card na mão do jogador é %.0f.", hlp_label_at_pos(4, FORMAT_LOWER), crd_get_value_at(hand[0], 4));
	printf("\nA %s do primeiro card na mão do jogador é %.0f.", hlp_label_at_pos(5, FORMAT_LOWER), crd_get_value_at(hand[0], 5));
	printf("\nEsse deveria estar fora da range %.0f.", crd_get_value_at(hand[0], 6));
	printf("\nEsse deveria estar fora da range %s.", hlp_label_at_pos(999, FORMAT_LOWER));
}
