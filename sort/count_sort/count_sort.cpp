#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;


void bubble_sort_vector(vector<int> *array)
{
    ull size = array->size();
    for(ull i = 0; i < size; i++)
        for(ull j = 0; j < size - 1 - i; j++)
        {
            if(array->operator[](j) > array->operator[](j+1))
            {
                swap(array->operator[](j), array->operator[](j+1));
            }
        }
}

void print_vector(vector<int> *array)
{
    ull size = array->size();
    for(ull i = 0; i < size; i++)
    {
        cout << array->operator[](i) << " ";
    }
    cout << endl;
}


void bubble_sort_array(int *array, ull size)
{
    for(ull i = 0; i < size; i++)
        for(ull j = 0; j < size - 1 - i; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
            }
        }
}

void print_array(int *array, ull size)
{
    for(ull i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main()
{
    /*
     * Array bubble sort
     */
    ull size = 16;
    int array[] = {5, 7, -12, 14, 21, 48, -13, 7, 3, 7, 5, -4, 123, 15, -193, 88};

    print_array(array, size);
    bubble_sort_array(array, size);
    print_array(array, size);

    /*
     * Vector bubble sort
     */
    vector<int> vector1 = {5, 7, -12, 14, 21, 48, -13, 7, 3, 7, 5, -4, 123, 15, -193, 88};

    print_vector(&vector1);
    bubble_sort_vector(&vector1);
    print_vector(&vector1);
    
    return 0;
}