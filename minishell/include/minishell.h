/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:21 by pviegas           #+#    #+#             */
/*   Updated: 2023/10/31 14:25:40 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ------------------------------- INCLUDES --------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "../libft/libft.h"
#include "built_in.h"

// -------------------------------- MACROS ---------------------------------- //

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

// -----------------------------  FUNCTIONS --------------------------------- //

#endif