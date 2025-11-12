/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parcing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:31:38 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 16:22:44 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	*atoi_args(char **argv)
{
	int		i;
	int		j;
	size_t	*data;

	data = NULL;
	data = malloc(6 * sizeof(size_t));
	if (!data)
		return (NULL);
	i = 0;
	j = 0;
	while (j <= 4)
	{
		data[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	if (!argv[ARGV_DINNERS])
		data[ARGV_DINNERS] = 100;
	if (argv[ARGV_DINNERS])
		data[ARGV_DINNERS] = ft_atoi(argv[ARGV_DINNERS]);
	return (data);
}

size_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

bool	check_len_argv(char **arg)
{
	int	i;
	int	j;

	j = 1;
	while (j <= 4)
	{
		i = 0;
		while (arg[j][i])
			i++;
		if (i > 10)
			return (false);
		j++;
	}
	if (arg[ARGV_DINNERS])
	{
		i = 0;
		while (arg[ARGV_DINNERS][i])
			i++;
		if (i > 10)
			return (false);
	}
	return (true);
}
