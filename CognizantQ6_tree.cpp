#include <bits/stdc++.h>

using namespace std;

unordered_map<char, vector<char>> parseToGraph(string &graphInput)
{
    unordered_map<char, vector<char>> g;

    for (int i = 0; i < graphInput.size(); i++)
    {
        if (graphInput[i] == '(')
        {
            char parent = graphInput[i + 1];
            char child = graphInput[i + 3];
            g[parent].push_back(child);
            i += 3;
        }
    }

    return g;
}

bool isLoop(char j, unordered_map<char, bool> &vis)
{
    if (vis[j] == true)
    {
        return true;
    }
    return false;
}

void createAns(unordered_map<char, vector<char>> graph, char node, string &ans)
{
    for (auto i : graph[node])
    {
        ans += '(';
        ans += i;
        createAns(graph, i, ans);
        ans += ')';
    }
}

char findParent(unordered_map<char, vector<char>> &tree)
{
    set<char> graphNodes;
    set<char> children;

    for (auto i : tree)
    {
        graphNodes.insert(i.first);
        for (auto child : i.second)
        {
            graphNodes.erase(child);
            children.insert(child);
        }
    }

    int flag = 1;

    for(auto i :graphNodes){
        for(auto child :children){
            if (i == child){
                flag = 0;
            }
        }

        if (flag == 1){
            return i;
        }
    }
    

    return '\0';
}

int main()
{
    string graphInput;
    getline(cin, graphInput);
    unordered_map<char, bool> visited;

    unordered_map<char, vector<char>> graph = parseToGraph(graphInput);

    for (auto i : graph)
    {
        if (i.second.size() > 2)
        {
            cout << "Code Stopped";
            return 0;
        }

        for (auto j : i.second)
        {

            if (isLoop(j, visited))
            {
                cout << "Code Stopped";
                return 0;
            }
            visited[j] = true;
        }
    }

    string ans = "(A";

    char parent = findParent(graph);

    createAns(graph, parent, ans);

    cout << (ans + ')') << endl;

    return 0;
}
