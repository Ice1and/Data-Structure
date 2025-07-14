// 单链表，头节点是第0个节点，第一个数据节点从1开始，与顺序表的位序一致
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* nextNode;
};


Node* headerNodePointer;     // 头节点指针

bool initLinkedList() {
    // 初始化头节点
    headerNodePointer = new Node;
    headerNodePointer->data = 0;    // 头节点的数据位用来记录链表长度
    headerNodePointer->nextNode = NULL;

    return true;
};

int length() {
    return headerNodePointer->data;
};

// 按序号查找结点
Node* get(int n) {
    Node* nodePointer = headerNodePointer;
    int j = 0;
    while(nodePointer != NULL && j < n) {
        nodePointer = nodePointer->nextNode;
        j++;
    }
    return nodePointer;
}

// 按值查找结点
Node* find(int value) {
    Node* nodePointer = headerNodePointer;
    while(nodePointer != NULL && nodePointer->data != value) {
        nodePointer = nodePointer->nextNode;
    }
    return nodePointer;
}

bool insert(int i, int data) {
    // 检查插入位置的合法性
    if (i > headerNodePointer->data + 1) {
        cout << '插入位置不合法' << endl;
        return false;
    }

    // 获取第 i - 1 的结点指针
    Node* nodePointer = headerNodePointer;
    for (int j = 0; j < i; j++) {
        nodePointer = nodePointer->nextNode;
        j++;
    }
    Node* newNodePointer = new Node;
    newNodePointer->data = data;
    newNodePointer->nextNode = nodePointer->nextNode;       // 新结点的 nextNode 为第 i - 1 个结点的 nextNode
    nodePointer->nextNode = newNodePointer;     // 第 i - 1 个结点的 nextNode 为新插入的新结点

    return true;
}

void deleteAllNode() {
    cout << 'haha' << endl;
}

int main() {
    initLinkedList();

    delete headerNodePointer;
    return 0;
}