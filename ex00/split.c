/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:58:24 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 16:40:48 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"
#include <stdio.h>

int	g_no;
int	g_charset[256] = {0, };

// 공백에 대한 코드
char	**split_allocate(char *str)
{
	int		flag;
	char	**rtn;

	g_no = 0;
	flag = 0;

	// 공백의 갯수 파악
	while (*str != '\0')
	{
		// flag가 0이 아닌데(=문자있을 때) 공백이 나오면
		// 여기가지 보면 g_charset[i]에 공백만 1을 처리해줬음
		if (flag && g_charset[(unsigned char)(*str)] == 1)
		{
			flag = 0;
			g_no++;
		}

		// 공백이 아닌 문자가 나올 때
		else if (g_charset[(unsigned char)(*str)] == 0)
		{
			flag = 1;
		}
		str++;
	}

	// 패스....
	if (g_charset[(unsigned char)*(str - 1)] == 0)
		g_no++;

	// 공백이 차지하는 메모리	
	rtn = (char **)malloc(sizeof(char *) * (g_no + 1));
	return (rtn);
}

// key 반환
char	*word_saver(char **str, int size)
{
	char	*rtn;
	int		cnt;
	int		flag;

	flag = 0;
	cnt = 0;
	rtn = (char *)malloc(sizeof(char) * (size + 1));
	while (**str != '\0')
	{
		if (g_charset[(unsigned char)(**str)] == 0)
		{
			rtn[cnt++] = **str;
			flag = 1;
			//printf("cnt = %d\n", cnt);
			//printf("rtn = %c\n", rtn[cnt++]);
		}
		else if (g_charset[(unsigned char)(**str)] == 1 && flag == 1)
			break ;
		(*str)++;
	}
	rtn[cnt] = '\0';
	return (rtn);
}

// str을 한 개 한 개 검사하는데 공백이 아닌 경우
int		word_size_getter(char *str)
{
	// cnt는 글자수
	int cnt;
	int flag;

	flag = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (g_charset[(unsigned char)(*str)] == 0)
		{
			cnt++;
			flag = 1;
			//printf("\ng_charset = %d\n",g_charset[(unsigned char)(*str)]);
			//printf("cnt = %d\n\n",cnt);
		}

		// flag = 1이라는 건 이전에 문자가 있었다는 말
		// g_charset[(unsigned char)(*str)] == 1는 개행 문자
		else if (g_charset[(unsigned char)(*str)] == 1 && flag == 1)
		{
			//printf("\n-----------g_charset = %d\n",g_charset[(unsigned char)(*str)]);
			break ;
		}
		str++;
	}
	return (cnt);
}

/*
** splits str by members of the charset
*/

// str은 line_save.
// splitted = ft_split(str, " "); 이렇게 넘어옴
char	**ft_split(char *str, char *charset)
{
	char	**rtn;
	int		cnt;
	int		size;

	// 뭔가 들어있을 때
	while (*charset != '\0')
	{
		// 공백에 해당되는 아스키 코드 값을 1로 처리
		g_charset[(unsigned char)(*charset)] = 1;
		
		// 공백 다음은 null이니깐 끝남
		charset++;
	}
	
	// 패스......
	g_charset[0] = 1;

	// 공백에 대한 코드
	rtn = split_allocate(str);

	cnt = 0;
	
	while (*str != '\0')
	{
		// printf("\n-----------------------------\n");
		// printf("str = %s\n", str);
		// 공백이 아닌 경우
		if (g_charset[(unsigned char)(*str)] == 0)
		{
			// printf("#1\n");
			// 글자의 갯수 
			// four이면 4, one이면 3
			size = word_size_getter(str);

			// rtn은 key값인데..
			// key값을 뽑는 거 같음
			rtn[cnt++] = word_saver(&str, size);
			// printf("rtn = %s\n", *rtn);
			continue;
		}
		// printf("#2\n");
		// 잘은 모르겠지만, str의 인덱스를 하나씩 올려줌
		// 출력하면 그 인덱스부터 끝까지 나옴
		str++;
		// printf("#3\n");
	}
	// printf("#4\n");
	rtn[g_no] = 0;

	return (rtn);
}
