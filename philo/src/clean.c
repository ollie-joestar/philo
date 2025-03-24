/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:40:31 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 11:05:48 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->frk);
	pthread_mutex_unlock(&(*philo)->frk);
	pthread_mutex_destroy(&(*philo)->frk);
	free(*philo);
	*philo = NULL;
}

void	free_philos(t_data *data)
{
	int		i;
	t_philo	*tmp;

	if (!data || !data->philos)
		return ;
	i = data->num_of_philos;
	while (i-- && data->philos)
	{
		tmp = data->philos->next;
		free_philo(&data->philos);
		data->philos = tmp;
	}
	data->philos = NULL;
}

void	free_overseer(t_data *data)
{
	if (!data || !data->overseer)
		return ;
	free(data->overseer);
	data->overseer = NULL;
}

void	kill(t_data *data)
{
	if (!data)
		return ;
	if (data->philos)
		free_philos(data);
	if (data->overseer)
		free_overseer(data);
	lock(&data->meals_lock);
	unlock(&data->meals_lock);
	pthread_mutex_destroy(&data->meals_lock);
	lock(&data->print_lock);
	unlock(&data->print_lock);
	pthread_mutex_destroy(&data->print_lock);
	lock(&data->start_lock);
	unlock(&data->start_lock);
	pthread_mutex_destroy(&data->start_lock);
}
