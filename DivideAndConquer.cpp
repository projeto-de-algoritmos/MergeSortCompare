#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// #include "matplotlibcpp.h"
// namespace plt = matplotlibcpp;

template <typename Iterator>
void merge(size_t N, Iterator first, Iterator middle, Iterator last)
{
    vector<typename iterator_traits<Iterator>::value_type> temp(N);
    auto it = first, jt = middle;
    auto k = 0;

    while (it != middle and jt != last)
    {
        temp[k++] = min(*it, *jt);
        temp[k - 1] == *it ? ++it : ++jt;
    }

    while (it != middle)
    {

        temp[k++] = *it;
        it++;
    }

    while (jt != last)
    {

        temp[k++] = *jt;
        jt++;
    }

    for (const auto &elem : temp)
    {

        *first = elem;
        first++;
    }
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

int main()
{

    ios::sync_with_stdio(false);
    int N;
    int inicio_i, final_i, valor, item_pesquisado;

    while (cin >> N)
    {
        int size=N;

        vector<int> intervalo;
        bool found = false;

        while (N--)
        {

            cin >> inicio_i >> final_i;

            while (inicio_i <= final_i)
            {

                intervalo.push_back(inicio_i);
                inicio_i++;
            }
        }

        cin >> item_pesquisado;
        // auto start = high_resolution_clock::now();
        mergesort(intervalo.begin(), intervalo.end());
        // auto stop = high_resolution_clock::now();

        for (int i = 0; i < intervalo.size(); ++i)
        {
            if (item_pesquisado == intervalo[i])
                found = true;
        }
        if (found)
        {
            //O lower_bound é um método que retorna um iterador para o primeiro elemento que é maior ou igual ao valor passado.
            auto lower = lower_bound(intervalo.begin(), intervalo.end(), item_pesquisado);
            //O upper_bound retorna um iterador para o primeiro elemento que é maior que o valor passado.
            auto upper = upper_bound(intervalo.begin(), intervalo.end(), item_pesquisado);
            cout << item_pesquisado << " found from " << distance(intervalo.begin(), lower) << " to " << distance(intervalo.begin(), upper - 1) << endl;
        }
        else
            cout << item_pesquisado << " not found" << endl;

        // plt::figure_size(1200, 780);

        // auto duration = duration_cast<microseconds>(stop - start);
        // plt::plot(size, duration.count());
        // plt::title("Sample figure");
        // cout << "Time taken by MergeSort: "
        //     << duration.count() << " microseconds" << endl;
    }
    return 0;
}
