/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:14:59 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/29 13:27:10 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./lib/libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *s, ...);
int		ft_putnbr_count(int n);
int		ft_putstr_count(char *s);
int		ft_putunbr_count(unsigned int n, int count);
int		ft_putnbrhex_count(unsigned int n, int count, int lower);
int		ft_putptr_count(unsigned long n, int count);
#endif
