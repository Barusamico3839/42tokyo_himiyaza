/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:23:19 by felixtanhm        #+#    #+#             */
/*   Updated: 2025/03/30 15:58:31 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
  int i = 0;

  while(argv[0][i] != '\0' && argc)
  {
    write(1,&argv[0][i],1);
    i++;
  }
  write(1,"\n",1);
  return (0);
}
