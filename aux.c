/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:18:56 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/02 19:24:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	cont;

	cont = 0;
	if (!str)
		return (-1);
	while (str[cont])
	{
		if (write (1, &str[cont], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

static int	ft_cifras(long nb)
{
	int	cifras;

	cifras = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		cifras++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		cifras++;
	}
	return (cifras);
}

static char	*ft_mayomen(char *s, int cifras, long m)
{
	if (m < 0)
	{
		s[0] = '-';
		m = m * -1;
	}
	while (m > 0)
	{
		s[cifras] = '0' + (m % 10);
		m = m / 10;
		cifras--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		cifras;
	long	m;

	m = n;
	cifras = ft_cifras(m);
	if (m == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (cifras + 1));
	if (!s)
		return (NULL);
	s[cifras] = '\0';
	cifras--;
	s = ft_mayomen(s, cifras, m);
	return (s);
}
