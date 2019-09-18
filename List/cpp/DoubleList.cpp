//
// Created by user on 2019/9/18.
//

#include "DoubleList.h"

DListNode::DListNode(DListNode *prev, DListNode *next, int val) : prev(prev), next(next), val(val) {}

DListNode::~DListNode() {
    prev = next = nullptr;
}

DoubleList::DoubleList(DListNode *head, DListNode *tail) : head(head), tail(tail) {}

DoubleList::~DoubleList() {
    head = tail = nullptr;
}

void DoubleList::add2head(int val) {
    if (head != nullptr) {
        head->prev = new DListNode(nullptr, head, val);
        head = head->prev;
    } else {
        head = tail = new DListNode(nullptr, nullptr, val);
    }
}

void DoubleList::add2tail(int val) {
    if (tail != nullptr) {
        tail->next = new DListNode(tail, nullptr, val);
        tail = tail->next;
    } else {
        head = tail = new DListNode(nullptr, nullptr, val);
    }
}

int DoubleList::deleteFromHead() {
    int val = head->val;
    DListNode *p = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    head->next->prev = nullptr;
    head = head->next;
    delete p;
    return val;
}

int DoubleList::deleteFromTail() {
    int val = tail->val;
    DListNode *p = tail;
    if (head == tail) {
        head = tail = nullptr;
    }
    tail->prev->next = nullptr;
    tail = tail->prev;
    delete p;
    return val;
}

void DoubleList::deleteNode(int val) {
    if (head != nullptr) {
        if (head == tail && val == head->val) {
            delete head;
            head = tail = nullptr;
        } else {
            DListNode *p;
            for(p=head;p!= nullptr&&p->val!=val;p=p->next);
            if(p==tail){
                tail = p->prev;
                tail->next = nullptr;
            }else{
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;
        }

    }
}

bool DoubleList::isEmpty() {
    return head == nullptr;
}

bool DoubleList::isExist(int val) {
    DListNode *p;
    for (p = head; p != nullptr && p->val != val; p = p->next);
    return p != nullptr;
}

bool DoubleList::showList() {
    cout << "DoubleList:";
    for (DListNode *p = head; p != nullptr; p = p->next) {
        if (p->next == nullptr) {
            cout << p->val;
        } else {
            cout << p->val << " <-> ";
        }
    }
    cout << endl;
}
