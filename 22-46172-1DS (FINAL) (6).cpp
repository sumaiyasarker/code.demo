#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct StudentRecord {
    string id;
    string name;
    int age;
    int NumberOfFriends;
    string* friendId;
    StudentRecord* next;
};


struct Node {
    int index;
    Node* next;
};


void addEdge(Node** adjList, int src, int dest) {
    Node* newNode = new Node;
    newNode->index = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}


Node** buildAdjList(StudentRecord* head, int n) {
    Node** adjList = new Node*[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    StudentRecord* curr = head;
    int i = 0;
    while (curr != NULL) {
        for (int j = 0; j < curr->NumberOfFriends; j++) {
            string friendId = curr->friendId[j];

            int friendIndex = 0;
            StudentRecord* temp = head;
            while (temp != NULL) {
                if (temp->id == friendId) {
                    break;
                }
                friendIndex++;
                temp = temp->next;
            }
            addEdge(adjList, i, friendIndex);
            addEdge(adjList, friendIndex, i);
        }
        curr = curr->next;
        i++;
    }
    return adjList;
}


int bfs(Node** adjList, int n, int src) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    queue<int> q;
    int numFriends = 0;
    visited[src] = true;
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        Node* temp = adjList[curr];
        while (temp != NULL) {
            int neighbor = temp->index;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                numFriends++;
                q.push(neighbor);
            }
            temp = temp->next;
        }
    }
    delete[] visited;
    return numFriends;
}


StudentRecord* findStudentRecord(StudentRecord* head, string id) {
    StudentRecord* curr = head;
    while (curr != NULL) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int main() {
    int n;
    cout << "Total number of student records: ";
    cin >> n;


    StudentRecord* head = NULL;
    StudentRecord* tail = NULL;
    for (int i = 0; i < n; i++) {
        cout << "Student Record " << i + 1 <<":\n";

      StudentRecord* newRecord = new StudentRecord;


    cout << "Student ID: ";
    cin >> newRecord->id;
    cout << "Name of student: ";
    cin >> newRecord->name;
    cout << "Age of student: ";
    cin >> newRecord->age;
    cout << "Number of friends: ";
    cin >> newRecord->NumberOfFriends;


    newRecord->friendId = new string[newRecord->NumberOfFriends];

    cout << "Friend's ID (separated by spaces) : ";
    for (int j = 0; j < newRecord->NumberOfFriends; j++) {
        cin >> newRecord->friendId[j];
    }


    newRecord->next = NULL;
    if (head == NULL) {
        head = newRecord;
        tail = newRecord;
    }
    else {
        tail->next = newRecord;
        tail = newRecord;
    }
}


Node** adjList = buildAdjList(head, n);

string searchId;
cout << "Enter the ID of the student to find the number of friends: ";
cin >> searchId;

StudentRecord* search_record = findStudentRecord(head, searchId);

if (search_record == NULL) {
    cout << "Student not found\n";
}
else {
    int searchIndex = 0;
    StudentRecord* temp = head;
    while (temp != search_record) {
        searchIndex++;
        temp = temp->next;
    }
    int numFriends = bfs(adjList, n, searchIndex);
    cout << "Number of his/her friends: " << numFriends << endl;
}


StudentRecord* curr = head;
while (curr != NULL) {
    StudentRecord* temp = curr;
    curr = curr->next;
    delete[] temp->friendId;
    delete temp;
}
for (int i = 0; i < n; i++) {
    Node* curr = adjList[i];
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
delete[] adjList;

return 0;
}

