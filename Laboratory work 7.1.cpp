#include <iostream>
using namespace std;
int const const_hight = 5;
int const const_wight = 4;
int const const_lenght = 12;

void func(int matrix[const_hight][const_wight], int hight, int wight);
void print(int matrix[const_hight][const_wight], int hight, int wight);
void func(int array[const_lenght], int lenght);
void print(int array[const_lenght], int lenght);

int main()
{
    setlocale(LC_ALL, "Rus");
    int hight = const_hight;
    int wight = const_wight;
    int matrix[const_hight][const_wight] = {{71, 52, 12, 26},
                                            {11, 64, 19, 23}, 
                                            {21, 10, 70, 94}, 
                                            {83, 11, 67, 20}, 
                                            {22, 61, 77, 15}};
    func(matrix, hight, wight);

    int lenght = const_lenght;
    int array[] = {5, 8, 0, 1, 0, 12, 6, 11, 0, 3, 0 , 7};
    func(array, lenght);
    return 0;
}

void func(int matrix[const_hight][const_wight], int hight, int wight)
{
    print(matrix, hight, wight);
    int oddRow = 0;
    for (int row = 0; row < hight; row++)
    {
        if (row % 2 == 0)
        {
            if (row != oddRow)
            {
                for (int col = 0; col < wight; col++)
                {
                    matrix[oddRow][col] = matrix[row][col];
                }
            }
            oddRow++;
        }
    }
    hight = hight / 2 + 1;
    print(matrix, hight, wight);
}

void print(int matrix[const_hight][const_wight], int hight, int wight)
{
    cout << "Двумерный массив:\n";
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < wight; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

void func(int array[const_lenght], int lenght)
{
    print(array, lenght);
    for (int i = 1; i < lenght - 1; i++)
    {
        if (array[i - 1] == 0 && array[i + 1] == 0)
        {
            for (int j = i; j < lenght; j++)
            {
                array[j] = array[j + 1];
            }
            lenght--;
        }
    }
    print(array, lenght);
}

void print(int array[const_lenght], int lenght)
{
    cout << "Одномерный массив:\n";
    for (int i = 0; i < lenght; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
