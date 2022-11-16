/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:11:52 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/02 18:20:47 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cifras(long nb)
{
	int	cifras;

	cifras = 0;
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

char	*ft_u_itoa(unsigned int n)
{
	char			*s;
	int				cifras;
	unsigned int	m;

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
