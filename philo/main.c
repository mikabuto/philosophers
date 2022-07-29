/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:06:33 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/29 15:30:33 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int agc, char **argv)
{
	t_data	data;

	if (agc != 5 && agc != 6)
		return (write_error("Wrong amount of arguments"));
	if (parsing(&data, argv))
		return (write_error("Init error"));
	if (simulation(&data))
		return (write_error("Thread error"));
	free(data.forks);
	free(data.philosophers);
	return (0);
}
