/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:01:15 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/06 14:05:56 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			t;

	if (-1 == gettimeofday(&time, NULL))
		return (-1);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (t < 0)
		return (-1);
	return (t);
}
