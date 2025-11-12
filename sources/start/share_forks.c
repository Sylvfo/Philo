/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:19:36 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 11:19:36 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_initilization(t_philo **philo)
{
	share_forks(philo);
	if (philo[0]->times->nbr_philo % 2 != 0 && philo[0]->times->nbr_philo >= 3)
		init_state_forks(philo);
}

void	share_forks(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (philo[0]->times->nbr_philo - 1))
	{
		philo[i]->left_fork = philo[i + 1]->right_fork;
		philo[i]->left_fork_state = &philo[i + 1]->right_fork_state;
		i++;
	}
	if (philo[0]->times->nbr_philo > 1)
	{
		philo[i]->left_fork = philo[0]->right_fork;
		philo[i]->left_fork_state = &philo[0]->right_fork_state;
	}
}

void	init_state_forks(t_philo **philo)
{
	int	i;

	i = 1;
	philo[0]->right_fork_state = PASS;
	while (i < philo[0]->times->nbr_philo)
	{
		philo[i]->right_fork_state = CLEAN;
		i++;
	}
}
