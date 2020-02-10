/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:34:23 by jungtlee          #+#    #+#             */
/*   Updated: 2020/02/09 21:38:10 by jungtlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "struct.h"

char			*ft_strjoin(int size, char **strs, char *sep);
char			**ft_split(char *str, char *charset);
int				str_len(char *str);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
void			split_join(void);

#endif
