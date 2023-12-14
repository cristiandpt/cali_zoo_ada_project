
template<typename T>
void Merge(T arr[], int start, int end)
{

    // x: start index of first half [start, mid]
    // y: start index of second half [mid+1, end]
    // z: start index of temp
    // temp: temporary vector to store the merged array
    int z, x, y, mid;
    vector<T> temp(end -start + 1);
    mid = (start + end) / 2;
    z = 0;
    x = start;
    y = mid + 1;

    while (x <= mid && y <= end)
    {
        if (arr[x] < arr[y])
        {
            temp[z] = arr[x];
            ++x, ++z;
        }
        else
        {
            temp[z] = arr[y];
            ++y, ++z;
        }
    }

    while (x <= mid)
    {
        temp[z] = arr[x];
        ++x, ++z;
    }

    while (y <= end)
    {
        temp[z] = arr[y];
        ++y, ++z;
    }

    // write the merged sequence back to the original array
    for (int i = start; i <= end; ++i)
    {
        arr[i] = temp[i - start];
    }

}

// template function to perform merge sort on array, arr
template<typename T>
void MergeSort(T arr[], int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid); // merge sort the elements in range [start, mid]
        MergeSort(arr, mid + 1, end); // merge sort the elements in range [mid+1, end]
        Merge(arr, start, end);   // merge the above 2 componenets
    }

}
