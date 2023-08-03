#include <stack>

class Stack {
private:
    struct Node {
        int value;
        int min;
        Node* prev;
    };
    Node* head_ = nullptr;

public:
    Stack() = default;

    void Push(int x) {
        Node* node = new Node();
        node->value = x;
        node->prev = head_;
        if (head_ == nullptr) {
            node->min = x;
        } else {
            node->min = std::min(x, head_->min);
        }
        head_ = node;
    }

    int Top() {
        return head_->value;
    }

    int Min() {
        return head_->min;
    }

    void Pop() {
        Node* new_head = head_->prev;
        delete head_;
        head_ = new_head;
    }

    bool Empty() {
        return head_ == nullptr;
    }

    void Clear() {
        while (!Empty()) {
            Pop();
        }
    }

    ~Stack() {
        Clear();
    }
};
