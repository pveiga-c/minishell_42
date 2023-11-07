/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/07 19:58:21 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//#include "minishell.h"

typedef struct s_listm
{
	char	**content;
	char	*opera;
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
void start_list(t_prompt *parse, char *p_input);
char *division_token(char *p_input, int num);
char **start_memory_list(t_prompt *parse, char *p_input);

#endif