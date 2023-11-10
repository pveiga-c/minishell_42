/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:23:15 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/09 16:29:49 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char **start_list(t_prompt *parse, char *p_input)
{
	int i;
	unsigned int j;
	int n;
	char **token;

	j = 0;
	n = 0;
	token = start_memory_list(parse, p_input);
	while(n < parse->n_tokens)
	{
		i = 0;
		while(p_input[j] == ' ')
			j++;
		if(p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
		{
			while(j < ft_strlen(p_input) && (p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|'))
				token[n][i++] = p_input[j++];	
		}
		else if(p_input[j] == '<' || p_input[j] == '>' || p_input[j] == '|')
		{
			if(p_input[j] == '<' && p_input[j + 1] != '<')
				token[n][i++] = p_input[j++];
			else if (p_input[j] == '<' && p_input[j + 1] == '<')
			{
				token[n][i++] = p_input[j++];
				token[n][i++] = p_input[j++];
			}
			if(p_input[j] == '>' && p_input[j + 1] != '>')
				token[n][i++] = p_input[j++];
			else if (p_input[j] == '>' && p_input[j + 1] == '>')
			{
				token[n][i++] = p_input[j++];
				token[n][i++] = p_input[j++];
			}
			if(p_input[j] == '|' && p_input[j + 1] != '|')
				token[n][i++] = p_input[j++];
			else if (p_input[j] == '|' && p_input[j + 1] == '|')
			{
				token[n][i++] = p_input[j++];
				token[n][i++] = p_input[j++];
			}
		}
		token[n][i] = '\0';
		n++;
	}
	return (token);
}

char **start_memory_list(t_prompt *parse, char *p_input)
{
	int i;
	int j;
	int n;
	char **token;

	j = 0;
	n = 0;
	token = malloc(sizeof(char **) * parse->n_tokens);
	while(n < parse->n_tokens)
	{
		i = 0;
		while(p_input[j] == ' ')
			j++;
		if(p_input[j] != ' ' && p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
		{
			while(p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
			{
				i++;
				j++;
			}
		}
		else if(p_input[j] == '<' && p_input[j] == '>' && p_input[j] == '|')
		{
			if(p_input[j] == '<' && p_input[j + 1] != '<')
				i = 1;
			else if (p_input[j] == '<' && p_input[j + 1] == '<')
			{	
				i = 2;
				j++;
			}
			if(p_input[j] == '>' && p_input[j + 1] != '>')
				i = 1;
			else if (p_input[j] == '>' && p_input[j + 1] == '>')
			{	
				i = 2;
				j++;
			}
			if(p_input[j] == '|' && p_input[j + 1] != '|')
				i = 1;
			else if (p_input[j] == '|' && p_input[j + 1] == '|')
			{	
				i = 2;
				j++;
			}
			j++;
		}
		token[n] = (char *)malloc(sizeof(char *) * i + 1);
		n++;
	}
	return (token);
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
		if(p_input[i - 1] != '|')
			return (i - 1);
		else if(p_input[i - 1] == '|')
			return (i - 2);
	}
	else if(p_input[i] == '>')
	{
		parse->n_tokens++;
		if(p_input[i - 1] != '>')
			return (i - 1);
		else if(p_input[i - 1] == '>')
			return (i - 2);
	}
	else if(p_input[i] == '<')
	{
		parse->n_tokens++;
		if(p_input[i - 1] != '<')
			return (i - 1);
		else if(p_input[i - 1] == '<')
			return (i - 2);
	}
	return (0);	
}
