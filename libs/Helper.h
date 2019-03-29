/**
**	Sigla: hlp
**	Lib responsavel por conter funções auxiliares, de conversão e etc
**
*/

//	CONSTANTES
#define FORMAT_LOWER 0
#define FORMAT_UPPER 1
#define FORMAT_CAP 2

/**
**    Converte um int no intervalo [1,5] para o label da posição no card
**    @param int pos: posição no intervalo [1,5]
**	  @param int format: FORMAT_LOWER=0, FORMAT_UPPER=1, FORMAT_CAP=2
**
**	  @return char*: label da posição
**
**	  Uso:
**		hlp_label_at_pos(1, FORMAT_UPPER); // retorna "PODER DESTRUTIVO"
**		hlp_label_at_pos(3, FORMAT_CAP); // retorna "Eficiência"
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
		case 2:
			if 		(format == FORMAT_LOWER) return "segurança";
			else if (format == FORMAT_UPPER) return "SEGURANÇA";
			else if (format == FORMAT_CAP)   return "Segurança";
		case 3:
			if 		(format == FORMAT_LOWER) return "eficiência";
			else if (format == FORMAT_UPPER) return "EFICIÊNCIA";
			else if (format == FORMAT_CAP)   return "Eficiência";
		case 4:
			if 		(format == FORMAT_LOWER) return "dados afetados";
			else if (format == FORMAT_UPPER) return "DADOS AFETADOS";
			else if (format == FORMAT_CAP)   return "Dados afetados";
		case 5:
			if 		(format == FORMAT_LOWER) return "furtividade";
			else if (format == FORMAT_UPPER) return "FURTIVIDADE";
			else if (format == FORMAT_CAP)   return "Furtividade";
		default:
			printf("\nERRO: pos out of range.");
	}
	return "";
}
