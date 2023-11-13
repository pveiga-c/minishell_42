/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:54:08 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/09 15:42:20 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Procura a variavel ambiente PATH e confirma com o comando access se o comando
// a executar existe ou nao, caso exista retorna o caminho
char	*get_cmd_path(char **env, char **cmd)
{
	char	*path;
	char	*path_complete;
	char	*dir;
	int		i;

	path = NULL;
	if (strchr(cmd[0], '/'))
		return (ft_strdup(cmd[0]));
	dir = env_search_str(env, "PATH");
	i = 0;
	while (dir[i])
	{
		path = ft_strjoin(&dir[i], "/");
		path_complete = ft_strjoin(path, cmd[0]);
		if (access(path_complete, F_OK) == 0)
		{
			free(path);	
			break ;
		}
		free(path);
		free(path_complete);
		i++;
	}
	return (path_complete);
}