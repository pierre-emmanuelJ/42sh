/*
** eval_bltns.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Sat Jun 04 19:47:39 2016 Antoine Baudrand
** Last update Sat Jun 04 19:48:46 2016 Antoine Baudrand
*/

#include <sys/wait.h>
#include <assert.h>
#include "eval.h"
#include "exec.h"

void     get_bltins(t_bltin *bltins)
{
  int           i;

  i = 0;
  bltins[i].name = "env";
  bltins[i++].function = env_cmd;
  bltins[i].name = "setenv";
  bltins[i++].function = setenv_cmd;
  bltins[i].name = "cd";
  bltins[i++].function = cd_cmd;
  bltins[i].name = "exit";
  bltins[i++].function = exit_cmd;
  bltins[i].name = "unsetenv";
  bltins[i++].function = unsetenv_cmd;
  bltins[i].name = "echo";
  bltins[i++].function = echo_cmd;
  bltins[i].name = NULL;
  bltins[i++].function = NULL;
}

t_bltin_function find_bltin(t_hs command)
{
  t_bltin               builtins[32];
  t_bltin               *builtin;

  get_bltins(builtins);
  builtin = builtins;
  while (builtin->name)
    {
      if (hs_equals(command, hs(builtin->name)))
        return (builtin->function);
      builtin++;
    }
  return (NULL);
}
