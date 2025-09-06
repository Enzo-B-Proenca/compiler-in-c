// Criar tokens em uma tabela de símbolos
// Montar uma árvore léxica
#include "lexer.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static token_t *list;
static token_t *head;

void lexer_push(token_type_t ty, char *lexeme) {
  list->next = (token_t *)malloc(sizeof(token_t));
  list->next->ty = ty;
  list->next->lexeme = lexeme;

  list = list->next;
}

token_t *lexer_parser(char *source) {
  token_t *list = (token_t *)malloc(sizeof(*list));
  head = list;
  bzero(list, sizeof(token_t));

  for (size_t i = 0; i < strlen(source); i++) {
    char current = source[i];

    switch (current) {
    case '+':
      lexer_push(PLUS, "+");
    case '-':
      lexer_push(MINUS, "-");
    case '*':
      lexer_push(STAR, "*");
    case '/':
      lexer_push(SLASH, "/");
    }

    if (isdigit(current)){
      char *begin = &source[i];
      size_t len = i;
      i++;
      current = source[i];

      while (isdigit(current)){
        i++;
        current = source[i];
      }

      len = i - len;
      char *lexeme = malloc(sizeof(char) * (len+1));
      strncpy(lexeme, begin, len);
      lexeme[len] = '\0';
      lexer_push(NUMBER, lexeme);
    }
  }

  return list;
}
