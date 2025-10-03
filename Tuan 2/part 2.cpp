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
void SelectionSort(int n, int arr[]) {

    for (int i = 0; i < n; i++) {
        int _min = arr[i];
        int wher = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < _min) {
                _min = arr[j];
                wher = j;
            }

        }
        if (i != wher) {
            arr[wher]= arr[i];
            arr[i] = _min;
        }
    }
}

void BubbleSort(int n, int arr[]) {
    int tail = n;
    while (tail >= 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            tail --;
        }
    }
}
void InsertSort(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int BinarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}

int main() {
    int a[5]={2,1,5,7,3};
    int n = 5;
    BubbleSort(n,a);
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}

//
// Created by Trung Thanh on 10/2/2025.
//
