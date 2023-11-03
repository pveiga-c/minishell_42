/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/03 17:19:16 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void start_parse(t_prompt *parse, char *p_input)
{
	count_tokens(parse, p_input);
	start_list(parse, p_input);
}
void start_list(t_prompt *parse, char *p_input)
{
	int i;
	char *token;

	i = 0;
	while(i < parse->n_tokens)
	{
		
	}
}


void	count_tokens(t_prompt *parse, char *p_input)
{
	int i;
	
	i = ft_strlen(p_input) - 1;
	while(i > 0)
	{
		if(p_input[i] != ' ' && p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' /*&& p_input[i] != '&'*/)
		{
			parse->n_tokens++;
			while(i > 0 && (p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' /*&& p_input[i] != '&'*/))
				i--;
		}
		if(p_input[i] == ' ')
			i--;
		else if(p_input[i] == '|' || p_input[i] == '>' || p_input[i] == '<')
			i = check_operators(parse, p_input, i);
		else
			i--;
	}
}

int	check_operators(t_prompt *parse, char *p_input, int i)
{
	if(p_input[i] == '|')
	{
		parse->n_tokens++;
		if(p_input[i - 1] == '|')
			return (i - 1);
		else if(p_input[i - 1] != '|')
			return (i - 2);
	}
	else if(p_input[i] == '>')
	{
		parse->n_tokens++;
		if(p_input[i - 1] == '>')
			return (i - 1);
		else if(p_input[i - 1] != '>')
			return (i - 2);
	}
	else if(p_input[i] == '<')
	{
		parse->n_tokens++;
		if(p_input[i - 1] == '<')
			return (i - 1);
		else if(p_input[i - 1] != '<')
			return (i - 2);
	}
	return (0);	
}
