#include "final_words.h"

token_t* evaluate_program(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'p')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'r')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'o')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 'g')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'r')state = 5;
            else state = -1;
            break;
        case 5:
            if(way == 'a')state = 6;
            else state = -1;
            break;
        case 6:
            if(way == 'm')state = 7; //estado final
            else state = -1;
            break;
        
        default:
            break;
        }
    }

    if(state == 7){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}
token_t* evaluate_boolean(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'b')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'o')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'o')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 'l')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'e')state = 5;
            else state = -1;
            break;
        case 5:
            if(way == 'a')state = 6;
            else state = -1;
            break;
        case 6:
            if(way == 'n')state = 7; 
            else state = -1;
            break;
        
        default:
            break;
        }
    }

    if(state == 7){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}
token_t* evaluate_procedure(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'p')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'r')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'o')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 'c')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'e')state = 5;
            else state = -1;
            break;
        case 5:
            if(way == 'd')state = 6;
            else state = -1;
            break;
        case 6:
            if(way == 'u')state = 7; 
            else state = -1;
            break;
        case 7:
            if(way == 'r')state = 8; 
            else state = -1;
            break;
        case 8:
            if(way == 'e')state = 9; //estado final
            else state = -1;
            break;
        
        default:
            break;
        }
    }

    if(state == 9){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_if(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'i')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'f')state = 2;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
    if(state == 2){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_do(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'd')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'o')state = 2;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
     if(state == 2){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}
token_t* evaluate_or(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'o')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'r')state = 2;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
     if(state == 2){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_var(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'v')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'a')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'r')state = 3;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
     if(state == 3){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_false(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'f')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'a')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'l')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 's')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'e')state = 5;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
    if(state == 5){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_begin(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'b')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'e')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'g')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 'i')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'n')state = 5;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
    if(state == 5){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_then(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
            case 0:
            if(way == 't')state = 1;
            else state = -1;
            break;
            case 1:
            if(way == 'h')state = 2;
            else state = -1;
            break;
            case 2:
            if(way == 'e')state = 3;
            else state = -1;
            break;
            case 3:
            if(way == 'n')state = 4;
            else state = -1;
            break;
            default:
            break;
        }
    }
    
    if(state == 4){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }
    
    return NULL;
}
token_t* evaluate_else(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
            case 0:
            if(way == 'e')state = 1;
            else state = -1;
            break;
            case 1:
            if(way == 'l')state = 2;
            else state = -1;
            break;
            case 2:
            if(way == 's')state = 3;
            else state = -1;
            break;
            case 3:
            if(way == 'e')state = 4;
            else state = -1;
            break;
            default:
            break;
        }
    }
    
    if(state == 4){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }
    
    return NULL;
}
token_t* evaluate_true(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
            case 0:
            if(way == 't')state = 1;
            else state = -1;
            break;
            case 1:
            if(way == 'r')state = 2;
            else state = -1;
            break;
            case 2:
            if(way == 'u')state = 3;
            else state = -1;
            break;
            case 3:
            if(way == 'e')state = 4;
            else state = -1;
            break;
            default:
            break;
        }
    }
    
    if(state == 4){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }
    
    return NULL;
}

token_t* evaluate_and(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
        if(way == 'a')state = 1;
            else state = -1;
            break;
            case 1:
            if(way == 'n')state = 2;
            else state = -1;
            break;
            case 2:
            if(way == 'd')state = 3;
            else state = -1;
            break;
            default:
            break;
        }
    }
    
    if(state == 3){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }
    
    return NULL;
}
token_t* evaluate_not(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
        if(way == 'n')state = 1;
            else state = -1;
            break;
            case 1:
            if(way == 'o')state = 2;
            else state = -1;
            break;
            case 2:
            if(way == 't')state = 3;
            else state = -1;
            break;
            default:
            break;
        }
    }
    
    if(state == 3){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }
    
    return NULL;
}

token_t* evaluate_end(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
        if(way == 'e')state = 1;
            else state = -1;
            break;
            case 1:
            if(way == 'n')state = 2;
            else state = -1;
            break;
            case 2:
            if(way == 'd')state = 3;
            else state = -1;
            break;
            default:
            break;
        }
    }
    
    if(state == 3){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }
    
    return NULL;
}


token_t* evaluate_integer(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
        if(way == 'i')state = 1;
        else state = -1;
        break;
        case 1:
        if(way == 'n')state = 2;
        else state = -1;
        break;
        case 2:
        if(way == 't')state = 3;
        else state = -1;
        break;
        case 3:
        if(way == 'e')state = 4;
        else state = -1;
        break;
        case 4:
        if(way == 'g')state = 5;
        else state = -1;
        break;
        case 5:
        if(way == 'e')state = 6;
        else state = -1;
        break;
        case 6:
        if(way == 'r')state = 7;
        else state = -1;
        break;
        default:
        break;
    }
}

if(state == 7){
    char* lexeme = word;
    token_t* t = (token_t*)malloc(sizeof(token_t));
    t->lexeme = &lexeme;
    t->ty = FINAL_WORD;
    return t;
}

return NULL;
}

token_t* evaluate_write(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'w')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'r')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'i')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 't')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'e')state = 5;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
    if(state == 5){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

token_t* evaluate_while(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i  = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'w')state = 1;
            else state = -1;
            break;
        case 1:
            if(way == 'h')state = 2;
            else state = -1;
            break;
        case 2:
            if(way == 'i')state = 3;
            else state = -1;
            break;
        case 3:
            if(way == 'l')state = 4;
            else state = -1;
            break;
        case 4:
            if(way == 'e')state = 5;
            else state = -1;
            break;
        default:
            break;
        }
    }
    
    if(state == 5){
        char* lexeme = word;
        token_t* t = (token_t*)malloc(sizeof(token_t));
        t->lexeme = &lexeme;
        t->ty = FINAL_WORD;
        return t;
    }

    return NULL;
}

