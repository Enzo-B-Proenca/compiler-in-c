#ifndef FINAL_WORDS_H
#define FINAL_WORDS_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../../lexer/lexer.h"


token_t* evaluate_program(char* word);
token_t* evaluate_if(char* word);
token_t* evaluate_do(char* word);
token_t* evaluate_var(char* word);
token_t* evaluate_false(char* word);
token_t* evaluate_begin(char* word);
token_t* evaluate_then(char* word);
token_t* evaluate_and(char* word);
token_t* evaluate_integer(char* word);
token_t* evaluate_write(char* word);
token_t* evaluate_end(char* word);
token_t* evaluate_else(char* word);
token_t* evaluate_or(char* word);
token_t* evaluate_boolean(char* word);
token_t* evaluate_procedure(char* word);
token_t* evaluate_while(char* word);
token_t* evaluate_not(char* word);
token_t* evaluate_true(char* word);

#endif