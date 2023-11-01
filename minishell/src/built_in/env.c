/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:41:02 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/01 17:12:26 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Cria uma linked list com todas as variaveis ambiente*/
t_env	*get_env(char **env)
{
	int		i;
	t_env	*res;

	i = -1;
	res = NULL;
	while (env[++i])
		env_add_back(&res, env_new(ft_strdup(env[i])));
	return (res);
}