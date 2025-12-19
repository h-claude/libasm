/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:58:07 by hclaude           #+#    #+#             */
/*   Updated: 2025/12/19 17:47:59 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(const char *str);
int ft_write(int fd, const void *buf, size_t count);
int ft_read(int fd, void *buf, size_t count);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);

int	main(void)
{
	char str[256];
	char buffer[100];
	int bytes_read = ft_read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read >= 0)
	{
		// test ft_strlen with the read input from stdin
		buffer[bytes_read] = '\0'; // Null-terminate the string
		ft_write(1, "Read from stdin: ", 17);
		ft_write(1, buffer, bytes_read);
		sprintf(str, "\nLength of input with mine: %d\n", ft_strlen(buffer));
		ft_write(1, str, strlen(str));
		sprintf(str, "Length of input with original: %zu\n", strlen(buffer));
		ft_write(1, str, strlen(str));
	}
	// Test ft_strcmp
	char *cmp_str1 = "Hello";
	char *cmp_str2 = "Hell";
	int cmp_result_mine = ft_strcmp(cmp_str1, cmp_str2);
	int cmp_result_original = strcmp(cmp_str1, cmp_str2);
	sprintf(str, "ft_strcmp result: %d\n", cmp_result_mine);
	ft_write(1, str, strlen(str));
	sprintf(str, "strcmp result: %d\n", cmp_result_original);
	ft_write(1, str, strlen(str));

	// Test ft_strcpy
	char dest[50];
	char *src = "This is a test string.";
	ft_strcpy(dest, src);
	sprintf(str, "Copied string: %s\n", dest);
	ft_write(1, str, strlen(str));

	// Test ft_strdup
	char *original = "Duplicate me!";
	char *duplicate = ft_strdup(original);
	sprintf(str, "Original: %s\nDuplicate: %s\n", original, duplicate);
	ft_write(1, str, strlen(str));
	free(duplicate);

	return (EXIT_SUCCESS);
}