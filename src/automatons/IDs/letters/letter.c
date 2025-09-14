#include "numbers.h"

bool verify_letter(char c)
{
    int state = 0;
    switch (c)
    {
        case 0:
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_'))state = 1;
            break;

        default:
            break;
    }

    return state;
}