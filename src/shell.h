#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <dirent.h>

struct Shell {
    bool running;
    int line_number;
    char current_directory[70];
    char * buffer;
    size_t buffer_size;
};


void shell_init(struct Shell *s);
void shell_run(struct Shell *s);
void shell_free(struct Shell *s);
void shell_read_line(struct Shell *s);
void shell_execute_line(struct Shell *s);


#endif 