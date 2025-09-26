#include <bits/stdc++.h>
#include <vector>

struct node {
    int data;
    node *next;
};

int access(int _n, node *head) {
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
}//o[2n]

int main() {
    node *head;
    head = NULL;
    add(1, head);
    add(2, head);
    add(3, head);
    insert_ll(1, 36, head);
    duyet_invert(head);

    return 0;
}
