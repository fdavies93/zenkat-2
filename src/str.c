#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "consts.h"

void concat_str(Str* dest, char* c_str) {
    size_t c_size = strlen(c_str);
    // concat Str struct IN PLACE
    if (c_size + dest->length > dest->size) {
        // reallocate buffer 
        char* prevBuf = dest->c_str;
        size_t newSize = dest->size * 2;
        dest->c_str = malloc(sizeof(char) * newSize);
        memcpy(dest->c_str,prevBuf,dest->size);
        dest->size = newSize;
        free(prevBuf);
    }
    strcat(dest->c_str, c_str);
    dest->length = dest->length + c_size; 
}

Str str(char* c_str) {
    size_t length = strlen(c_str);
    Str out = { malloc(sizeof(char) * length), length, length};
    strncpy(out.c_str, c_str, length);
    return out;
}

StrSlice slice_str(const Str* str, int start, int end) {
    int realStart = start;
    int realEnd = end;
    if (realStart < 0) {
        realStart = 0;
    }
    if (realEnd > str->length) {
        realEnd = str->length;
    }
    StrSlice slice = {str, realStart, realEnd};
    return slice;
}

Str slice_to_str(StrSlice slice) {
    size_t sliceLen = slice.end - slice.start;
    if (slice.end <= slice.str->length) {
        sliceLen += 1; // ensure last character is 0 
    }
    char* new_c_str = malloc(sizeof(char) * sliceLen);
    memcpy(new_c_str, slice.str->c_str + slice.start, sliceLen);
    if (slice.end <= slice.str->length) {
        new_c_str[slice.str->length] = '\0';
    }
    Str out = {
        new_c_str,
        sliceLen,
        sliceLen
    };
    return out;
}

void delete_str(Str str) {
   free(str.c_str); 
}

Str read_file(const char *path) {
    FILE *f = fopen(path, "r"); 
    char buffer[BUFFER_SIZE];
 
    Str output = { malloc(sizeof(char) * BUFFER_SIZE), 0, BUFFER_SIZE };
   
    while (!feof(f)) {
        size_t length = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, f);
        concat_str(&output, buffer); 
        memset(buffer,0,BUFFER_SIZE);
    }
    fclose(f);
    return output;
}

