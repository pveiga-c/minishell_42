/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:54:08 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 16:24:09 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Procura a variavel ambiente PATH e verifica com o comando access se o 
comando que se pretende executar existe ou nao, caso exista retorna o caminho */
/*
char	*get_cmd_path(char **env, char **cmd)
{
	char	**matrix;
	char	*temp;
	char	*res;
	int		i;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (ft_strdup(cmd[0]));
	matrix = ft_split(search_env(env, "PATH"), ':');
	res = ft_strjoin("/", cmd[0]);
	while (matrix[i])
	{
		temp = ft_strjoin(matrix[i], res);
		if (access(temp, X_OK) == 0)
		{
			free(res);
			res = temp;
			break ;
		}
		free(temp);
		i++;
	}
	ft_free_matrix(&matrix);
	return (res);
}
*/

char	*get_cmd_path(char **env, char **cmd)
{
	char	*path;
	char	*dir;
	int		i;

	path = NULL;
	if (strchr(cmd[0], '/'))
		return (ft_strdup(cmd[0]));
	dir = search_env(env, "PATH");
	i = 0;
	while (dir[i])
	{
		path = ft_strjoin(&dir[i], "/");
		path = ft_strjoin(path, cmd[0]);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		i++;
	}
	free(dir);
	return (path);
}
