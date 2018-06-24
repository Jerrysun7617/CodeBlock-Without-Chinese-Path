#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

void PrintIntDoubleUnOrderedMap(unordered_map<int, double>& m, char* pre)
{
    unordered_map<int, double>::iterator iter;
    cout << pre;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << ", " << iter->second << ")" << " ";
    cout << endl;
}

void UnOrderedMapExp1()
{
    unordered_map<int, double> m;
    //没有key,就自动创建
    m[0] = 1.11;
    //普通插入，使用类型转换
    m.insert(unordered_map<int, double>::value_type(1, 2.22));
    //带暗示的插入，pair<int, double>就相当于上面的unordered_map<int ,double>
    m.insert(m.end(), pair<int, double>(2, 3.33));
    PrintIntDoubleUnOrderedMap(m, "插入元素之前的m:");

    //插入一个范围
    unordered_map<int, double> m2;
    m2.insert(unordered_map<int, double>::value_type(3, 4.44));
    m2.insert(unordered_map<int, double>::value_type(4, 5.44));
    m2.insert(unordered_map<int, double>::value_type(5, 6.44));
    m.insert(m2.begin(), m2.end());

    m.emplace(6, 5.55);
    m.emplace_hint(m.end(), 7, 3.09);
    m.at(5) = 3.333333;

    PrintIntDoubleUnOrderedMap(m, "插入元素之后m：");

    unordered_map<int, double>::iterator iter;
    iter = m.find(4);
    if (iter != m.end())
    {
        cout << "m.find(4): ";
        cout << "(" << iter->first << ", " << iter->second << ")" << endl;
    }

    if (iter != m.end())
    {
        m.erase(iter);
    }
    PrintIntDoubleUnOrderedMap(m, "删除主键为4的元素之后m:");

    //遍历删除
    for (iter = m.begin(); iter != m.end(); ++iter)
    {
        if (iter->first == 2)
        {
            m.erase(iter);
            break;
        }
    }

    //内部数据
    cout << "bucket_count:" << m.bucket_count() << endl;
    cout << "max_bucket_count:" << m.max_bucket_count() << endl;
    cout << "bucket_size:" << m.bucket_size(0) << endl;
    std::cout << "load_factor：" << m.load_factor() << std::endl;
    std::cout << "max_load_factor：" << m.max_load_factor() << std::endl;
    PrintIntDoubleUnOrderedMap(m, "删除主键为2的元素后的foo1：");
    m.clear();
    PrintIntDoubleUnOrderedMap(m, "清空后的foo1：");
}

int main()
{
    UnOrderedMapExp1();
    while(1);
    return 0;
}
