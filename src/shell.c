#include "shell.h"
#include "StringVector.h"


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
    char *repertory = getenv("PWD");
    printf ("\e[1;34m%s\e[0m@\e[1;32m%s\e[0m > ", env, repertory);

    ssize_t bytes_read = getline ( &s->buffer, &s->buffer_size, stdin);
    if (bytes_read < 0) 
        s->running = false;
    s->line_number++;   
}



void shell_execute_line(struct Shell *s){
    //printf ("Line %d: %s\n", s->line_number, s->buffer);
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

        else if (strcmp(command, "ls") == 0) {
            system("ls");
        }

        else if (strcmp(command, "clear") == 0) 
            system("clear");
        
        else    
            printf ("[!] Commande inconnue\n");
    }

    string_vector_free(&tokens);
}