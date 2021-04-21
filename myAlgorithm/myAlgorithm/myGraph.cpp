#include "pch.h"
#include "myGraph.h"

void MyGraph::AddEdge(char from, char to, unsigned int weight)
{
    this->m_edges.emplace_back(from, to, weight);
}

void MyGraph::DijkStra(char start)
{

}