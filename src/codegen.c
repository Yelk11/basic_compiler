

#include "../include/parse.h"
#include "../include/codegen.h"
#include <stdio.h>

void generate_code(ast_node* root) {
    if (root->type == PRINT) {
        printf("printf(\"%%s\\n\", %s);\n", root->value);
    } else if (root->type == ASSIGNMENT) {
        printf("%s = %s;\n", root->left->value, root->right->value);
    }
    // Add more cases for INPUT, IF, GOTO, etc.
}

