// 静态分配的顺序表，元素的位序从1开始，而数组的下标是从0开始，往顺序表内插入数据时注意位序与下标的转换，插入位置 = 位序 - 1
#include <iostream>
using namespace std;

const int MaxSize = 50;

struct seqListStruct {
    int datas[MaxSize] = {0};
    int length = 0;
};

seqListStruct* seqList;

void initSeqList() {
    seqList = new seqListStruct;
};

// 将元素插入位序为 i 的位置
bool insert(int i, int element) {
    if (i < 1 || i > seqList->length + 1) {   // 判断插入位置，顺序表的存储必须是连续的，第 i 个元素的后面紧接着存储第 i+1 元素
        return false;
    }

    else if (seqList->length >= MaxSize) {     // 判断顺序表是否已满
        return false;
    }

    else {
        for(int j = seqList->length; j >= i; j--) {
            seqList->datas[j] = seqList->datas[j - 1];      // 将第 i 位之后的元素都后移
        };

        seqList->datas[i - 1] = element;
        seqList->length++;

        return true;
    };
};

void printSeqList() {
    for(int j = 0; j < MaxSize; j++) {
        cout << seqList->datas[j] << " ";
    };
    cout << "\nSize: " << seqList->length << endl;
};

// 删除位序为 i 的元素
bool drop(int i) {
    if (i < 1 || i > seqList->length + 1) {
        return false;
    }

    for(int j = i; j < seqList->length; j++) {
        seqList->datas[j - 1] = seqList->datas[j];      // 将位序 i 后的所有元素都向前移一位
        seqList->datas[j] = 0;
    }

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
    insert(1, 10);
    insert(1, 20);
    insert(1, 30);
    insert(2, 40);
    printSeqList();

    drop(2);
    printSeqList();

    int element = locate(10);
    cout << element << endl;
    
    delete seqList;
    return 0;
};