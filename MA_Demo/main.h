#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX 12

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void shell_prompt(char **ac, char **env);

#endif
