/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniShell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:34 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/01 14:50:30 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// struct s_global	g_data;

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
		return (1);
	(void)env;
//	desativa a captura de sinais pelo readline 
	rl_catch_signals = 0;
	
//	g_data.env = get_env(env);
//	g_data.status = 0;
//	g_data.hd = 0;
//	g_data.vars = init_vars();
//	rl_catch_signals = 0;
//	signals_default();
//	prompt();
}
/*
int main()
{
	// Declaração de variáveis
	char	*linha_de_comando;

	while (1)
	{
		// Leitura da linha de comando
		linha_de_comando = readline("Digite um comando: ");

		if (linha_de_comando == NULL)
		{
			perror("Erro na leitura da linha de comando");
			return 1;
		}
		if (ft_strncmp(linha_de_comando, "exit", 4) == 0)
		{
			break;
		}
		// Impressão da linha de comando
		printf("A linha de comando é: %s\n", linha_de_comando);

	}
	// Liberação da memória alocada
	free(linha_de_comando);

	return (0);
}
*/
