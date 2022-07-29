/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:10:56 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/29 15:29:15 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = data->philo_num;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
	if (data->forks == NULL)
		return (1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->write), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	if (pthread_mutex_init(&(data->all_ate_m), NULL))
		return (1);
	if (pthread_mutex_init(&(data->died_m), NULL))
		return (1);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = data->philo_num;
	data->philosophers = (t_philo *)malloc(sizeof(t_philo) * i);
	if (data->philosophers == NULL)
		return (1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->philosophers[i].x_ate_m), NULL))
			return (1);
		data->philosophers[i].id = i;
		data->philosophers[i].x_ate = 0;
		data->philosophers[i].t_last_meal = 0;
		data->philosophers[i].data = data;
		data->philosophers[i].left_fork_id = \
			ft_min(i, (i + 1) % data->philo_num);
		data->philosophers[i].right_fork_id = \
			ft_max(i, (i + 1) % data->philo_num);
	}
	return (0);
}

int	parsing(t_data *data, char **s)
{
	data->philo_num = ft_atoi(s[1]);
	data->time_death = ft_atoi(s[2]);
	data->time_eat = ft_atoi(s[3]);
	data->time_sleep = ft_atoi(s[4]);
	data->died = 0;
	data->all_ate = 0;
	if (data->philo_num < 1 || data->time_death < 0
		|| data->time_eat < 0 || data->time_sleep < 0)
		return (1);
	if (s[5])
	{
		data->num_eat = ft_atoi(s[5]);
		if (data->num_eat <= 0)
			return (1);
	}
	else
		data->num_eat = -1;
	if (init_mutex(data) || init_philo(data))
		return (1);
	return (0);
}
