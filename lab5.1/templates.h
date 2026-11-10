#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <cstddef>
#include "birthdate.h"

template <class T>
T minValue(T* arr, int n)
{
    T result = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < result)
            result = arr[i];
    return result;
}

template <class T>
T maxValue(T* arr, int n)
{
    T result = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > result)
            result = arr[i];
    return result;
}

template <class T>
double avgValue(T* arr, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (double)arr[i];
    return sum / n;
}

// average age in days
template <>
double avgValue<BirthDate>(BirthDate* arr, int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += BirthDate::toDays(arr[i]);
    return (double)sum / n;
}

template <class T>
T valueRange(T* arr, int n)
{
    return maxValue(arr, n) - minValue(arr, n);
}

template <>
double valueRange<double>(double* arr, int n)
{
    return maxValue(arr, n) - minValue(arr, n);
}

template <class T>
bool isInRange(const T& value, const T& lo, const T& hi)
{
    return value >= lo && value <= hi;
}


template <class T>
int countInRange(T* arr, int n, const T& lo, const T& hi)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (isInRange(arr[i], lo, hi))
            count++;
    return count;
}

#endif // TEMPLATES_H