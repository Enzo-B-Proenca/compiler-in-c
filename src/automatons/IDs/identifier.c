#include "identifier.h"

token_t *evaluate_id(char *word)
{
    int state = 0;
    int size = strlen(word);

    for(int i = 0; i < size; i++){
        char way = word[i];
        switch (state)
        {
        case 0:
            if(verify_digit(way)) state = 1;
            else state = -1;
            break;
        case 1:
            if(verify_digit(way) || verify_letter(way)) state = 1;
            else state = -1;
        
        default:
            break;
        }
    }

    if(state == 1){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = ID;
        return t;
    }

    return NULL;
}
