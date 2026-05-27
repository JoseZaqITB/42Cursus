/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:14:59 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/27 16:20:33 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "./lib/libft/libft.h"
# include <stdarg.h>


int		ft_printf(char const *s, ...);
int		ft_putnbr_count(int n);
int		ft_putstr_count(char *s);
#endif
