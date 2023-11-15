/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:21 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 16:23:13 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ------------------------------- INCLUDES --------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
# include <readline/history.h>
#include "../libft/libft.h"
#include "built_in.h"
#include "parse.h"

// -------------------------------- MACROS ---------------------------------- //

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

// -----------------------------  FUNCTIONS --------------------------------- //

t_env	*get_env(char **env);
#endif