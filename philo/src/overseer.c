/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:40 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/07 14:31:36 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	overseer(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = first_philo(data->philos);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(philo->thread, NULL))
			return (1);
		i++;
		philo = philo->next;
	}
	return (0);
}
