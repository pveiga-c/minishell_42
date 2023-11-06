/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:29:07 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 16:52:07 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Liberta a memoria de uma variavel do tipo char** 
void	free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m && m[0] && m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	if (m)
	{
		free(m[0]);
		*m = NULL;
	}
}
/*
void free_matrix(char ***m)
{
	if (m && *m) 
	{
        int i = 0;
        while ((*m)[i]) 
		{
            free((*m)[i]);
            i++;
        }
        free(*m);
        *m = NULL;
    }
}
*/