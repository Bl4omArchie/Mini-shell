#ifndef CMD_H
#define CMD_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "shell.h"

void execute_cmd_ls(struct Shell *s);

#endif