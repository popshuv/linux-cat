#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    FILE *file;
    char buffer[BUFFER_SIZE];

    if (argc == 0) {
        // Read from standard input and write to standard output
        while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Output the text entered by the user
            printf("%s", buffer);
        }
    }

    if (argc == 1) {

        file = fopen(argv[1], "r");

        if (file == NULL) {
            printf("cat: %s No such file or directory\n", argv[1]);
        }

        do {
            fgets(buffer, sizeof(buffer), file);
            printf("%s", buffer);
        } while (!feof(file));
    }
}