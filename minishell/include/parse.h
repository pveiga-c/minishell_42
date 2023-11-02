/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/02 17:18:02 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H


typedef struct s_list
{
	char	**content;
	char	*opera;
	int		id;
	struct s_list *next;
	struct s_list *prev;
} 	t_list;

typedef struct s_prompt
{
	int n_tokens;
	int n_pipes;
	t_list	*tokens; 
}	t_prompt;

void		parse(char *p_input);
void		redirection_operators(t_prompt parse, char op, int i)
t_list	init_var(void);
#endif