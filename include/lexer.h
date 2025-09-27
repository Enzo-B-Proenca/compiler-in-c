#ifndef LEXER_H
#define LEXER_H

#define BUF_SIZE 256
#define MAX_TOKENS 1024

// Includes
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas usadas
typedef struct {
  char *source_code;
  size_t current_pos;
  size_t current_line;
} LexerState;

typedef enum TokenType {
  PROGRAM,
  BEGIN,
  END,
  PROCEDURE,
  IF,
  THEN,
  ELSE,
  WHILE,
  DO,
  AND,
  OR,
  NOT,
  VAR,
  INTEGER,
  BOOLEAN,
  TRUE,
  FALSE,
  WRITE,
  DIV,
  DELIMITER_PAREN_OPEN,
  DELIMITER_PAREN_CLOSE,
  DELIMITER_DOT,
  DELIMITER_COMMA,
  DELIMITER_SEMICOLON,
  DELIMITER_COLON,
  OPERATOR_LESS,
  OPERATOR_GREATER,
  OPERATOR_NOT_EQUAL,
  OPERATOR_LESS_EQUAL,
  OPERATOR_GREATER_EQUAL,
  OPERATOR_ASSIGN,
  OPERATOR_PLUS,
  OPERATOR_MINUS,
  OPERATOR_TIMES,
  ID,
  NUMBER,
  EOF_TOKEN,
  ERROR
} Token_t;

typedef struct {
  char *lexeme; // 8 Bytes
  Token_t type; // 4 Bytes
  size_t line;
} Token;

typedef struct {
  char *keyword_string;
  Token_t type;
} Keyword;

// Declarações de funções
Token get_next_token(LexerState *state);
char *read_source_file(const char *file_path);
static void consume_whitespace(LexerState *state);
static Token scan_identifier_or_keyword(LexerState *state, size_t line);
static Token scan_number(LexerState *state, size_t line);
#endif // !LEXER_H
