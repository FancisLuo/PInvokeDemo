// MyConsoleApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <functional>

#include "DllInterface.h"

using delegate_emplace = std::function<void*(std::uint32_t, void*)>;

enum class StructID: std::uint32_t
{
    None = 0,
    NoMemberStruct = 1,
};

struct NoMemberStruct
{
};

template<typename Component>
void AddMember(std::uint32_t id)
{
    RegisterMember(id, [](std::uint32_t id, void* pData) -> void* {
        if (pData)
        {
            Component com = *(Component*)pData;

            return nullptr;
        }
        });
}

std::unordered_map<std::uint32_t, delegate_emplace> emplaceList;

void RegisterMember(std::uint32_t id, delegate_emplace&& emplacer)
{
    emplaceList[id] = emplacer;
}

int main()
{
    std::uint32_t v = (std::underlying_type<StructID>::type)StructID::NoMemberStruct;
    AddMember<NoMemberStruct>(v);

    std::cout << Add(3, 4) << std::endl;
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
