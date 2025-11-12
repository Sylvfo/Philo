/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:57:59 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 11:49:12 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->times->nbr_philo)
	{
		pthread_join(*philo[i]->philo_thread, NULL);
		i++;
	}
}
