/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:21 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/06 16:52:18 by pviegas          ###   ########.fr       */
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
//#include "aux.h"

// -------------------------------- MACROS ---------------------------------- //

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_commands
{
	char				**content;
	char				*path;
	int					fd_master[2];
	int					fd[2];
	int					fd_master_error[2];		// guarda se o fd_master for invalido
	struct s_commands	*next;
	struct s_commands	*prev;
	void				(*ft_exec)(struct s_commands **commands);
}	t_commands;

typedef struct s_vars
{
	t_list			*head;
	char			*str;
	char			**env;
	char			**division;
}	t_vars;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

struct s_global
{
	t_vars			*vars;
	int				status;
	t_env			*env;
	int				hd;
	int				interrupted;
//	struct termios	termios_save;
};

extern struct s_global	g_data;

// -----------------------------  FUNCTIONS --------------------------------- //

t_env		*get_env(char **env);
t_env		*env_last(t_env *lst);
void		env_add_back(t_env **lst, t_env *new);
t_env		*env_new(char *str);
int			free_env(t_env **lst);
void		env_first(t_env **lst);
void		executor(t_commands *command);
void		execution(t_commands *command);
void		print_lst(t_commands *command);
char		**lst_to_arr(t_env *lst_env);
int			env_lst_size(t_env *lst);
t_commands	*lst_last(t_commands *lst);
void		lst_add_back(t_commands **lst, t_commands *new);
char		*get_cmd_path(char **env, char **cmd);
char		*search_env(char **env, char *str);
int			search_number(char *s1, char *s2);
void		free_matrix(char ***m);

#endif