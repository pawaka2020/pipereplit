/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
PARAMETERS:
1.'nbr' is the original number 
2.'base' are the characters expected in a number base. 
Example, if we are going hexadecimal, 
'base' are "0123456789abcdef" 
3.'res' is the int result of ft_printf,
HOW IT WORKS:
1. Get the length of 'base' as baselen.
Since we are going hexademical,  baselen is gonna be 16.
2. Divide 'nbr' with baselen (16)
3. 
*/
int	ft_putnbr_base(unsigned long nbr, char *base, int *res)
{
	unsigned int	baselen;
	int	i;

	i = 0;
	baselen = ft_strlen(base);
	if (nbr >= baselen)
	{
		ft_putnbr_base(nbr / baselen, base, res);
		ft_putnbr_base(nbr % baselen, base, res);
	}
	else
	{
		*res += 1;
		i = write(1, base + nbr, 1);
	}
	return (i);
}
