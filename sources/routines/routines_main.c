/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:05:31 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 19:19:55 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_even(void *arg)
{
	pthread_mutex_lock(((t_philo *)arg)->times->mutex_creation);
	pthread_mutex_unlock(((t_philo *)arg)->times->mutex_creation);
	while (check_not_end((t_philo *)arg) == true)
	{
		if (((t_philo *)arg)->nbr_of_dinners == 0)
			break ;
		if (turn_is_even(((t_philo *)arg)) == true)
		{
			if (philo_exe(((t_philo *)arg)) == false)
				return (0);
		}		
		else if (turn_is_even(((t_philo *)arg)) == false)
		{
			if (philo_wait(((t_philo *)arg)) == false)
				return (0);
		}
		change_turn((t_philo *)arg);
	}
	end_of_dinners(((t_philo *)arg));
	return (0);
}

void	*routine_odd(void *arg)
{
	pthread_mutex_lock(((t_philo *)arg)->times->mutex_creation);
	pthread_mutex_unlock(((t_philo *)arg)->times->mutex_creation);
	while (check_not_end((t_philo *)arg) == true)
	{
		if (((t_philo *)arg)->nbr_of_dinners == 0)
			break ;
		if (turn_is_even(((t_philo *)arg)) == true
			&& philo_exe(((t_philo *)arg)) == false)
			return (0);
		else if (turn_is_even((t_philo *)arg) == false
			&& last_turn((t_philo *)arg) == false)
		{
			if (philo_wait(((t_philo *)arg)) == false)
				return (0);
		}
		else if (last_turn((t_philo *)arg) == true)
		{
			if (philo_pass((t_philo *)arg) == false)
				return (0);
		}	
		change_turn((t_philo *)arg);
	}
	end_of_dinners(((t_philo *)arg));
	return (0);
}
