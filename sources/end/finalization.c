/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:06:27 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 15:45:57 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finilize_simulation(t_philo **philo)
{
	int	nb_philo;

	nb_philo = philo[0]->times->nbr_philo;
	destroy_general_mutex(philo[0]->times);
	destroy_mutex_philo(philo, nb_philo);
	free_philo(philo, nb_philo);
	free (philo);
}

void	destroy_general_mutex(t_times *general)
{
	if (general->mutex_creation)
	{
		pthread_mutex_destroy(general->mutex_creation);
		free(general->mutex_creation);
	}	
	if (general->mutex_end)
	{
		pthread_mutex_destroy(general->mutex_end);
		free(general->mutex_end);
	}
	if (general->mutex_philo_fed)
	{
		pthread_mutex_destroy(general->mutex_philo_fed);
		free(general->mutex_philo_fed);
	}
	if (general->mutex_philo_print)
	{
		pthread_mutex_destroy(general->mutex_philo_print);
		free(general->mutex_philo_print);
	}
	free(general);
}

void	destroy_mutex_philo(t_philo **philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo && philo[i] != NULL)
	{
		pthread_mutex_destroy(philo[i]->mutex_time_to_die);
		pthread_mutex_destroy(philo[i]->right_fork);
		i++;
	}
}

void	free_philo(t_philo **philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo && philo[i] != NULL)
	{
		philo[i]->times = NULL;
		free(philo[i]->mutex_time_to_die);
		free(philo[i]->right_fork);
		free(philo[i]->philo_thread);
		philo[i]->left_fork = NULL;
		free(philo[i]);
		i++;
	}
}

void	free_philo_init(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i] != NULL)
	{
		philo[i]->times = NULL;
		free(philo[i]->mutex_time_to_die);
		free(philo[i]->right_fork);
		free(philo[i]->philo_thread);
		philo[i]->left_fork = NULL;
		free(philo[i]);
		i++;
	}
}
