#include <token.h>

char* type_to_string(token* tok)
{
    switch(tok->type)
    {
        case IDENTIFIER:
            return "IDENTIFIER";
        case KEYWORD:
            return "KEYWORD";
        case NUMBER:
            return "NUMBER";
        case OPERATOR:
            return "OPERATOR";
        case DELIMETER:
            return "DELIMETER";
        case EOF:
            return "EOF";
    }
}


