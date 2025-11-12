/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:21:50 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 11:21:50 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_datas(char **argv, t_philo **philo)
{
	t_times	*times_to;

	times_to = init_general_datas(argv);
	if (times_to == NULL)
	{
		destroy_general_mutex(philo[0]->times);
		free (philo);
		return (false);
	}
	if (init_philo(argv, philo, times_to) == false)
	{
		destroy_general_mutex(philo[0]->times);
		free_philo(philo, 300);
		free (philo);
		return (false);
	}
	return (true);
}

bool	init_philo(char **argv, t_philo **philo, t_times *times_to)
{
	int	i;

	i = 0;
	while (i < times_to->nbr_philo)
	{
		philo[i] = new_philo(i, times_to);
		if (!philo[i])
			return (false);
		if (init_philo_mutex(philo[i]) == false)
		{
			destroy_mutex_philo(philo, i);
			return (false);
		}	
		if (argv[ARGV_DINNERS])
		{
			philo[i]->count_dinner = true;
			philo[i]->nbr_of_dinners = ft_atoi(argv[ARGV_DINNERS]);
		}
		else
			philo[i]->count_dinner = false;
		i++;
	}
	return (true);
}

t_philo	*new_philo(int i, t_times *times_to)
{
	t_philo	*new_node;

	new_node = malloc(sizeof(t_philo));
	if (!new_node)
		return (NULL);
	new_node->number = i + 1;
	new_node->turn = i + 1;
	new_node->nbr_of_dinners = 100;
	new_node->times = times_to;
	new_node->right_fork_state = CLEAN;
	new_node->left_fork = NULL;
	return (new_node);
}

t_times	*init_general_datas(char **argv)
{
	t_times		*times_to;
	size_t		*data;

	times_to = malloc(sizeof(t_times));
	if (!times_to)
		return (NULL);
	data = atoi_args(argv);
	times_to->nbr_philo = data[ARGV_NB_PHILO];
	times_to->end = false;
	times_to->nb_philo_fed = 0;
	times_to->to_die = data[ARGV_T_DIE];
	times_to->to_eat = data[ARGV_T_EAT];
	times_to->to_sleep = data[ARGV_T_SLEEP];
	if (init_general_mutex(times_to) == false)
	{
		free (times_to);
		return (false);
	}
	free(data);
	return (times_to);
}
