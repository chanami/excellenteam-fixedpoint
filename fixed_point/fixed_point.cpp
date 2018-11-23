#include "fixed_point.h"
int power1 (int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if ((y % 2) == 0)
        return power1 (x, y / 2) * power1 (x, y / 2);
    else
        return x * power1 (x, y / 2) * power1 (x, y / 2);

}