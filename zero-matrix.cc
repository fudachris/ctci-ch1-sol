#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string.h>
#include <vector>

void
initArray (int **a, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        a[i] = new int [N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = rand () % 20;
        }
    }

}

void 
printArray (int **a, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << " "<< a[i][j];
        }
        std::cout << std::endl;
    }
}

void
setZero (int **a, int row, int col, int M, int N)
{
    memset (a[row], 0, N*sizeof(a[0][0]));

    for (int i = 0; i < M; i++)
    {
        a[i][col] = 0;
    }
}

void
findZero (int **a, int M, int N)
{
    std::vector <std::pair<int,int>> zeroLocation;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] == 0)
            {
                zeroLocation.push_back(std::make_pair(i,j));
            }
        }
    }

    for (int i = 0; i < zeroLocation.size(); i++)
    {
        setZero (a, zeroLocation[i].first, zeroLocation[i].second, M, N);
    }


}

int main ()
{
    srand (time(NULL));

    std::cout << "\n enter MxN dimensions " << std::endl;
    int M = 0, N=0;

    std::cin >> M; 
    std::cin >> N;
    
    int **a = new int* [M];
    initArray (a,M,N);

    printArray (a, M, N);

    findZero (a,M,N);

    std::cout << std::endl;

    printArray (a,M,N);


}
