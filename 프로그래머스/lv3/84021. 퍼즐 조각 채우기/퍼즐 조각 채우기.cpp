#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<pair<int, int>> piece;
vector<vector<int>> check;

vector<vector<int>> rotation(vector<vector<int>> &table)
{
    vector<vector<int>> result(table.size(), vector<int>(table.size()));

    for (int i = 0; i < table.size(); i++)
        for (int j = 0; j < table.size(); j++)
            result[j][table.size() - 1 - i] = table[i][j];

    table = result;
    return table;
}

void dfs(vector<vector<int>>& game_board, int x, int y, int value, int nonValue)
{
    stack<pair<int, int>> s;
    s.push({ x, y });
    check[y][x] = nonValue;
    piece.push_back({ x, y });

    while (!s.empty())
    {
        int currentX = s.top().first;
        int currentY = s.top().second;
        s.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = currentX + dir[i].first;
            int nextY = currentY + dir[i].second;

            if (nextX < 0 || nextY < 0 || nextX >= game_board.size() || nextY >= game_board.size()) continue;
            if (check[nextY][nextX] == nonValue) continue;

            s.push({ nextX, nextY });
            piece.push_back({ nextX, nextY });
            check[nextY][nextX] = nonValue;
        }
    }
}

int match(vector<vector<int>> &game_board, vector<vector<int>> &table)
{
    int answer = 0;

    vector<vector<pair<int, int>>> empty;
    check = game_board;
    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board.size(); j++)
        {
            if (check[i][j] == 0)
            {
                piece.clear();
                dfs(game_board, j, i, 0, 1);
                empty.push_back(piece);
            }
        }
    }

    vector<vector<pair<int, int>>> block;
    check = table;
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.size(); j++)
        {
            if (check[i][j] == 1)
            {
                piece.clear();
                dfs(table, j, i, 1, 0);
                block.push_back(piece);
            }
        }
    }



    vector<int> blockCheck(block.size());
    for (int i = 0; i < empty.size(); i++)
    {
        bool isMatch = true;
        for (int j = 0; j < block.size(); j++)
        {
            isMatch = true;
            if (blockCheck[j]) { isMatch = false; continue; }

            if (empty[i].size() == block[j].size())
            {
                int diffX = 0, diffY = 0;
                for (int h = 0; h < empty[i].size(); h++)
                {
                    if (h == 0)
                    {
                        diffX = empty[i][h].first - block[j][h].first;
                        diffY = empty[i][h].second - block[j][h].second;
                    }
                    else
                    {
                        if (diffX != empty[i][h].first - block[j][h].first || diffY != empty[i][h].second - block[j][h].second)
                        {
                            isMatch = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isMatch = false;
            }

            if (isMatch)
            {
                blockCheck[j] = true;
                for (int hh = 0; hh < block[j].size(); hh++)
                {
                    int x = block[j][hh].first;
                    int y = block[j][hh].second;
                    table[y][x] = 0;
                }
                break;
            }
        }

        if (isMatch)
        {
            for (int hhh = 0; hhh < empty[i].size(); hhh++)
            {
                int x = empty[i][hhh].first;
                int y = empty[i][hhh].second;
                game_board[y][x] = 1;
                answer++;
            }
        }
    }


    return answer;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

    for (int i = 0; i < 4; i++)
    {
        answer += match(game_board, table);
        rotation(table);
    }



    return answer;
}