#include "../includes/cmd.h"
#include "../includes/shell.h"
#include "../includes/colors.h"


/*
Implementation of the ls command: print in the terminal the content of the current directory
  
In my implementation, I'm printing 8 files/folders in a row, then I jump at the next line.
File names are printed in white and folder names in cyan.

I'm also trying to display names properly with *longest_name. 
This tab take the longest name in the row and adjust offset of space between two names so every names can be align to each other
*/



void execute_cmd_ls(struct Shell *s) {
    DIR *dp = opendir(s->current_directory);
    struct dirent *entry;
    
    char *longest_name = NULL;
    long unsigned int offset = 0;
    int counter = 0;

    if (dp == NULL) 
        perror("opendir");

    entry = readdir(dp);
    longest_name = (char*)malloc(strlen(entry->d_name) + 1);
    strcpy(longest_name, entry->d_name);

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (sizeof(longest_name) < sizeof(entry->d_name)) {
                longest_name = (char*)realloc(longest_name, strlen(entry->d_name) + 1); 
                strcpy(longest_name, entry->d_name);
            } 

            offset = sizeof(longest_name) - sizeof(entry->d_name); 
            if (entry->d_type == DT_DIR) 
                printf(ANSI_COLOR_CYAN"%s   "ANSI_COLOR_RESET, entry->d_name);
            else
                printf("%s   ", entry->d_name);
            counter = (counter+1)%8;

            if (counter == 0) {
                printf ("\n");
                longest_name = (char*)realloc(longest_name, strlen(entry->d_name) + 1); 
                strcpy(longest_name, entry->d_name);
            }
        }
    }
    printf ("\n");
    free(longest_name);
    closedir(dp);
} 