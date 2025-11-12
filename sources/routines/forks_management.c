/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:27:39 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:20:09 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_right_fork(t_philo *philo)
{
	while (check_not_end(philo) == true)
	{
		pthread_mutex_lock(philo->right_fork);
		if (philo->right_fork_state == CLEAN)
		{
			philo->right_fork_state = TAKEN;
			pthread_mutex_unlock(philo->right_fork);
			return (true);
		}
		pthread_mutex_unlock(philo->right_fork);
		usleep(10);
	}
	return (false);
}

bool	take_left_fork(t_philo *philo)
{
	while (check_not_end(philo) == true)
	{
		pthread_mutex_lock(philo->left_fork);
		if (*philo->left_fork_state == CLEAN)
		{
			*philo->left_fork_state = TAKEN;
			pthread_mutex_unlock(philo->left_fork);
			return (true);
		}
		pthread_mutex_unlock(philo->left_fork);
		usleep(10);
	}
	return (false);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	philo->right_fork_state = DIRTY;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	if (philo->times->nbr_philo % 2 != 0
		&& philo->turn == philo->times->nbr_philo - 1)
	{
		*philo->left_fork_state = PASS;
	}	
	else
	{
		*philo->left_fork_state = DIRTY;
	}
	pthread_mutex_unlock(philo->left_fork);
	return ;
}

bool	clean_left_fork(t_philo *philo)
{
	while (check_not_end(philo) == true)
	{
		usleep(10);
		pthread_mutex_lock(philo->left_fork);
		if (*philo->left_fork_state == DIRTY)
		{
			*philo->left_fork_state = CLEAN;
			pthread_mutex_unlock(philo->left_fork);
			return (true);
		}
		pthread_mutex_unlock(philo->left_fork);
	}
	return (false);
}

bool	clean_right_fork(t_philo *philo)
{
	while (check_not_end(philo) == true)
	{
		usleep(10);
		pthread_mutex_lock(philo->right_fork);
		if (philo->right_fork_state == PASS)
		{
			philo->right_fork_state = CLEAN;
			pthread_mutex_unlock(philo->right_fork);
			return (true);
		}
		else if (philo->right_fork_state == DIRTY)
		{
			(philo->right_fork_state = CLEAN);
			pthread_mutex_unlock(philo->right_fork);
			return (true);
		}
		pthread_mutex_unlock(philo->right_fork);
	}
	return (false);
}
