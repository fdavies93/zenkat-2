#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include "str.h"

void show_help() {
    Str output = str("");
    concat_str(&output,
            "zenkat\n\n"
            "Tool for managing and extracting data from markdown files.\n\n"
            "Usage: zenkat [--file | -f filepath]\n\n"
            "Options:\n"
            "[--file | -f filepath] Read in a single file and display the result of parsing it.\n"
    );
    printf("%s", output.c_str);
    delete_str(output);
}

int main(int argc, char *argv[]) {

    char opt;
    Str s1;

    int opt_index;
     
    static struct option long_options[] = {
        {"file", required_argument, 0, 'f'}, // pass the file path
        {"help", no_argument, 0, 'h'}
    };

    int index;
    Str help;

    while((opt = getopt_long(argc, argv, "hf:", long_options, &index)) != -1) {
        switch (opt) {
            case 'f':
                if (optarg == NULL) break;
                s1 = read_file(optarg);
                printf("%s",s1.c_str);
                break;
            case 'h':
                show_help();
                break;
        }
    };
     
    return 0;
}
