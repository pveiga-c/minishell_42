/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:17:19 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 16:27:09 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	search_number(char *s1, char *s2)
{
	int	res;
	int	i;

	res = ft_strlen(s2);
	i = 0;
	while (s1[i] && s1[i] != '=')
		i++;
	if (i > res)
		return (i);
	return (res);
}

/* Procura na variavel env a string cujo nome da
variavel seja o segundo argumento str */
char	*search_env(char **env, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (env && env[i] && \
		ft_strncmp(env[i], str, search_number(env[i], str)))
		i++;
	if (*str == '?')
		return (ft_itoa(g_data.status));
	if (!env[i] || !str || !*str)
		return ("");
	temp = (env[i] + ft_strlen(str));
	if (*temp == '=')
		temp++;
	return (temp);
}

/* Calcula o tamanho da lista */
int	env_lst_size(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
