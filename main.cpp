#include <iostream>

int det(const int * a, size_t n)
{
    if (!n)
    {
        return 0;
    }
    else if(n == 1)
    {
        return *a;
    }
    else if(n == 2)
    {
        return a[0]*a[3] - a[1]*a[2];
    }
    else
    {
        //для каждого эл-та 1-ой строки
        //опорный эл-т == эл-т
        //сделать матрицу для минора - new!!!
        //заполнить минор
        //считаем определитель минорами рекурсивно - det new
        //накапливаем определитель
    }
}

int main()
{

}