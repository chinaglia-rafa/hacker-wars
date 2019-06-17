#include <stdio.h>

void print_init_text() {
  printf("Saudacoes, hackers.\n");
  printf("Voces estao prestes a duelar no Hacker Wars. Voces conhecem as regras do jogo?\n");
}

void print_tutorial() {
  printf("\nNo Hacker Wars, dois hackers duelam usando varias tecnicas ciberneticas para fazer pontos.\n");
  printf("Os jogadores usarao a mesma pilha de cards com caracteristicas diferentes.\n");
  printf("    Cards com PODER DESTRUTIVO elevado causam muitos danos ao oponente.\n");
  printf("    Cards com altos niveis de SEGURANCA protegem melhor o hacker.\n");
  printf("    EFICIENCIA diz quao rapido o hacker consegue usar a tecnica.\n");
  printf("    DADOS AFETADOS mede a quantidade de Terabytes afetados pelo card.\n");
  printf("    Um bom hacker age sem ser visto, e a FURTIVIDADE indica isso!\n\n");
  printf("O jogo comeca com os hackers comprando 3 cards cada um e sorteando quem comeca.\n");
  printf("O jogador que comecar escolhe uma das 5 caracteristicas, e depois um card de sua mao.\n");
  printf("O segundo jogador entao escolhe um card de sua mao, com a intencao de que o valor\n");
  printf("da caracteristica escolhida para o duelo seja superior a do oponente.\n");
  printf("Os dois cards sao entao colocados em uma fila de duelos juntos. Isso ocorre ate que\n");
  printf("os dois jogadores fiquem sem cards na mao.\n\n");
  printf("Quando a fila de duelos esta cheia, um a um os duelos sao resolvidos e o jogador\n");
  printf("que escolheu o card com maior valor de caracteristica ganha um ponto.\n");
  printf("Quando a fila de duelos termina, os jogadores compram 3 novos cards e o processo\n");
  printf("se repete ate que a pilha de cards acabe e um jogador seja declarado CAMPEAO!\n\n");
  printf("Resumindo: \n");
  printf("    1. Cada jogador compra 3 cards\n");
  printf("    2. Um jogador escolhe uma caracteristica e um card\n");
  printf("    3. O outro jogador tambem escolhe um card da mao\n");
  printf("    4. Volta para o passo 2 enquanto houverem cards na mao dos hackers\n");
  printf("    5. Cada jogador que ganhou um duelo ganha um ponto\n");
  printf("    6. Repete ate qua a pilha de cards acabe e um jogador venca!\n\n");
}
