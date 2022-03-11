/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/10/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	display_nbr(int n, int fd)
{
	int	i;
	
	if (n >= 10)
		display_nbr(n / 10, fd);
	i = write(fd, &"0123456789"[n % 10], 1);
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (0);
	if (n == -2147483648)
	{
		i = write(fd, "-2147483648", 11);
		return (0);
	}
	if (n < 0)
	{
		i = write(fd, "-", 1);
		n *= -1;
	}
	display_nbr(n, fd);
	return (i);
}
