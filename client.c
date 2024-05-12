/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:11:31 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/05/12 11:38:11 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **argv)
{
	size_t	i;
	int	pid;
	char	*string;

	if (ac != 3)
	{
		write(1, "Try Use the Argmant like [IPD] [MSG]\n",37); 
		return (1);
	}
	i = 0;
	pid = ft_atoi_of((char *)argv[1]);
	if (pid == 0 || pid == -1)
		return (1);
	else
	{
		string = argv[2];
		while (string[i])
			ft_sendbits(pid, string[i++]);
		ft_sendbits(pid, '\0');
		ft_sendbits(pid, '\n');
	}
	return (0);
}
