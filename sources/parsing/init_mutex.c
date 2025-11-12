/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:23:31 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 15:35:30 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_general_mutex(t_times *times_to)
{
	times_to->mutex_end = malloc(sizeof(pthread_mutex_t));
	if (!times_to->mutex_end)
		return (false);
	pthread_mutex_init(times_to->mutex_end, NULL);
	times_to->mutex_creation = malloc(sizeof(pthread_mutex_t));
	if (!times_to->mutex_creation)
		return (false);
	pthread_mutex_init(times_to->mutex_creation, NULL);
	times_to->mutex_philo_fed = malloc(sizeof(pthread_mutex_t));
	if (!times_to->mutex_philo_fed)
		return (false);
	pthread_mutex_init(times_to->mutex_philo_fed, NULL);
	times_to->mutex_philo_print = malloc(sizeof(pthread_mutex_t));
	if (!times_to->mutex_philo_print)
		return (false);
	pthread_mutex_init(times_to->mutex_philo_print, NULL);
	return (true);
}

bool	init_philo_mutex(t_philo *philo)
{
	philo->mutex_time_to_die = malloc(sizeof(pthread_mutex_t));
	if (!philo->mutex_time_to_die)
		return (false);
	pthread_mutex_init(philo->mutex_time_to_die, NULL);
	philo->right_fork = malloc(sizeof(pthread_mutex_t));
	if (!philo->right_fork)
		return (false);
	pthread_mutex_init(philo->right_fork, NULL);
	philo->philo_thread = malloc(sizeof(pthread_t));
	if (!philo->philo_thread)
		return (false);
	return (true);
}
