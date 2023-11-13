/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/13 20:43:44 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void start_parse(t_prompt *parse, char *p_input)
// {
// 	char **token;
// 	t_listm *list;
	
// 	count_tokens(parse, p_input);
// 	token = start_list(parse, p_input);
// 	list = update_list(parse, token);
// 	print_lst(list);
// }

void start_parse_2(t_prompt *parse, char *p_input)
{
	//int i = 0;
	char **token;
	t_listm *list;

	count_tokens_2(parse, p_input);
	token = start_list_2(parse, p_input);
	// while(i < parse->n_tokens)
	// {
	// 	printf("token[%d] = %s\n", i, token[i]);
	// 	i++;
	// }
	list = update_list_2(parse, token);	
	//print_lst(list);
}
t_listm *update_list_2(t_prompt *parse, char **token)
{
	int i;
	t_listm *list;

	i = 0;
	list = NULL;
	while(i < parse->n_tokens)
	{
		lst_add_back_2(parse, &list, token[i], i);
		i++;
	}
	return (list);
}
void	lst_add_back_2(t_prompt *parse, t_listm **lst, char *new, int i)
{
	t_listm *new_node;
	t_listm *current;;
	
	new_node = malloc(sizeof(t_listm));
	if(!new_node)
		exit (1);
	new_node->next = NULL;
	new_node->id = i + 1;
	new_node->content = new;
	new_node->prompt = parse;
	split_content(new_node, new_node->content);
	if(!*lst)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while(current->next)
		current = current->next;
	current->next = new_node;
}
void split_content(t_listm *node, char *content)
{
	int i;
	char *aux;
	int op;
	int j;

	// i = 0;
	
	// while(content[i])
	// {
	// 	if(content[i] == '<')
	// 		node->prompt->n_in_redir++;
	// 	if(content[i] == '>')
	// 		node->prompt->n_out_redir++;
	// 	i++;
	// }
	i = 0;
	op = 0;
	while(content[i] && (content[i] != '<' && content[i] != '>'))
			i++;
	if( content[i] == '>')
		op = 1;
	aux = malloc(sizeof(char *) * i + 1);
	
	while(content[i])
		i++;
	if(op == 0)
		node->in_redir = malloc(sizeof(char *) * i + 1);
	else
		node->out_redir = malloc(sizeof(char *) * i + 1);
	i = 0;
	while(content[i] != '<' && content[i] != '>')
	{
		aux[i] = content[i];
		i++;	
	}
	aux[i] = '\0';
	j = -1;
	if(op == 0)
	{
		while(content[++i])
			node->in_redir[++j] = content[i];
		node->in_redir[j] = '\0';
	}
	if(op == 1)
	{
		while(content[++i])
			node->out_redir[++j]= content[i];
		node->out_redir[j] = '\0';
	}
	i = 0;
	while(aux && aux[i] != ' ')
		i++;
	node->cmd = malloc(sizeof(char *) * i + 1);
	while(aux && aux[i])
		i++;
	node->args = malloc(sizeof(char *) * i + 1);
	i = 0;
	while(aux[i])
	{
		while(aux && aux[i] != ' ')
		{
			node->cmd[i] = aux[i];
			i++;
		}
	i++;
		while(aux[++i])
		{
			node->args[i] = aux[i];
			i++;
		}
		i++;
	}
	
	printf("content = %s\n", content);
	printf("aux = %s\n", aux);
	printf("in = %s\n", node->in_redir);
	printf("out = %s\n", node->out_redir);
	printf("cmd = %s\n", node->cmd);
	printf("args = %s\n", node->args);

}


char **start_list_2(t_prompt *parse, char *p_input)
{
	int i;
	int j;
	int n;
	char **token;

	i = 0;
	n = 0;
	token = start_memory_list_2(parse, p_input);
	while(i < parse->n_tokens)
	{
		j = 0;
		while (p_input[n] == ' ' || p_input[n] == '\t')
			n++;
		while(p_input[n] && p_input[n] != '|')
		{
			token[i][j] = p_input[n];
			j++;
			n++;
		}
		token[i][j] = '\0';
		i++;
		n++;
	}
	return (token);
}

char **start_memory_list_2(t_prompt *parse, char *p_input)
{
	int i;
	int j;
	int n;
	char **token;

	i = 0;
	n = 0;
	token = malloc(sizeof(char **) * parse->n_tokens);
	while(i < parse->n_tokens)
	{
		j = 0;
		while(p_input[n] && p_input[n] != '|')
		{
			j++;
			n++;
		}
		token[i] = malloc(sizeof(char *) * j + 1);
		i++;
		n++;
	}
	return (token);
}

void count_tokens_2(t_prompt *parse, char *p_input)
{
	size_t i;

	i = -1;
	while(++i < ft_strlen(p_input))
	{
		if(p_input[i] == '|')
			parse->n_pipes++;
	}
	parse->n_tokens = parse->n_pipes + 1;
	//printf("pipes = %d\n", parse->n_pipes);
	//printf("tokens = %d\n", parse->n_tokens);
}