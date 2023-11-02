/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:35:04 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/02 17:16:56 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_commands	*commands;
	execution(commands);
}

void	execution(t_commands *command)
{
	int		status;
	pid_t	proc_id;

	core_execution(command);
	go_head(&command);
	while (command)
	{
		if (command->content[0])
		{
			proc_id = waitpid(-1, &status, 0);
			if (proc_id != -1 && WIFEXITED(status))
				g_data.status = WEXITSTATUS(status);
		}
		if (!command->next)
			break ;
		command = command->next;
	}
	if (check_fds(command))
		g_data.status = 1;
}

void	core_execution(t_commands *command)
{
	char	**env_vars;

	while (command)
	{
		if (command->content[0] && !command->master_error[0] && !command->master_error[1])
		{
			env_vars = lst_to_arr(g_data.env);
			command->path = get_cmd_path(env_vars, command->content);
			ft_free_matrix(&env_vars);
			define_exec(command);
			command_execution(command);
		}
		if (!command->next)
			break ;
		command = command->next;
	}
}