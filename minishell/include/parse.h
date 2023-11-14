/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/14 15:24:52 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//#include "minishell.h"
typedef struct s_prompt t_prompt;

typedef struct s_listm
{
	int		pipe_line;
	char	*content;
	char 	*cmd;
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

void		init_param(t_prompt *parse);
void		print_lst(t_listm *list);

void 		start_parse(t_prompt *parse, char *p_input);
char		**start_list(t_prompt *parse, char *p_input);
void 		count_tokens(t_prompt *parse, char *p_input);
t_listm 	*update_list(t_prompt *parse, char **token);
char 		**start_memory_list(t_prompt *parse, char *p_input);
void		lst_add_back(t_prompt *parse, t_listm **lst, char *new, int i);
void 		split_content(t_listm *node, char *content);

#endif