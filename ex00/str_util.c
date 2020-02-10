/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:57:04 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 11:05:12 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

char	*ft_strcpy(char *dest, char *src)
{
	int idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int idx;
	unsigned int idx1;

	idx = 0;
	idx1 = 0;
	while (dest[idx] != '\0')
		idx++;
	while (src[idx1] != '\0')
	{
		dest[idx++] = src[idx1++];
	}
	dest[idx] = '\0';
	return (dest);
}
