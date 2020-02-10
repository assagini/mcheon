/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:15 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 22:00:10 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_HEADER_H
# define RUSH_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "struct.h"
# include "str_utils.h"
# include "free.h"
# include "divide.h"
# include "parse.h"

void			solve(char *num, t_dict *dict, char *str, int i);

int				g_len;
int				g_error;
char			g_ans[100000];
int				g_ans_idx;
char			g_buf;

#endif
