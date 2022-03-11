/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Integrated header for all previous 42KL projects.
To use, simply include this header into your project header.
Then type 'gcc main.c mylibft/star.a'
*/
#ifndef MYLIBFT_H
# define MYLIBFT_H

# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

//additional functions not included in either libraries
//prints error message, then terminates program using exit (0)
void	ft_printerror(char *message);

#endif
