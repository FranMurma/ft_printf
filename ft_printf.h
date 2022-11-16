/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:22:22 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/02 18:08:01 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

// #define SPECIFIERSS "cspdiuxX%"

int		ft_printf(char const *s, ...);
int		ft_print_s(char *s);
int		ft_print_char(int c);
int		ft_print_hex(unsigned int nb);
int		ft_print_hexmay(unsigned int nb);
int		ft_print_ptr(void *p);
int		ft_print_bsten(int nb);
int		ft_print_decu(unsigned int nb);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_u_itoa(unsigned int n);

#endif
