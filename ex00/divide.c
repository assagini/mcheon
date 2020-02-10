/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:05:42 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 21:40:09 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

/*
** saving int array "a" into char array "str"
*/

void	print(int *a, int l, char *str)
{
	int i;

	i = 0;
	while (i < l && !a[i])
		i++;
	if (i == l)
	{
		*str = '0';
		str++;
	}
	while (i < l)
	{
		*str = a[i++] + 48;
		str++;
	}
	*str = '\0';
}

/*
** segment of long integer division algorithm('cause of norm)
*/

void	go_util(int *i, int *j)
{
	g_q[g_ql - 1]++;
	*j = 0;
	while ((*j)++ < g_bl)
		g_a[*i + *j - 1] -= g_b[*j - 1];
	*j = g_bl - 1;
	while ((*j)-- >= 0)
	{
		if (g_a[*i + *j + 1] < 0)
		{
			g_a[*i + *j]--;
			g_a[*i + *j + 1] += 10;
		}
	}
	while (g_a[*i + (*j)--] < 0)
	{
		g_a[*i + *j]--;
		g_a[*i + *j + 1] += 10;
	}
}

/*
** segment of long integer division algorithm('cause of norm)
** it can g_q = g_a / g_b, g_r = g_a % g_b for big integers like 10^1000
*/

void	go(void)
{
	int i;
	int j;
	int k;
	int as;

	go_init(&i, &k, &as);
	while (as < g_al && !g_a[as])
		as++;
	while (i + g_bl <= g_al)
	{
		if (i < as || (i == as && cmp(g_a + i, g_al - i, g_b, g_bl) < 0))
		{
			if (++i + g_bl <= g_al)
				g_ql++;
			continue;
		}
		go_util(&i, &j);
		while (as < g_al && !g_a[as])
			as++;
	}
	i = 0;
	while (i < g_al - as)
		g_r[g_rl++] = g_a[as + (i++)];
	if (g_rl == 0)
		g_rl++;
}

/*
** setting up for divison, initialing some global variables(g_q, g_r)
** first / second = qout, first % second = rmd
*/

void	divide(char *first, char *second, char *quot, char *rmd)
{
	int i;

	i = 0;
	while (i < 10001)
	{
		g_r[i] = 0;
		g_q[i++] = 0;
	}
	g_q[10001] = 0;
	g_q[10002] = 0;
	g_ql = 2;
	div_init(first, g_a, &g_al);
	div_init(second, g_b, &g_bl);
	go();
	print(g_q, g_ql, quot);
	print(g_r, g_rl, rmd);
}
