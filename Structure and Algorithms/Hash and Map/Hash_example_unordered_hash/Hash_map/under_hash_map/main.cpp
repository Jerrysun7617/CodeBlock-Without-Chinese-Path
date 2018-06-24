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
    //û��key,���Զ�����
    m[0] = 1.11;
    //��ͨ���룬ʹ������ת��
    m.insert(unordered_map<int, double>::value_type(1, 2.22));
    //����ʾ�Ĳ��룬pair<int, double>���൱�������unordered_map<int ,double>
    m.insert(m.end(), pair<int, double>(2, 3.33));
    PrintIntDoubleUnOrderedMap(m, "����Ԫ��֮ǰ��m:");

    //����һ����Χ
    unordered_map<int, double> m2;
    m2.insert(unordered_map<int, double>::value_type(3, 4.44));
    m2.insert(unordered_map<int, double>::value_type(4, 5.44));
    m2.insert(unordered_map<int, double>::value_type(5, 6.44));
    m.insert(m2.begin(), m2.end());

    m.emplace(6, 5.55);
    m.emplace_hint(m.end(), 7, 3.09);
    m.at(5) = 3.333333;

    PrintIntDoubleUnOrderedMap(m, "����Ԫ��֮��m��");

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
    PrintIntDoubleUnOrderedMap(m, "ɾ������Ϊ4��Ԫ��֮��m:");

    //����ɾ��
    for (iter = m.begin(); iter != m.end(); ++iter)
    {
        if (iter->first == 2)
        {
            m.erase(iter);
            break;
        }
    }

    //�ڲ�����
    cout << "bucket_count:" << m.bucket_count() << endl;
    cout << "max_bucket_count:" << m.max_bucket_count() << endl;
    cout << "bucket_size:" << m.bucket_size(0) << endl;
    std::cout << "load_factor��" << m.load_factor() << std::endl;
    std::cout << "max_load_factor��" << m.max_load_factor() << std::endl;
    PrintIntDoubleUnOrderedMap(m, "ɾ������Ϊ2��Ԫ�غ��foo1��");
    m.clear();
    PrintIntDoubleUnOrderedMap(m, "��պ��foo1��");
}

int main()
{
    UnOrderedMapExp1();
    while(1);
    return 0;
}
