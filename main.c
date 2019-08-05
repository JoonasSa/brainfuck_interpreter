#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interprete_bf(char* pcntr);
char* read_file(char* fileName);

int main(int argc, char** argv) {

    if (argc == 1) {
        printf("An argument is required.\n");
        return 0;
    }

    if (strcmp(argv[1], "-f") == 0) {
        interprete_bf(read_file(argv[2]));
    } else {
        interprete_bf(argv[1]);
    }
    printf("\n");
    return 0;
}

void interprete_bf(char* pcntr) {
    char array[10000];
    char *arrptr = array;
    int bracketnum = 0;

    while (*pcntr) {
        switch (*pcntr) {
            case '>':
                ++arrptr;
                break;
            case '<':
                --arrptr;
                break;
            case '+':
                ++*arrptr;
                break;
            case '-':
                --*arrptr;
                break;
            case '.':
                printf("%c", *arrptr);
                break;
            case ',':
                scanf("%c", arrptr);
                break;
            case '[':
                if (*arrptr != 0) break;
                bracketnum = 1;
                while (*pcntr) {
                    pcntr++;
                    if (*pcntr == ']') bracketnum--;
                    else if (*pcntr == '[') bracketnum++;
                    if (bracketnum == 0) break;
                }
                break;
            case ']':
                if (*arrptr == 0) break;
                bracketnum = 1;
                while (*pcntr) {
                    pcntr--;
                    if (*pcntr == '[') bracketnum--;
                    else if (*pcntr == ']') bracketnum++;
                    if (bracketnum == 0) break;
                }
                break;
            default:
                if (*pcntr == '\n') break;
                if (*pcntr == '\0') return;
                printf("Input contains unknown character: %c\n", *pcntr);
                return;
        }
        pcntr++;
    }
}

char* read_file(char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("An error occurred while opening the file.\n");
        exit(-1);
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* pcntr = malloc(sizeof(char) * length);
    fread(pcntr, sizeof(char), length, file);
    fclose(file);
    return pcntr;
}
