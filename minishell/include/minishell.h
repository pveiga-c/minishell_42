/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:21 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/02 16:11:24 by pviegas          ###   ########.fr       */
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

typedef struct s_commands
{
	char				**content;
	char				*path;
	int					fd_master[2];
	int					fd[2];
	int					master_error[2];
	struct s_commands	*next;
	struct s_commands	*prev;
	void				(*ft_exec)(struct s_commands **commands);
}	t_commands;

// -----------------------------  FUNCTIONS --------------------------------- //

t_env	*get_env(char **env);
t_env	*env_last(t_env *lst);
void	env_add_back(t_env **lst, t_env *new);
t_env	*env_new(char *str);
int		free_env(t_env **lst);
void	execution(t_commands *command);

#endif