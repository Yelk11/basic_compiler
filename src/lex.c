#include "../include/lex.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>


lexer* init_lexer(char* src)
{
    lexer* lex = calloc(1,sizeof(lexer));
    lex->src = src;
    lex->i = 0;
    lex->c = lex->src[lex->i];
    return lex;
}

void lexer_advance(lexer* lexer)
{
    if(lexer->c != '\0')
    {
        lexer->i++;
        lexer->c = lexer->src[lexer->i];
    }
}

void skip_whitespace(lexer* lexer){
    while(lexer->c == ' ' || lexer->c == '\t')
    {
        lexer_advance(lexer);
    }
}

token* lexer_peek_next_token(lexer* lex)
{
    lexer* temp_lex = lex;
    return lexer_next_token(temp_lex);
}
token* lexer_next_token(lexer* lexer)
{
    skip_whitespace(lexer);
    if (isdigit(lexer->c)) {
        char buffer[256] = {0};
        int i = 0;
        while (isdigit(lexer->c)) {
            buffer[i++] = lexer->c;
            lexer_advance(lexer);
        }
        token* tok = malloc(sizeof(token));
        tok->type = NUMBER;
        tok->value = strdup(buffer);
        return tok;
    }

    if (isalpha(lexer->c)) {
        char buffer[256] = {0};
        int i = 0;
        while (isalnum(lexer->c)) {
            buffer[i++] = lexer->c;
            lexer_advance(lexer);
        }
        token* tok = malloc(sizeof(token));
        tok->type = IDENTIFIER;
        tok->value = strdup(buffer);
        return tok;
    }

    if (lexer->c == '\0') {
        token* tok = malloc(sizeof(token));
        tok->type = EOF;
        tok->value = NULL;
        return tok;
    }

    // Handle single-character tokens (e.g., =, +, -, etc.)
    char c = lexer->c;
    lexer_advance(lexer);
    token* tok = malloc(sizeof(token));
    tok->type = OPERATOR;
    tok->value = strndup(&c, 1);
    return tok;
}



