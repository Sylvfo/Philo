/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:21:40 by sforster          #+#    #+#             */
/*   Updated: 2024/12/04 11:21:40 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> 
# include <stdio.h> 
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>

# define BLUE		"\001\033[0;34m\002"
# define ORCHID		"\001\033[38;5;170m\002" 
# define CYAN		"\001\033[0;36m\002"
# define PURPLE		"\001\033[0;35m\002"
# define GRAY		"\001\033[1;90m\002"
# define RESET  	"\001\033[0m\002"
# define SKY		"\033[1;36m"

# define ARGV_NB_PHILO 1
# define ARGV_T_DIE 2
# define ARGV_T_EAT 3
# define ARGV_T_SLEEP 4
# define ARGV_DINNERS 5 

typedef struct s_times {
	int					nbr_philo;
	size_t				to_eat;
	size_t				to_sleep;
	size_t				to_die;
	struct timeval		tv_time_start;
	int					nb_philo_fed;
	pthread_mutex_t		*mutex_philo_fed;
	bool				end;
	pthread_mutex_t		*mutex_end;
	pthread_mutex_t		*mutex_creation;
	pthread_mutex_t		*mutex_philo_print;
}	t_times;

typedef struct s_philo {
	int				number;
	pthread_mutex_t	*right_fork;
	int				right_fork_state;
	pthread_mutex_t	*left_fork;
	int				*left_fork_state;
	size_t			time_to_death_lachesis;
	pthread_mutex_t	*mutex_time_to_die;
	int				nbr_of_dinners;
	bool			count_dinner;
	int				turn;
	pthread_t		*philo_thread;
	t_times			*times;
}	t_philo;

typedef enum s_philo_state
{
	EAT = 0,
	SLEEP,
	THINK,
}	t_philo_state;

typedef enum s_fork_state
{
	CLEAN = 0,
	TAKEN,
	DIRTY,
	PASS,
}	t_fork_state;

//////////// PARSING ////////////
// main_parsing.c
t_philo	**parsing(int argc, char **argv);

// checking_arguments.c
bool	check_arguments(int argc, char **argv);
bool	check_nb_arguments(int argc);
bool	check_args_is_digit(char **arg);
bool	check_max_int(size_t *data);
bool	check_nb_philo(size_t *data);

// create_datas.c
bool	init_datas(char **argv, t_philo **philo);
bool	init_philo(char **argv, t_philo **philo, t_times *times_to);
t_philo	*new_philo(int i, t_times *times_to);
t_times	*init_general_datas(char **argv);

//init_mutex.c
bool	init_philo_mutex(t_philo *philo);
bool	init_general_mutex(t_times *times_to);

// utils_parsing.c
size_t	*atoi_args(char **argv);
size_t	ft_atoi(const char *str);
bool	check_len_argv(char **arg);

//////////// START ////////////
//share_forks.c
void	share_forks(t_philo **philo);
void	forks_initilization(t_philo **philo);
void	init_state_forks(t_philo **philo);

// start_simulation.c
void	lauching_even(t_philo **philo);
void	lauching_odd(t_philo **philo);
void	start_simulation(t_philo **philo);
void	init_time(t_philo **philo);

// monitoring.c 
void	monitoring(t_philo	**philo);
bool	end_of_dinners(t_philo *philo);
bool	check_time(t_philo	**philo);

//////////// ROUTINE ////////////
// routine_main.c
void	*routine_even(void *arg);
void	*routine_odd(void *arg);

//routine_utils.c
void	time_before_dying(t_philo *philo);
bool	check_not_end(t_philo *philo);
size_t	get_timestamp(struct timeval start);
void	usleep_sharped(size_t time_to_sleep);

// routine_action.c
bool	philo_eat(t_philo *philo);
bool	philo_sleep(t_philo *philo);
bool	philo_think(t_philo *philo);
bool	philo_exe(t_philo *philo);

// order_monitoring.c
void	change_turn(t_philo *philo);
bool	philo_wait(t_philo *philo);
bool	philo_pass(t_philo *philo);

//forks_management.c
bool	take_right_fork(t_philo *philo);
bool	take_left_fork(t_philo *philo);
void	leave_forks(t_philo *philo);
bool	clean_right_fork(t_philo *philo);
bool	clean_left_fork(t_philo *philo);

// routine_turn.c
bool	turn_is_even(t_philo *philo);
bool	last_turn(t_philo *philo);

//print_state.c
void	print_state(t_philo *philo, int state);

//////////// END ////////////
// finalization.c
void	finilize_simulation(t_philo **philo);
void	destroy_general_mutex(t_times *general);
void	destroy_mutex_philo(t_philo **philo, int nb_philo);
void	free_philo(t_philo **philo, int nb_philo);
void	free_philo_init(t_philo **philo);

// end_simulation.c
void	end_simulation(t_philo **philo);

#endif