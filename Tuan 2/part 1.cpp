#include <bits/stdc++.h>
#include <vector>
using namespace std;

//no
struct node {
    int data;
    node *next;
};

int access(int _n, node *head) {
    _n--;
    node *a = head;
    for (int i = 0; i < _n; i++) {
        a = a->next;
    }
    std::cout << a->data << std::endl;
    return a->data;
} //o[n]
void add(int x, node *&head) {
    node *new_node = new node;
    node *temp = head;
    new_node->next = NULL;
    new_node->data = x;
    if (head == NULL) {
        head = new_node;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
} //o[n]

void add_head(int x, node *&head) {
    node *new_node = new node;
    new_node->data = x;
    new_node->next = head;
    head = new_node;
} //o[1]

void insert_ll(int x, int a, node *&head) {
    node *new_node = new node;
    node *temp1 = head;
    node *temp2 = head;
    for (int i = 0; i < x; i++) {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    new_node->data = a;
    new_node->next = temp2;
    temp1->next = new_node;
} //o[n]
void delete_hll(node *&head) {
    head = head->next;
} //o[1]

void delete_tll(node *&head) {
    node *temp1 = head;
    while (temp1->next->next != NULL) {
        temp1 = temp1->next;
    }

    temp1->next = NULL;
} //o[n]

void delete_insert(int x, node *&head) {
    node *temp1 = head;
    node *temp2 = head;
    for (int i = 0; i < x - 1; i++) {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
} //o[n]


void duyet(node *head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    } //o[n]
}

void duyet_invert(node *head) {
    std::vector<int> v;
    node *temp = head;

    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i] << " ";
    }
} //o[2n]

// interger_number
class interger_number {
private:
    int *number;

public:
    int n;

    interger_number() {
        n = 0;
        number = new int[n];
    };

    int access(int _n) {
        return number[_n - 1];
    }

    void add(int x) {
        number[n] = x;
        n++;
    }; //o[1]
    void add_head(int x) {
        n++;
        int a, b;
        a = number[0];
        number[0] = x;
        for (int i = 1; i < n; i++) {
            b = number[i];
            number[i] = a;
            a = b;
        }
    } //o[n]
    void insert_int(int x, int a) {
        n++;
        for (int i = n - 1; i > x; i--) {
            number[i] = number[i - 1];
        }
        number[x] = a;
    } //o[n]
    void delet_head() {
        for (int i = 0; i < n - 1; i++) {
            number[i] = number[i + 1];
        }
        n--;
    } //o[n]
    void delet() {
        n--;
    } //o[1]
    void delet_x(int x) {
        for (int i = x; i < n - 1; i++) {
            number[i] = number[i + 1];
        }
        n--;
    } //o[n]
    void browse() {
        for (int i = 0; i < n; i++) {
            cout << number[i];
            cout << " ";
        }
    } //o[n]
    void browse_in() {
        for (int i = n - 1; i >= 0; i--) {
            cout << number[i];
            cout << " ";
        }
    } //o[n]
};

// Queue
class Queue {
private:
    interger_number queue_list;
    int head = 0;
    int &tail = queue_list.n;

public:
    Queue(int _size) {
        queue_list.n = _size;
    }

    bool isEmpty() {
        if (queue_list.n == 0) {
            return true;
        }
        return false;
    }

    void push(int x) {
        queue_list.add(x);
    }

    int pop() {
        int a = queue_list.access(tail);
        queue_list.delet();
        return a;
    }

    int top() {
        return queue_list.access(head);
    }

    int size() {
        return queue_list.n;
    }
};

//Stack
class Stack {
private:
    node *Stack_head = nullptr;
    int n = 0;

public:
    Stack() {
        n = 0;
    }

    bool isEmpty() {
        if (Stack_head == nullptr) {
            return true;
        }
        return false;
    }

    void push(int x) {
        add(x, Stack_head);
        n++;
    }

    int pop() {
        int a = access(n, Stack_head);
        delete_tll(Stack_head);
        n--;
        return a;
    }

    int top() {
        return access(n, Stack_head);
    }

    int size() {
        return n;
    }
};


int main() {
    Queue a(10);
    Stack b;

    b.push(1);
    b.push(2);
    b.push(3);

    cout << b.size();

    b.pop();
    cout << b.size();
    b.pop();
    b.pop();
    b.pop();


    return 0;
}

//
// Created by Trung Thanh on 10/2/2025.
//
