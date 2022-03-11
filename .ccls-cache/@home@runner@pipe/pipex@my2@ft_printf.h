/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//for using 'write' function
# include <unistd.h>
// for malloc and free
# include <stdlib.h>
//for using va_start, va_arg, va_copy, va_end
//ft_printf is a variadic function
# include <stdarg.h>
//required .c files
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
void	ft_printchar(int i, int *strlen);
void	ft_printint(long i, int *strlen);
void	ft_printstr(char *str, int *strlen);
void	ft_printptr(unsigned long ptr, int *strlen);
void	ft_printunsint(long i, int *strlen);
int	ft_putnbr_base(unsigned long nbr, char *base, int *res);
void	ft_printhexa(unsigned int i, int *strlen);
void	ft_printbighexa(unsigned int i, int *strlen);
int		ft_partof(char c, char *str);
void	ft_printspec(char c, va_list arg, int *strlen);

#endif
