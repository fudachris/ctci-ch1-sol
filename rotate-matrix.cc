#include <iostream>

void 
initArray (int **a, int row)
{
    for (int i = 0; i < row;  i++)
    {
        a[i] = new int [row];
    }

    int count = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            a[i][j] = count;
            count++;
        }
    }
}

void 
printArray (int **a, int row)
{
    int count = 0;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            std::cout << " " << a[i][j];
            if (count == row-1 )
            {
               std::cout<< std::endl;
               count = -1;
            }
            count++;
        }
    }
}

void 
swapCells (int **a, int x1, int y1, int x2, int y2)
{
    a[x2][y2] = a[x2][y2] + a[x1][y1];
    a[x1][y1] = a[x2][y2] - a[x1][y1];
    a[x2][y2] = a[x2][y2] - a[x1][y1];
}

void
shiftCells (int **a, int x1, int y1, int iteration, int size, int depth)
{
    
    if (iteration == 0)
    {
        swapCells (a, x1, y1, y1, size-1-depth);
        shiftCells (a, x1, y1, iteration+1, size, depth);
    }
    else if (iteration == 1)
    {
        swapCells (a, x1, y1, size-1-depth, size-1-depth-y1+x1);
        shiftCells (a, x1, y1, iteration+1, size, depth);
    }
    else if (iteration == 2)
    {
        swapCells (a, x1, y1, size-1-depth-y1+x1, x1);
    }
}


int main ()
{
    int size = 20;
    int **a = new int* [size];

    initArray(a,size);
    printArray (a,size);

    std::cout << "\n after shift " << std::endl;

    int depth = 0;

    do
    {
        for (int i = depth; i < size-1 -depth; i++)
        { 
            shiftCells (a, depth, i, 0, size, depth);
        }

        depth += 1;

    }while(size-1-depth-depth>0);
    
    std::cout << std::endl;
    printArray(a,size);

}
