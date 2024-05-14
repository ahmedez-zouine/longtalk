#include "minitalk_bonus.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		bit = 0;
		c = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}

int main(void)
{
	struct sigaction sact;

	write (1, "pid :", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sact.sa_sigaction = ft_handler;
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
