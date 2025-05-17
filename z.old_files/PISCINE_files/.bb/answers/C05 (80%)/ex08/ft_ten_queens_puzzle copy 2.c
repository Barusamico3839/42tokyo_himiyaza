/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle copy 2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:34:05 by rteles            #+#    #+#             */
/*   Updated: 2025/03/30 22:16:55 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

int check(int pos, int *temp, int value)
{
  int i;

  i = 0;
  while (i < pos)
  {
    if (value == temp[i])
      return (0);
    if (value == temp[i] + pos - i && temp[i] + pos - i < 10)
    {
      return (0);
    }
    if (value == temp[i] - (pos - i) && temp[i] - (pos - i) > -1)
    {
      return (0);
    }
    i++;
  }
  return (1);
}

void ft_print(int *temp)
{
  int i;
  int print;

  i = 0;
  while (i < 10)
  {
    print = temp[i] + '0';
    write(1, &print, 1);
    i++;
  }
  write(1, "\n", 1);
}

int recursive(int pos, int *temp, int count)
{
  int i;

  i = 0;
  while (i <= 9)
  {
    if (check(pos, temp, i))
    {
      temp[pos] = i;
      if (pos == 9)
      {
        ft_print(temp);
        return (count + 1);
      }
      count = recursive(pos + 1, temp, count);
    }
    i++;
  }
return (count);
}

int ft_ten_queens_puzzle(void)
{
  int temp[10];

  return (recursive(0, temp, 0));
}

int main (void)
{
	ft_ten_queens_puzzle();
}
