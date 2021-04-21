// myAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "pow.hpp"
#include "myGraph.h"
#include "dijkstra.hpp"

int main()
{
    {
        std::cout << "pow(3, 0)" << myPow(3, 0) << std::endl;
        std::cout << "pow(3, 1)" << myPow(3, 1) << std::endl;
        std::cout << "pow(3, 2)" << myPow(3, 2) << std::endl;
        std::cout << "pow(3, 7)" << myPow(3, 7) << std::endl;
        std::cout << "pow(3,-7)" << myPow(3, -7) << std::endl;
    }

    {
        MyGraph myGraph;
        myGraph.AddEdge('a', 'b', 1);
        myGraph.AddEdge('a', 'c', 3);
        myGraph.AddEdge('b', 'c', 1);
        myGraph.AddEdge('b', 'd', 5);
        myGraph.AddEdge('c', 'd', 2);

        myGraph.DijkStra('a');
    }
    {
        Matrix graph{
            {0,        12,       UINT_MAX, UINT_MAX, UINT_MAX, 16, 14},
            {12,       0,        10,       UINT_MAX, UINT_MAX, 7, UINT_MAX},
            {UINT_MAX, 10,       0, 3,               5,        6, UINT_MAX},
            {UINT_MAX, UINT_MAX, 3, 0,               4, UINT_MAX, UINT_MAX},
            {UINT_MAX, UINT_MAX, 5, 4,               0,        2,  8},
            {16,       7,        6,        UINT_MAX, 2,        9,  9},
            {14,       UINT_MAX, UINT_MAX, UINT_MAX, 8,        9,  0}
        };

        auto results = dijkstra(graph, unsigned int('D' -65));
        print(results);
    }
    
    std::cout << "Hello World!\n";
    system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
