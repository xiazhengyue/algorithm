#include<cstdio>
#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;
using Matrix = vector<vector<unsigned int>>;
using SNodes = vector<tuple<unsigned int, unsigned int, unsigned int>>;
using UNodes = list<tuple<unsigned int, unsigned int, unsigned int>>;
using ENode = tuple<unsigned int, unsigned int, unsigned int>;

ENode searchNearest(const UNodes& unvistedNodes)
{
    unsigned int minDist = UINT_MAX;
    ENode nearest;
    for (const auto& node : unvistedNodes)
    {
        if (get<1>(node) <= minDist)
        {
            minDist = get<1>(node);
            nearest = node;
        }
    }
    return nearest;
}

SNodes dijkstra(const Matrix& graph, unsigned int startNodeIndex)
{
    const int numOfNodes = graph.size();
    SNodes visitedNodes;
    UNodes unvisitedNodes;

    for (int i = 0; i < numOfNodes; i++)
    {
        if (i == startNodeIndex)
            visitedNodes.emplace_back(i, 0, startNodeIndex);
        else
            unvisitedNodes.emplace_back(i, graph[startNodeIndex][i], startNodeIndex);
    }

    while (!unvisitedNodes.empty())
    {
        auto nextNode = searchNearest(unvisitedNodes);
        unvisitedNodes.erase(find(unvisitedNodes.begin(), unvisitedNodes.end(), nextNode));
        visitedNodes.emplace_back(nextNode);

        for (auto& node : unvisitedNodes)
        {
            if (graph[get<0>(nextNode)][get<0>(node)] != UINT_MAX &&
                (graph[get<0>(nextNode)][get<0>(node)] + get<1>(nextNode) < get<1>(node)))
            {
                get<1>(node) = graph[get<0>(nextNode)][get<0>(node)] + get<1>(nextNode);
                get<2>(node) = get<0>(nextNode);
            }
        }
        return visitedNodes;
    }
}

void print(const SNodes& paths)
{
    stack<int> tracks;
    for (auto it = ++paths.begin(); it != paths.end(); ++it)
    {
        printf("%c -> %c:\t Length: %d\t Paths: %c",
            char(get<0>(paths[0]) + 65),
            char(get<0>(*it) + 65),
            get<1>(*it),
            char(get<0>(paths[0]) + 65));
        auto pointer = *it;
        while (get<2>(pointer) != get<0>(paths[0]))
        {
            tracks.push(get<0>(pointer));
            auto condition = [pointer](tuple<unsigned int, unsigned int, unsigned int> x) {return get<0>(x) == get<2>(pointer); };
            pointer = *find_if(paths.begin(), paths.end(), condition);
        }
        tracks.push(get<0>(pointer));

        while (!(tracks.empty()))
        {
            printf(" -> %c", char(tracks.top() + 65));
            tracks.pop();
        }
        printf("\n");
    }
}