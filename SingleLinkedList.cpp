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
        cout << "插入位置不合法" << endl;
        return false;
    }

    // 获取第 i - 1 的结点指针，进行后插操作
    Node* nodePointer = headerNodePointer;
    for (int j = 0; j < i - 1; j++) {
        nodePointer = nodePointer->nextNode;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->nextNode = nodePointer->nextNode;       // 新结点的 nextNode 为第 i - 1 个结点的 nextNode
    nodePointer->nextNode = newNode;     // 第 i - 1 个结点的 nextNode 为新插入的新结点

    headerNodePointer->data++;

    return true;
}

bool deleteNode(int i) {
    if (i > headerNodePointer->data) {
        cout << "需要删除的i值不合法" << endl;
        return false;
    }

    Node *pointer = headerNodePointer;
    int j = 0;
    while(pointer->nextNode != NULL && j < i - 1) {     // 找到待删除结点的前驱结点
        pointer = pointer->nextNode;
        j++;
    }

    Node *temp = pointer->nextNode;
    pointer->nextNode = temp->nextNode;
    delete temp;

    return true;
};

void deleteAllNode() {
    Node *pointer = headerNodePointer;
    while(pointer) {
        Node *temp = pointer->nextNode;
        delete pointer;
        pointer = temp;
    }
}

void printAllNode() {
    Node *pointer = headerNodePointer;
    while(pointer->nextNode != NULL) {
        pointer = pointer->nextNode;
        cout << pointer->data << " ";
    }
    cout << endl;
}

int main() {
    initLinkedList();

    insert(1, 39);
    int l = length();
    cout << "length: " << l << endl;
    insert(1, 22);
    l = length();
    cout << "length: " << l << endl;
    insert(3, 99);
    l = length();
    cout << "length: " << l << endl;
    printAllNode();

    Node *value = find(99);
    cout << value->data << endl;

    value = get(1);
    cout << value->data << endl;

    deleteAllNode();
    return 0;
}