/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:41:48 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 14:36:37 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	numstrlen(const char *str)
{
	size_t	i;
	size_t	len;
	size_t	neg;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	neg = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		len++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	return (len + neg);
}

static int	args_check(char **argv, int i)
{
	long	num;
	char	*tmp;

	while (argv[++i])
	{
		if (!is_num(argv[i]))
			return (not_n(), 1);
		num = ft_atol(argv[i]);
		if (longlen(num) != numstrlen(argv[i]) || numstrlen(argv[i]) > 19)
			return (n_too_big(num, argv[i]));
		tmp = ft_ltoa(num);
		if (!tmp)
			return (write(2, "ltoa error\n", 11), 1);
		if (zero_check(num, i))
			return (ft_free((void **)&tmp), 1);
		if (num != ft_atol(tmp) || longlen(num) != longlen(ft_atol(tmp)))
			return (ft_free((void **)&tmp), n_too_big(num, argv[i]));
		if (num < 0)
			return (ft_free((void **)&tmp), n_too_small());
		ft_free((void **)&tmp);
	}
	return (0);
}

static int	join_and_kill(t_data *data, int thread_num)
{
	int		i;
	t_philo	*philo;

	philo = first_philo(data->philos);
	i = 0;
	if (thread_num <= 0)
		return (kill(data), 1);
	while (i < thread_num)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
	return (kill(data), 1);
}

static int	start(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = first_philo(data->philos);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&philo->thread, NULL, philo_routine, philo))
		{
			lock(&data->print_lock);
			*philo->dead = 1;
			unlock(&data->print_lock);
			return (write(2, "pthread_create error\n", 22), i);
		}
		philo = philo->next;
		i++;
	}
	lock(&data->print_lock);
	data->start_time = get_time();
	if (data->start_time == -1)
		return (unlock(&data->print_lock), write(2, "get_time error\n", 14), i);
	data->start = 1;
	unlock(&data->print_lock);
	return (i);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				thread_num;

	if (argc < 5 || argc > 6)
		return (write(2, "Error: Wrong number of arguments\n", 33));
	if (args_check(argv, 0))
		return (1);
	data.num_of_philos = 0;
	data.dead = 0;
	data.full = 0;
	data.start = 0;
	data.start_time = 0;
	data.start = 0;
	data.start_time = 0;
	data.philos = NULL;
	data.overseer = NULL;
	if (init(&data, argv))
		return (kill(&data), 1);
	thread_num = start(&data);
	if (thread_num != data.num_of_philos)
		return (join_and_kill(&data, thread_num));
	if (overseer(data.overseer))
		return (kill(&data), 1);
	return (kill(&data), 0);
}
