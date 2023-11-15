/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:41:02 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/01 17:14:04 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Cria a linked list do tipo t_env
com todas as variaveis ambiente*/
// t_env	*get_env(char **env)
// {
// 	int		i;
// 	t_env	*res;

// 	i = -1;
// 	res = NULL;
// 	while (env[++i])
// 		env_add_back(&res, env_new(ft_strdup(env[i])));
// 	return (res);
// }