/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:42:13 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/05 20:20:01 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list lst, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(lst, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_bsten(va_arg(lst, int)));
	else if (c == 'u')
		return (ft_print_decu(va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(lst, unsigned int)));
	else if (c == 'X')
		return (ft_print_hexmay(va_arg(lst, unsigned int)));
	else if (c == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_printing(char const *s, va_list lst, int cont, int ret_tot)
{
	int	sub_ret;

	while (s[cont])
	{
		if (s[cont] == '%' && s[cont + 1])
		{
			sub_ret = ft_type(lst, s[cont + 1]);
			if (sub_ret == -1)
				return (-1);
			ret_tot = ret_tot + sub_ret;
			cont = cont + 2;
		}
		else
		{
			if (write (1, &s[cont], 1) == -1)
				return (-1);
			ret_tot++;
			cont++;
		}
	}
	return (ret_tot);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	int		cont;
	int		ret_tot;

	va_start(lst, s);
	cont = 0;
	ret_tot = 0;
	ret_tot = ft_printing(s, lst, cont, ret_tot);
	va_end(lst);
	return (ret_tot);
}

int	main(void)
{
	int				k;
	char			*c;
	char			*d;
	unsigned int	h;
	void			*p;
	int				n;
	int				i;

	k = 65;
	c = "papa";
	d = NULL;
	h = 2394732;
	p = &k;
	n = -214;
	i = 0;
	ft_printf("Esto es un char %c\n", k);
	ft_printf("Esto es un string %s\n", c);
	ft_printf("Esto es un null %s\n", d);
	ft_printf("Esto es un por ciento %%\n");
	ft_printf("esto es una prueba %u\n", -10);
	ft_printf("Esto es un hexadecimal mayuscula %X\n", h);
    ft_printf("Esto es un hexadecimal minuscula %x\n", h);
	ft_printf("Esta es la direccion de un puntero %p\n", p);
	ft_printf("Esto es un decimal %d\n", n);
	ft_printf("Esto es un entero %i\n", i);
	ft_printf("Esto es un puntero %p\n", &c);
	return (0);
}
