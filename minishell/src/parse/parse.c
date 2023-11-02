/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/02 17:18:13 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void parse(char *p_input)
{
	int i;
	t_prompt parse;
	
	// if(!p_input)
	// 	return (0);
	parse.n_tokens = 0;
	parse.tokens = init_var();
	i = ft_strlen(p_input) - 1;
	while(i > 0)
	{
		if(p_input[i] != ' ' && p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' && p_input[i] != '&')
		{
			parse.n_tokens++;
			while(i > 0 && (p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' && p_input[i] != '&'))
				i--;
		}
		if(p_input[i] == ' ')
			i--;
		else
			redirection_operators(parse, p_input[i], i);
	}
	//printf("%d\n", parse.n_tokens);
}

void	redirection_operators(t_prompt parse, char op, int i)
{
		
}

t_list	init_var(void)
{
	t_list parse;

	parse.n_tokens = 0;
}
