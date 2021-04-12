// MyConsoleApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <functional>
#include <vector>

#include "DllInterface.h"
#include "json.hpp"

using delegate_emplace = std::function<void*(std::uint32_t, void*)>;

using json = nlohmann::json;

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

// ====================================== enum class test ====================================================

enum class TestColorType : std::uint32_t
{
    None = 0,
    Red = 1,
    Blue = 2,
    Yellow = 3,
};

class BaseClass
{
public:
    void ShowColorType();

protected:
    virtual TestColorType getColorType();
};

class DerivedClass : public BaseClass
{
protected:
    TestColorType getColorType() override;
};

// ====================================== enum class test ====================================================

int main()
{
    //std::uint32_t v = (std::underlying_type<StructID>::type)StructID::NoMemberStruct;
    //AddMember<NoMemberStruct>(v);

    //std::cout << Add(3, 4) << std::endl;

    //DerivedClass base;
    //base.ShowColorType();

    // ============================json=================================

	json jsonObject = {
		{"pi", 3.1415},
		{"happy", true},
		{"name", "Niels"},
		{"answer", {"everything", 42}},
		{"list", {1, 0, 2}},
		{"object", {{"currency", "USD"}, {"value", 42.99}}}
	};

    std::cout << jsonObject.at("/list/2"_json_pointer) << std::endl;
    std::cout << jsonObject["list"] << std::endl;
    std::vector<int> getList = jsonObject["list"];
    std::vector<int> getListAt = jsonObject.at("list");

    // ============================json=================================

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

void BaseClass::ShowColorType()
{
    TestColorType color = getColorType();
    std::cout << static_cast<std::underlying_type<TestColorType>::type>(color) << std::endl;
}

TestColorType BaseClass::getColorType()
{
    return TestColorType::Blue;
}

TestColorType DerivedClass::getColorType()
{
    return TestColorType::Yellow;
}
