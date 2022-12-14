/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:44:35 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/30 12:19:12 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_action(t_info *info, t_philo *philo, char *string)
{
    int         dif;

    dif = timestamp() - info->first_timestamp;
    if(!check_dead(info))
        return (0);
    printf("%d %d %s\n", dif, philo->id, string);
    return (1);
}

int	print_selection (t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->l_fork]);
	print_action(info, philo, "has taken a fork");
	pthread_mutex_lock(&info->forks[philo->r_fork]);
	print_action(info, philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex);
	print_action(info, philo, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&philo->mutex);
	info->all_ate++;
	pthread_mutex_unlock(&info->forks[philo->l_fork]);
	pthread_mutex_unlock(&info->forks[philo->r_fork]);
	usleep(info->tmp_eat*1000);
	pthread_mutex_lock(&philo->mutex);
	print_action(info, philo, "is sleeping");
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

// void	accounting_time(int	act, t_info *info)
// {
// 	long long	time;

// 	time = timestamp();
// 	info->
// }