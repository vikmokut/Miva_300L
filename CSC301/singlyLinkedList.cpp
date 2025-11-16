#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Node structure representing each element in the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor for easy node creation
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class to manage all operations
class LinkedList {
private:
    Node* head;  // Pointer to the first node
    int size;    // Track the number of nodes
    
public:
    // Constructor initializes empty list
    LinkedList() : head(nullptr), size(0) {}
    
    // Destructor to free all allocated memory
    ~LinkedList() {
        clear();
    }
    
    // Add node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
        cout << " Inserted " << value << " at the beginning." << endl;
    }
    
    // Add node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If list is empty, new node becomes head
        if (head == nullptr) {
            head = newNode;
            size++;
            cout << "Inserted " << value << " at the end (empty list)." << endl;
            return;
        }
        
        // Traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        size++;
        cout << "Inserted " << value << " at the end." << endl;
    }
    
    // Add node at a specific position (0-indexed)
    void insertAtMiddle(int value, int position) {
        // Validate position
        if (position < 0 || position > size) {
            throw out_of_range("Invalid position! Position must be between 0 and " + to_string(size));
        }
        
        // If position is 0, insert at beginning
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        // If position equals size, insert at end
        if (position == size) {
            insertAtEnd(value);
            return;
        }
        
        // Traverse to the node before the insertion point
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        
        // Create new node and link it
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        cout << " Inserted " << value << " at position " << position << "." << endl;
    }
    
    // Delete node by position (0-indexed)
    void deleteByPosition(int position) {
        // Check if list is empty
        if (head == nullptr) {
            throw runtime_error("Cannot delete from an empty list!");
        }
        
        // Validate position
        if (position < 0 || position >= size) {
            throw out_of_range("Invalid position! Position must be between 0 and " + to_string(size - 1));
        }
        
        Node* temp = head;
        
        // If deleting the first node
        if (position == 0) {
            head = head->next;
            cout << " Deleted node with value " << temp->data << " from position 0." << endl;
            delete temp;
            size--;
            return;
        }
        
        // Traverse to the node before the one to delete
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted node with value " << nodeToDelete->data << " from position " << position << "." << endl;
        delete nodeToDelete;
        size--;
    }
    
    // Delete node by value (deletes first occurrence)
    void deleteByValue(int value) {
        // Check if list is empty
        if (head == nullptr) {
            throw runtime_error("Cannot delete from an empty list!");
        }
        
        // If the head node contains the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node with value " << value << "." << endl;
            delete temp;
            size--;
            return;
        }
        
        // Search for the node with the value
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        // If value not found
        if (temp->next == nullptr) {
            throw runtime_error("Value " + to_string(value) + " not found in the list!");
        }
        
        // Delete the node
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted node with value " << value << "." << endl;
        delete nodeToDelete;
        size--;
    }
    
    // Display all nodes in the list
    void display() const {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
        cout << "Size: " << size << " nodes" << endl;
    }
    
    // Get the current size of the list
    int getSize() const {
        return size;
    }
    
    // Clear all nodes from the list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
    
    // Check if list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
};

// Helper function to print section headers
void printSection(const string& title) {
    cout << "\n" << string(50, '=') << endl;
    cout << title << endl;
    cout << string(50, '=') << endl;
}

// Test Case 1: Basic operations
void testCase1() {
    printSection("TEST CASE 1: Basic Insert and Delete Operations");
    
    LinkedList list;
    
    cout << "\n||====> Inserting elements <====||" << endl;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    
    cout << "\n||====> Insert at beginning <====||" << endl;
    list.insertAtBeginning(5);
    list.display();
    
    cout << "\n||====> Insert at middle (position 2) <====||" << endl;
    list.insertAtMiddle(15, 2);
    list.display();
    
    cout << "\n||====> Delete by position (position 3) <====||" << endl;
    list.deleteByPosition(3);
    list.display();
    
    cout << "\n||====> Delete by value (value 15) <====||" << endl;
    list.deleteByValue(15);
    list.display();
}

// Test Case 2: Edge cases and error handling
void testCase2() {
    printSection("TEST CASE 2: Edge Cases and Error Handling");
    
    LinkedList list;
    
    cout << "\n||====> Attempting to delete from empty list <====||" << endl;
    try {
        list.deleteByPosition(0);
    } catch (const exception& e) {
        cout << "X Error caught: " << e.what() << endl;
    }
    
    cout << "\n||====> Insert into empty list <====||" << endl;
    list.insertAtBeginning(100);
    list.display();
    
    cout << "\n||====> Attempting invalid position insertion <====||" << endl;
    try {
        list.insertAtMiddle(200, 5);
    } catch (const exception& e) {
        cout << "X Error caught: " << e.what() << endl;
    }
    
    cout << "\n||====> Valid insertion at position 1 <====||" << endl;
    list.insertAtMiddle(150, 1);
    list.display();
    
    cout << "\n||====> Attempting to delete non-existent value <====||" << endl;
    try {
        list.deleteByValue(999);
    } catch (const exception& e) {
        cout << "X Error caught: " << e.what() << endl;
    }
    
    cout << "\n====> Delete all elements <====" << endl;
    list.deleteByPosition(0);
    list.deleteByPosition(0);
    list.display();
}

// Test Case 3: Large list operations
void testCase3() {
    printSection("TEST CASE 3: Operations on Larger List");
    
    LinkedList list;
    
    cout << "\n||====> Building list with values 2, 4, 6, 8, 10, 12 <====||" << endl;
    for (int i = 2; i <= 12; i += 2) {
        list.insertAtEnd(i);
    }
    list.display();
    
    cout << "\n||====> Insert 1 at beginning <====||" << endl;
    list.insertAtBeginning(1);
    list.display();
    
    cout << "\n||====> Insert 7 at position 4 <====||" << endl;
    list.insertAtMiddle(7, 4);
    list.display();
    
    cout << "\n||====> Insert 14 at end <====||" << endl;
    list.insertAtEnd(14);
    list.display();
    
    cout << "\n||====> Delete values 1, 7, and 14 <====||" << endl;
    list.deleteByValue(1);
    list.deleteByValue(7);
    list.deleteByValue(14);
    list.display();
    
    cout << "\n||====> Delete positions 0 and 2 <====||" << endl;
    list.deleteByPosition(0);
    list.deleteByPosition(2);
    list.display();
}

// Main function
int main() {
    cout << "\n";
    cout << "||=============================================||" << endl;
    cout << "||   SINGLY LINKED LIST IMPLEMENTATION IN C++  ||" << endl;
    cout << "||=============================================||" << endl;
    
    try {
        testCase1();
        testCase2();
        testCase3();
        
        printSection("ALL TESTS COMPLETED SUCCESSFULLY");
        
    } catch (const exception& e) {
        cout << "\nX Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
