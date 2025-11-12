/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:35:07 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:06:47 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**parsing(int argc, char **argv)
{
	t_philo	**philo;

	if (check_arguments(argc, argv) == false)
		return (NULL);
	philo = (t_philo **)malloc(ft_atoi(argv[ARGV_NB_PHILO])
			* sizeof(t_philo *));
	if (!philo)
		return (NULL);
	if (init_datas(argv, philo) == false)
	{
		return (NULL);
	}
	if (philo[0]->count_dinner == true && philo[0]->nbr_of_dinners == 0)
	{
		printf("No dinners... Ciao!\n");
		return (NULL);
	}
	return (philo);
}
