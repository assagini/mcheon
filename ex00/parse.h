/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:58:51 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 22:04:04 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

t_dict			*parse(int fd, int flag, char *file);
void			sort(t_dict *tab, int size);
int				ft_cmp(char *s1, char *s2);
int				col_check(char *str, int flag);

#endif
