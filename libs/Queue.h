/**
**	Sigla: qeu
**	Lib responsavel por gerenciar a fila de duelos
**
*/

struct Duel {
  float value_p1;
  float value_p2;
  int opt;          //  Caracteristica escolhida para o duelo
  struct Duel* next;
};

struct Queue {
  struct Duel *top;
  struct Duel *bottom;
};
