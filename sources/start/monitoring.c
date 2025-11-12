/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:59:36 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:11:10 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo	**philo)
{
	while (1)
	{
		pthread_mutex_lock(philo[0]->times->mutex_end);
		if (philo[0]->times->end == true)
		{
			pthread_mutex_unlock(philo[0]->times->mutex_end);
			return ;
		}
		pthread_mutex_unlock(philo[0]->times->mutex_end);
		usleep(10);
		if (check_time(philo) == false)
			return ;
	}
}

bool	check_time(t_philo	**philo)
{
	int		i;
	size_t	timenow;

	i = 0;
	timenow = get_timestamp(philo[0]->times->tv_time_start);
	while (i < philo[0]->times->nbr_philo)
	{
		pthread_mutex_lock(philo[i]->mutex_time_to_die);
		if (timenow >= philo[i]->time_to_death_lachesis
			&& philo[i]->nbr_of_dinners != 0)
		{
			pthread_mutex_unlock(philo[i]->mutex_time_to_die);
			pthread_mutex_lock(philo[i]->times->mutex_end);
			philo[i]->times->end = true;
			pthread_mutex_unlock(philo[i]->times->mutex_end);
			pthread_mutex_lock(philo[0]->times->mutex_philo_print);
			printf(GRAY "%li philo %i died\n" RESET, timenow, philo[i]->number);
			pthread_mutex_unlock(philo[0]->times->mutex_philo_print);
			return (false);
		}
		pthread_mutex_unlock(philo[i]->mutex_time_to_die);
		i++;
	}
	return (true);
}

bool	end_of_dinners(t_philo *philo)
{
	if (philo->nbr_of_dinners != 0)
		return (true);
	pthread_mutex_lock(philo->times->mutex_philo_fed);
	philo->times->nb_philo_fed++;
	if (philo->times->nb_philo_fed == philo->times->nbr_philo)
	{
		pthread_mutex_unlock(philo->times->mutex_philo_fed);
		pthread_mutex_lock(philo->times->mutex_end);
		philo->times->end = true;
		pthread_mutex_unlock(philo->times->mutex_end);
		return (false);
	}
	pthread_mutex_unlock(philo->times->mutex_philo_fed);
	return (true);
}
