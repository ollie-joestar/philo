/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:21:05 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/08 11:59:55 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->q_turn = 1;
	if (init(data, argv))
		return (kill(data), 1);
	if (start(data))
		return (kill(data), 1);
	/*if (overseer(data))*/
	/*	return (kill(data), 1);*/
	return (kill(data), 0);
}
