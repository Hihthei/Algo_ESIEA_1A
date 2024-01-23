int minimum3(int a, int b, int c)
{
    if ((a <= b) && (a <= c)) int min = a;
    else if ((b <= a) && (b <= c)) int min = b;
    else if ((c <= a) && (c <= b)) int min = c;

    return min;
}