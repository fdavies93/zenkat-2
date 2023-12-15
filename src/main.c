#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include "str.h"
#include "ast.h"

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

    int valid_option = 0;

    static struct option long_options[] = {
        {"file", required_argument, 0, 'f'}, // pass the file path
        {"help", no_argument, 0, 'h'}
    };

    int index;
    Str help;
    AstNode ast_root;
    Str root_str;

    while((opt = getopt_long(argc, argv, "hf:", long_options, &index)) != -1) {
        switch (opt) {
            case 'f':
                if (optarg == NULL) break;
                s1 = read_file(optarg);
                ast_root = str_to_ast(s1);
                root_str = slice_to_str(ast_root.source); 
                printf("%s", root_str.c_str);
                valid_option = 1;
                break;
            case 'h':
                show_help();
                valid_option = 1;
                break;
        }
    };

    if (!valid_option) {
        show_help();  
    }
     
    return 0;
}
