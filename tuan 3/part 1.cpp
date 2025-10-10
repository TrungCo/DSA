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
    void sort_int() {
        sort(number, number + n, greater<int>());
    }

    void change_value(int x, int val) {
        number[x] = val;
    };
};

class PriorityQueue {
private:
    interger_number Queue;

public:
    void insert(int x) {
        Queue.add(x);
        Queue.sort_int();
    }

    int del_Max() {
        int temp = Queue.access(1);
        Queue.delet_head();
        return temp;
    }

    bool isEmpty() {
        return Queue.n == 0;
    }

    int max_queue() {
        return Queue.access(1);
    }

    int size_queue() {
        return Queue.n;
    }
};

class BinaryHeap {
private:
    interger_number Heap;

public:
    void browse_heap() {
        Heap.browse();
    }

    void insert(int x) {
        Heap.add(x);
        int i = Heap.n - 1;

        while (i > 0) {
            if (Heap.access(i + 1) >= Heap.access((i - 1) / 2 + 1)) {
                int temp = Heap.access(i + 1);

                Heap.change_value(i, Heap.access((i - 1) / 2 + 1));

                Heap.change_value((i - 1) / 2, temp);
                i = (i - 1) / 2;
            } else {
                i = -1;
            }
        }
    }
    int delMax() {
        int out = Heap.access(1);
        int temp = Heap.access(1);
        Heap.change_value(0, Heap.access(Heap.n));
        Heap.change_value(Heap.n, temp);
        Heap.delet();
        int i=0;
        bool check = true;
        while (check) {
            if (i>=(Heap.n-1)/2) {
                check = false;
            }
            if (Heap.access(i+1)<=Heap.access(i*2+1 + 1)) {
                int temp1 = Heap.access(i + 1);
                Heap.change_value(i, Heap.access(i*2+1 + 1));
                Heap.change_value(i*2+1, temp1);
                i = i*2 + 1;
            }
            else if (Heap.access(i+1)<=Heap.access(i*2+2 + 1)) {
                int temp1 = Heap.access(i + 1);
                Heap.change_value(i, Heap.access(i*2+2 + 1));
                Heap.change_value(i*2+2, temp1);
                i = i*2 + 2;
            }
            else {
                check = false;
            }
        }
        return out;
    }
    bool isEmpty() {
        return Heap.n == 0;
    }
    int max_heap() {
        return Heap.access(1);
    }
    int size_heap() {
        return Heap.n;
    }
    void swim(int k) {
        Heap.add(k);
        int i = Heap.n - 1;

        while (i > 0) {
            if (Heap.access(i + 1) >= Heap.access((i - 1) / 2 + 1)) {
                int temp = Heap.access(i + 1);

                Heap.change_value(i, Heap.access((i - 1) / 2 + 1));

                Heap.change_value((i - 1) / 2, temp);
                i = (i - 1) / 2;
            } else {
                i = -1;
            }
        }
    }
    

};

int main() {
    BinaryHeap a;
    a.insert(10);
    a.insert(8);
    a.insert(6);
    a.insert(4);
    a.insert(5);

    cout << a.delMax() << endl;
    a.browse_heap();


    return 0;
}

//
// Created by Trung Thanh on 10/2/2025.
//
