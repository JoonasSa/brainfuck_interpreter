#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    //Brainfuck to C?
    //file read https://tmc.mooc.fi/mooc/exercises/4861/solution kannattaa tehdä pathin kautta
    //arg read: flagi spacejen ja /n poistamiselle ja/tai kaikille turhille merkeille?
    if (argc == 1) {
        printf("An argument is required.\n");
        return 0;
    } else if (argc > 2) {
        printf("Only one argument allowed.\n");
        return 0;
    }
    
    char array[10000];
    char *arrptr = array;
    printf("%c", *arrptr);
    char *pcntr = argv[1];
    int bracketnum = 0;
    
    while(*pcntr) {
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
                printf("Input contains unknown character: %c\n", *pcntr);
                return 0;
        } 
        pcntr++;
    }
    return 0;
}