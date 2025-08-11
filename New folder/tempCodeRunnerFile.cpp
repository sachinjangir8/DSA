], int size)
{
    int start = 0;
    int end = size - 1;
    while (value[start] < value[end])
    {
        swap(value[start], value[end]);
    }
    return 0;
}
int main()
{
    int n[] = {1, 2, 3, 4, 5, 8};
    int size = 6;
    // cout<< array(n, size);
    array(n, size);
    for (int i = 0; i < size; i++)
    {
        cout << n[i] << " ";
    }


    return 0;
}