#include "../includes/shell.h"
#include "../includes/StringVector.h"
#include "../includes/colors.h"
#include "../includes/cmd.h"



void shell_init(struct Shell *s) {
    s->running = false;
    s->buffer = NULL;
    s->buffer_size = 0;
    s->line_number = 0;
}

void shell_run(struct Shell *s){
    s->running = true;
    while (s->running) {
        shell_read_line(s);
        shell_execute_line((s));
    }

}

void shell_free(struct Shell *s){
    free(s->buffer);
}


void shell_read_line(struct Shell *s){
    char *env = getenv("USER");
    
    if (getcwd(s->current_directory, sizeof(s->current_directory)) == NULL)
        perror("getcwd");
    printf (ANSI_COLOR_BLUE"%s"ANSI_COLOR_RESET"@"ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET"> ", env, s->current_directory);

    ssize_t bytes_read = getline ( &s->buffer, &s->buffer_size, stdin);
    if (bytes_read < 0) 
        s->running = false;
    s->line_number++;   
}   


void shell_execute_line(struct Shell *s){
    struct StringVector tokens = split_line(s->buffer);

    if (string_vector_size((&tokens)) > 0) {
        char *command = string_vector_get(&tokens, 0);
        if (strcmp(command, "exit") == 0)
            s->running = false;

        else if (strcmp(command, "!") == 0) {
            if (string_vector_size(&tokens) == 1) {
                char *current_shell = getenv("SHELL");
                assert(current_shell != NULL);
                system(current_shell);
            }

            else {
                char *command = string_vector_get(&tokens, 1);
                char *tmp = malloc(256*sizeof(char));
                tmp = strjoinarray(tmp, &tokens, 1, string_vector_size(&tokens), ";");
                printf ("command externe: %s\n", tmp);
                free(tmp);
            }
        }

        else if (strcmp(command, "cd") == 0) {
            char *path = string_vector_get(&tokens, 1);
            if (path == NULL)
                path = getenv("HOME");
            
            if (chdir(path)) 
                printf ("cd: %s, No such file or directory", path);
        }

        else if (strcmp(command, "cat") == 0) {
            char *filename = string_vector_get(&tokens, 1);
            if (filename == NULL)
                printf ("cat: no file indicated");
            else
                execute_cmd_cat(s, filename);
                
        }

        else if (strcmp(command, "ls") == 0) 
            execute_cmd_ls(s);
        else if (strcmp(command, "kisuisje") == 0)
            system("whoami");
        else if (strcmp(command, "clear") == 0) 
            system("clear");        
        else    
            printf ("[!] We can't find this command \n");
    }
    string_vector_free(&tokens);
}