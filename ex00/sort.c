/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:05:59 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/10 14:47:03 by mcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"
#include <stdio.h>

/*
** swapping t_dict by values
*/

// 값을 교체
void	swap(t_dict *now, t_dict *next)
{
	char *temp;

	// now의 값을 temp에 넣고
	temp = now->key;

	// next의 값을 now에 넣고
	now->key = next->key;

	// temp의 값을 next에 넣고
	next->key = temp;
	
	// now의 값을 temp에 넣고
	temp = now->value;
	
	// next의 값을 now에 넣고
	now->value = next->value;
	
	// temp의 값을 next에 넣고
	next->value = temp;
}

/*
** simple str_len
*/

// str의 길이을 반환
int		str_len(char *str)
{
	int rtn;

	rtn = 0;
	while (*str != '\0')
	{
		rtn++;
		str++;
	}
	return (rtn);
}

/*
** if s1 > s2 as number, return positive. otherwise negative
*/

// 두 값을 비교해서 
int		ft_cmp(char *s1, char *s2)
{
	unsigned int	idx;
	int				s1_len;
	int				s2_len;

	idx = 0;
	s1_len = str_len(s1);
	s2_len = str_len(s2);

	


	// 들어온 두 개의 값이 다르면
	if (s1_len != s2_len)
		// 둘의 차이값을 리턴
		return (s1_len - s2_len);

	// 들어온 두 개의 값이 같으면
	// 둘다 null이 아니면
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		// Q. 근데 두 개의 값이 다르면???
		printf("\n\n------------------------------------------\n");
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}

	// Q. 저 두 경우가 아니면?
	return (s1[idx] - s2[idx]);
}

/*
** bubble sort using ft_cmp as the comparing fucntion
*/

// 딕션어리랑 길이를 가져와서
void	sort(t_dict *tab, int size)
{
	int idx1;
	int idx2;

	idx1 = 0;
	while (idx1 < size - 1)
	{
		idx2 = 0;

		while (idx2 < size - 1 - idx1)
		{
			// tab[0]의 key값 과 tab[1]의 key값을 ft_cmp함수로 보냄
			// 차이값이 마이너스 이면
			// printf("(tab + %d)->key = %d, (tab + %d + 1)->key = %d\n", idx2, (tab+ idx2), idx2, (tab+ idx2)+ 1);
			if (ft_cmp((tab+ idx2)->key, (tab + idx2 + 1)->key) < 0)
			{
				// 두 줄을 바꿈
				swap(tab + idx2, tab + idx2 + 1);
			}

			// 마이너스가 아니면 idx2를 하나 올림
			idx2++;
		}
		idx1++;
	}
}
