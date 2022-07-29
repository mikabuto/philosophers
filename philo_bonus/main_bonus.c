/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:44:25 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/29 15:46:22 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int agc, char **argv)
{
	t_data	data;

	if (agc != 5 && agc != 6)
		return (printf("Error: Wrong amount of arguments\n"));
	if (parsing(&data, argv))
		return (printf("Error: Init error\n"));
	if (simulation(&data))
		return (printf("Error: Thread error\n"));
	free(data.philo);
	return (0);
}
