/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:28 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:06:54 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	**philo;

	philo = parsing(argc, argv);
	if (philo == NULL)
		return (0);
	forks_initilization(philo);
	start_simulation(philo);
	monitoring(philo);
	end_simulation(philo);
	finilize_simulation(philo);
	return (0);
}
