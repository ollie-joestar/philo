/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:55:01 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 15:33:25 by oohnivch         ###   ########.fr       */
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
	unsigned long	time_to_think;
	long			meals_eaten;
	long			meals_to_eat;
	long			*start_time;
	long			last_meal;
	pthread_t		thread;
	int				*dead;
	int				*full;
	pthread_mutex_t	frk;
	pthread_mutex_t	*frst_frk;
	pthread_mutex_t	*scnd_frk;
	int				frks_taken;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*meals_lock;
	pthread_mutex_t	*clock_lock;
	int				*start;
	struct s_philo	*next;
	struct s_philo	*prev;
}				t_philo;

typedef struct s_overseer
{
	pthread_t		thread;
	int				num_of_philos;
	long			meals_to_eat;
	int				*dead;
	int				*full;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*meals_lock;
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*clock_lock;
	t_philo			*philos;
}				t_overseer;

typedef struct s_data
{
	int				num_of_philos;
	int				dead;
	int				full;
	int				start;
	long			start_time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	meals_lock;
	pthread_mutex_t	clock_lock;
	t_overseer		*overseer;
	t_philo			*philos;
}				t_data;

// Initialization
int		init(t_data *data, char **argv);

// Numbers
long	ft_atol(const char *str);
char	*ft_ltoa(long n);
size_t	longlen(long n);

// Errors
int		n_too_big(long n, char *str);
int		n_too_small(void);
int		not_n(void);
int		zero_check(long n, int i);

// Philo
t_philo	*first_philo(t_philo *philo);
t_philo	*last_philo(t_philo *philo);
void	link_to_data(t_data *data, t_philo *philo);
long	p_get_time(t_philo *philo);

// Print
void	print_eat(t_philo *philo);
void	print_fork(t_philo *philo);
void	print_sleep(t_philo *philo);
void	print_think(t_philo *philo);
void	print_death(t_philo *philo);

// Routine
int		overseer(void *ptr);
void	*philo_routine(void *ptr);
void	set_frks(t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	nap(t_philo *philo);
void	die(t_philo *philo);
void	ft_usleep(long time);
void	p_usleep(t_philo *philo, unsigned long time);
void	update_meals(t_philo *philo);
int		should_die(t_philo *philo);
// Checks
int		alive_and_hungry(t_philo *philo);
int		organised(t_philo *philo);
int		hungry(t_philo *philo);
int		dead(t_philo *philo);
int		full(t_philo *philo);
// Utils
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		is_num(char *str);
long	get_time(void);
void	ft_free(void **ptr);
void	kill(t_data *data);
void	lock(pthread_mutex_t *lock);
void	unlock(pthread_mutex_t *lock);
void	destroy(pthread_mutex_t *lock);
void	lock_forks(t_philo *philo);
void	unlock_forks(t_philo *philo);

// Debug
void	p_philo(t_philo *philo);
void	p_philos(t_data *data);
void	e_lock(pthread_mutex_t *lock, t_philo *philo, char *s);
void	e_unlock(pthread_mutex_t *lock, t_philo *philo, char *s);

#endif
