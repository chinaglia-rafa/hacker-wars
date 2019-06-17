/**
**	Sigla: hlp
**	Lib responsavel por conter funções auxiliares, de conversão e etc
**
*/

//	CONSTANTES
#define FORMAT_LOWER 0
#define FORMAT_UPPER 1
#define FORMAT_CAP 2
#define FORMAT_UNIT 3

/**
**    Converte um int no intervalo [1,5] para o label da posicao no card
**    @param int pos: posicao no intervalo [1,5]
**	  @param int format: FORMAT_LOWER=0, FORMAT_UPPER=1, FORMAT_CAP=2
**
**	  @return char*: label da posicao
**
**	  Uso:
**		hlp_label_at_pos(1, FORMAT_UPPER); // retorna "PODER DESTRUTIVO"
**		hlp_label_at_pos(3, FORMAT_CAP); // retorna "Eficiencia"
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
//	TODO: estudar esse const
const char *hlp_label_at_pos(int pos, int format) {
	switch(pos) {
		case 1:
			if 		(format == FORMAT_LOWER) return "poder destrutivo";
			else if (format == FORMAT_UPPER) return "PODER DESTRUTIVO";
			else if (format == FORMAT_CAP)   return "Poder destrutivo";
			else if (format == FORMAT_UNIT)   return "%";
		case 2:
			if 		(format == FORMAT_LOWER) return "seguranca";
			else if (format == FORMAT_UPPER) return "SEGURANCA";
			else if (format == FORMAT_CAP)   return "Seguranca";
			else if (format == FORMAT_UNIT)   return "%";
		case 3:
			if 		(format == FORMAT_LOWER) return "eficiencia";
			else if (format == FORMAT_UPPER) return "EFICIENCIA";
			else if (format == FORMAT_CAP)   return "Eficiencia";
			else if (format == FORMAT_UNIT)   return "";
		case 4:
			if 		(format == FORMAT_LOWER) return "dados afetados";
			else if (format == FORMAT_UPPER) return "DADOS AFETADOS";
			else if (format == FORMAT_CAP)   return "Dados afetados";
			else if (format == FORMAT_UNIT)   return "Tb";
		case 5:
			if 		(format == FORMAT_LOWER) return "furtividade";
			else if (format == FORMAT_UPPER) return "FURTIVIDADE";
			else if (format == FORMAT_CAP)   return "Furtividade";
			else if (format == FORMAT_UNIT)   return "%";
		default:
			printf("\nERRO: pos out of range.");
	}
	return "";
}

/**
**    Troca o turno
**		@param int* turn*: variavel cujo turno sera alternado
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void hlp_change_turn(int* turn) {
	if (*turn == 0) *turn = 1; else *turn = 0;
}

/**
**    Mostra um pequeno painel de controle da partida
**		@param struct Player p1: jogador 1
**		@param struct Player p2: jogador 1
**		@param struct Stack* stack: ponteiro para o baralho
**		@param struct Queue* queue: ponteiro para a fila de duelos
**
**    @author Rafael Chinaglia <chinaglia.rafa@gmail.com>
*/
void hlp_render_top_bar(struct Player p1, struct Player p2, struct Stack* stack, struct Duel* duel) {
	printf("[%d x %d]", p1.score, p2.score);
	printf("     %d cartas restantes", stk_count(stack));
	printf("    duelos para resolver: [ ");
	struct Duel* seeker = duel;
	while (seeker != NULL) {
		printf("%s", hlp_label_at_pos(seeker->opt, FORMAT_CAP));
		if (seeker->prev != NULL) printf(", ");
		seeker = seeker->prev;
	}
	printf(" ]\n");
}
