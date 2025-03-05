/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:55:01 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/05 13:52:12 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// DELETE THIS
# define L_MAX_ABS "9223372036854775807"
# define L_MIN_ABS "9223372036854775808"

typedef struct s_philo
{
	pthread_t		thread;
	int				index;
	int				num_of_philos;
	
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;

	long			meals_eaten;
	long			meals_to_eat;

	long			last_meal;
	long			start_time;

	pthread_mutex_t	*frk;

	struct s_philo	*next;
	struct s_philo	*prev;
}				t_philo;

typedef struct s_data
{
	t_philo			*philos;
}				t_data;

// Initialization
int		init(char **argv);
// Numbers
long	ft_atol(const char *str);
char	*ft_ltoa(long n);
size_t	longlen(long n);
// Errors
int		n_too_big(void);
int		n_too_small(void);
int		too_many_philos(void);
// Utils
void	ft_free(void **ptr);
size_t	ft_strlen(const char *str);

#endif
