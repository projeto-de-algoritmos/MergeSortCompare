#include <bits/stdc++.h>
#include <ctime>
#include "matplotlibcpp.h"
#include <cmath>

namespace plt = matplotlibcpp;
using namespace std;

template <typename RandIt>
void merge(size_t N, RandIt first, RandIt middle, RandIt last)
{
    vector<typename iterator_traits<RandIt>::value_type> temp(N);
    auto it = first, jt = middle;
    auto k = 0;

    while (it != middle and jt != last)
    {
        temp[k++] = min(*it, *jt);
        temp[k - 1] == *it ? ++it : ++jt;
    }

    while (it != middle)
        temp[k++] = *it++;

    while (jt != last)
        temp[k++] = *jt++;

    for (const auto &elem : temp)
        *first++ = elem;
}

template <typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
    auto N = last - first;

    if (N == 1)
        return;

    auto middle = first + (N + 1) / 2;

    mergesort(first, middle);
    mergesort(middle, last);

    merge(N, first, middle, last);
}

void selectsort(vector<int> &vetor)
{
    for (int indice = 0; indice < vetor.size(); ++indice)
    {
        int indiceMenor = indice;
        for (int indiceSeguinte = indice + 1; indiceSeguinte < vetor.size(); ++indiceSeguinte)
        {
            if (vetor[indiceSeguinte] < vetor[indiceMenor])
            {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}

int main()
{

    vector<int> xs;
    vector<int> ys;
    vector<int> zs;
    vector<pair<int, int>> data;
    srand((unsigned)time(NULL));
    // for (int a = 1; a <= 100000; a++)
    // {
    int x = 10;
    vector<int> size;
    vector<double> time;
    vector<double> time2;
    vector<double> time3;
    // cout << "Digite tamanho: ";
    while (x <= 100000)
    {
        for (int i = 0; i < x; i++)
        {
            int b = rand() % 10000 + 1;
            xs.push_back(b);
            ys.push_back(b);
            zs.push_back(b);
        }
        clock_t begin = clock();
        mergesort(xs.begin(), xs.end());
        clock_t end = clock();

        clock_t begin1 = clock();
        selectsort(ys);
        clock_t end1 = clock();

        // clock_t begin2 = clock();
        // sort(zs.begin(), zs.end());
        // clock_t end2 = clock();

        size.push_back(x);
        // size.push_back(x);
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;
        // double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
        time.push_back(elapsed_secs);
        time2.push_back(elapsed_secs1);
        // time3.push_back(elapsed_secs2);
        // auto size_time = make_pair(x, elapsed_secs);
        printf("Tamanho: %d Tempo Merge    : %.7lf segundos\n", x, elapsed_secs);
        printf("Tamanho: %d Tempo Selection: %.7lf segundos\n", x, elapsed_secs1);
        // printf("Tamanho: %d Tempo Sort: %.7lf segundos\n", x, elapsed_secs2);
        // data.push_back(size_time);
        x *= 10;
    }

    plt::figure_size(1200, 780);
    // // Plot line from given x and y data. Color is selected automatically.
    plt::plot( size, time);
    plt::plot( size, time2);
    // plt::plot( size, time3 );
    
    plt::ylim(0, 15);
    plt::xlim(0, 100000);

    for (int i = 0; i < time.size(); i++)
    {
        cout << time[i] << endl;
    }
    for (int i = 0; i < time3.size(); i++)
    {
        cout << time3[i] << endl;
    }
    for (int i = 0; i < size.size(); i++)
    {
        cout << size[i] << endl;
    }


    // // }
    // plt::legend();
    plt::title("Merge VS Sort VS Select");
    plt::save("./basic2.png");
    // return 0;
}