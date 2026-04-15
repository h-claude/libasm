/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:58:07 by hclaude           #+#    #+#             */
/*   Updated: 2026/04/15 16:02:50 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

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

	int ret;

	printf(BOLD CYAN "\n=== ft_read / ft_write (bad fd) ===\n" RESET);
	errno = 0; ret = ft_read(10, buffer, sizeof(buffer));
	printf("ft_read  (bad fd): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));
	errno = 0; ret = (int)read(10, buffer, sizeof(buffer));
	printf("read     (bad fd): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));
	errno = 0; ret = ft_write(10, buffer, sizeof(buffer));
	printf("ft_write (bad fd): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));
	errno = 0; ret = (int)write(10, buffer, sizeof(buffer));
	printf("write    (bad fd): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));

	printf(BOLD CYAN "\n=== ft_read / ft_write (NULL buffer) ===\n" RESET);
	errno = 0; ret = ft_read(0, NULL, sizeof(buffer));
	printf("ft_read  (NULL): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));
	errno = 0; ret = (int)read(0, NULL, sizeof(buffer));
	printf("read     (NULL): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));
	errno = 0; ret = ft_write(1, NULL, sizeof(buffer));
	printf("ft_write (NULL): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));
	errno = 0; ret = (int)write(1, NULL, sizeof(buffer));
	printf("write    (NULL): " RED "%d" RESET " errno: " YELLOW "%d (%s)" RESET "\n", ret, errno, strerror(errno));

	printf(BOLD CYAN "\n=== ft_read / ft_strlen (stdin) ===\n" RESET);
	int bytes_read = ft_read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read >= 0)
	{
		buffer[bytes_read] = '\0';
		printf("Read from stdin: " GREEN "%s" RESET, buffer);
		printf("ft_strlen : " GREEN "%d" RESET "\n", ft_strlen(buffer));
		printf("strlen    : " GREEN "%zu" RESET "\n", strlen(buffer));
	}

	printf(BOLD CYAN "\n=== ft_strcmp ===\n" RESET);
	char *cmp_str1 = "Hello";
	char *cmp_str2 = "Hell";
	int cmp_result_mine = ft_strcmp(cmp_str1, cmp_str2);
	int cmp_result_original = strcmp(cmp_str1, cmp_str2);
	printf("ft_strcmp(\"%s\", \"%s\"): " YELLOW "%d" RESET "\n", cmp_str1, cmp_str2, cmp_result_mine);
	printf("strcmp   (\"%s\", \"%s\"): " YELLOW "%d" RESET "\n", cmp_str1, cmp_str2, cmp_result_original);

	// test with NULL parameters
	//printf(BOLD CYAN "\n=== ft_strcmp (NULL) ===\n" RESET);
	//printf("ft_strcmp (NULL, \"%s\"): " RED "%d" RESET " (expected -1)\n", cmp_str2, ft_strcmp(NULL, cmp_str2));
	//printf("ft_strcmp (\"%s\", NULL): " RED "%d" RESET " (expected -1)\n", cmp_str1, ft_strcmp(cmp_str1, NULL));
	//printf("ft_strcmp (NULL, NULL): " RED "%d" RESET " (expected -1)\n", ft_strcmp(NULL, NULL));
	//printf("strcmp    (NULL, \"%s\"): " RED "%d" RESET " (expected -1)\n", cmp_str2, strcmp(NULL, cmp_str2));
	//printf("strcmp   (\"%s\", NULL): " RED "%d" RESET " (expected -1)\n", cmp_str1, strcmp(cmp_str1, NULL));
	//printf("strcmp  (NULL, NULL): " RED "%d" RESET " (expected -1)\n", strcmp(NULL, NULL));

	printf(BOLD CYAN "\n=== ft_strcpy ===\n" RESET);
	char dest[50];
	char *src = "This is a test string.";
	ft_strcpy(dest, src);
	printf("Copied string: " GREEN "%s" RESET "\n", dest);

	printf(BOLD CYAN "\n=== ft_strdup ===\n" RESET);
	char *original = "Duplicate me!";
	char *duplicate = ft_strdup(original);
	printf("Original : " GREEN "%s" RESET "\n", original);
	printf("Duplicate: " GREEN "%s" RESET "\n", duplicate);
	printf("ft_strdup(NULL): " RED "%s" RESET " (expected NULL)\n", ft_strdup(NULL));

	printf(BOLD CYAN "\n=== ft_write vs write ===\n" RESET);
	sprintf(str, "Original: %s\nDuplicate: %s\n", original, duplicate);
	printf("ft_write output: " RESET);
	fflush(stdout);
	ft_write(1, str, strlen(str));
	printf("write    output: " RESET);
	fflush(stdout);
	write(1, str, strlen(str));
	free(duplicate);

	return (EXIT_SUCCESS);
}