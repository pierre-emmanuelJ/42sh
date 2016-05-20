/*
** sh.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 16:42:03 2016 antoine
** Last update Fri May 20 15:56:36 2016 Valentin Pichard
*/

#ifndef SH_H
# define SH_H

# include "egc.h"

# define GOODBYE(x) exit(x)

/*
** Display environment
*/
void		display_environment(const char **envp);

/*
** Display user prompt
*/
void		display_prompt(const char *user);

/*
** Display segfault error when signal catched
*/
void		check_segfault(const int status);

/*
** Print string on stdout
*/
void		print_string(const char *string);

/*
** Print string on stderr
*/
void		print_string_error(const char *string);

#endif /* SH_H */
