#include <stdlib.h>
#include "includes/shell.h"



int main(int argc, char *argv[])
{
    struct Shell shell;
    shell_init(& shell);
    shell_run(& shell);
    shell_free(& shell);

    return (EXIT_SUCCESS);
}