/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:35:04 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 16:54:20 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

struct s_global g_data;

int	main(int argc, char **argv, char **env)
{
//	t_env	*env_list;

	(void) argc;
	(void) argv;

	g_data.env = get_env(env);

	// Uso da função lst_add_back para adicionar comandos à lista
	t_commands *commands = NULL; // Inicializa a lista como vazia

	// Cria um novo elemento t_commands
	t_commands *novo_comando = (t_commands *)malloc(sizeof(t_commands));
	novo_comando->content = (char *[]){"sleep", "5", NULL}; // Exemplo de comando
	novo_comando->path = "/bin/sleep"; // Exemplo de caminho
	novo_comando->fd[0] = 0; // Exemplo de descritor de arquivo de entrada
	novo_comando->fd[1] = 1; // Exemplo de descritor de arquivo de saída
	novo_comando->fd_master[0] = 2; // Exemplo de descritor de arquivo de erro
	novo_comando->fd_master[1] = 3; // Exemplo de descritor de arquivo de erro
	novo_comando->next = NULL;
	novo_comando->prev = NULL;
	novo_comando->ft_exec = NULL; // Defina sua função de execução, se necessário

	// Adicione o novo elemento à lista
	lst_add_back(&commands, novo_comando);
	free(novo_comando);

	// Você pode repetir o processo para adicionar mais comandos à lista

	// Exemplo de outro comando
	t_commands *outro_comando = (t_commands *)malloc(sizeof(t_commands));
	outro_comando->content = (char *[]){"ls", "-al", NULL};
	outro_comando->path = "/bin/ls";
	outro_comando->fd[0] = 4;
	outro_comando->fd[1] = 5;
	outro_comando->fd_master[0] = 6;
	outro_comando->fd_master[1] = 7;
	outro_comando->next = NULL;
	outro_comando->prev = NULL;
	outro_comando->ft_exec = NULL;

	// Adicione o segundo elemento à lista
	lst_add_back(&commands, outro_comando);
	free(outro_comando);

	// Exemplo de impressão da lista
	printf("\nCOMMANDS: \n");
	print_lst(commands);
	executor(commands);

	free_env(&g_data.env);
	return (0);
}

void	executor(t_commands *command)
{
//	int		status;
//	pid_t	proc_id;
	int	i;

	char	**env_vars;
	env_vars = lst_to_arr(g_data.env);
	i = 0;
	while (env_vars[i])
	{
		printf("env_vars:  %s\n", env_vars[i++]);
	}
	
	execution(command);
/*
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
*/
	free(env_vars);
}

void	execution(t_commands *command)
{
	// guarda as variaveis de ambiente
	char	**env_vars;

	command->path = NULL;
	while (command)
	{
		if (command->content[0] && !command->fd_master_error[0] && !command->fd_master_error[1])
		{
			env_vars = lst_to_arr(g_data.env);
			command->path = get_cmd_path(env_vars, command->content);
			printf("\n\nPATH: %s\n", command->path);
			free_matrix(&env_vars);
/*
			define_exec(command);
			command_execution(command);
*/			
		}
		if (!command->next)
			break ;
		command = command->next;
	}
}