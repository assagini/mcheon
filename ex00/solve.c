/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:39:49 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 18:05:03 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

/*
** storing answers to g_ans.
** later to be splitted and joined
*/

void	ans_parse(char *qout, char *rmd, t_dict *dict, int i)
{
	ft_strcat(g_ans, " ");
	ft_strcat(g_ans, dict[i - 1].value);
	if (ft_strcmp(qout, "1") == 0 && ft_strcmp(rmd, "0") == 0)
		return ;
	ft_strcat(g_ans, " ");
}

/*
** check if recurion should end.
** if num is "1" done (smallest quotient)
** adding "one" because of english number counting (one hund..)
*/

int		recur_end(char *num, char *str, t_dict *dict)
{
	if (ft_strcmp(num, "1") == 0)
	{
		if (ft_cmp(str, "99") > 0)
			ft_strcat(g_ans, dict[g_len - 2].value);
		return (1);
	}
	return (0);
}

/*
** split g_ans by " "
** then join by " "
** then print joined string
*/

void	split_join(void)
{
	char	**splitted;
	char	*print;
	int		size;
	int		i;

	if (g_error == 1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	i = 0;
	size = 0;
	splitted = ft_split(g_ans, " ");
	while (splitted[size] != 0)
		size++;
	print = ft_strjoin(size, splitted, " ");
	free_splitted(splitted);
	while (print[i])
		write(1, &print[i++], 1);
	write(1, "\n", 1);
	free(print);
}

/*
** """"" (num / dict[idx].key) dict[idx].value """"
** do recursion for expressing (num / dict[idx].key)
** strcpy(num, num % dict[idx].key) for next interation
** idx++ for next iteration
** it works because the t_dict array is sorted
*/

void	solve(char *num, t_dict *dict, char *str, int i)
{
	char	qout[10000];
	char	rmd[10000];
	char	prev[10000];

	prev[0] = '\0';
	if (recur_end(num, str, dict) == 1)
		return ;
	while (i++ < g_len - 1)
	{
		divide(num, dict[i - 1].key, qout, rmd);
		if (*qout == '0')
			prev[0] = '\0';
		if (*qout == '0')
			continue;
		if (ft_strcmp(prev, num) == 0)
			g_error = 1;
		if (ft_strcmp(prev, num) == 0)
			break ;
		solve(qout, dict, dict[i - 1].key, 0);
		ans_parse(qout, rmd, dict, i);
		ft_strcpy(prev, num);
		ft_strcpy(num, rmd);
	}
}
