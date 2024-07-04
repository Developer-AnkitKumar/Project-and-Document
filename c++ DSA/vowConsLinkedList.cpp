#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* arrangeVowCon(Node* head) {
    if (!head) {
        return nullptr;
    }

    Node* vowels = nullptr;
    Node* consonants = nullptr;
    Node* curr = head;

    while (curr) {
        if (curr->data == 'a' || curr->data == 'e' || curr->data == 'i' || curr->data == 'o' || curr->data == 'u'
            || curr->data == 'A' || curr->data == 'E' || curr->data == 'I' || curr->data == 'O' || curr->data == 'U') {

            if (!vowels) {
                vowels = curr;
            } else {
                vowels->next = curr;
                vowels = vowels->next;
            }
        } else {
            if (!consonants) {
                consonants = curr;
            } else {
                consonants->next = curr;
                consonants = consonants->next;
            }
        }

        curr = curr->next;
    }

    if (!vowels) {
        return consonants;
    }

    vowels->next = consonants;
    if (consonants) {
        consonants->next = nullptr;
    }

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('i');
    head->next->next->next = new Node('k');
    head->next->next->next->next = new Node('e');

    cout << "Original linked list: ";
    printList(head);

    head = arrangeVowCon(head);

    cout << "Rearranged linked list: ";
    printList(head);
    return 0;
}