/*
 *  Necessary function:
 *   -> quick_sort_vector
 *          for sort vector
 *
 *   Arguments:
 *
 *   size of array
 *
 */



#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;


vector<int> quick_sort_vector(vector<int> array, ull size)
{
    if(size < 2)
    {
        return array;

        // already sorted
    }
    vector<int> before;
    vector<int> equals;
    vector<int> after;

    ull size_before = 0;
    ull size_equals = 0;
    ull size_after = 0;

    // create vectors and sizes

    int element = array[0];

    for(ull i = 0; i < size; i++)
    {
        if(array[i] < element)
        {
            before.push_back(array[i]);
            size_before++;;
        }

        else if(array[i] == element)
        {
            equals.push_back(array[i]);
            size_equals++;
        }

        else if(array[i] > element)
        {
            after.push_back(array[i]);
            size_after++;
        }
    }
    // fill vectors

    vector<int> end_before = quick_sort_vector(before, size_before);
    vector<int> end_after = quick_sort_vector(after, size_after);
    // recursion for before and after

    end_before.insert(end_before.end(), equals.begin(), equals.end());
    end_before.insert(end_before.end(), end_after.begin(), end_after.end());
    // merge arrays and return it

    return end_before;

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


int main()
{
    /*
     * Vector quick sort
     */
    vector<int> vector1 = {5, 7, -12, 14, 21, 48, -13, 7, 3, 7, 5, -4, 123, 15, -193, 88};

    print_vector(&vector1);
    vector1 = quick_sort_vector(vector1, 16);
    print_vector(&vector1);

    return 0;
}