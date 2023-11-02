/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:05:40 by pviegas           #+#    #+#             */
/*   Updated: 2023/11/02 16:30:46 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mostra o conteudo da lista com os comandos apos o parser
void	print_lst(t_commands *list)
{
	int	i;

	if (!list)
		return ;
	while (list)
	{
		i = -1;
		printf("\nendereco: %p\n", list);
		printf("content: ");
		while (list->content[++i])
			printf("%s ", list->content[i]);
		printf("\nfd in: %i\n", list->fd[0]);
		printf("fd out: %i\n", list->fd[1]);
		printf("fd OW in: %i\n", list->fd_master[0]);
		printf("fd OW out: %i\n\n", list->fd_master[1]);
		list = list->next;
	}
}

// Converte uma lista numa variavel do tipo char**
char	**lst_to_arr(t_env *lst_env)
{
	int		size;
	char	**arr;
	int		i;

	size = ft_env_lstsize(lst_env);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	env_go_head(&lst_env);
	while (lst_env)
	{
		arr[i] = ft_strdup(lst_env->content);
		lst_env = lst_env->next;
		i++;
	}
	arr[size] = NULL;
	return (arr);
}