/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/13 20:19:25 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//#include "minishell.h"
typedef struct s_prompt t_prompt;

typedef struct s_listm
{
	char	*content;
	char 	*cmd;
	char	*args;
	char	*in_redir;
	char	*out_redir;
	int		id;
	struct s_listm *next;
	struct s_listm *prev;
	t_prompt *prompt;
} 	t_listm;

struct s_prompt
{
	int n_tokens;
	int n_pipes;
	int n_in_redir;
	int n_out_redir;
	t_listm	*tokens; 
}	;

void		start_parse(t_prompt *parse, char *p_input);
int			check_operators(t_prompt *parse, char *p_input, int i);
void		count_tokens(t_prompt *parse, char *p_input);
void		init_param(t_prompt *parse);
char 		**start_list(t_prompt *parse, char *p_input);
char 		**start_memory_list(t_prompt *parse, char *p_input);
t_listm *update_list(t_prompt *parse, char **token);
void	lst_add_back(t_listm **lst, char *new, int i);
t_listm	*lst_last(t_listm *lst);
void	print_lst(t_listm *list);
void	lst_first(t_listm **list);

void 		start_parse_2(t_prompt *parse, char *p_input);
char		**start_list_2(t_prompt *parse, char *p_input);
void 		count_tokens_2(t_prompt *parse, char *p_input);
t_listm 	*update_list_2(t_prompt *parse, char **token);
char 		**start_memory_list_2(t_prompt *parse, char *p_input);
void		lst_add_back_2(t_prompt *parse, t_listm **lst, char *new, int i);
void 		split_content(t_listm *node, char *content);

#endif