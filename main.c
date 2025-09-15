#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

typedef struct {
  char *source_code;
  int current_pos;
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
  Token_t type;
  char *lexeme;
} Token;

typedef struct {
  char *keyword_string;
  Token_t type;
} Keyword;

Keyword keywords[] = {{"program", PROGRAM}, {"begin", BEGIN},
                      {"end", END},         {"procedure", PROCEDURE},
                      {"if", IF},           {"then", THEN},
                      {"else", ELSE},       {"while", WHILE},
                      {"do", DO},           {"and", AND},
                      {"or", OR},           {"not", NOT},
                      {"var", VAR},         {"integer", INTEGER},
                      {"boolean", BOOLEAN}, {"true", TRUE},
                      {"false", FALSE},     {"write", WRITE},
                      {"div", DIV}};

Token get_next_token(LexerState *state) {
  // Consome os espaçps em branco
  while (isspace(state->source_code[state->current_pos]))
    state->current_pos++;

  char current_char = state->source_code[state->current_pos];

  if (current_char == '\0')
    return (Token){EOF, NULL};

  // Palavras reservadas e identificadores
  if (isalpha(current_char)) {
    char buffer[BUF_SIZE];
    int buf_pos = 0;

    while (isalnum(state->source_code[state->current_pos]) ||
           state->source_code[state->current_pos] == '_')
      buffer[buf_pos++] = state->source_code[state->current_pos++];

    buffer[buf_pos] = '\0';
    char *lexeme = strdup(buffer);

    for (int i = 0; keywords[i].keyword_string != NULL; i++) {
      if (strcmp(lexeme, keywords[i].keyword_string) == 0)
        return (Token){keywords[i].type, lexeme};
    }

    return (Token){ID, lexeme};
  }

  // Números
  if (isdigit(current_char)) {
    char buffer[BUF_SIZE];
    int buf_pos = 0;

    while (isdigit(state->source_code[state->current_pos]))
      buffer[buf_pos++] = state->source_code[state->current_pos++];

    buffer[buf_pos] = '\0';
    return (Token){NUMBER, strdup(buffer)};
  }

  // Operadores e delimitadores
  switch (current_char) {
  case '(':
    state->current_pos++;
    return (Token){DELIMITER_PAREN_OPEN, strdup("(")};
  case ')':
    state->current_pos++;
    return (Token){DELIMITER_PAREN_CLOSE, strdup(")")};
  case '.':
    state->current_pos++;
    return (Token){DELIMITER_DOT, strdup(".")};
  case ',':
    state->current_pos++;
    return (Token){DELIMITER_COMMA, strdup(",")};
  case ';':
    state->current_pos++;
    return (Token){DELIMITER_SEMICOLON, strdup(";")};

  case '+':
    state->current_pos++;
    return (Token){OPERATOR_PLUS, strdup("+")};
  case '-':
    state->current_pos++;
    return (Token){OPERATOR_MINUS, strdup("-")};
  case '*':
    state->current_pos++;
    return (Token){OPERATOR_TIMES, strdup("*")};

  case '<':
    state->current_pos++;
    if (state->source_code[state->current_pos] == '>') {
      state->current_pos++;
      return (Token){OPERATOR_NOT_EQUAL, strdup("<>")};
    } else if (state->source_code[state->current_pos] == '=') {
      state->current_pos++;
      return (Token){OPERATOR_LESS_EQUAL, strdup("<=")};
    } else {
      return (Token){OPERATOR_LESS, strdup("<")};
    }
  case '>':
    state->current_pos++;
    if (state->source_code[state->current_pos] == '=') {
      state->current_pos++;
      return (Token){OPERATOR_GREATER_EQUAL, strdup(">=")};
    } else {
      return (Token){OPERATOR_GREATER, strdup(">")};
    }
  case ':':
    state->current_pos++;
    if (state->source_code[state->current_pos] == '=') {
      state->current_pos++;
      return (Token){OPERATOR_ASSIGN, strdup(":=")};
    } else {
      return (Token){DELIMITER_COLON, strdup(":")};
    }

  default:
    return (Token){ERROR, strdup("Caractere inválido")};
  }
}

char *read_source_file(const char *file_path) {
  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    perror("Erro ao abrir o arquivo\n");
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  if (file_size == 0) {
    fclose(file);
    char *empty_buffer = malloc(1);
    if (empty_buffer == NULL) {
      perror("Erro de alocação de memória");
      return NULL;
    }
    empty_buffer[0] = '\0';
    return empty_buffer;
  }

  char *buffer = (char *)malloc(file_size + 1);
  if (buffer == NULL) {
    perror("Erro de alocação de memória\n");
    fclose(file);
    return NULL;
  }

  size_t bytes_read = fread(buffer, 1, file_size, file);
  if (bytes_read != file_size) {
    perror("Erro ao ler o arquivo\n");
    free(buffer);
    fclose(file);
    return NULL;
  }

  buffer[file_size] = '\0';
  fclose(file);
  return buffer;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Uso: %s <caminho_do_arquivo>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *source = read_source_file(argv[1]);
  if (source == NULL) {
    return EXIT_FAILURE;
  }

  LexerState lexer_state = {.source_code = source, .current_pos = 0};

  Token token;
  do {
    // Passa a struct de estado para a função
    token = get_next_token(&lexer_state);
    if (token.type != EOF_TOKEN && token.lexeme != NULL) {
      printf("Tipo: %d, Lexeme: %s\n", token.type, token.lexeme);
      free(token.lexeme);
    }
  } while (token.type != EOF_TOKEN && token.type != ERROR);

  free(source);
  return EXIT_SUCCESS;
}
