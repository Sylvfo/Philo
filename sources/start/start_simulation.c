/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:41:18 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:11:17 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philo **philo)
{
	if (philo[0]->times->nbr_philo % 2 == 0)
		lauching_even(philo);
	else if (philo[0]->times->nbr_philo % 2 != 0)
		lauching_odd(philo);
}

void	lauching_even(t_philo **philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo[0]->times->mutex_creation);
	while (i < philo[0]->times->nbr_philo)
	{
		pthread_create(philo[i]->philo_thread, NULL, &routine_even, philo[i]);
		i++;
	}
	gettimeofday(&philo[0]->times->tv_time_start, NULL);
	init_time(philo);
	pthread_mutex_unlock(philo[0]->times->mutex_creation);
}

void	lauching_odd(t_philo **philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo[0]->times->mutex_creation);
	while (i < philo[0]->times->nbr_philo)
	{
		pthread_create(philo[i]->philo_thread, NULL, &routine_odd, philo[i]);
		i++;
	}
	gettimeofday(&philo[0]->times->tv_time_start, NULL);
	init_time(philo);
	pthread_mutex_unlock(philo[0]->times->mutex_creation);
}

void	init_time(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->times->nbr_philo)
	{
		time_before_dying(philo[i]);
		i++;
	}
}
