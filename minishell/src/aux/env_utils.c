/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:08:25 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/01 16:56:58 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Retorna o ultimo elemento */
t_env	*env_last(t_env *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/* Adiciona um novo elemento */
void	env_add_back(t_env **lst, t_env *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->prev = env_last(*lst);
			env_last(*lst)->next = new;
		}
		else
			*lst = new;
	}
}

/* Cria um novo node */
t_env	*env_new(char *str)
{
	t_env	*new;

	new = (t_env *)ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (NULL);
	new->data = str;
	return (new);
}

/* Liberta toda a memoria */
int	free_env(t_env **lst)
{
	t_env	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->data);
		free(*lst);
		*lst = temp;
	}
	return (1);
}

/* Retorna o primeiro elemento */
void	env_first(t_env **lst)
{
	while ((lst) && (*lst) && (*lst)->prev)
		(*lst) = (*lst)->prev;
}
