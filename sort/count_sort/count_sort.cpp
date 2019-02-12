/*
 *  Necessary function:
 *   -> count_sort_vector
 *          for sort vector
 *
 *   -> count_sort_array
 *          for sort array with known size
 *
 *   Arguments:
 *
 *   range of values for array elements: "min_elem" and "max_elem"
 *
 */



#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;


void count_sort_vector(vector<int> *array, int min_elem, int max_elem)
{
    ull size = array->size();

    int size_secondary_array = max_elem - min_elem + 1;
    int secondary_array[size_secondary_array];
    // create secondary array

    int elem;

    for(ull i = 0; i < size_secondary_array; i++){
        secondary_array[i] = 0;
    }
    // fill secondary array with zeros

    for(ull i = 0; i < size; i++){
        elem = array->operator[](i);
        secondary_array[elem - min_elem]++;
    }
    // run through the main array

    ull index = 0;

    for(int i = 0; i < size_secondary_array; i++)
    {
        for(ull j = 0; j < secondary_array[i]; j++)
        {
            array->operator[](index++) = i + min_elem;
        }
    }
    // change main array
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

void count_sort_array(int *array, ull size, int min_elem, int max_elem)
{
    int size_secondary_array = max_elem - min_elem + 1;
    int secondary_array[size_secondary_array];
    // create secondary array

    int elem;

    for(ull i = 0; i < size_secondary_array; i++){
        secondary_array[i] = 0;
    }
    // fill secondary array with zeros

    for(ull i = 0; i < size; i++){
        elem = array[i];
        secondary_array[elem - min_elem]++;
    }
    // run through the main array

    ull index = 0;

    for(int i = 0; i < size_secondary_array; i++)
    {
        for(ull j = 0; j < secondary_array[i]; j++)
        {
            array[index++] = i + min_elem;
        }
    }
    // change main array
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
     * Array count sort
     */
    ull size = 16;
    int array[] = {5, 7, -12, 14, 21, 48, -13, 7, 3, 7, 5, -4, 123, 15, -193, 88};

    print_array(array, size);
    count_sort_array(array, size, -200, 200);
    print_array(array, size);

    /*
     * Vector count sort
     */
    vector<int> vector1 = {5, 7, -12, 14, 21, 48, -13, 7, 3, 7, 5, -4, 123, 15, -193, 88};

    print_vector(&vector1);
    count_sort_vector(&vector1, -200, 200);
    print_vector(&vector1);

    return 0;
}