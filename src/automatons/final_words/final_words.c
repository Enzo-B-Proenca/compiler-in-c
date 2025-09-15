#include "final_words.h"

token_t* evaluate_final_word(char *word)
{
    int size = strlen(word);
    int state = 0;
    for(int i = 0; i < size; i++){
        char way = tolower(word[i]);
        switch (state)
        {
        case 0:
            if(way == 'a')state = 1;
            else if(way == 'b') state = 2; //begin ou boolean 
            else if(way == 'd') state = 3; // do
            else if(way == 'e') state = 4; // else ou end
            else if(way == 'f') state = 5; // false
            else if(way == 'i') state = 6; // if ou integer
            else if(way == 'n') state = 7; // not
            else if(way == 'o') state = 8; // or
            else if(way == 'p') state = 9; // procedure ou program
            else if(way == 't') state = 10; // true ou then
            else if(way == 'v') state = 11; // var
            else if(way == 'w') state = 12; // while ou write
            else state = -1;
            break;
        case 1:
            if(way == 'n')state = 13; // and
            else state = -1;
            break;
        case 2:
            if(way == 'e')state = 14; // begin
            else if(way == 'o') state = 15; //boolean
            else state = -1;
            break;
        case 3:
            if(way == 'o')state = 16; // do
            else if(way == 'i') state = 17 // div
            else state = -1;
            break;
        case 4:
            if(way == 'l')state = 18; // else
            else if(way == 'n') state = 19;  // end
            else state = -1;
            break;
        case 5:
            if(way == 'a')state = 20; // false
            else state = -1;
            break;
        case 6:
            if(way == 'f')state = 21; //if
            else if(way == 'n') state=22; //integer
            else state = -1;
            break;
        case 7:
            if(way == 'o')state = 23; //not
            else state = -1;
            break;
        case 8:
            if(way == 'r')state = 24; //or
            else state = -1;
            break;
        case 9:
            if(way == 'r')state = 25; //procedure ou program
            else state = -1;
            break;
        case 10:
            if(way == 'h')state = 26; //then
            else if(way == 'r') state=27; //true
            else state = -1;
            break;
        case 11:
            if(way == 'a')state = 28; //var
            else state = -1;
            break;
        case 12:
            if(way == 'h' || way == 'r')state = 29; // while ou write
            else state = -1;
            break;
        case 13:
            if(way == 'd')state = 30; //and
            else state = -1;
            break;
        case 14:
            if(way == 'g')state = 31; //begin
            else state = -1;
            break;
        case 15:
            if(way == 'o')state = 32; //boolean
            else state = -1;
            break;
        case 16:
            break; //palavra pronta em teste: 'do'
        case 17:
            if(way == 'v') state = 33; //div
            else state = -1;
            break;
        case 18:
            if(way == 's')state = 34; //else
            else state = -1;
            break;
        case 19:
            if(way == 'd') state=35; //end
            else state = -1;
            break;
        case 20:
            if(way == 'l')state = 36; //false
            else state = -1;
            break;
        case 21:
            break; //Palavra pronta: if
        case 22:
            if(way == 't') state=37; //integer
            else state = -1;
            break;
        case 23:
            if(way == 't')state = 38; //not
            else state = -1;
            break;
        case 24:
            break; //Palavra pronta: or
        case 25:
            if(way == 'o')state = 39; //procedure ou program
            else state = -1;
            break;
        case 26:
            if(way == 'e')state = 40; //then
            else state = -1;
            break;
        case 27:
            if(way == 'u')state = 41; //true
            else state = -1;
            break;
        case 28:
            if(way == 'r')state = 42; //var
            else state = -1;
            break;
        case 29:
            if(way == 'i')state = 43; //while ou write
            else state = -1;
            break;
        case 30:
            break; //Palavra pronta: and
        case 31:
            if(way == 'i') state = 44; //begin
            else state = -1;
            break;
        case 32:
            if(way == 'l') state = 45;//boolean
            else state = -1;
            break;
        case 33:
            break; //Palavra pronta: div
        case 34:
            if(way == 'e') state = 46; // else
            else state = -1
            break;
        case 35:
            break; // Palavra pronta: end
        case 36:
            if(way == 's') state = 47; // false
            else state = -1;
            break;
        case 37:
            if(way == 'e') state = 48; // integer
            else state = -1;
            break;
        case 38:
            break;  //not
        case 39:
            if(way == 'c') state = 49; // procedure
            else if(way == 'g') state = 50; // program
            else state = -1;
            break;
        case 40:
            if(way == 'n') state = 51; //then
            else state = -1;
            break;
        case 41:
            if(way == 'e') state = 52; //true
            else state = -1;
            break;
        case 42:
            break; //Palavra pronta: var
        case 43:
            if(way == 'l') state = 53; //while
            else state = -1;
            break;
        case 44:
            if(way == 't') state = 53; //write
            else state = -1;
            break;
        case 45:
            if(way == 'n') state = 54; //begin
            els
            e state = -1;
            break;
        case 46:
            if(way == 'e') state = 55; // boolean
            else state = -1;
            break;
        case 47:
            if(way == 'e') state = 56; // false
            else state = -1;
            break;
        case 48:
            if(way == 'g') state = 57; //integer
            else state = -1;
            break;
        case 49:
            if(way == 'e') state = 58; //procedure
            else state = -1;
            break;
        case 50:
            if(way == 'r') state = 59; //program
            else state = -1;
            break;
        case 51:
            break; //then
        case 52:
            break; //true
        case 53:
            if(way == 'e' && word[i-1] == 'l') state = 60; //while
            else if(way == 'e' && word[i-1] == 't') state = 61; //write
            else state = -1;
            break;
        case 54:
            break // palavra: begin
        case 55:
            if(way == 'a') state = 62;//boolean
            else state = -1;
            break;
        case 56:
            break; //palvra false
        case 57:
            if(way == 'e') state = 63; // integer
            else state = -1;
            break;
        case 58:
            if(way == 'd') state = 64;// procedure
            else state = -1;
            break;
        case 59:
            if(way == 'a') state = 65; //program
            else state = -1;
            break;
        case 60:
            break; //while
        case 61:
            break; //write
        case 62:
            if(way == 'n') state = 66; //boolean
            else state = -1;]
            break;
        case 63:
            if(way == 'r') state = 67; //integer
            else state = -1;
            break;
        case 64:
            if(way == 'u') state = 68; //procedure
            else state = -1;
            break;
        case 65:
            if(way == 'm') state = 69; //program
            else state = -1;
            break;
        case 66:
            break; //boolean
        case 67:
            break; //integer
        case 68:
            if(way == 'r') state = 70; //procedure
            else state = -1;
            break;
        case 69:
            break; // program
        case 70:
            if(way == 'e') state = 71; //procedure
            else state = -1;
            break;
        case 71:
            break; //procedure
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

