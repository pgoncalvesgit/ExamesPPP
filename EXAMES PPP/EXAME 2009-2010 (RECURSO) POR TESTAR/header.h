
typedef  struct  pais  *List;
typedef  struct  jogo  *Pont_jogo;
typedef  struct  pais{
    char*  nome;
    char  grupo;
    Pont_jogo jogos[3];
    List  next;
}Pais_node;

typedef  struct  jogo  {
    Pais_node  *p1,  *p2;
    int  g1,  g2;
}Jogo_node;
