#ifndef PARSER_H
#define PARSER_H

#include "../include/lex.h"

typedef struct ast_node {
    enum {
        PRINT,
        INPUT,
        ASSIGNMENT,
        IF,
        GOTO
    } type;
    char* value; // For PRINT, INPUT, or variable names
    struct ast_node* left;  // For expressions
    struct ast_node* right; // For expressions
} ast_node;

ast_node* parse_statement(lexer* lex);
ast_node* parse_let_stmt(lexer* lex);
ast_node* parse_print_stmt(lexer* lex);
ast_node* parse_print_list(lexer* lex);
ast_node* parse_print_item(lexer* lex);
ast_node* parse_input_stmt(lexer* lex);
ast_node* parse_goto_stmt(lexer* lex);
ast_node* parse_if_stmt(lexer* lex);
ast_node* parse_end_stmt(lexer* lex);
ast_node* parse_expression(lexer* lex);
ast_node* parse_term(lexer* lex);
ast_node* parse_factor(lexer* lex);
ast_node* parse_relop(lexer* lex);
ast_node* parse_var(lexer* lex);
ast_node* parse_number(lexer* lex);

ast_node* parse_string(lexer* lex);






#endif