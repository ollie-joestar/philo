/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:57:02 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/07 18:42:29 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = first_philo(data->philos);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&philo->thread, NULL, philo_routine, philo))
			return (1);
		philo = philo->next;
		i++;
	}
	return (0);
}

void	think(t_philo *philo)
{	
	long	time;

	time = get_time();
	printf("%ld %d is thinking\n", time - philo->start_time, philo->index);
	ft_usleep(1);
	return ;
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	//init routine
	philo = (t_philo *)ptr;
	philo->start_time = get_time();
	if (philo->start_time == -1)
		return (write(2, "get_time error\n", 14), NULL);
	philo->last_meal = philo->start_time;
	//routine itself
	think(philo);
	think(philo);
	return (NULL);
}
