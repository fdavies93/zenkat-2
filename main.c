#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BUFFER_SIZE = 1024;

struct Str{
    char* c_str;
    size_t length;
    size_t bufferSize;
};

struct Str readTo(const char *path) {
    FILE *f = fopen(path, "r"); 
    char buffer[BUFFER_SIZE];
    char *outBuf = malloc( sizeof(char) * BUFFER_SIZE );
    size_t fileLength = 0;
    size_t outLength = BUFFER_SIZE;
    
    while (!feof(f)) {

        size_t length = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, f);
        if (fileLength + length > outLength) {
            char* prevOut = outBuf;
            outLength = outLength * 2;
            outBuf = malloc(sizeof(char) * outLength);
            memcpy(outBuf,prevOut,fileLength);
            free(prevOut);
        }
        strcat(outBuf, buffer);
        fileLength = fileLength + length;
        memset(buffer,0,BUFFER_SIZE); 
    }
     
    struct Str s1 = { outBuf, fileLength, outLength };
    return s1;
}

int main() { 
    struct Str s1 = readTo("./input/notes/long-item.md");

    printf("%s", s1.c_str);


    return 0;
}
