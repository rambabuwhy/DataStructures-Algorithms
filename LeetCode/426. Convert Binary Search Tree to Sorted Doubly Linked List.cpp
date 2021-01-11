/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    void toDll(Node* root){
        if(root){
            toDll(root->left);
            
            if(last){
                last->right = root;
                root->left=last;
                
            }else{
                
                first = root;
            }
            
            last=root;

            toDll(root->right);
        }
        
        
    }
    Node* treeToDoublyList(Node* root) {
        first=last=nullptr;
        
        if(root == nullptr)
        return nullptr;
        toDll(root);
        
        last->right=first;
        first->left=last;
        
        return first;
    }
private:
    Node* first;
    Node* last;
};
