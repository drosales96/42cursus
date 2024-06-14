/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:11:44 by drosales          #+#    #+#             */
/*   Updated: 2024/05/29 13:47:52 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main() {
    int     fd;
    int     fd2;
    int     fd3;
    char    *next_line;
    int     count;

    count = 0;
    fd = open("example1.txt", O_RDONLY);
    fd2 = open("example2.txt", O_RDONLY);
    fd3 = open("example3.txt", O_RDONLY);
    if (fd == -1 || fd2 == -1 || fd3 == -1) 
    {
        perror("Error al abrir archivo");
        return 1;
    }

    while ((next_line = get_next_line(fd)) != NULL) {
        count++;
        printf("[%d]: %s\n", count, next_line);
        free(next_line);
    }

    while ((next_line = get_next_line(fd2)) != NULL) {
        count++;
        printf("[%d]: %s\n", count, next_line);
        free(next_line);
    }

    while ((next_line = get_next_line(fd3)) != NULL) {
        count++;
        printf("[%d]: %s\n", count, next_line);
        free(next_line);
    }

    if (close(fd) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }

    if (close(fd2) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }

    if (close(fd3) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }
    return 0;
}
