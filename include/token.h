#ifndef TOKEN_H
#define TOKEN_H


typedef struct token{
    char* value;
    enum
    {
        IDENTIFIER,
        KEYWORD,
        NUMBER,
        OPERATOR,
        DELIMETER,
        EOF
    }type;
}token;

token *init_token(char *value, int type);
char* type_to_string(token* tok);

#endif