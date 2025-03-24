/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:05:12 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/21 12:20:02 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_usleep(t_philo *philo, unsigned long time)
{
	long	start;
	long	now;

	start = p_get_time(philo);
	if (start == -1)
	{
		write(2, "p_get_time error\n", 17);
		return ;
	}
	while (1)
	{
		now = p_get_time(philo);
		if (now == -1)
			return ;
		if ((unsigned long)now - start >= time)
			return ;
		if (should_die(philo))
			return ;
		if (dead(philo))
			return ;
		usleep(5);
	}
	return ;
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	if (start == -1)
		return ;
	while (get_time() - start < time)
		usleep(1);
	return ;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;

	total_size = size * nmemb;
	if (size && total_size / size != nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, total_size);
	return (ptr);
}
