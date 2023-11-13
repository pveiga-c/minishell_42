/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:43:55 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/13 14:17:26 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isspace(int c)
{
	return ((c == ' '));
}


// redirecciona o STDERROR para /dev/NULL para nao escrever o 
// comando exit no terminal apos a mensagem de erro.
// falta testar se sai do MiniShell ou nao (nao pode sair)
// PFV
void	stderr_null(void)
{
	int null_fd = open("/dev/null", O_WRONLY);

	if (null_fd == -1) 
	{
		perror("Erro ao abrir /dev/null");
		exit(1);
	}
	// Redirecionar stderr para /dev/null
	if (dup2(null_fd, STDERR_FILENO) == -1)
	{
		perror("Erro ao redirecionar stderr");
		exit(1);
	}
	close(null_fd);
}

void	sort_array(char **arr, int size)
{
	int		i;
	int		changed;
	char	*temp;

	changed = 1;
	while (changed)
	{
		changed = 0;
		i = 0;
		while (i < size - 1)
		{
			if (str_cmp(arr[i], arr[i + 1]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				changed = 1;
			}
		i++;
		}
		size--;
	}
}
// Compara a string1 com a string2
int	str_cmp(char *s1, char *s2)
{
	unsigned int	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
			i++;
		return (s1[i] - s2[i]);
	}
	return (1);
}

/* Calcula o size de uma variavel do tipo char** */
int	strlen_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] && array[i][0] != 3)
		i++;
	return (i);
}

/* Compara dois elementos ate um deles acabar */
int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
			i++;
		return (s1[i] - s2[i]);
	}
	return (1);
}
