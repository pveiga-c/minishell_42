/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:37:59 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/08 16:29:04 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Verifica se uma str tem apenas digitos
int	str_is_num(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


// Verifica se o exit code ultrapassa long long int
int	isoverflow(t_commands **lst)
{
	int	i;

	i = 0;
	if ((*lst)->content[1])
		i = 0 + ((*lst)->content[1][0] == '-' || (*lst)->content[1][0] == '+');
	if ((*lst)->content[1] && (ft_strlen((*lst)->content[1] + i) > 19 || \
		(i && ft_strlen((*lst)->content[1]) == 20 && \
		ft_strncmp("-9223372036854775808", (*lst)->content[1], 20) < 0) || \
		(!i && ft_strlen((*lst)->content[1]) == 19 && \
		ft_strncmp("9223372036854775807", (*lst)->content[1], 19) < 0)))
	{
		write(2, "minishell: exit: ", 17);
		write(2, (*lst)->content[1], ft_strlen((*lst)->content[1]));
		write(2, ": numeric argument required\n", 29);
		return (1);
	}
	return (0);
}

void	is_numeric_arg(t_commands **lst)
{
	g_data.exit_status = 2;
	write(2, "minishell: exit: ", 17);
	write(2, (*lst)->content[1], ft_strlen((*lst)->content[1]));
	write(2, ": numeric argument required\n", 29);
}

void	execute_exit(t_commands **command)
{
	int	number;

	if ((*command)->content[2])
	{
		g_data.exit_status = 1;
		write(2, "minishell: exit: too many arguments\n", 37);
	}
	else if (isoverflow(command))
		g_data.exit_status = 2;
	else if ((*command)->content[1] && str_is_num((*command)->content[1]) == 0)
		is_numeric_arg(command);
	else if ((*command)->content[1])
	{
		number = ft_atoi((*command)->content[1]);
		if (number >= 256)
			number -= 256;
		g_data.exit_status = number;
	}
}

// 0: O comando foi executado com sucesso
// 1: Ocorreu um erro genérico ou não especificado
// 2: Ocorreu um erro de sintaxe no comando
// 126: O comando não é executável
// 127: O comando não foi encontrado
// 128: O comando foi interrompido por um sinal (ex: SIGINT)
// 130: Foi interrompido manualmente (ex: Ctrl+C ou Ctrl+D)
// 255: Valor máximo de um exit code 
/*
The exit utility shall cause the shell to exit with the exit status specified 
by the unsigned decimal integer n.
If n is specified, but its value is not between 0 and 255 inclusively,
the exit status is undefined.
*/