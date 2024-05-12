/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:27:23 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/05/12 11:35:04 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <unistd.h>

void	ft_bit_handler(int sig);
void	ft_sendbits(int pid, char c);
int	ft_atoi_of(char *str);
void	ft_putnbr(int nb);

#endif
