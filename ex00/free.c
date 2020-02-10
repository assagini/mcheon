/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:18:38 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 16:01:48 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

/*
** freeing array of strings(splitted)
*/

void	free_splitted(char **strs)
{
	int cnt;

	cnt = 0;
	while (strs[cnt])
	{
		free(strs[cnt]);
		cnt++;
	}
	free(strs);
}

/*
**	freeing array of t_dict
*/

void	dict_arr_free(t_dict *dict)
{
	int i;

	i = 0;
	while (i < g_len)
	{
		free(dict[i].key);
		free(dict[i++].value);
	}
	free(dict);
}
