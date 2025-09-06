#ifndef LEXER_H
#define LEXER_H

typedef enum token_type {
  NUMBER,
  PLUS,
  MINUS,
  STAR,
  SLASH 
} token_type_t;

typedef struct token {
  token_type_t ty;
  char *lexeme;
  struct token *next;
} token_t;

token_t *lexer_parser(char *source);
void lexer_push(token_type_t ty, char *lexeme);
#endif // !_LEXER_H_
