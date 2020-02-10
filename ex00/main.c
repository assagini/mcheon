/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:12:57 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/10 14:39:46 by mcheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

/*
** checking if arg is a correct non-negative integer
** if so, return 0. otherwise -1
*/

// 입력값이 유효한지 
int		is_correct_num(char *arg)
{
	int cnt;

	cnt = 0;
	while (arg[cnt])
	{
		if (arg[cnt] > '9' || arg[cnt] < '0')
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		cnt++;
	}

	// 파일명이 없는데 값이 있는 경우
	if (arg[0] == '0' && cnt != 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}

	// 에러가 없으면 0을 반환
	return (0);
}

/*
** checking if arguments are correct
** if so, try to open dict file
** if successfully opened allocate an array of "t_dict" to dict_arr
*/

int		main_init(int argc, char *argv[], int *fd, t_dict **dict_arr)
{
	// 인자가 2개 혹은 3개이어야 하니깐
	if (argc > 3 || argc < 2)
		write(1, "Dict Error\n", 11);
	if (argc > 3 || argc < 2)
		return (-1);

	// 인자가 제대로 들어온 경우
	if (argc == 2)
	{
		// 앞으로 fd를 이용해서 딕션어리를 참조
		// open("파일이름", 읽기모드 등)
		*fd = open("numbers.dict", O_RDONLY);

		// 올바은 입력값인지 조사
		// 입력된 숫자가 정상이면 0을, 이상한 숫자이면 -1을 반환시키니깐
		if (is_correct_num(argv[1]) < 0)
			return (-1);
	}

	// 인자가 3개인 경우
	else
	{
		// argv[1]에 있는 파일명을 오픈
		*fd = open(argv[1], O_RDONLY);

		// 입력된 숫자가 이상한 숫자일 때 -1을 반환시키니깐
		if (is_correct_num(argv[2]) < 0)
			return (-1);
	}

	// 오픈에 실패한 경우
	if (*fd == -1)
		write(1, "Dict Error\n", 11);
	if (*fd == -1)
		return (-1);

	// 인자가 2개일 때 파싱하기 위함
	if (argc == 2)
		*dict_arr = parse(*fd, 0, "numbers.dict");

	// 인자가 3개일 때 파싱하기 위함
	else
		*dict_arr = parse(*fd, 0, argv[1]);

	return (0);
}

/*
** printing zero as an exception
*/

void	zero_print(t_dict *dict)
{
	write(1, dict[g_len - 1].value, str_len(dict[g_len - 1].value));
}

/*
** allocate an array of t_dict -> sort the array(descending)
** -> solve the args -> split and join
*/

int		main(int argc, char *argv[])
{
	int		fd;
	t_dict	*dict_arr;

	// 입력이 유효한지 보는데 
	// g_error는 전역 변수로 rush_header.h에 있음
	// g_error가 1이면 앞으로 만나는 특정 함수에서 진행이 안됨
	if (main_init(argc, argv, &fd, &dict_arr) < 0 || g_error == 1)
		return (0);
	
	close(fd);

	// 
	sort(dict_arr, g_len);
	
	// 인자는 유효해서 아래로 진행한 경우
	// 인자가 2개일 때
	if (argc == 2)
	{
		if (ft_strcmp("0", argv[1]) == 0)
			zero_print(dict_arr);
		solve(argv[1], dict_arr, "100", 0);
	}
	
	// 인자가 3개일 때
	if (argc == 3)
	{
		if (ft_strcmp("0", argv[2]) == 0)
			zero_print(dict_arr);
		solve(argv[2], dict_arr, "100", 0);
	}
	
	// 
	split_join();
	
	// 동적할당한 메모리를 해제
	dict_arr_free(dict_arr);
	return (0);
}
