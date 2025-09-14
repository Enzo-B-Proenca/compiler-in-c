#ifndef ID_H
#define ID_H

#include "../../lexer/lexer.h"
#include "letters/letter.h"
#include "numbers/number.h"
#include <stdlib.h>
#include <string.h>

token_t* evaluate_id(char* word);

#endif