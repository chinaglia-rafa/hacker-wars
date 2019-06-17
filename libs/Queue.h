/**
**	Sigla: qeu
**	Lib responsavel por gerenciar a fila de duelos
**
*/

#include <stdlib.h>

struct Duel {
  float value_p1;
  float value_p2;
  int opt;          //  Caracteristica escolhida para o duelo
  struct Duel* next;
  struct Duel* prev;
};

struct Queue {
  struct Duel *top;
  struct Duel *bottom;
};

/**
**    Cria uma nova struct do tipo Queue e a retorna com os ponteiros inicializados
**
**    @return struct Queue: uma variavel do tipo struct Queue pronta para uso
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
struct Queue qeu_make_queue() {
	struct Queue new_queue;
	new_queue.top = NULL;
	new_queue.bottom = NULL;

	return new_queue;
}


/**
**    Adiciona um duelo na fila de duelos
**    @param float value_p1: Valor do atributo escolhido pelo P1
**    @param float value_p2: Valor do atributo escolhido pelo P2
**    @param int tipo: Indice do atributo escolhido para ser comparado
**    @param struct* Queue: ponteiro para a fila onde o duelo devera ser inserido
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void qeu_push(float value_p1, float value_p2, int opt, struct Queue* queue) {
	if(queue == NULL) {
		printf("\n(qeu_push) ERRO: Queue nao pode ser nula.\n");
		return;
	}

  struct Duel* new_duel = (struct Duel*)malloc(sizeof(struct Duel));
  if (new_duel == NULL) {
    printf("\n(qeu_push) ERRO: Não foi possivel alocar memoria.\n");
    return;
  }

  new_duel->value_p1 = value_p1;
  new_duel->value_p2 = value_p2;
  new_duel->opt = opt;

  if (queue->bottom == NULL) {
    queue->top = new_duel;
    queue->bottom = new_duel;
    new_duel->next = NULL;
    new_duel->prev = NULL;
  } else {
    queue->top->prev = new_duel;
    new_duel->next = queue->top;
    new_duel->prev = NULL;
    queue->top = new_duel;
  }

  return;
}


/**
**    Verifica se a fila esta vazia
**    @param struct Queue: fila a ser analisada
**
** 	  @return short: Sim ou nao
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
short qeu_is_empty(struct Queue queue) {
	return queue.bottom == NULL;
}


/**
**    Conta o numero de elementos na fila
**    @param struct Queue: fila a ser analisada
**
** 	  @return int: Numero de elementos na fila
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
int qeu_count(struct Queue queue) {
	int i = 0;
	struct Duel* current_item = queue.bottom;
	while (current_item != NULL){
		i++;
		current_item = current_item->prev;
	}
	return i;
}


/**
**    Resolve o duelo no comeco da fila
**    @param struct* Queue: ponteiro para a fila de onde o duelo sera resolvido
**
** 	  @return struct Duel: Duelo resolvido
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
struct Duel qeu_pop(struct Queue* queue) {
	if (queue == NULL || qeu_is_empty(*queue))
		return;

  //  Guarda quem e o duelo no comeco da fila
	struct Duel* duel_on_bottom = queue->bottom;
  struct Duel bkp_duel = *duel_on_bottom;

  // Remove o item do comeco da fila
  queue->bottom = duel_on_bottom->prev;
  if (queue->bottom != NULL)
    queue->bottom->next = NULL;

  free(duel_on_bottom);

  return bkp_duel;
}
