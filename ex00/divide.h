/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:25:19 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 21:57:41 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVIDE_H
# define DIVIDE_H

# include "rush_header.h"

void	divide(char *first, char *second, char *quot, char *rmd);
void	go_init(int *a, int *b, int *c);
void	div_init(char *str, int *arr, int *l);
int		cmp(int *a, int al, int *b, int bl);

int g_a[10001];
int	g_al;
int g_b[10001];
int	g_bl;
int g_q[10003];
int g_ql;
int g_r[10001];
int g_rl;

#endif
