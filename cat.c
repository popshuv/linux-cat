#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    FILE *file;
    char buffer[BUFFER_SIZE];

    // If no arguments are passed, read from stdin
    if (argc == 1) {
        
        while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Output the text entered by the user
            printf("%s", buffer);
        }
    }

    // If a file is passed as an argument, read from the file
    if (argc >= 2) {
        // Loop through the arguments
        for (int i = 1; i < argc; i++) {
            file = fopen(argv[i], "r");
            // If the file does not exist, print an error message
            if (file == NULL) {
                printf("cat: %s No such file or directory\n", argv[1]);
            }
            // If the file exists, read the file and print the contents
            do {
                fgets(buffer, sizeof(buffer), file);
                printf("%s", buffer);
            } while (!feof(file));
        }
    }
}
