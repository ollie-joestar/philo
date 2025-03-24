/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:11:48 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 16:07:01 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	n_too_big(long n, char *str)
{
	if (longlen(n) > 19 || ft_strlen(str) > 19)
		return (write(2, "Can you even spell that number?\n", 33));
	else if (*str == '0')
	{
		if (ft_strlen(str) > 1 && str[1] != '0')
			return (write(2, "Remove the leading zero...\n", 28));
		else if (ft_strlen(str) > 1 && str[1] == '0')
			return (write(2, "Remove the leading zeros...\n", 29));
	}
	else
		return (write(2, "Bruh... just use a normal argument\n", 36));
	return (1);
}

int	n_too_small(void)
{
	return (write(2, "Really? Negative number?\n", 26));
}

int	not_n(void)
{
	return (write (2, "That's not even a number...\n", 29));
}

int	zero_check(long n, int i)
{
	if (i == 1)
	{
		if (n == 0)
			return (write(2, "Zero philosophers? Really?\n", 28));
		if (n > 1000000000)
			return (write(2, "Be realistic, please\n", 22));
		if (n < 1)
			return (write(2, "Negative num of philosophers?..\n", 32));
	}
	if (i == 2)
	{
		if (n == 0)
			return (write(2, "Zero time to die? Have a heart...\n", 35));
		if (n < 1)
			return (write(2, "Give at least 1ms to die\n", 26));
	}
	if (i == 5)
	{
		if (n == 0)
			return (write(2, "Not hungry\n", 11));
	}
	return (0);
}
