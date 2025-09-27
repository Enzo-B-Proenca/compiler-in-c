#include "lexer.c"

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
      printf("%ld#  %d | %s\n", token.line, token.type, token.lexeme);
      free(token.lexeme);
    }
  } while (token.type != EOF_TOKEN && token.type != ERROR);

  free(source);
  return EXIT_SUCCESS;
}
