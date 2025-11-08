#include <iostream>
#include <cstddef>

size_t detsize(size_t n1, size_t n2, size_t m1, size_t m2, size_t i)
{
    size_t minn = n1 > n2 ? n2 : n1;
    size_t minm = m1 > m2 ? m2 : m1;
    if (i < minn)
    {
        return m1 + m2;
    }
    else
    {
        return n1 > n2 ? m1 : m2;
    }
}

int** ct(size_t n1, size_t m1, size_t n2, size_t m2)
{
    size_t n = n1 > n2 ? n1 : n2;
    int ** c = new int*[n];
    size_t i = 0;
    try 
    {
        for (; i < n; ++i)
        {
            size_t m = detsize(n1, n2, m1, m2, i);
            c[i] = new int[m];
        }
    }
    catch (...)
    {
        rm(c, i);
        throw;
    }
}

int* copy(const int * v, size_t k, int * w)
{
    for (size_t i = 0; i < k; ++i)
    {
        w[i] = v[i];
    }
    return w + k;
}

void rm(int** a, size_t k)
{
    for (size_t i = 0; i < k; ++i)
    {
        delete [] a[i];
    }
    delete [] a;
}

int** conced_rows(const int * const * a, size_t n1, size_t m1, const int * const * b, size_t n2, size_t m2)
{
    size_t n = n1 > n2 ? n2 : n1;
    int ** c = ct(n1, n2, m1, m2);
    for (size_t i = 0; i < n; ++i)
    {
        const int * rowa = a[i];
        const int * rowb = b[i];
        int* rowc = c[i];
        rowc = copy(rowa, m1, rowc);
        rowc = copy(rowb, m2, rowc);
    }





    return c;
}