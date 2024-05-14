/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:11:31 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/05/14 17:48:52 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbits(int pid, char c)
{
	int	i;
	int	n;

	i = 0;
	while (i < 8)
	{
		n = c & (1 << i);
		if (n)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
}

int	main(int ac, char **argv)
{
	size_t	i;
	int		pid;
	char	*string;

	if (ac != 3)
	{
		write(1, "Try Use the Argmant like [IPD] [MSG]\n", 37);
		exit(1);
	}
	i = 0;
	pid = ft_atoi_of((char *)argv[1]);
	if (pid == 0 || pid == -1)
		exit(1);
	else
	{
		string = argv[2];
		while (string[i])
			ft_sendbits(pid, string[i++]);
		ft_sendbits(pid, '\n');
		ft_sendbits(pid, '\0');
	}
	return (0);
}
