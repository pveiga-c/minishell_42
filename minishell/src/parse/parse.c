/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/16 18:51:35 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void start_parse(t_prompt *parse, char *p_input)
// {
// 	char **token;
// 	t_listm *list;

// 	count_tokens(parse, p_input);
// 	token = start_list(parse, p_input);
// 	list = update_list(parse, token);	
// 	print_lst(list);
// }

void start_new(char *p_input)
{
	t_prompt2 parse;
	t_mini	mini;
	char **prompt_arr;
	//int i = 0;
	
	init_data(&parse, &mini);
	count_quote(&parse, p_input);
	prompt_arr = split_prompt(&parse, p_input);
	// while(prompt_arr && prompt_arr[i])
	// {
	// 	printf("%s\n", prompt_arr[i]);
	// 	i++;
	// }
	
	
}

char **split_prompt(t_prompt2 *parse, char *p_input)
{
	int		i;
	int		j;
	int 	n;
	int		n_words;
	const char	*p;
	char **words;
	
	i = -1;
	n = 0;
	p = p_input;
	n_words = count_words(parse, p_input, ' ');
	words = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!p_input || !words)
		return (NULL);
	while(++i < n_words)
	{
		words[i] = input_split(parse, p_input);
 	}
		
}

char *input_split(t_prompt2 *parse, char *p_input)
{
	char *word;

	
}

size_t	count_words(t_prompt2 *parse, const char *s, char c)
{
	int i;
    int n_word;
	(void)c;

    i = 0;
    n_word = 0;
    while (s[i])
    {
        if (s[i] == '\"' && parse->d_quote != 0)
        {
           i++;
            while (s[i] != '\"')
                i++;
            if (s[i] != '\0')
                n_word++;
			parse->d_quote -= 2;
        }
		else if (s[i] == '\'' && parse->s_quote != 0)
        {
           i++;
            while (s[i] != '\'')
                i++;
            if (s[i] != '\0')
                n_word++;
			parse->s_quote -= 2;
        }
        else
        {
             while (s[i] && s[i] != ' ' && s[i] != '\'' && s[i] != '\"')
                i++;
            n_word++;
        }
		i++;
    }
    return (n_word);
}

char	*next_word(const char **s, char c)
{
	const char	*start;
	char		*word;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	word = ft_substr(start, 0, *s - start);
	if (!word)
	{
		free(word);
		return (NULL);
	}
	if (**s)
		(*s)++;
	return (word);
}

void count_quote(t_prompt2 *parse, char *p_input)
{
	int i;

	i = 0;
	while(p_input && p_input[i])
	{
		if(p_input[i] == '\"')
			parse->d_quote++;
		if(p_input[i] == '\'')
			parse->s_quote++;	
		i++;
	}
	if(parse->d_quote % 2 != 0 || parse->s_quote % 2 != 0)
	{
		printf("dquote>\n");
		exit (1);
	}
}

void init_data(t_prompt2 *parse, t_mini *mini)
{
	parse->cmds = NULL;
	parse->envp = NULL;
	parse->mini = NULL;
	parse->pid= 0;
	parse->d_quote = 0;
	parse->s_quote = 0;
	mini->full_cmd = NULL;
	mini->full_path = NULL;
	mini->outfile = 0;
	mini->infile = 0;
	
}
