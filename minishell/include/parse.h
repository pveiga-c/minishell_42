/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/08 18:12:20 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//#include "minishell.h"

typedef struct s_listm
{
	char	**content;
	int		id;
	struct s_listm *next;
	struct s_listm *prev;
} 	t_listm;

typedef struct s_prompt
{
	int n_tokens;
	t_listm	*tokens; 
}	t_prompt;

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

#endif