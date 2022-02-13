#ifndef ERR_H
#define ERR_H

#include <stdio.h>
#include <stdlib.h>

void erro(char* stringDeErro)
{
    printf("%s\n", stringDeErro);
    exit(EXIT_FAILURE);
}


#endif
