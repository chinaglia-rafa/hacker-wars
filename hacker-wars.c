#include <stdio.h>
#include <locale.h>
#include "libs/Cards.h"
#include "libs/Stack.h"
#include "libs/Player.h"
#include "libs/Queue.h"
#include "libs/Helper.h"
#include "libs/tutorials.h"

void main () {
	setlocale(LC_ALL, "");

  srand(time(NULL));

  int opt = -1;
  print_init_text();
  while(opt != 0 && opt != 1) {
    printf("Sim [1] | Nao [0]: ");
    scanf("%d", &opt);
  }

  if (opt == 0) {
    print_tutorial();
    system("pause");
  }

  system("cls");
  printf("Prontos para duelar? Vou embaralhar a pilha de cards.\n");
  struct Stack stack = stk_make_stack();
  char p1_name[100];
  char p2_name[100];
  stk_shuffle(&stack);
  printf("Pronto. Agora precisamos de nomes hackers.\n");
  printf("Digite como se chama o Jogador 1: ");
  scanf("%s", &p1_name);
  printf("Digite como se chama o Jogador 2: ");
  scanf("%s", &p2_name);
  printf("Muito bom, vamos comecar. BOM JOGO.\n\n");
  system("pause");
  struct Player players[2] = {plr_make_player(p1_name) , plr_make_player(p2_name)};

	struct Queue queue = qeu_make_queue();
	//	Representa o jogador com o turno. 0 = P1, 1 = P2.
	int turn = rand() % 2;
	//	Guardara a escolha de cada jogador para um dado duelo
	struct Card card_choices[2];

	//	Cada volta deste loop e um turno. Os turnos param quando nao houverem
	//	mais cards na pilha de cards
  while (!stk_is_empty(stack)) {
    plr_draw_hand(&players[0], &stack);
    plr_draw_hand(&players[1], &stack);

    while (!plr_is_hand_empty(players[0]) && !plr_is_hand_empty(players[1])) {
			opt = -1;
			int caracteristica = -1, i;
			hlp_change_turn(&turn);
			system("cls");
			hlp_render_top_bar(players[0], players[1], &stack, queue.bottom);
			plr_print_hand(players[turn]);
			//	Aqui o jogador primario vai escolher a caracteristica do duelo
			printf("Vez de %s! Ele deve escolher secretamente uma CARACTERISTICA para o duelo [1,5]: ", players[turn].player_name);
			while (caracteristica < 1 || caracteristica > 5) {
				caracteristica = (getch() - '1') + 1;
				//	O -45 correndo ao caractere de abortar a execucao do programa
				if (caracteristica == -45) exit(0);
			}
			//	Agora os jogadores vao alternar escolhendo um card da mao para jogar
			for (i = 0; i < 2; i++) {
				system("cls");
				plr_print_hand(players[turn]);
				printf("\n%s, escolha agora a CARTA que deseja jogar [1,3]: ", players[turn].player_name);
				while (opt < 1 || opt > 3) {
					opt = (getch() - '1') + 1;
					if (plr_count_cards_in_hand(players[turn]) < opt)
						opt = -1;
					//	O -45 correndo ao caractere de abortar a execucao do programa
					if (opt == -45) exit(0);
				}
				card_choices[turn] = plr_get_card_at(players[turn], opt - 1);
				plr_remove_card_from_hand(&players[turn], opt - 1);
				hlp_change_turn(&turn);
				opt = -1;
			}
			// Adiciona um duelo a fila de duelos da rodada
			qeu_push(crd_get_value_at(card_choices[0], caracteristica),
							 crd_get_value_at(card_choices[1], caracteristica),
						   caracteristica, &queue);
    }

		system("cls");
		hlp_render_top_bar(players[0], players[1], &stack, queue.bottom);
		printf("\nFIM DA RODADA! Hora de calcular os pontos!\n\n");
		while (qeu_count(queue) > 0) {
			struct Duel current_duel = qeu_pop(&queue);
			printf("Duelo de %s: ", hlp_label_at_pos(current_duel.opt, FORMAT_UPPER));
			crd_print_formatted_value_at(current_duel.value_p1, current_duel.opt);
			printf("  x ");
			crd_print_formatted_value_at(current_duel.value_p2, current_duel.opt);
			printf("\n");
		  if (current_duel.value_p1 > current_duel.value_p2) {
				printf("Vitoria de %s! +1 ponto para %s.\n", players[0].player_name, players[0].player_name);
				players[0].score += 1;
			} else if (current_duel.value_p1 < current_duel.value_p2) {
				printf("Vitoria de %s! +1 ponto para %s.\n", players[1].player_name, players[1].player_name);
				players[1].score += 1;
			} else {
				printf("EMPATE! Nao houveram vitoriosos.\n");
			}
			printf("================================================\n");
		}
		printf("\nPlacar ate o momento: [%d x %d]\n", players[0].score, players[1].score);
		system("pause");
	}
	system("cls");
	printf("O JOGO ACABOU!\n\nVoces lutaram bem, hackers!\n");
	int winner = 0;
	if (players[0].score > players[1].score)
		winner = 0;
	else if (players[0].score < players[1].score)
		winner = 1;
	else {
		printf("Suas pericias como hackers sao tao grandes que um nao conseguiu ");
		printf("superar o outro! A partida terminou em EMPATE!\n");
		printf("\nAte a proxima partida, hackers!");

		return;
	}

	printf("O vencedor foi %s! Com um placar de [%d x %d]", players[winner].player_name, players[0].score, players[1].score);
	printf("\nAte a proxima partida, hackers!");
}
