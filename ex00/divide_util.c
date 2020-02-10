/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:24:54 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 21:44:21 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

/*
** comparing big integer "a" and "b" which are stored as int arrays
** al and bl are size of array "a" and "b"
*/

int		cmp(int *a, int al, int *b, int bl)
{
	int i;

	if (al < bl)
		return (-1);
	i = 0;
	while (i < bl)
	{
		if (a[i] < b[i])
			return (-1);
		if (a[i] > b[i])
			return (1);
		i++;
	}
	return (0);
}

/*
** initializing function divide
*/

void	div_init(char *str, int *arr, int *l)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	*l = i;
	i = 0;
	while (i < *l)
	{
		arr[i] = str[i] - '0';
		i++;
	}
}

/*
** initializing function go
*/

void	go_init(int *a, int *b, int *c)
{
	*a = 0;
	*b = 10;
	*c = 0;
}
