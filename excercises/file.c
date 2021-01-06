#include <stdio.h>
#include <stdlib.h>

int open_file(void)
{
    FILE *fp = fopen("./test.txt", "r");
    if (fp == NULL) {
        fputs("Cannot open file\n", stderr);
        return EXIT_FAILURE;
    }
    if (fseek(fp, 0, SEEK_END) != 0) {
        return EXIT_FAILURE;
     }
    long int fpi = ftell(fp);
    if (fpi == -1L) {
        perror("Tell");
        return EXIT_FAILURE;
    }
    printf("file position = %ld\n", fpi);
    if (fclose(fp) == EOF) {
        fputs("Failed to close file\n", stderr);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
