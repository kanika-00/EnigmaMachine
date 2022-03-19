#include "util.h"
int mod(int a, int b)
{
    return (a >= 0 || a % b == 0) ? (a % b) : (b + a % b);
}