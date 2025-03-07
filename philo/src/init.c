/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:22:42 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/07 18:36:14 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_check(char **argv)
{
	int		i;
	long	num;
	char	*tmp;

	i = 0;
	while (argv[++i])
	{
		if (!is_num(argv[i]))
			return (not_n());
		num = ft_atol(argv[i]);
		if (longlen(num) != ft_strlen(argv[i]) || ft_strlen(argv[i]) > 19)
			return (n_too_big(num, argv[i]));
		tmp = ft_ltoa(num);
		if (!tmp)
			return (write(2, "ltoa error\n", 11), 1);
		if (i == 1 && (num > 200 || num < 1))
			return (ft_free((void **)&tmp), philo_num(num));
		if (num != ft_atol(tmp) || longlen(num) != longlen(ft_atol(tmp)))
			return (ft_free((void **)&tmp), n_too_big(num, argv[i]));
		if (num < 0)
			return (ft_free((void **)&tmp), n_too_small());
		ft_free((void **)&tmp);
	}
	return (0);
}

static int	init_philo(t_data *data, char **argv, int i)
{
	t_philo		*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (write(2, "calloc error\n", 13), 1);
	philo->num_of_philos = ft_atol(argv[1]);
	philo->index = philo->num_of_philos - i;
	link_to_data(data, philo);
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->meals_to_eat = ft_atol(argv[5]);
	philo->frk = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!philo->frk)
		return (write(2, "calloc error\n", 13), 1);
	if (pthread_mutex_init(philo->frk, NULL))
		return (write(2, "mutex init error\n", 1));
	return (0);
}

int	init_philos(t_data *data, char **argv)
{
	int		i;

	i = ft_atol(argv[1]);
	while (i--)
	{
		if (init_philo(data, argv, i))
			return (1);
	}
	/*p_philos(data);*/
	if (!data->philos)
		return (write(2, "init_philos error\n", 13), 1);
	return (0);
}

int	init(t_data *data, char **argv)
{
	if (args_check(argv))
		return (1);
	data->num_of_philos = ft_atol(argv[1]);
	if (init_philos(data, argv))
		return (kill(data), 1);
	return (0);
}
