/*
** display.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu May 19 23:13:05 2016 Valentin Pichard
** Last update Thu May 19 23:28:32 2016 Valentin Pichard
*/

#include "sh.h"
#include <stdio.h>
#include "../colorize/colorize.h"

void		display_environment(const char **envp)
{
  int		i;

  i = 0;
  while (envp[i])
    printf("%s\n", envp[i]);
}

void		display_prompt(const char *user)
{
  printf("%s%s%s@360SH-NoScop3 ~ $ ", FG_RED, user, RESET);
}
