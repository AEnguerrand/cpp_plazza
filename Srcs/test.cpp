#include "NamedPipe.hpp"

int main(int ac, char **av)
{
  if (av[1])
    NamedPipe np(av[1]);
  return (0);
}
