#include "lexer.c"
#include <stdio.h>

static char *SOURCE = "1 + 2";

int main(int argc, char *argv[]) {
  token_t *list = lexer_parser(SOURCE);

  while (list != NULL){
    printf("Token: %s\n", list->lexeme);

    list = list->next;
  }

  return 0;
}
