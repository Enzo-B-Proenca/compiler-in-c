#include "../include/lexer.h"
Keyword keywords[] = {{"program", PROGRAM}, {"begin", BEGIN},
                      {"end", END},         {"procedure", PROCEDURE},
                      {"if", IF},           {"then", THEN},
                      {"else", ELSE},       {"while", WHILE},
                      {"do", DO},           {"and", AND},
                      {"or", OR},           {"not", NOT},
                      {"var", VAR},         {"integer", INTEGER},
                      {"boolean", BOOLEAN}, {"true", TRUE},
                      {"false", FALSE},     {"write", WRITE},
                      {"div", DIV},         {NULL, ERROR}};

Token symbolTable[MAX_TOKENS];

static void consume_whitespace(LexerState *state) {
  while (1) {
    char c = state->source_code[state->current_pos];
    if (c == '\n') {
      state->current_line++;
      state->current_pos++;
    } else if (isspace(c))
      state->current_pos++;
    else
      break;
  }
}

static Token scan_identifier_or_keyword(LexerState *state, size_t line) {
  char buffer[BUF_SIZE];
  int buf_pos = 0;

  while (state->source_code[state->current_pos] != '\0' &&
         buf_pos < BUF_SIZE - 1 &&
         (isalnum(state->source_code[state->current_pos]) ||
          state->source_code[state->current_pos] == '_')) {
    buffer[buf_pos++] = state->source_code[state->current_pos++];
  }

  buffer[buf_pos] = '\0';
  char *lexeme = strdup(buffer);

  for (int i = 0; keywords[i].keyword_string != NULL; i++) {
    if (strcmp(lexeme, keywords[i].keyword_string) == 0)
      return (Token){.type = keywords[i].type, .lexeme = lexeme, .line = line};
  }

  return (Token){.type = ID, .lexeme = lexeme, .line = line};
}

static Token scan_number(LexerState *state, size_t line) {
  char buffer[BUF_SIZE];
  int buf_pos = 0;

  while (state->source_code[state->current_pos] != '\0' &&
         buf_pos < BUF_SIZE - 1 &&
         isdigit(state->source_code[state->current_pos])) {
    buffer[buf_pos++] = state->source_code[state->current_pos++];
  }

  buffer[buf_pos] = '\0';
  return (Token){.type = NUMBER, .lexeme = strdup(buffer), .line = line};
}

Token get_next_token(LexerState *state) {
  consume_whitespace(state);
  size_t token_start_line = state->current_line;
  char current_char = state->source_code[state->current_pos];

  if (current_char == '\0')
    return (Token){.type = EOF_TOKEN, .lexeme = NULL, .line = token_start_line};

  // Palavras reservadas e identificadores
  if (isalpha(current_char)) {
    return scan_identifier_or_keyword(state, token_start_line);
  }

  // Números
  if (isdigit(current_char)) {
    return scan_number(state, token_start_line);
  }

  state->current_pos++;

  // Operadores e delimitadores
  switch (current_char) {
  case '(':
    return (Token){.type = DELIMITER_PAREN_OPEN,
                   .lexeme = strdup("("),
                   .line = token_start_line};
  case ')':
    return (Token){.type = DELIMITER_PAREN_CLOSE,
                   .lexeme = strdup(")"),
                   .line = token_start_line};
  case '.':
    return (Token){
        .type = DELIMITER_DOT, .lexeme = strdup("."), .line = token_start_line};
  case ',':
    return (Token){.type = DELIMITER_COMMA,
                   .lexeme = strdup(","),
                   .line = token_start_line};
  case ';':
    return (Token){.type = DELIMITER_SEMICOLON,
                   .lexeme = strdup(";"),
                   .line = token_start_line};

  case '+':
    return (Token){
        .type = OPERATOR_PLUS, .lexeme = strdup("+"), .line = token_start_line};
  case '-':
    return (Token){.type = OPERATOR_MINUS,
                   .lexeme = strdup("-"),
                   .line = token_start_line};
  case '*':
    return (Token){.type = OPERATOR_TIMES,
                   .lexeme = strdup("*"),
                   .line = token_start_line};

  case '<':
    if (state->source_code[state->current_pos] == '>') {
      state->current_pos++;
      return (Token){.type = OPERATOR_NOT_EQUAL,
                     .lexeme = strdup("<>"),
                     .line = token_start_line};
    } else if (state->source_code[state->current_pos] == '=') {
      state->current_pos++;
      return (Token){.type = OPERATOR_LESS_EQUAL,
                     .lexeme = strdup("<="),
                     .line = token_start_line};
    } else {
      return (Token){.type = OPERATOR_LESS,
                     .lexeme = strdup("<"),
                     .line = token_start_line};
    }
  case '>':
    if (state->source_code[state->current_pos] == '=') {
      state->current_pos++;
      return (Token){.type = OPERATOR_GREATER_EQUAL,
                     .lexeme = strdup(">="),
                     .line = token_start_line};
    } else {
      return (Token){.type = OPERATOR_GREATER,
                     .lexeme = strdup(">"),
                     .line = token_start_line};
    }
  case ':':
    if (state->source_code[state->current_pos] == '=') {
      state->current_pos++;
      return (Token){.type = OPERATOR_ASSIGN,
                     .lexeme = strdup(":="),
                     .line = token_start_line};
    } else {
      return (Token){.type = DELIMITER_COLON,
                     .lexeme = strdup(":"),
                     .line = token_start_line};
    }

  default:
    return (Token){.type = ERROR,
                   .lexeme = strdup("Caractere inválido"),
                   .line = token_start_line};
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
