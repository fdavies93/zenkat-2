#ifndef STR_INCLUDED
#define STR_INCLUDED
#endif

#include <stdio.h>

typedef struct Str{
    char* c_str; // underlying c string
    size_t length; // length of content
    size_t size; // length of buffer
} Str;

typedef struct StrSlice{
    const Str* str; // underlying string
    int start; // start of slice (inclusive)
    int end; // end of slice (exclusive)
} StrSlice;


void concat_str(Str* dest, char* c_str);

Str str(char* c_str);

StrSlice slice_str(const Str* str, int start, int end);

Str slice_to_str(StrSlice slice);

void delete_str(Str str);

Str read_file(const char *path);
