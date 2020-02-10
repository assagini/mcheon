/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:12:59 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 21:19:00 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"
#include <stdio.h>

/*
** check if the num string is valid(no float, no numbers staring 0)
** if valid, malloc and store num to the "t_dict array"
*/

int		is_num(char *num, t_dict *save)
{
	int		i;
	char	*no_str;

	i = 0;
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9' || (i != 0 && num[0] == '0'))
		{
			g_error = 1;
			return (-1);
		}
		i++;
	}
	no_str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (num[i] != '\0')
	{
		no_str[i] = num[i];
		i++;
	}
	no_str[i] = '\0';
	save->key = no_str;
	return (0);
}

/*
** returns the size of string array "strs"
*/

int		size_finder(char **strs)
{
	int		rtn;
	char	**cp;

	cp = strs;
	rtn = 0;
	while (*cp != 0)
	{
		rtn++;
		cp++;
	}
	return (rtn);
}

/*
** applying split and join to given line
** then store key and value to the t_dict array
*/

// 밑에서 apply_line(rtn, line_save, flag); 이렇게 넘어옴
void	apply_line(t_dict *array, char *str, int flag)
{
	char	**splitted;
	char	*parsed_str;

	// 이상하면 에러
	if (*str < '0' || *str > '9' || col_check(str, flag))
	{
		write(1, "Dict Error\n", 11);
		g_error = 1;
		return ;
	}

	// key값 데리고 옴
	splitted = ft_split(str, " ");
	if (is_num(splitted[0], &array[g_len]) == -1 || splitted[1] == 0)
	{
		g_error = 1;
		return ;
	}

	// value값 데리고 옴
	if ((parsed_str = ft_strjoin(size_finder(splitted + 1), splitted + 1, " ")) == 0)
	{
		g_error = 1;
		return ;
	}
	
	// 해당되는 key에 value값 넣기
	array[g_len].value = parsed_str;
	g_len++;
	free_splitted(splitted);
}

/*
** allocate the array of t_dict by counting the number of '\n'
** plus some initializing
*/

// 파싱하기 전에 메모리 확보
// idx를 0 처리 하기 위함
t_dict	*parse_init(char *file, int *idx)
{
	t_dict	*rtn;
	int		fd;
	int		cnt;
	char	buf;
	char	prev;

	cnt = 0;
	prev = 0;

	// 파일을 오픈
	// 해당 함수에서 사용하려면 그 함수에서 오픈
	fd = open(file, O_RDONLY);

	/*
	idx는 그냥 변수
	fd는 open() 시스템 콜로 열린 파일을 가리키는 파일 지정 번호
	&buf는 파일에서 읽은 데이터를 저장할 메모리 공간
	1은 읽을 데이터의 크기(Byte 단위)
	반환값은 파일 읽기 성공 : 0 보다 큰 수
	읽을 데이터 없을 시 : 0
	*/
	while ((*idx = read(fd, &buf, 1)))
	{
		// idx의 값이 -1 이면 에러
		if (*idx == -1)
		{
			write(1, "Dict Error\n", 11);
			g_error = 1;
			return (0);
		}

		// prev는 전에 나온 문자
		// 개행 문자를 만났는데 이전 문자가 개행 문자가 아닐때 줄 수 추가 
		// 읽을 때 개행 문자보면 그 다음 줄을 이어서 읽는다. 
		if (buf == '\n' && prev != buf)
			cnt++;
		prev = buf;
	}

	// 열었으니깐 닫아줬음
	close(fd);

	// cnt는 줄 수
	rtn = (t_dict *)malloc(sizeof(t_dict) * cnt);
	
	// idx를 0으로 초기화
	*idx = 0;
	
	// 딕션어리를 넣을 배열에 대해서 확보한 메모리를 리턴
	return (rtn);
}

/*
** flag : beforing meeting ":" set 0. after, 1
** when ":" is first met, change it into " "
** when the line ends, split the line with " "
** take splitted[0] for key and join the remainder of value
*/

// 메인에서 *dict_arr = parse(*fd, 0, "numbers.dict"); 이렇게 넘어옴
t_dict	*parse(int fd, int flag, char *file)
{
	t_dict	*rtn;
	char	line_save[100000];
	int		idx;

	// 딕션어리 넣을 공간에 대한 메모리 확보
	// 갔다오면 idx가 0이 됨
	rtn = parse_init(file, &idx);

	// 딕션어리 내용 넣기
	// g_error == 1이면 진행이 안됨
	// g_buf에 글자를 1개씩 넣고 읽음
	// read의 결과가 null이 나올때까지 반복
	while (read(fd, &g_buf, 1) && g_error == 0)
	{
		// flag는 첫번 째 :의 인덱스
		// flag가 0인데 :를 보았다면
		if (flag == 0 && g_buf == ':')
		{
			// :를 빈칸으로 교체
			g_buf = ' ';

			// 해당 인덱스 번호를 flag에 입력
			flag = idx;
		}

		// 줄바꿈이 보였는데
		if (g_buf == '\n')
		{
			// Q.줄바꿈이 보였는데 인덱스가 0이 아니면 왜 null처리를 해주나?
			// --> 끝에 닫아줌
			if (idx != 0)
				line_save[idx] = '\0';


			// 딕션어리 완성
			if (idx != 0)
				apply_line(rtn, line_save, flag);
			idx = 0;
			flag = 0;
			continue;
		}
		// null값이 보일 때까지 글자 하나 하나 저장
		line_save[idx++] = g_buf;
	}
	return (rtn);
}
