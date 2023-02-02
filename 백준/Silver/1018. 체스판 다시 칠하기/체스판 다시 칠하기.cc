#pragma warning (disable : 4996)
#include<cstdio>
#include<algorithm>
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    char chess[50][50]{};
    for (int i = 0; i < N; i++)
    {
        scanf("%s", &chess[i]);
    }
    int min = 64;
    for (int iStart = 0; iStart <= N - 8; iStart++)
    {
        for (int jStart = 0; jStart <= M - 8; jStart++)
        {
            int changeCount = 0;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((i + j) % 2 == 0 && chess[iStart + i][jStart + j] == 'B') changeCount++;
                    else if ((i + j) % 2 == 1 && chess[iStart + i][jStart + j] == 'W') changeCount++;
                }
            }
            min = std::min({ min, changeCount, 64-changeCount});

        }
    }
    printf("%d", min);
    
}