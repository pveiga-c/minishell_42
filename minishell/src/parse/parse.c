/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:03:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/11/15 18:20:29 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void start_parse(t_prompt *parse, char *p_input)
{
	char **token;
	t_listm *list;

	count_tokens(parse, p_input);
	token = start_list(parse, p_input);
	list = update_list(parse, token);	
	print_lst(list);
}

void start_new(char *p_input)
{
	t_prompt2 parse;
	t_mini	mini;
	
	init_data(&parse, &mini);
	count_quote(&parse, p_input);
	split_prompt(&parse, p_input);
	
	
}

void split_prompt(t_prompt2 *parse, char *p_input)
{
	int		i;
	int		n_words;
	const char	*p;
	char **words;
	(void)parse;
	
	p = p_input;
	n_words = count_words(p_input, ' ');
	words = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!p_input || !words)
		return ;
	i = 0;
	while (i < n_words)
	{
		words[i] = next_word(&p, ' ');
		if (!words[i])
		{
			while (i--)
				free(words[i]);
			free(words);
			return ;
		}
		i++;
	}
	words[i] = NULL;
	i = 0;
	while(words[i])
	{
		printf("%s\n", words[i]);
		i++;
	}
}
static size_t	count_words(const char *s, char c)
{
	int i;
    int n_word;

    i = 0;
    n_word = 0;
    while (s[i])
    {
        if (s[i] == '\"')
        {
           i++;
            while (s[i] != '\"')
                i++;
            if (s[i] != '\0')
                n_word++;
        }
        else
        {
             while (s[i] && s[i] != c)
                i++;
            if (s[i] != '\0')
                n_word++;
        }
		i++;
    }
    return n_word;
}

static char	*next_word(const char **s, char c)
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
