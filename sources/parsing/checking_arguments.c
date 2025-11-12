/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:47 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 17:40:34 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_arguments(int argc, char **argv)
{
	size_t	*arguments;

	arguments = NULL;
	if (check_nb_arguments(argc) == false)
		return (false);
	if (check_args_is_digit(argv) == false)
	{
		printf(SKY "Please enter only positive integer\n" RESET);
		return (false);
	}
	if (check_len_argv(argv) == false)
	{
		printf(SKY "Please enter arguments that do not exceed INT MAX\n" RESET);
		return (false);
	}
	arguments = atoi_args(argv);
	if (check_nb_philo(arguments) == false)
		return (false);
	if (check_max_int(arguments) == false)
	{
		printf(SKY "Please enter arguments that do not exceed INT MAX\n" RESET);
		return (false);
	}
	free(arguments);
	return (true);
}

bool	check_nb_philo(size_t *data)
{
	if (data[ARGV_NB_PHILO] == 0)
	{
		printf(SKY "No philosopher, No dinner! Bye!\n" RESET);
		free (data);
		return (false);
	}
	return (true);
}

bool	check_max_int(size_t *data)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (data[i] >= (size_t)INT_MAX)
		{
			free (data);
			return (false);
		}	
		i++;
	}
	if (data[ARGV_DINNERS] != 0)
	{
		if (data[ARGV_DINNERS] >= INT_MAX)
		{
			free (data);
			return (false);
		}
	}
	return (true);
}

bool	check_nb_arguments(int argc)
{
	if (argc == 5 || argc == 6)
	{
		return (true);
	}
	printf(SKY "Usage: number_of_philosophers, time_to_die, time_to_eat, ");
	printf("time_to_sleep, [number_of_times_each_philosopher_must_eat]\n" RESET);
	return (false);
}

bool	check_args_is_digit(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '+' && arg[i][1] == 0)
			return (false);
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] == '+' && j == 0)
				j++;
			else if (arg[i][j] >= 48 && arg[i][j] <= 57)
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}
