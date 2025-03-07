/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:55:01 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/07 18:43:09 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_of_philos;
	int				index;
	
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;

	int				eating;
	long			meals_eaten;
	long			meals_to_eat;

	long			start_time;
	long			last_meal;

	pthread_t		thread;

	int				*is_dead;
	pthread_mutex_t	*frk;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*meals_lock;
	struct s_philo	*next;
	struct s_philo	*prev;
}				t_philo;

typedef struct s_data
{
	int				num_of_philos;
	int				dead_flag;

	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meals_lock;

	t_philo			*philos;
}				t_data;

// Initialization
int		init(t_data *data, char **argv);
int		init_philos(t_data *data, char **argv);

// Numbers
long	ft_atol(const char *str);
char	*ft_ltoa(long n);
size_t	longlen(long n);

// Errors
int		n_too_big(long n, char *str);
int		n_too_small(void);
int		too_many_philos(void);
int		not_n(void);
int		philo_num(long n);

// Philo
t_philo	*first_philo(t_philo *philo);
t_philo	*last_philo(t_philo *philo);
void	link_to_data(t_data *data, t_philo *philo);

// Routine
int		overseer(t_data *data);
int		start(t_data *data);
void	*philo_routine(void *ptr);
/*void	eat(t_philo *philo);*/
void	think(t_philo *philo);
void	ft_usleep(long time);

// Utils
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		is_num(char *str);
long	get_time(void);
void	ft_free(void **ptr);
void	kill(t_data *data);
void	free_philos(t_data *data);
void	free_philo(t_philo *philo);

// Debug
void	p_philo(t_philo *philo);
void	p_philos(t_data *data);

#endif
