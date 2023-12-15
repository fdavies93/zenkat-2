#include "ast.h"
#include "str.h"
#include <stdlib.h>
#include <string.h>

AstNode str_to_ast(Str s1) {
    StrSlice slice;
    slice = slice_str(&s1, 0, s1.length);
    AstNode root = { slice, BLOCK, NULL, 1 };

    int charIndex = 0;

    AstNode childBuffer[512];
    char accBuffer[512];
    int bufferIndex = 0;

    while (charIndex < s1.length) {
        switch (s1.c_str[charIndex]) {
            case '\n':
            case '\r':
            case '\t':
            case ' ':
                accBuffer[bufferIndex] = s1.c_str[charIndex];
                bufferIndex += 1;
                break;
            default:
                // get the indentation level of the block
                // i.e. is it a sub-block, part of the same block, or a sibling
                // block?
                memset(&accBuffer, 0, 512);
                break;
        }
    }

    return root; 
}
