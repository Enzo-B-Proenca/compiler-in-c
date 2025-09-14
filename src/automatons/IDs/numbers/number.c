#include "number.h"

bool verify_digit(char c)
{
    int state = 0;
    switch (c)
    {
        case 0:
            if(c >= '0' && c <= '9')state = 1;
            break;

        default:
            break;
    }

    return state;
}

token_t *evaluate_number(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(verify_digit(way))state = 1;
            else state = -1;
            break;
        case 1:
            if(verify_digit(way))state = 1;
            else state = -1;
            break;
        default:
            break;
        }
    }

    if(state == 1){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}
