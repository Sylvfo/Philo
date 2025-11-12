/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:59:58 by sforster          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:58 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, int state)
{
	size_t	timestamp;

	timestamp = get_timestamp(philo->times->tv_time_start);
	pthread_mutex_lock(philo->times->mutex_philo_print);
	if (state == EAT && check_not_end(philo) == true)
	{
		printf(BLUE "%li %i has taken a fork\n" RESET, timestamp, philo->number);
		printf(ORCHID "%li %i is eating\n" RESET, timestamp, philo->number);
	}
	else if (state == SLEEP && check_not_end(philo) == true)
	{
		printf(CYAN "%li %i is sleeping\n" RESET, timestamp, philo->number);
	}
	else if (state == THINK && check_not_end(philo) == true)
	{
		printf(PURPLE "%li %i is thinking\n" RESET, timestamp, philo->number);
	}
	pthread_mutex_unlock(philo->times->mutex_philo_print);
}
