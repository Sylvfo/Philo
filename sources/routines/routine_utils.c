/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:24:38 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:06:58 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_before_dying(t_philo *philo)
{
	size_t	timedie;

	timedie = get_timestamp(philo->times->tv_time_start) + philo->times->to_die;
	pthread_mutex_lock(philo->mutex_time_to_die);
	philo->time_to_death_lachesis = timedie;
	pthread_mutex_unlock(philo->mutex_time_to_die);
}

size_t	get_timestamp(struct timeval start)
{
	struct timeval	current;
	size_t			milliseconds;

	gettimeofday(&current, NULL);
	milliseconds = (current.tv_sec - start.tv_sec) * 1000 \
					+ (current.tv_usec / 1000 - start.tv_usec / 1000);
	return (milliseconds);
}

void	usleep_sharped(size_t time_to_sleep)
{
	struct timeval	start;
	size_t			time_slept;

	if (time_to_sleep == 0)
		return ;
	gettimeofday(&start, NULL);
	time_slept = 0;
	while (time_slept < time_to_sleep)
	{
		usleep((time_to_sleep - time_slept) / 2);
		time_slept = get_timestamp(start);
	}
}

bool	check_not_end(t_philo *philo)
{
	pthread_mutex_lock(philo->times->mutex_end);
	if (philo->times->end == true)
	{
		pthread_mutex_unlock(philo->times->mutex_end);
		return (false);
	}
	pthread_mutex_unlock(philo->times->mutex_end);
	return (true);
}
