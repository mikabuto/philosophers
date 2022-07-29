/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:04:43 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/29 15:37:23 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_philo
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_data		*data;
	pthread_t			thread_id;
	pthread_mutex_t		x_ate_m;
}						t_philo;

typedef struct s_data
{
	int					philo_num;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					num_eat;
	int					died;
	int					all_ate;
	long long			start;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write;
	pthread_mutex_t		died_m;
	pthread_mutex_t		all_ate_m;
	t_philo				*philosophers;
}						t_data;

int			parsing(t_data *r, char **s);
int			simulation(t_data *data);
long long	time_now(void);
void		print_action(t_data *data, int id, char *str);
void		ft_sleep(long long time, t_data *data);
int			write_error(char *s);
int			ft_atoi(const char *str);
int			well_fed_philo(t_data *d);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

#endif