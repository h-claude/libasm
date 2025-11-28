/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:58:07 by hclaude           #+#    #+#             */
/*   Updated: 2025/11/28 19:11:16 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int some_function(int a, int b);

int main(void)
{
	int result = some_function(5, 10);
	printf("Result: %d\n", result);
	return (EXIT_SUCCESS);
}