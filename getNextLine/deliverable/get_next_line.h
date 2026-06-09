/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:40 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/09 14:40:48 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*read_line(int fd);
char	*get_next_line(int fd);
int		get_linebreak(char *buffer, int size);
char	*append_str(char *str1, char str2[]);
void	add_substr(char *tempbuff, char *buffer, int endindex);
char	*ft_substr(char const *s, unsigned int start, int len);
#endif

