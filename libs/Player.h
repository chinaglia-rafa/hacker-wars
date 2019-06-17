/**
**	Sigla: plr
**	Lib responsavel por gerenciar as informacoes de cada jogador
**
*/

#include <stdlib.h>

struct Card_in_hand {
  struct Card card;
  struct Card_in_hand* next;
  struct Card_in_hand* prev;
};

struct Player {
  struct Card_in_hand* hand;
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
  new_player.hand = NULL;

  return new_player;
}

/**
**    Insere um novo card em uma lista duplamente encadeada de mao
**
**    @param struct Player*: ponteiro para o jogador que recebera o card
**    @param struct Card: Card a ser adicionado
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void plr_add_card_to_hand(struct Player* player, struct Card card) {
  if (player == NULL || !crd_is_valid(card)) return;

  struct Card_in_hand* new_card_in_hand = (struct Card_in_hand*)malloc(sizeof(struct Card_in_hand));
  new_card_in_hand->card = card;
  new_card_in_hand->next = NULL;
  new_card_in_hand->prev = NULL;

  if (player->hand == NULL) {
    player->hand = new_card_in_hand;
    return;
  }

  struct Card_in_hand* seeker = player->hand;
  while (seeker->next != NULL)
    seeker = seeker->next;

  seeker->next = new_card_in_hand;
  new_card_in_hand->prev = seeker;

  return;
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
    plr_add_card_to_hand(player, stk_pop(stack));
}

/**
**    Retorna o card no indice index
**
**    @param struct Player*: ponteiro para o jogador que recebera os cards
**    @param int index: indice do card a ser buscado
**
**    @return card: card encontrado
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
struct Card plr_get_card_at(struct Player player, int index) {
  if (player.hand == NULL) return;

  int i = 0;
  struct Card_in_hand* seeker = player.hand;
  while (seeker != NULL && i < index) {
    i++;
    seeker = seeker->next;
  }

  return seeker->card;
}

/**
**    Diz se a mao do jogador esta vazia
**
**    @param struct Player*: ponteiro para o jogador
**    @return short: 1 se vazia, 0 se nao
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
short plr_is_hand_empty(struct Player player) {
  if (player.hand == NULL) return 1;
  return 0;
}

/**
**    Diz quantos cards tem na mao do jogador
**
**    @param struct Player*: ponteiro para o jogador
**    @return int: numero de cards na mao do jogador
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
short plr_count_cards_in_hand(struct Player player) {
  int total = 0;
  struct Card_in_hand* seeker = player.hand;
  while (seeker != NULL) {
    total++;
    seeker = seeker->next;
  }

  return total;
}

/**
**    Remove um card da mao de um jogador
**
**    @param struct Player*: ponteiro para o jogador
**    @param int: indice do card a ser removido
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void plr_remove_card_from_hand(struct Player* player, int index) {
  if (player == NULL ||
      player->hand == NULL ||
      plr_count_cards_in_hand(*player) < index + 1)
        return;

  int i = 0;
  struct Card_in_hand* seeker = player->hand;
  while (seeker != NULL && i < index) {
    i++;
    seeker = seeker->next;
  }

  if (seeker == NULL) return;
  if (seeker->prev == NULL) {
    player->hand = seeker->next;
    if (player->hand != NULL)
      player->hand->prev = NULL;
    // printf("To dentro?\n");
    // printf("Aqui\n");
  } else {
    seeker->prev->next = seeker->next;
    if (seeker->next != NULL)
      seeker->next->prev = seeker->prev;
  }

  free(seeker);
}

/**
**    Imprime os cards da mao de um jogador
**
**    @param struct Player*: ponteiro para o jogador
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void plr_print_hand(struct Player player) {
  switch(plr_count_cards_in_hand(player)) {
    case 1:
      crd_print_card(player.hand->card);
      break;
    case 2:
      crd_print_2_cards(player.hand->card, player.hand->next->card, CRD_FULL_CARDS);
      break;
    case 3:
      crd_print_3_cards(player.hand->card, player.hand->next->card, player.hand->next->next->card, CRD_FULL_CARDS);
      break;
  }
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
