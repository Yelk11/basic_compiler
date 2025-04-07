#ifndef LEX_H
#define LEX_H

#include "../include/token.h"

typedef struct lexer{
    char* src;
    int i;
    char c;
}lexer;

lexer* init_lexer(char* src);

void lexer_advance(lexer* lexer);

void skip_whitespace(lexer* lexer);

token* lexer_next_token(lexer* lexer);

token* lexer_peek_next_token(lexer* lex);

#endif