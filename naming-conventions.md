# Naming Conventions

## O que não fazer
 *Usar caracteres especiais em "printf"(parênteses estão inclusos)
## Nomes de arquivos
+ Arquivos .c
  * Apenas letras minúsculas
  * Palavras separadas por underline (_)
+ Arquivos .h
  * Primeira letra maiúscula
  * Palavras separadas por underline (_)
  * Recomenda-se um comentário na primeira linha discriminando a sigla do arquivo
+ Arquivos de dados (.txt, .csv, .json)
  * Apenas letras minúsculas
  * Palavras no plural

## Variáveis
+ Separar as palavras apenas por underline (_)
+ Não abreviar nomes de variáveis se isso for perder legibilidade
+ Usar apenas nomes em inglês, com exceção de variáveis onde a legibilidade fica comprometida

### Constantes
Todas as letras maiúsculas.

Ex.:
+ *int* MAX = 10;
+ *short* ERROR_ALERT = 0;

### Tipos de estrutura
Apenas a primeira letra maiúscula. _Não usar typedef_.

Ex.:
+ *struct* Queue {}
+ *struct* Card {}
+ *struct* Cards_in_deck {}

### Variáveis locais
Todas as letras minúsculas.

Ex.:
+ *int* i = 0;
+ *char* initial_letter = 'c';
+ *float* very_long_variable_name = 0;

### Vetores
Usar as palavras no plural.

E.:
+ *int* values[10];
+ *struct* Queue players_decks[2];

## Funções
+ Usar apenas letras minúsculas
+ Usar nomes de função apenas em inglês
+ Separar as palavras apenas por underlines (_)
+ Usar verbos que sejam claros
  * make_card();
  * draw_hand();
  * play_card(int position_in_hand, struct Player_hand *hand);
+ Para gestão de filas e pilhas, usar os nomes padrões:
  + push() *para adicionar um item*
  + pop() *para remover um item*
+ Se houver parâmetros que sejam ponteiros, ordená-los por último
  ```c
    //  função
    void play_card(int position_in_hand, struct Player_hand *hand);
    //  chamada
    play_card(1, &p1_hand);
  ```
+ Usar os seguintes prefixos conforme relevante:
  * is_ (para funções que respondem sim ou não)
  * make_ (para funções que criam um tipo de dado)
  * generate_ (para funções que geram estruturas com valores aleatórios)
  * remove_ (para funções que removem itens de estruturas)
  * add_ (para funções que adicionam itens a estruturas)
  * print_ (para imprimir conteúdos)
  * format_ (para formatação de conteúdos como nomes, valores com casas decimais)
+ Criar docstring acima da função, no padrão abaixo:
```c
/**
**    Função responsável por verificar se um card é raro
**    @param struct Card: card a ser verificado
**    @return Boolean: 1 se o card for raro, 0 caso contrário.
**
**    @author Nome do autor <email.do@autor.com>
*/
Boolean is_rare(struct Card card) {
    return 1;
}
```

### Funções que verificam valores e retornam Boolean (short 0/1)
Começar por "is_"

Ex.:
+ is_rare(struct Card);
+ is_used();

### Funções que geram objetos
Começar por "make_"

Ex.:
+ make_card();
+ make_hand();

### Funções componentes de uma lib
Havendo uma função cuja definição aconteça em um nome_do_arquivo.h, prefixar a função com a sigla do arquivo.

Ex.:
+ *Card.h* (crd)
  + crd_make_card();
  + crd_shuffle_in_deck();
+ *Player_hand.h* (phnd)
  + phnd_draw_hand();
  + phnd_is_empty(struct Player_hand hand);
+ *Deck.h* (dck)
  + dck_is_empty(struct Deck deck);
  
### Funções helper
Funções com intenção de formatar, imprimir, ou de forma geral servirem como procedimento que ajuda em
uma tarefa devem ser escritas de forma clara, em letras minúsculas e sem prefixo.

Ex.:
+ *void* print_card(struct Card card);
+ *int* overview_card(struct Card card);
