/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:04 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/09 15:23:10 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	lst_first(t_listm **list)
// {
// 	while((list) && (*list) && (*list)->prev)
// 		(*list) = (*list)->prev;
// }

// t_listm	*lst_last(t_listm *lst)
// {
// 	while (lst)
// 	{
// 		if (lst->next == NULL)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (lst);
// }


t_listm *update_list(t_prompt *parse, char **token)
{
	int i;
	t_listm *list;

	i = 0;
	list = NULL;
	while(i < parse->n_tokens)
	{
		lst_add_back(&list, token[i], i);
		i++;
	}
	return (list);
} 
void	lst_add_back(t_listm **lst, char *new, int i)
{
	t_listm *new_node;
	t_listm *current;;
	
	new_node = malloc(sizeof(t_listm));
	if(!new_node)
		exit (1);
	new_node->next = NULL;
	new_node->id = i + 1;
	new_node->content = ft_split(new, ' ');
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


void	print_lst(t_listm *list)
{
	int	i;

	if (!list)
		return ;
	while (list)
	{
		i = -1;
		while (list->content[++i])

			printf("%s \n", list->content[i]);
		list = list->next;
	}
}