/**
**	Sigla: plr
**	Lib responsavel por gerenciar as informacoes de cada jogador
**
*/

#include <stdlib.h>

struct Player {
  struct Card cards_in_hand[3];
  int score;
  char player_name[50];
};

/**
**    Cria uma nova struct do tipo Player e a retorna com os dados preenchidos
**
**    @return struct Player: uma variavel do tipo struct Player pronta para uso
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
struct Player plr_make_player(char *player_name) {
  struct Player new_player;
  new_player.score = 0;
  strcpy(new_player.player_name, player_name);

  return new_player;
}

/**
**    Compra 3 novos cards do topo da stack e os colocam na mao do player
**
**    @param struct Player*: ponteiro para o jogador que recebera os cards
**    @param struct Stack*: pilha de onde tirar os cards
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void plr_draw_hand(struct Player* player, struct Stack* stack) {
  if (player == NULL || stack == NULL)
    return;

  int i;
  for (i = 0; i < 3; i++)
    player->cards_in_hand[i] = stk_pop(stack);
}

void plr_print_hand(struct Player player) {
  crd_print_3_cards(player.cards_in_hand[0], player.cards_in_hand[1], player.cards_in_hand[2], CRD_FULL_CARDS);
}

/**
**    Compara dois valores e retorna um numero correspondente ao jogador vencedor
**
**    @param float p1: caracteristica enviada pelo jogador 1
**    @param float p2: caracteristica enviada pelo jogador 2
**
**    @return int: 0 caso p1 seja vencedor, 1 caso p2 seja, -1 se empate.
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
int plr_duel(float p1, float p2) {
  if (p1 == p2) return -1;
  return p1 < p2;
}
