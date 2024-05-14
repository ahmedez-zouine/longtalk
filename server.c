/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:26:40 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/05/14 16:35:44 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit_handler(int signbr, siginfo_t *info, void *context)
{
	static char	res;
	static int	i;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		res = 0;
		i = 0;
	}
	if (signbr == SIGUSR1)
		res = res | (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &res, 1);
		i = 0;
		res = 0;
	}
}

int	main(void)
{
	int	pid;
	struct sigaction sact;

	pid = getpid();
	write(1, "pid :", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sact.sa_sigaction = ft_bit_handler;
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
