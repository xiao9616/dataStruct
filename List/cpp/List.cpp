//
// Created by user on 2019/9/18.
//

#include "List.h"


List::List() {
    head = tail = nullptr;
}

List::~List() {
    for (ListNode *p; !isEmpty();) {
        p = head->next;
        delete head;
        head = p;
    }
}

void List::add2head(int val) {
    head = new ListNode(val, head);
    if (tail == nullptr) {
        tail = head;
    }
}

void List::add2tail(int val) {
    if (tail != nullptr) {
        tail->next = new ListNode(val, nullptr);
        tail = tail->next;
    } else {
        head = tail = new ListNode(val, nullptr);
    }
}

int List::deleteFromHead() {
    int val = head->val;
    ListNode *p = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    delete p;
    head = head->next;
    return val;
}

int List::deleteFromTail() {
    int val = tail->val;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        ListNode *p;
        for (p = head; p->next != tail; p = p->next) {

        }
        delete tail;
        tail = p;
        tail->next = nullptr;
    }
    return val;
}

void List::deleteNode(int val) {
    if (head != nullptr) {
        if (head == tail && val == head->val) {
            delete head;
            head = tail = nullptr;
        } else if (val == head->val) {
            ListNode *p = head;
            head = head->next;
            delete p;
        } else {
            ListNode *prev, *p;
            for (prev = head, p = head->next; p != nullptr && p->val != val; p = p->next, prev = prev->next);
            if (p != nullptr) {
                prev->next = p->next;
                if (p == tail) {
                    tail = prev;
                }
                delete p;
            }
        }
    }
}

bool List::isEmpty() {
    return head == nullptr;
}

bool List::isExist(int val) {
    ListNode *p;
    for (p = head; p != nullptr && p->val != val; p = p->next) {

    }
    return p != nullptr;
}

bool List::showList() {
    cout << "List:";
    for (ListNode *p = head; p != nullptr; p = p->next) {

        if (p->next == nullptr) {
            cout << p->val;
        } else {
            cout << p->val << " -> ";
        }
    }
    cout << endl;
}


ListNode::ListNode(int val, ListNode *next) : val(val), next(next) {}
