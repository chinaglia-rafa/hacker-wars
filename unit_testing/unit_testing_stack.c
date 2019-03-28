#include <stdio.h>
#include <locale.h>
#include "../libs/Cards.h"
#include "../libs/Stack.h"
#include "../libs/Helper.h"

void main() {
	setlocale(LC_ALL, "");
	
	struct Stack stack = stk_make_stack();
	
	struct Card hand[3];
	hand[0] = crd_make_card("Enviar vírus", 85, 20, 3, 500, 60);
	hand[1] = crd_make_card("Aapagando Las Luces (EMP)", 30, 50, 5, 1000, 0);
	hand[2] = crd_make_card("Be The ONE", 100, 100, 5, 1000, 100);
	
	//	Empilha todo o deck padrão (contido em standard_deck.h)
	stk_stack_deck(&stack);
	
	printf("%d cards foram empilhados!\n\n", stk_size_of(stack));
	//	Loop de esvaziamento
	while (stk_is_empty(stack) == 0) {
		printf("\n\nDesempilhando card do topo!\n");
		crd_print_card(stk_pop(&stack));
	}
}
