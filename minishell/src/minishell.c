/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:34 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/13 15:51:35 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char *prompt;
	t_prompt parse;
	
	init_param(&parse);
	prompt = argv[1];
	(void)argc;
	(void)env;
	rl_catch_signals = 0;
	//prompt = readline("$ ");
	//add_history(prompt);
	start_parse_2(&parse ,prompt);
}

void	init_param(t_prompt *parse)
{
	t_listm *tokens;

	tokens = ft_calloc(1, sizeof(t_listm));
	
	parse->n_tokens = 0;
	parse->n_pipes = 0;
	parse->n_in_redir = 0;
	parse->n_out_redir = 0;
	tokens->content = NULL;
	tokens->id = 0; 
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
