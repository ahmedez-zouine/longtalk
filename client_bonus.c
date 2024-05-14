/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:57:11 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/05/14 17:59:35 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_conferm(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message received\n", 17);
}

void	ft_sendbits(int pid, char c)
{
	int	i;
	int	b;

	i = 0;
	while (i <= 7)
	{
		b = c & (1 << i);
		if (b)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	*string;
//hgg
	if (argc != 3)
	{
		write(1, "Error in the Argmnt\n", 20);
		exit(1);
	}
	pid = ft_atoi_of(argv[1]);
	if (pid == 0 || pid == -1)
		exit(1);
	string = argv[2];
	signal(SIGUSR1, ft_conferm);
	i = 0;
	while (string[i])
		ft_sendbits(pid, string[i++]);
	ft_sendbits(pid, '\n');
	ft_sendbits(pid, '\0');
	return (0);
}
