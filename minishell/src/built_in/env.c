/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:41:02 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 15:51:20 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Cria uma linked list com todas as variaveis ambiente 
t_env	*get_env(char **env)
{
	int		i;
	t_env	*res;

	i = -1;
	res = NULL;
	while (env[++i])
		env_add_back(&res, env_new(env[i]));
	return (res);
}

// Replica o comando env do bash 
void	execute_env(t_commands **command)
{
	(void)command;
	if (command && (*command)->content[1])
	{
		printf("env: %s: No such file or directory\n", (*command)->content[1]);
		g_data.status = 127;
		return ;
	}
	while (g_data.env && g_data.env->data)
	{
		if (ft_strchr(g_data.env->data, '='))
			printf("%s\n", g_data.env->data);
		if (!g_data.env->next)
			break ;
		g_data.env = g_data.env->next;
	}
	env_first(&g_data.env);
	g_data.status = 0;
}

