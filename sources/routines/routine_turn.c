/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:09:23 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 19:19:33 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	turn_is_even(t_philo *philo)
{
	if (philo->turn % 2 == 0)
		return (true);
	return (false);
}

bool	last_turn(t_philo *philo)
{
	if (philo->turn == philo->times->nbr_philo)
		return (true);
	return (false);
}
