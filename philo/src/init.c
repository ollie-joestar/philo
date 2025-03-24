/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:22:42 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 11:09:23 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (pthread_mutex_init(&philo->frk, NULL))
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
	if (!data->philos)
		return (write(2, "init_philos error\n", 13), 1);
	return (0);
}

int	init_overseer(t_data *data)
{
	t_overseer	*overseer;

	overseer = ft_calloc(1, sizeof(t_overseer));
	if (!overseer)
		return (write(2, "calloc error\n", 13), 1);
	data->overseer = overseer;
	overseer->print_lock = &data->print_lock;
	overseer->meals_lock = &data->meals_lock;
	overseer->start_lock = &data->start_lock;
	overseer->clock_lock = &data->clock_lock;
	overseer->dead = &data->dead;
	overseer->full = &data->full;
	overseer->num_of_philos = data->num_of_philos;
	overseer->philos = data->philos;
	return (0);
}

int	init(t_data *data, char **argv)
{
	if (pthread_mutex_init(&data->print_lock, NULL))
		return (write(2, "mutex init error\n", 17), 1);
	if (pthread_mutex_init(&data->start_lock, NULL))
		return (write(2, "mutex init error\n", 17), 1);
	if (pthread_mutex_init(&data->meals_lock, NULL))
		return (write(2, "mutex init error\n", 17), 1);
	if (pthread_mutex_init(&data->clock_lock, NULL))
		return (write(2, "mutex init error\n", 17), 1);
	data->num_of_philos = ft_atol(argv[1]);
	if (init_philos(data, argv))
		return (kill(data), 1);
	if (init_overseer(data))
		return (kill(data), 1);
	return (0);
}
