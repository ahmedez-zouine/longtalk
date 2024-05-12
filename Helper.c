/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:12:58 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/05/12 11:34:21 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi_of(char *nbr)
{
	int			sign;
	int			i;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\v' || nbr[i] == '\f'
		|| nbr[i] == '\r' || nbr[i] == ' ')
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = (res * 10) + (nbr[i++] - '0');
		if (res > INT_MAX || res < INT_MIN)
			return (0);
	}
	return (res * sign);
}

void	ft_sendbits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

void	ft_putnbr(int nb)
{
	char	c;
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write (1, &c, 1);
}