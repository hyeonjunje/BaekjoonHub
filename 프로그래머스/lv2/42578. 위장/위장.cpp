#include <string>
#include<vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int result = 1;

    unordered_map<string, int> map;
    for (vector<string> v : clothes)
        map[v[1]]++;

    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        result *= (*iter).second + 1;
    }
    result -= 1;

    return result;
}
