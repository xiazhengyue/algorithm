#pragma once

#include<string>
#include<vector>

class MyGraph
{
public:
    MyGraph()=default;
    ~MyGraph()=default;

    void AddEdge(char from, char to, unsigned int weight);
    void DijkStra(char start);

private:
    struct Edge
    {
        char m_from;
        char m_to;
        unsigned int m_weight;

        Edge() = default;
        Edge(char from, char to, unsigned int weight):
            m_from(from), m_to(to), m_weight(weight){}
    };
    
    std::vector<Edge> m_edges;
};

