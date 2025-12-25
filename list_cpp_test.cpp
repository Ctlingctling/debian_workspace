#include<iostream>

using namespace std;

struct Node {
        int data;
        Node* next;// So cpp-stylish this is...
        Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
        private:
                Node* head;
                Node* tail;

        public:
                LinkedList() : head(nullptr), tail(nullptr) {}

                ~LinkedList() {
                        while (head != nullptr) {
                                Node* temp = head;
                                head = head->next;
                                delete temp;
                        }
                }

                void append(int val) {
                        Node* newNode = new Node(val);
                        if (head == nullptr) {
                                head = newNode;
                                tail = newNode;
                        } else {
                                tail->next = newNode;
                                tail = newNode;
                        }
                }

                void print() {
                        Node* temp = head;
                        while (temp != nullptr) {
                                std::cout << temp->data << "->";
                                temp = temp->next;
                        }
                        std::cout << "nullptr" << std::endl;
                }

                void reverse() {
                        Node* prev = nullptr;
                        Node* curr = head;
                        Node* next_temp = nullptr;

                        tail = head;

                        while (curr != nullptr) {
                                next_temp = curr->next;
                                curr->next = prev;

                                prev = curr;
                                curr = next_temp;
                        }

                        head = prev;
                }
};

int main()
{
      //  std::list<int> test;

      //  test.push_back(10);
      //  test.push_front(20);
      //  test.push_back(30);

      //  test.pop_front();
      //  test.pop_back();

      //  test.push_front(30);

      //  test.sort();
      //  test.reverse();
        LinkedList list;
        int n, val;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
                std::cin >> val;
                list.append(val);
        }
        list.print();
        list.reverse();
        list.print();
        return 0;
}
