#include <stdio.h>
#include "str.h"

int main() { 
    Str s1 = read_file("./input/notes/chapter 1.md");

    StrSlice slice = slice_str(&s1, sizeof(char) * 500, sizeof(char) * 1000);

    Str s2 = slice_to_str(slice);

    printf("%s", s2.c_str);

    return 0;
}
