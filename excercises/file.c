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
        perror("Tell: ");
        return EXIT_FAILURE;
    }
    printf("file position = %ld\n", fpi);
    if (fclose(fp) == EOF) {
        fputs("Failed to close file\n", stderr);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int open_file_alt(void) {
    FILE *fp = fopen("test.txt", "w+");
    if (fp == NULL) {
        fputs("Cannot open file\n", stderr);
        return EXIT_FAILURE;
    }
    fpos_t pos;
    if (fgetpos(fp, &pos) != 0) {
        perror("get position");
        return EXIT_FAILURE;
    }
    if (fputs("abcdefg", fp) == EOF) {
        fputs("Cannot write to test.txt\n", stderr);
    }
    if (fsetpos(fp, &pos) != 0) {
        perror("set position");
        return EXIT_FAILURE;
    }
    long int fpi = ftell(fp);
    if (fpi == -1L) {
        perror("Tell: ");
        return EXIT_FAILURE;
    }
    printf("file position = %ld\n", fpi);
    if (fputs("0123456789", fp) == EOF) {
        fputs("Cannot write to test.txt\n", stderr);
    }
    if (fclose(fp) == EOF) {
        fputs("Failed to close file\n", stderr);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int formatted(void) {
    int status = EXIT_SUCCESS;
    FILE *in;

    struct sigrecord {
        int signum;
        char signame[10];
        char sigdesc[100];
    } sigrec;

    if ((in = fopen("signals.txt", "r")) == NULL) {
        fputs("Cannot open signals.txt\n", stderr);
        return EXIT_FAILURE;
    }
    do {
        int n = fscanf(in, "%d%9s%*[ \t]%99[^\n]", &sigrec.signum, sigrec.signame, sigrec.sigdesc);
        if (n == 3) {
            printf("Signal\n  number = %d\n  name = %s\n description = %s\n\n", sigrec.signum, sigrec.signame, sigrec.sigdesc);
        }
        else if (n != EOF) {
            fputs("Failed to match signum, signame or sigdesc\n", stderr);
            status = EXIT_FAILURE;
            break;
        }
        else {
            break;
        }
    } while (1);

    if (fclose(in) == EOF) {
        fputs("Failed to close file\n", stderr);
        status = EXIT_FAILURE;
    }
    return status;
}
