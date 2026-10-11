#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    
    vector<char> L;
    cout << "(1)初始化顺序表 L 成功" << endl;

    
    L.push_back('a');
    L.push_back('b');
    L.push_back('c');
    L.push_back('d');
    L.push_back('e');
    cout << "(2)依次插入 a, b, c, d, e 完成" << endl;
    cout << "(3)输出顺序表 L: ";
    for (char c : L) {
        cout << c << " ";
    }
    cout << endl;
    cout << "(4)顺序表 L 的长度: " << L.size() << endl;
    cout << "(5)顺序表 L 是否为空: " << (L.empty() ? "是" : "否") << endl;

    if (L.size() >= 3) {
        cout << "(6)顺序表 L 的第 3 个元素: " << L[2] << endl;
    }

    
    auto it = find(L.begin(), L.end(), 'a');
    if (it != L.end()) {
        cout << "(7)元素 a 的位置: " << (it - L.begin() + 1) << endl;
    }
    L.insert(L.begin() + 3, 'f');
    cout << "(8)在第 4 个元素位置插入 f 完成" << endl;

    cout << "(9)输出顺序表 L: ";
    for (char c : L) {
        cout << c << " ";
    }
    cout << endl;

    L.erase(L.begin() + 2);
    cout << "(10)删除第 3 个元素完成" << endl;

    cout << "(11)输出顺序表 L: ";
    for (char c : L) {
        cout << c << " ";
    }
    cout << endl;

    L.clear();
    L.shrink_to_fit();
    cout << "(12)释放顺序表 L 完成" << endl;

    return 0;
}