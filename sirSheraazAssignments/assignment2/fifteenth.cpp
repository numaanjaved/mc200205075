//Question no 15
//xv.	Given a list of 100 values, write a program which should display largest possible sum out of 100 values

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

template <class T>
class TreeNode{
    private:
        T* object;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode(){
            this->object = NULL;
            this->left = this->right = NULL;
        }
        TreeNode(T* object){
            this->left = NULL;
            this->right = NULL;
            this->object = object;
        }
        T* get(){
            return this->object;
        }
        void set(T* object){
            this->object = object;
        }
        TreeNode* getLeft(){
            return this->left;
        }
        void setLeft(TreeNode* object){
            this->left = object;
        }
        TreeNode* getRight(){
            return this->right;
        }
        void setRight(TreeNode* object){
            this->right = object;
        }
        bool isLeaf(){
            bool X = false;
            if(this->left == NULL && this->right == NULL){
                X = true;
            }
            return X;
        }
};
template <class T>
void insert(TreeNode<T>* Root, T* info){
    TreeNode<T>* Node = new TreeNode<T>(info);
    TreeNode<T>* p, * q;
    p = q = Root;
    while(*info != *(p->get()) && q != NULL){
        p = q; 
        if(*info < *(p->get())){
            q = p->getLeft();
            //cout << "Skipped to left of  " << *(p->get()) << " to place " << *(Node->get()) << endl;
        }
        else if(*info > *(p->get())){
            q = p->getRight();
            //cout << "Skipped to right of  " << *(p->get()) << " to place " << *(Node->get()) << endl;
        }
    }
    if(*info == *(p->get())){
        cout << "Attempt to enter duplicate value " << *(Node->get()) << endl;
        delete Node;
    }
    else if (*info < *(p->get())){
        p->setLeft(Node);
        //cout << "Entered value " << *(Node->get()) << " in left" << endl;
    }
    else{
        p->setRight(Node);
        //cout << "Entered value " << *(Node->get()) << " in right" << endl;
    }

}
template<class T>
void InOrder(TreeNode<T>* treeNode){
    if(treeNode != NULL){        
        InOrder(treeNode->getLeft());
        cout << *(treeNode->get()) << " ";
        InOrder(treeNode->getRight());
    }
}
template<class T>
T findMax(TreeNode<T>* treeNode){
    TreeNode<T>* current = treeNode;     
    while(current->getRight() != NULL){
        current = current->getRight();
        
    }        
    return *(current->get());
}
template<class T>
T find2ndMax(TreeNode<T>* treeNode, T firstLargest){
    TreeNode<T>* current = treeNode;     
    while(current->getRight() != NULL && *(current->getRight()->get()) != firstLargest){
        current = current->getRight();
    }        
    return *(current->get());
}
int main(){
    int number = 0; int largestNumber = 0; int secondLargestNumber = 0;
    vector<int> hundredValues;
    for(int i = 0; i < 100; ++i){
        number = rand()%1000;
        hundredValues.push_back(number);
    }
    
    TreeNode<int>* binaryHundred = new TreeNode<int>(&hundredValues[0]);
    for(int i = 1; i < hundredValues.size(); ++i){
        insert(binaryHundred, &hundredValues[i]);
    }
    largestNumber = findMax(binaryHundred);
    secondLargestNumber = find2ndMax(binaryHundred, largestNumber);
    cout << "Sum of " << largestNumber << " and " << secondLargestNumber << " is " << largestNumber + secondLargestNumber;
    return 0;
}