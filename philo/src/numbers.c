/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:38:18 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/07 18:43:16 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ')
		i++;
	if (ft_strlen(str) - i > 19 + (str[i] == '-'))
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		sign = sign - (2 * (str[i++] == '-'));
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + sign * (str[i++] - '0');
	return (num);
}

size_t	longlen(long n)
{
	int	i;

	i = 1 + (n < 0);
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	put_long(long n, char *str)
{
	unsigned long	num;
	int				neg;
	int				i;
	int				index;

	i = 0;
	neg = n < 0;
	index = longlen(n) - 1;
	if (n == 0)
		str[0] = '0';
	num = (1 - 2 * neg) * n;
	while (index >= 0 && num > 0)
	{
		str[index--] = '0' + (num % 10);
		num /= 10;
	}
	if (neg == 1)
		str[0] = '-';
}

char	*ft_ltoa(long n)
{
	char	*str;
	int		len;
	int		neg;

	neg = n < 0;
	len = longlen(n);
	if (len - neg > 19)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	if (!str)
	{
		write (2, "ft_ltoa malloc error\n", 21);
		return (NULL);
	}
	memset(str, 0, len + neg + 1);
	put_long(n, str);
	if (ft_atol(str) != n)
	{
		printf("ltoa overflow? str: %s, res: %ld\n", str, ft_atol(str));
		free(str);
		return (NULL);
	}
	return (str);
}
