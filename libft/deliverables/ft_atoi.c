/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:34:11 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/04 18:06:13 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	char	*an;
	int		n;
	char	sign;

	sign = 1;
	an = (char *)nptr;
	n = 0;
	while (*an == ' ' || (*an >= 9 && *an <= 13))
		an++;
	if (*an == '-' || *an == '+')
	{
		if (*an == '-')
			sign *= -1;
		an++;
	}
	while (*an >= '0' && *an <= '9' && *an)
	{
		n = n * 10 + (*an - '0');
		an++;
	}
	return (sign * n);
}
