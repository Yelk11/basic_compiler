#include "../include/parse.h"
#include "../include/lex.h"
#include "../include/token.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void parse_error(token* tok)
{
    printf("below Token failed");
    printf("%s\n",type_to_string(tok));
    printf("%s\n",tok->value);
}

/*
<statement> ::= <let-stmt>
             | <print-stmt>
             | <input-stmt>
             | <goto-stmt>
             | <if-stmt>
             | <end-stmt>

*/

ast_node* parse_statement(lexer* lex)
{
    token* tok = lexer_peek_next_token(lex);
    if(strcmp(tok->value, "LET") == 0)
    {
        return parse_let_stmt(lex);
    }else if (strcmp(tok->value, "PRINT") == 0)
    {
        return parse_print_stmt(lex);
    }else if (strcmp(tok->value,"INPUT") == 0)
    {
        return parse_input_stmt(lex);
    }else if (strcmp(tok->value, "GOTO") == 0)
    {
        return parse_goto_stmt(lex);
    }else if (strcmp(tok->value,"IF") == 0)
    {
        return parse_if_stmt(lex);
    }else if(strcmp(tok->value, "END") == 0)
    {
        return parse_end_stmt(lex);
    }else{
        parse_error(tok);
        return NULL;
    }
}




// <let-stmt> ::= "LET" <var> "=" <expr>
ast_node* parse_let_stmt(lexer* lex)
{
    ast_node* var_node = NULL;
    ast_node* expr_node = NULL;
    ast_node* node = (ast_node*)calloc(1,sizeof(ast_node));
    token* tok = lexer_next_token(lex);

    if(strcmp(tok->value, "LET") == 0)
    {
        var_node = parse_var(lex);
        tok = lexer_next_token(lex);
        if(strcmp(tok->value, "LET") == 0)
        {
            expr_node = parse_expression(lex);
        }
    }
    node->type = ASSIGNMENT;
    node->left = var_node;
    node->right = expr_node;
    return node;
}
// <print-stmt> ::= "PRINT" <print-list>
ast_node* parse_print_stmt(lexer* lex)
{
    ast_node* node = (ast_node*)calloc(1,sizeof(ast_node));
    ast_node* print_list_node;
    token* tok = lexer_next_token(lex);
    if(strcmp(tok->value, "PRINT") == 0){
        print_list_node = parse_print_list(lex);
    }else{
        parse_error(tok);
    }
    node->type = PRINT;
    node->left = print_list_node;
    return node;
}
// <print-list> ::= <print-item> { "," <print-item> }
ast_node* parse_print_list(lexer* lex)
{
    ast_node* node = (ast_node*)calloc(1,sizeof(ast_node));
    ast_node* print_list_node;
    token* tok;
    parse_print_item(lex);
    tok = lexer_next_token(lex);
    if(strcmp(tok->value, ",") == 0)
    {

    }
    else
    {
        parse_print_item(lex);
    }
}
// <print-item> ::= <string> | <expr>
ast_node* parse_print_item(lexer* lex)
{

}
// <input-stmt> ::= "INPUT" <var>
ast_node* parse_input_stmt(lexer* lex)
{

}
// <goto-stmt> ::= "GOTO" <number>
ast_node* parse_goto_stmt(lexer* lex)
{

}
// <if-stmt> ::= "IF" <expr> <relop> <expr> "THEN" <number>
ast_node* parse_if_stmt(lexer* lex)
{

}
// <end-stmt> ::= "END"
ast_node* parse_end_stmt(lexer* lex)
{

}
// <expr> ::= <term> { ("+" | "-") <term> }
ast_node* parse_expression(lexer* lex)
{

}
// <term> ::= <factor> { ("*" | "/") <factor> }
ast_node* parse_term(lexer* lex)
{

}
/*
<factor> ::= <number>
          | <var>
          | "(" <expr> ")"
*/
ast_node* parse_factor(lexer* lex)
{

}

// <relop> ::= "=" | "<>" | "<" | ">" | "<=" | ">="
ast_node* parse_relop(lexer* lex)
{

}
// <var> ::= A | B | C | ... | Z
ast_node* parse_var(lexer* lex)
{

}

// <number> ::= [0-9]+
ast_node* parse_number(lexer* lex)
{

}
// <string> ::= "\"" { any character except "\"" } "\""
ast_node* parse_string(lexer* lex)
{

}



