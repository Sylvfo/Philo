/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:53:32 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:06:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_eat(t_philo *philo)
{
	if (take_right_fork(philo) == false)
		return (false);
	if (take_left_fork(philo) == false)
		return (false);
	time_before_dying(philo);
	if (check_not_end(philo) == false)
		return (false);
	print_state(philo, EAT);
	if (philo->count_dinner == true)
		philo->nbr_of_dinners--;
	usleep_sharped(philo->times->to_eat);
	leave_forks(philo);
	return (true);
}

bool	philo_sleep(t_philo *philo)
{
	if (check_not_end(philo) == false)
		return (false);
	print_state(philo, SLEEP);
	usleep_sharped(philo->times->to_sleep);
	return (true);
}

bool	philo_think(t_philo *philo)
{
	if (check_not_end(philo) == false)
		return (false);
	print_state(philo, THINK);
	return (true);
}

bool	philo_exe(t_philo *philo)
{
	if (philo_eat(philo) == false)
		return (false);
	if (philo_sleep(philo) == false)
		return (false);
	if (philo_think(philo) == false)
		return (false);
	if (end_of_dinners(philo) == false)
		return (false);
	return (true);
}
