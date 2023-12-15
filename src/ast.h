#pragma once

#include "str.h"

typedef enum AstNodeType { 
    BLOCK
} AstNodeType;

typedef struct AstNode {
    StrSlice source;
    AstNodeType type;
    struct AstNode* children;
    int num_children;
} AstNode;

AstNode str_to_ast(Str s1);
