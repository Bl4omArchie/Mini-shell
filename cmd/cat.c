#include "../includes/cmd.h"
#include "../includes/shell.h"
#include "../includes/colors.h"

void execute_cmd_cat(struct Shell *s, char *filename)    {
    FILE *fp = fopen(filename, "r");
    char ch;

    if (fp == NULL)
        printf("Cannot open the file or file doesn't exist\n");


    while ((ch = fgetc(fp)) != EOF)
        putchar(ch); 
    printf ("\n");

    if (fclose(fp) == EOF)
        printf("Error while closing\n");
}