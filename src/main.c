#include "../include/lex.h"
#include "../include/parse.h"
#include "../include/codegen.h"
#include <stdio.h>



int main()
{
  char* src = "PRINT X";
  lexer* lex = init_lexer(src);

  token* tok = lexer_next_token(lex);
  while(tok->type != EOF)
  {
    printf("Token: %s\n", tok->value);
    tok = lexer_next_token(lex);
  }
  return 0;
}







