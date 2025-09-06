#include "src/lexer.c"
#include <stdio.h>

static char *SOURCE = "1 + 2";

int main(int argc, char *argv[]) {
  // Testing the parser using the SOURCE string
  token_t *list = lexer_parser(SOURCE);

  while (list != NULL){
    printf("Token: %s\n", list->lexeme);

    list = list->next;
  }

  return 0;
}
