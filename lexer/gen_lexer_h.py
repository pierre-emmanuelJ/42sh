#!/usr/bin/env python3

BASE_TOKEN = '''
struct
  {
    t_token_type        type;
    t_position          position;
    t_hs                string;
  };
'''.strip('\n')

TEMPLATE = '''/*
** lexer.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 04:19:43 2016 antoine
** Last update Thu Apr 28 04:19:43 2016 antoine
*/

#ifndef LEXER_H
# define LEXER_H

# include "../egc.h"
# include "position.h"

typedef enum    e_token_type
{
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_WORD,
  TOKEN_TYPE_SEMICOLON,
}               t_token_type;

typedef struct          s_string_token
{
  BASE_TOKEN
  t_hs                  value;
}                       t_string_token;

typedef union           u_token
{
  BASE_TOKEN
  t_string_token        string_type;
}                       t_token;

typedef struct          s_syntax_error
{
  t_hs                  message;
  t_position            position;
}                       t_syntax_error;

t_syntax_error          *syntax_error_new(t_hs message, t_position position);
t_hs                    syntax_error_to_hs(const t_syntax_error *e);
void                    syntax_error_print(const t_syntax_error *e,
                                           int output_file);

typedef struct          s_token_list
{
  t_token               *token;
  struct s_token_list   *next;
}                       t_token_list;

typedef struct          s_lexer_result
{
  t_token_list          *tokens;
  t_syntax_error        *error;
}                       t_lexer_result;

t_lexer_result  lex(t_hs string);

#endif /* LEXER_H */
'''

def main():
    s = TEMPLATE
    while 'BASE_TOKEN' in s:
        s = s.replace('BASE_TOKEN', BASE_TOKEN)
    print(s, end='')

main()