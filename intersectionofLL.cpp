#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* getIntersection(Node* head1, Node* head2) {
    Node* a = head1;
    Node* b = head2;

    while (a->next && b->next) {
        if (a == b) {
            return a;
        }
        a = a->next;
        b = b->next;
    }

    if (!a->next) {
        int blen = 0;
        while (b->next) {
            blen++;
            b = b->next;
        }
        while (blen--) {
            head2 = head2->next;
        }
    }
    else {
        int alen = 0;
        while (a->next) {
            alen++;
            a = a->next;
        }
        while (alen--) {
            head1 = head1->next;
        }
    }

    while (head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    Node* head2 = new Node(10);
    head2->next = new Node(9);
    head2->next->next = new Node(8);
    head2->next->next->next = head1->next->next->next;  // Connecting to the same node in list 1

    Node* ans = getIntersection(head1, head2);

    if (ans) {
        cout << "Intersection point data: " << ans->data;
    } else {
        cout << "No intersection point found";
    }

    return 0;
}
