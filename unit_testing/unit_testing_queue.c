#include <stdio.h>
#include <locale.h>
#include "../libs/Cards.h"
#include "../libs/Stack.h"
#include "../libs/Player.h"
#include "../libs/Queue.h"
#include "../libs/Helper.h"

void main () {
	setlocale(LC_ALL, "");

  srand(time(NULL));

  struct Queue queue = qeu_make_queue();

	qeu_push(1, 2, 1, &queue);
	qeu_push(5, 10, 2, &queue);
	qeu_push(10, 20, 3, &queue);

	printf("count = %d", qeu_count(queue));

	qeu_pop(&queue);
	qeu_pop(&queue);
	qeu_pop(&queue);

	printf("count = %d", qeu_count(queue));
}
