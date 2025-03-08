/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:40:31 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/08 11:53:07 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo)
{
	if (philo->frk)
	{
		pthread_mutex_destroy(philo->frk);
		free(philo->frk);
	}
	free(philo);
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
		free_philo(data->philos);
		data->philos = tmp;
	}
	data->philos = NULL;
}

void	kill(t_data *data)
{
	if (!data)
		return ;
	if (data->philos)
		free_philos(data);
	free(data);
	data = NULL;
}
