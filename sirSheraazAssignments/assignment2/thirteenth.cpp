//Question no 13
//xiii.	Write a program which should traverse given 20 values using Binary Tree.

#include<iostream>
#include<stdio.h>
#include<time.h>
//Bug: Not taking all inputs in binary tree / not displaying all entries
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
    p = q = Root; int coun = 0;
    // cout << "root  " << *(Root->get()) << endl;
    while(*info != *(p->get()) && q != NULL){
        ++coun;
        // cout << coun << endl;
        p = q; 
        if(*info < *(p->get())){
            q = p->getLeft();
            // cout << "q " << q << endl;
            // cout << " inside less" << endl;
            // cout << "info  " << *info << endl;
            // cout << "p get " << *(p->get()) << endl;
            //cout << "p->getleft " << *(q->get()) << endl;
            // cout << endl;
            // cout << "Skipped to left of  " << *(p->get()) << " to place " << *(Node->get()) << " " << count << endl;
        }
        else if(*info > *(p->get())){
            q = p->getRight();
            // cout << "q " << q;
            // cout << " inside greater" << endl;
            // cout << "info  " << *info << endl;
            // cout << "p get " << *(p->get()) << endl;
            //cout << "p->getleft " << *(q->get()) << endl;
            // cout << endl;
            // cout << "Skipped to right of  " << *(p->get()) << " to place " << *(Node->get()) << " " << count << endl;
        }
        // ++count;
    }
    if(*info == *(p->get())){
        cout << "Attempt to enter duplicate value " << *(Node->get()) << endl;
        delete Node;
    }
    else if(*info < *(p->get())){
        p->setLeft(Node);
        // cout << "info  " << *info << endl;
        // cout << "p get " << *(p->get()) << endl;
        // cout << "p left " << *(p->getLeft()->get()) << endl;
        // ++coun;
        // cout << "Entered value " << *(Node->get()) << " in left"  << " " << count << endl;
    }
    else{
        p->setRight(Node);
        // cout << "info  " << *info << endl;
        // cout << "p get " << *(p->get()) << endl;
        // cout << "p right " << *(p->getRight()->get()) << endl;
        // ++coun;
        // cout << "Entered value " << *(Node->get()) << " in right"  << " " << count << endl;
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
int main(){
    int array[20];
    srand(time(NULL));
    for(int i = 0; i < 20; ++i){
        array[i] = rand()%30;
    }
    TreeNode<int>* binaryTree = new TreeNode<int>(&array[0]);
    for(int i = 0; i < 20; ++i){
        cout << array[i] << " "; 
    }
    cout << endl;
    for(int i = 1; i < 20; ++i){
        insert(binaryTree, &array[i]);
    }
    InOrder(binaryTree);
    cout << endl;
    return 0;
}