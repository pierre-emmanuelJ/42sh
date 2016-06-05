/*
** sh.h for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 16:42:03 2016 antoine
** Last update Sun Jun 05 18:37:10 2016 Antoine Baudrand
*/

#ifndef SH_H_
# define SH_H_

# include <termios.h>
# include "egc.h"
# include "toolbox/tools.h"
# include "file/sh_file.h"
# include "scope/scope.h"

# define GOODBYE(x) egc_exit(x)

typedef struct  s_test_stats
{
  int           failed_test_count;
  int           total_test_count;
}               t_test_stats;

/*
** `test_stats` is used only by the automated tests.
*/
typedef struct  	s_statics
{
  const char            *lexer_input_string;
  t_test_stats          test_stats;
  t_scope               env;
  int                   in;
  int                   out;
  int                   err;
}               	t_statics;

/*
** Initializes the statics variables, with an empty environment.
*/
void            statics_init(t_statics *statics);

/*
** built-in functions
*/
typedef int     (*t_bltin_function)(t_glist_hs *args);

typedef struct          s_bltin
{
  const char            *name;
  t_bltin_function      function;
}                       t_bltin;

void		generate_path(void);
void		update_shell_level(void);

int		chdir_error(t_hs path);
int		home_error(t_hs home_path);
void		print_exit(int status);

int		env_cmd(t_glist_hs *argv);
int		cd_cmd(t_glist_hs *argv);
int		exit_cmd(t_glist_hs *argv);
int		echo_cmd(t_glist_hs *argv);
int		setenv_cmd(t_glist_hs *argv);
int		unsetenv_cmd(t_glist_hs *argv);

/*
** Rcfile functions
*/
int		get_rcfile(t_glist_hs *to_exec);
int		get_history(t_glist_hs *history);

/*
** Return 0 if success and -1 if not
*/
int		expand_variables(t_hs input, t_hs *result);

/*
** Autocomplete functions
*/
int		opendir_to_list(t_hs path, t_glist_hs *files);
int		sort_by_keyword(t_hs keyword, t_glist_hs *files);

# ifndef STATICS
#  define STATICS       ((t_statics *)egc_get_statics())
# endif

#endif /* !SH_H_ */
