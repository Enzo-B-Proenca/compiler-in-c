#ifndef NUMBERS_H
#define NUMBERS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../lexer/lexer.h"


bool verify_digit(char c);
token_t* evaluate_number(char* word);

#endif