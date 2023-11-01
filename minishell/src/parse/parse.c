/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/01 17:18:56 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void parse(char *p_input)
{
	t_prompt parse;
	int i;

	parse.n_tokens = 0;
	// if(!p_input)
	// 	return (0);
	i = ft_strlen(p_input) - 1;
	while(i != 0)
	{
		if(p_input[i] != ' ' && p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' && p_input[i] != '&')
		{
			parse.n_tokens++;
			while(i != 0 && (p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' && p_input[i] != '&'))
			i--;
		}
		if(p_input[i] == ' ')
			i--;
	}
	printf("%d\n", parse.n_pipes);
}