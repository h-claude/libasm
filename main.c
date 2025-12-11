/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:58:07 by hclaude           #+#    #+#             */
/*   Updated: 2025/12/02 16:01:32 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int some_function(int a, int b);
int ft_strlen(const char *str);
int ft_write(int fd, const void *buf, size_t count);
int ft_read(int fd, void *buf, size_t count);

int	main(void)
{
	int result = some_function(5, 1000);
	char str[50];
	sprintf(str, "Result: %d", result);
	int len = ft_write(1, str, strlen(str));
	printf(" the lengh is %d\n", len);
	char buffer[100];
	int bytes_read = ft_read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read >= 0)
	{
		buffer[bytes_read] = '\0'; // Null-terminate the string
		ft_write(1, "Read from stdin: ", 17);
		ft_write(1, buffer, bytes_read);
	}
	return (EXIT_SUCCESS);
}