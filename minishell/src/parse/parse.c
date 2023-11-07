/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/07 20:36:28 by pveiga-c         ###   ########.fr       */
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
	int j;
	int n;
	char **token;

	j = 0;
	n = 0;
	token = start_memory_list(parse, p_input);

	while(n < parse->n_tokens)
	{
		i = 0;
		printf("%d\n", n);
		if(p_input[j] != ' ' && p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
		{
			
			while(p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
			{
				printf("p_input[%d][%d] = %c\n",n , j, p_input[j]);
				token[n][i++] = p_input[j++];
				
			}
				
		}
		else if(p_input[j] == '<' && p_input[j] == '>' && p_input[j] == '|')
		{
			printf("p_input[%d] = %c\n", j, p_input[j]);
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
			{
				printf("ola\n");
				token[n][i] = p_input[j];
				i++;
				j++;
			}
			else if (p_input[j] == '|' && p_input[j + 1] == '|')
			{
				token[n][i++] = p_input[j++];
				token[n][i++] = p_input[j++];
			}
		}
		printf("token[%d] = %s\n",n , token[n]);
		n++;
	}
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
		if(p_input[j] != ' ' && p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
		{
			while(p_input[j] != '<' && p_input[j] != '>' && p_input[j] != '|')
			{
				i++;
				j++;
			}
		}
		else if (p_input[j] == ' ')
			j++;
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

// char *division_token(char *p_input, int num)
// {
// 	int i;
// 	int j;
// 	char *token;
	
// 	i = 0;
// 	token = NULL;
// 	while(*p_input && p_input[i])
// 	{
// 		if(p_input[i] != ' ' && p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|')
// 		{
// 			while(p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|')
// 			{
// 				token[j] = p_input[i];
// 				j++;
// 				i++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (token);
// }

// char *division_token(char *p_input, int num)
// {
// 	// unsigned int i;
// 	// int j;
// 	// int x;
// 	// char *token;
	
// 	// i = 0;
// 	// j = 0;
// 	// x = 0;
// 	// token = malloc(sizeof(char *) * ft_strlen(p_input + 1));
// 	// while(i < (ft_strlen(p_input) - 1))
// 	// {
// 	// 	if(p_input[i] != ' ' && p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' /*&& p_input[i] != '&'*/)
// 	// 	{
// 	// 		printf("ola %d\n", i);
// 	// 		printf("num = %d  x = %d\n", num,  x);
// 	// 		x++;
// 	// 		while(i > 0 && (p_input[i] != '<' && p_input[i] != '>' && p_input[i] != '|' /*&& p_input[i] != '&'*/))
// 	// 			{
// 	// 				token[j] = p_input[i];
// 	// 				i++;
// 	// 				j++;
// 	// 			}
// 	// 	}
// 	// 	i++;
// 	// }
// 	// return(token);
// }


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
