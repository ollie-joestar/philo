/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:05:12 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/07 14:00:40 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
	return ;
}

int	is_num(char *str)
{
	if (!str || !*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
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
