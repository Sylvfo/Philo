/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:04:56 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:17:25 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_pass(t_philo *philo)
{
	while (check_not_end(philo) == true)
	{
		usleep(10);
		pthread_mutex_lock(philo->right_fork);
		if (philo->right_fork_state == PASS)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (true);
		}
		pthread_mutex_unlock(philo->right_fork);
	}
	return (false);
}

bool	philo_wait(t_philo *philo)
{
	if (clean_left_fork(philo) == false)
		return (false);
	if (clean_right_fork(philo) == false)
		return (false);
	return (true);
}

void	change_turn(t_philo *philo)
{
	philo->turn++;
	if (philo->turn > philo->times->nbr_philo)
		philo->turn = 1;
}
