/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/16 18:50:57 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//#include "minishell.h"
typedef struct s_prompt t_prompt;

typedef struct s_listm
{
	int		pipe_line;
	char	*content;
	char 	*cmd;
	char	*in_redir;
	char	*out_redir;
	int		id;
	struct s_listm *next;
	struct s_listm *prev;
	t_prompt *prompt;
} 	t_listm;

struct s_prompt
{
	int n_tokens;
	int n_pipes;
	int n_in_redir;
	int n_out_redir;
	t_listm	*tokens; 
}	;



void		init_param(t_prompt *parse);
void		print_lst(t_listm *list);

void 		start_parse(t_prompt *parse, char *p_input);
char		**start_list(t_prompt *parse, char *p_input);
void 		count_tokens(t_prompt *parse, char *p_input);
t_listm 	*update_list(t_prompt *parse, char **token);
char 		**start_memory_list(t_prompt *parse, char *p_input);
void		lst_add_back(t_prompt *parse, t_listm **lst, char *new, int i);
void 		split_content(t_listm *node, char *content);

void		init_param(t_prompt *parse);
void		print_lst(t_listm *list);

void 		start_parse(t_prompt *parse, char *p_input);
char		**start_list(t_prompt *parse, char *p_input);
void 		count_tokens(t_prompt *parse, char *p_input);
t_listm 	*update_list(t_prompt *parse, char **token);
char 		**start_memory_list(t_prompt *parse, char *p_input);
void		lst_add_back(t_prompt *parse, t_listm **lst, char *new, int i);
void 		split_content(t_listm *node, char *content);

//////////////////////////////////////////////////////////////////////////
typedef struct s_mini t_mini;

typedef struct s_prompt2
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
	t_mini	*mini;
	int		s_quote;
	int 	d_quote;
	char	**full_cmd;
}		t_prompt2;

struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}		;

void start_new(char *p_input);
void init_data(t_prompt2 *parse, t_mini *mini);
void count_quote(t_prompt2 *parse, char *p_input);
char **split_prompt(t_prompt2 *parse, char *p_input);
size_t	count_words(t_prompt2 *parse, const char *s, char c);
char	*next_word(const char **s, char c);
char	*input_split(t_prompt2 *parse, char *p_input);


#endif