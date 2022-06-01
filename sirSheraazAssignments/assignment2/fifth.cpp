//Question no 5
//v.	Given an array, Rotate (shift left) an array of n elements to the right by k steps. 
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//After rotating the array add in into another array and display array index with minumum value if the sum of all the indexes having odd values is greater than sum of all the indexes having even values otherwise write all odd values in the text file and create linked list of all odd values using pointers.

#include<algorithm>
#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<vector>

using namespace std;

class Node{
    int main;
    Node* next;

    public:
        void set(int aMain){
            this->main = aMain;
        }
        void setNext(Node* aNext){
            this->next = aNext;
        }
        int get(){
            return this->main;
        }
        Node* getNext(){
            return this->next;
        }

};
class LinkedList{
    private:
        Node* headNode; 
        Node* currentNode;
        Node* lastCurrentNode;
        int size; 
    public:
        LinkedList(){
            this->headNode = new Node();
            this->headNode->setNext(NULL);
            this->currentNode = NULL;
            this->size = 0;
        }
        void add(int aMain){
            Node* newNode = new Node();
            newNode->set(aMain);
            if(this->currentNode != NULL){
                newNode->setNext(this->currentNode->getNext());
                this->currentNode->setNext(newNode);
                this->lastCurrentNode = this->currentNode;
                this->currentNode = newNode;
            }
            if(this->currentNode == NULL){
                newNode->setNext(NULL);
                this->headNode->setNext(newNode);
                this->lastCurrentNode = headNode;
                this->currentNode = newNode;
            }
            ++this->size;
        }
        int get(){
            if(this->currentNode != NULL){
                return this->currentNode->get();
            }
            return 0;
        }
        bool next(){
            if(this->currentNode == NULL){
                return false;
            }
            this->lastCurrentNode = this->currentNode;
            this->currentNode = this->currentNode->getNext();
            if(this->currentNode == NULL || size == 0){
                return false;
            }
            else{
                return true;
            }
        }
        void start(){
            this->lastCurrentNode = this->headNode;
            this->currentNode = this->headNode;
        }
        void remove(){
            if(this->currentNode != NULL && this->currentNode != this->headNode){
                this->lastCurrentNode->setNext(this->currentNode->getNext());
                //delete currentnode;
                this->currentNode = this->lastCurrentNode->getNext();
                size--;
            }
        }
        int length(){
            return size;
        }
};

vector<int> leftRotate(vector<int> array, int k){
    rotate(array.begin(), array.begin()+k, array.end());
    return array;
}
vector<int> rightRotate(vector<int> array, int k){
    rotate(array.begin(), array.begin()+array.size()-k, array.end());
    return array;
}
vector<int> createIndexes(vector<int> array, int n){
    for(int i = 0; i < n; ++i){
        int number = rand()%1000;
        array.push_back(number);
    }
    return array;
}
vector<int> addIndexes(vector<int> arrayToBeAdded, vector<int> array){
    for(int i = 0; i < array.size(); ++i){
        arrayToBeAdded.push_back(array[i]);
    }
    return arrayToBeAdded;
}
void takeInput(){
    
}
int main(){
    int n, k, t;
    cout << "Enter number of values in array: ";
    cin >> n;
    while(n < 0){
        cout << "Please enter a positive number: ";
        cin >> n;
    }
    
    cout << "Enter value less than " << n << " to rotate the array to right: ";
    cin >> k;
    while(k < 0 || k >= n){
        cout << "Please enter positive value less than " << n << " to proceed :";
        cin >> k;
    }
    cout << "Enter number of values in second array: ";
    cin >> t;
    while(t < 0){
        cout << "Please enter a positive number: ";
        cin >> t;
    }
    std::vector<int> array;
    array = createIndexes(array, n);
    
    std::cout << "original array: ";
    for (int i = 0; i < n; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << endl;
    vector<int> arrayRotated = rightRotate(array, k);
    std::cout << "Rotated Array: ";
    for (int i = 0; i < n; ++i){
        std::cout << arrayRotated[i] << " ";
    };
    cout << endl;
    vector<int> arrayToBeAddedInto; 
    arrayToBeAddedInto = createIndexes(arrayToBeAddedInto, t);
    cout << "Array to be added into = ";
    for (int i = 0; i < t; ++i){
        std::cout << arrayToBeAddedInto[i] << " ";
    };
    cout << endl;
    arrayToBeAddedInto = addIndexes(arrayToBeAddedInto, arrayRotated);
    cout << "Complete Added Array = ";
    for (int i = 0; i < arrayToBeAddedInto.size(); ++i){
        std::cout << arrayToBeAddedInto[i] << " ";
    };
    cout << endl;
    int sumOfOddIndexes = 0; int sumOfEvenIndexes = 0;
    vector<int> arrayOfOdd;
    for(int i = 0; i < arrayToBeAddedInto.size(); ++i){
        if(arrayToBeAddedInto[i]%2 == 0){
            sumOfEvenIndexes += i;
        }
        else{
            arrayOfOdd.push_back(arrayToBeAddedInto[i]);
            sumOfOddIndexes += i;
        }
    }
    if(sumOfOddIndexes > sumOfEvenIndexes){
        int min = arrayToBeAddedInto[0];
        for(int i = 0; i < arrayToBeAddedInto.size(); ++i){
            if(arrayToBeAddedInto[i] < min){
                min = arrayToBeAddedInto[i];
            }
        }
        cout << "Minimum Number = " << min << endl;
    }
    else{
        LinkedList listOfOdd;
        fstream odd_file;
        odd_file.open("odd_file.txt", ios_base::app | ios::out);
        for(int i = 0; i < arrayOfOdd.size(); ++i){
            odd_file << arrayOfOdd[i] << " ";
            listOfOdd.add(arrayOfOdd[i]);
        }
        odd_file << "\n";
        odd_file.close(); 
        listOfOdd.start();
        cout << "List Elements = ";
        while(listOfOdd.next()){
            cout << listOfOdd.get() << " ";
        }
        cout << endl;
    }
    return 0;
}