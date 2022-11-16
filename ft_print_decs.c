/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:57:48 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/02 17:37:13 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_bsten(int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_itoa(nb);
	cont = ft_putstr(s);
	free(s);
	return (cont);
}

int	ft_print_decu(unsigned int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_u_itoa(nb);
	cont = ft_putstr(s);
	free(s);
	return (cont);
}
