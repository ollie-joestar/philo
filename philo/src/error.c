/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:11:48 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/05 12:23:41 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	n_too_big(void)
{
	return (write(2, "Can you even spell that number?\n", 33));
}

int	n_too_small(void)
{
	return (write(2, "Really? Negative number?\n", 26));
}

int	too_many_philos(void)
{
	return (write(2, "Read the eval sheet... 200 max\n", 31));
}
