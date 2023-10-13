#include "../includes/cmd.h"
#include "../includes/shell.h"
#include "../includes/colors.h"



void execute_cmd_ls(struct Shell *s) {
    DIR *dp = opendir(s->current_directory);
    struct dirent *entry;

    char *longest_name[100];
    long unsigned int offset = 0;
    int counter = 0;

    if (dp == NULL) 
        perror("opendir");

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {

            if (counter == 8) {
                counter = 0;
                printf("\n");
                strcpy(*longest_name, entry->d_name);
            }

            if (sizeof(longest_name) < sizeof(entry->d_name)) {
                strcpy(*longest_name, entry->d_name);

                offset = sizeof(longest_name) - sizeof(entry->d_name); 
                printf("%s   ", entry->d_name);
                counter++;
            }
        }
    }
    printf ("\n");
    closedir(dp);
} 