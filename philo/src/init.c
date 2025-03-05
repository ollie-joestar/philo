/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:22:42 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/05 14:04:32 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_check(char **argv)
{
	int		i;
	long	l1;
	long	l2;
	char	*tmp;

	i = 0;
	while (argv[++i])
	{
		l1 = ft_atol(argv[i]);
		if (longlen(l1) != ft_strlen(argv[i]))
			return (n_too_big());
		tmp = ft_ltoa(l1);
		if (!tmp)
			return (write(2, "ltoa error\n", 11), 1);
		l2 = ft_atol(tmp);
		if (i == 1 && l1 > 200)
			return (ft_free((void **)&tmp), too_many_philos());
		if (l1 != l2 || longlen(l1) != longlen(l2))
			return (ft_free((void **)&tmp), n_too_big());
		if (l1 < 0)
			return (ft_free((void **)&tmp), n_too_small());
		ft_free((void **)&tmp);
	}
	return (0);
}

int	init(char **argv)
{
	int	i;

	if (args_check(argv))
		return (1);
	i = 0;
	return (0);
}
