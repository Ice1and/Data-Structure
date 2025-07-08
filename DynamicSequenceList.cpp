// 动态分配的顺序表
#include <iostream>
#include <vector>
using namespace std;

struct seqListStruct {
    vector<int> datas;     // 在结构体内部不能使用函数式初始化(vector<int> datas(10))，该使用 vector<int> datas = vector<int>(10)(复用初始化) 或者 vector<int> datas{10}(列表初始化)
    int length = 0;
    int maxSize = 20;
};

seqListStruct* seqList;
void initSeqList() {
    seqList = new seqListStruct;
};

void printSeqList() {
    for(int i : seqList->datas) {
        cout << i << ' ';
    }
    cout << '\n';
}

// 将元素插入位序为 i 的位置
bool insert(int i, int element) {
    if (i < 1 || i > seqList->length + 1) {   // 判断插入位置，顺序表的存储必须是连续的，第 i 个元素的后面紧接着存储第 i+1 元素
        return false;
    }

    else if (seqList->length >= seqList->maxSize) {     // 判断顺序表是否已满
        return false;
    }

    else {
        seqList->datas.insert(seqList->datas.begin() + (i - 1), element);
        seqList->length++;

        return true;
    };
};

// 删除位序为 i 的元素
bool drop(int i) {
    if (i < 1 || i > seqList->length + 1) {
        return false;
    }

    seqList->datas.erase(seqList->datas.begin() + (i - 1));
    seqList->length--;

    return true;
};

// 顺序查找，返回第一个元素值等于 element 的元素位序
int locate(int element) {
    for(int i = 0; i < seqList->length; i++) {
        if(seqList->datas[i] == element) {
            return i + 1;
        }
    }
    return 0;
};

int main() {
    initSeqList();

    insert(1, 1);
    insert(2, 10);

    insert(1, 19);

    printSeqList();

    int element = locate(10);
    cout << element << endl;
    return 0;
}