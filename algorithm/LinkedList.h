#pragma once
#include "DataType.h"

class LinkedList {
public:
    class LinkedListNode {
    public:
        LinkedListNode* getNext() const noexcept { return next; }
    private:
        LinkedListNode* next;
        DataType data;
        friend class LinkedList;
    };
    ~LinkedList() { clear(); }
    DataType get(size_t pos) const {
        return getNode(pos)->data;
    }
    void set(size_t pos, DataType data) {
        getNode(pos)->data = data;
    }
    // insert a node after the node
    void insert(LinkedListNode* node, DataType data) {
        auto next = node->next;
        auto newNode = new LinkedListNode;
        newNode->next = next;
        newNode->data = data;
        node->next = newNode;
    }
    void insert(size_t pos, DataType data) {
        insert(getNode(pos), data);
    }
    void insertHead(DataType data) {
        if (head == nullptr) {
            head = new LinkedListNode;
            head->next = nullptr;
            head->data = data;
            return;
        }
        auto newNode = new LinkedListNode;
        newNode->next = head;
        newNode->data = data;
        head = newNode;
    }
    // remove the node RIGHT AFTER the node
    void removeAfter(LinkedListNode* node) {
        if (node->next == nullptr) throw BadArgument();
        auto next = node->next->next;
        delete node->next;
        node->next = next;
    }
    void remove(size_t pos) {
        if(pos==0) {
            head = head->next;
            return;
        }
        removeAfter(getNode(pos - 1));
    }
    size_t size() const noexcept {
        auto node = head;
        if (node == nullptr) return 0;
        size_t count = 1;
        while (node = node->next) count++;
        return count;
    }
    LinkedListNode* getHead() noexcept { return head; }
    const LinkedListNode* getHead() const noexcept { return head; }
    const LinkedListNode* getNode(size_t pos) const {
        LinkedListNode* current = head;
        if (current == nullptr) throw BadArgument();
        while (pos) {
            current = current->next;
            if (current == nullptr) throw BadArgument();
            if (pos-- == 0) break;
        }
        return current;
    }
    LinkedListNode* getNode(size_t pos) {
        return const_cast<LinkedListNode*>(const_cast<const LinkedList*>(this)->getNode(pos));
    }
    void clear() noexcept {
        while (size() > 0) remove(0);
    }
    struct BadArgument {};
private:
    LinkedListNode* head = nullptr;
};