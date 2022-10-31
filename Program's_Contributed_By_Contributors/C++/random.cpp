#include<bits/stdc++.h>
using namespace std;
class node{

    public:
           int data;
           node* left;
           node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"\nEnter the data: ";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"\nEnter in left of "<<data<<": ";
    root->left = buildTree(root->left);
    cout<<"\nEnter in right of "<<data<<": ";
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level complete traverse ho gya
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            if(temp -> left){
               q.push(temp -> left);
            }
            if(temp -> right){
               q.push(temp -> right);
            }

        }

    }
}

int preorderTraversal(node* root){
    if(root == NULL)
    return 1;

    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
    cout<<root -> data<<" ";
}

int main(){
    
    node* root = NULL;
    //for creating tree;
    root = buildTree(root);
    //for display
    cout<<"\norder of traversal\n";
    levelOrderTraversal(root);
    cout<<"\npreorder Traversal \n ";
    preorderTraversal(root);
    return 1;
} 