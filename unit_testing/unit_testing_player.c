#include <stdio.h>
#include <locale.h>
#include "../libs/Cards.h"
#include "../libs/Stack.h"
#include "../libs/Player.h"
#include "../libs/Helper.h"

void main () {
	setlocale(LC_ALL, "");

  srand(time(NULL));

  while (1) {
    system("cls");

    struct Player players[2] = {plr_make_player("Rafa") , plr_make_player("Marcelo")};
    struct Stack stack = stk_make_stack();
    stk_shuffle(&stack);

    plr_draw_hand(&players[0], &stack);
    plr_draw_hand(&players[1], &stack);

    // plr_print_hand(players[1]);
		int a = 0;
		while (!plr_is_hand_empty(players[0])) {
			plr_print_hand(players[0]);
			printf("\nJogador 1, escolha um card para jogar [1, 3]: ");
	    scanf("%d", &a);
			plr_remove_card_from_hand(&players[0], a - 1);
		}

		exit(0);

    int opt = -1;
    int p1_chosen_card, p2_chosen_card;
    printf("Jogador 1, escolha uma caracteristica [1, 5]: ");
    scanf("%d", &opt);
    printf("\nJogador 1, escolha um card para jogar [1, 3]: ");
    scanf("%d", &p1_chosen_card);
    printf("\nJogador 2, escolha um card para jogar [1, 3]: ");
    scanf("%d", &p2_chosen_card);
    struct Card p1_choice = plr_get_card_at(players[0], p1_chosen_card - 1);
    struct Card p2_choice = plr_get_card_at(players[1], p2_chosen_card - 1);
    crd_print_2_cards(p1_choice, p2_choice, CRD_FULL_CARDS);
    if (plr_duel(crd_get_value_at(p1_choice, opt), crd_get_value_at(p2_choice, opt)) == 0)
       printf("JOGADOR 1 VENCEU");
    else if (plr_duel(crd_get_value_at(p1_choice, opt), crd_get_value_at(p2_choice, opt)) == 1)
      printf("JOGADOR 2 VENCEU");
    else
      printf("EMPAAAAAAATE");

    system("pause");
  }
}
