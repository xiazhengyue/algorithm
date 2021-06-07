// Sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

void Swap(int* pData, int i, int j)
{
    int temp = pData[i];
    pData[i] = pData[j];
    pData[j] = temp;
}

namespace Selection
{
    void SelectionSorting(int* pData, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int minIndex = i;
            for (int j = i; j < size; j++)
            {
                if (pData[j] < pData[minIndex])
                {
                    minIndex = j;
                }
            }
            if (minIndex > i)
            {
                int temp = pData[i];
                pData[i] = pData[minIndex];
                pData[minIndex] = temp;
            }
        }
    }
}

namespace Bubble
{
    void BubbleSorting(int* pData, int size)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < (size - i); j++)
            {
                if (pData[j] > pData[j + 1])
                {
                    int temp = pData[j];
                    pData[j] = pData[j + 1];
                    pData[j + 1] = temp;
                }
            }
        }
    }
}

namespace Insert
{
    void InsertSorting(int* pData, int size)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (pData[j] < pData[j - 1])
                {
                    int temp = pData[j];
                    pData[j] = pData[j - 1];
                    pData[j - 1] = temp;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

namespace Quick
{
    int Partition(int* pData, int left, int right)
    {
        int pivot = left, index = left + 1;
        for (int i = index; i <= right; i++)
        {
            if (pData[i] < pData[pivot])
            {
                if (i > index)
                    Swap(pData, i, index);
                index++;
            }
        }
        Swap(pData, pivot, index - 1);

        return index - 1;
    }

    void QuickSorting(int* pData, int left, int right)
    {
        if (right > left)
        {
            int partitionIndex = Partition(pData, left, right);
            QuickSorting(pData, left, partitionIndex - 1);
            QuickSorting(pData, partitionIndex + 1, right);
        }
        return;
    }
}

namespace Shell
{
    void ShellSorting(int* pData, int size)
    {
        for (int div = size / 2; div >= 1; div /= 2)
        {
            for (int k = 0; k < div; k++)
            {
                for (int i = div + k; i < size; i += div)
                {
                    for (int j = i; j > k; j -= div)
                    {
                        if (pData[j] < pData[j - div])Swap(pData, j, j - div);
                        else break;
                    }
                }
            }
        }
    }
}

namespace Merge
{
    void Merge(int* pData, int start, int mid, int end)
    {
        int* pTemp = new int[end - start + 1];
        int start1 = start, start2 = mid + 1;
        int index = 0;
        while (start1 <= mid && start2 <= end)
        {
            if (pData[start1] < pData[start2])
            {
                pTemp[index] = pData[start1];
                start1++;
            }
            else
            {
                pTemp[index] = pData[start2];
                start2++;
            }
            index++;
        }
        if (start1 <= mid)
        {
            memcpy(pTemp + index, pData + start1, sizeof(int)*(mid - start1 + 1));
        }
        if (start2 <= end)
        {
            memcpy(pTemp + index, pData + start2, sizeof(int)*(end - start2 + 1));
        }
        memcpy(pData + start, pTemp, sizeof(int)*(end - start + 1));
        delete[] pTemp;
        pTemp = nullptr;
    }

    void MergeSorting(int* pData, int left, int right)
    {
        if (right > left)
        {
            int mid = (left + right) / 2;
            MergeSorting(pData, left, mid);
            MergeSorting(pData, mid + 1, right);
            Merge(pData, left, mid, right);
        }
    }
}

namespace Heap
{
    void AdjustHeap(int* pData, int parent, int size)
    {
        int lChild = 2 * parent + 1;
        int rChild = 2 * parent + 2;
        if (lChild < size && pData[parent] < pData[lChild])
            Swap(pData, parent, lChild);
        if (rChild < size && pData[parent] < pData[rChild])
            Swap(pData, parent, rChild);
    }
    void BuildHeap(int* pData, int size)
    {
        //非叶子节点的最大index是size/2
        for (int i = size / 2-1; i >= 0; i--)
        {
            AdjustHeap(pData, i, size);
        }
    }
    void HeapSorting(int* pData, int size)
    {
        for (int i = 0; i < size; i++)
        {
            BuildHeap(pData, size-i);
            Swap(pData, 0, size - i-1);
        }
    }

}


void Print(int* pData, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << pData[i] << ",";
    }
    std::cout << std::endl;
}

int main()
{
    int data[] = { 2, 3,1,5,9,10, 6, 7, 1, 8 };
    int size = sizeof(data) / sizeof(data[0]);
    int left = 0, right = size - 1;

    /*{
        BubbleSorting(data, size);
    }*/
    /*{
        SelectionSorting(data, size);
    }*/
    /*{
        Insert::InsertSorting(data, size);
    }*/
    /* {
         Quick::QuickSorting(data, left, right);
     }*/
     /*{
         Merge::MergeSorting(data, left, right);
     }*/
    /*{
        Shell::ShellSorting(data, size);
    }*/
    {
        Heap::HeapSorting(data, size);
    }

    Print(data, size);
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
