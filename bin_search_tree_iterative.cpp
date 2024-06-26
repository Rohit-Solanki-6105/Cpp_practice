#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

class Bin_search_tree{
	struct node{
		node *parent;
		int data;
		
		node *left;
		node *right;
	};
	
	node *root;
	node *current;
	
	// Display function using in-order traversal
	// no need to be public method
	//only loop
//	void displayInOrder() {
//        node* current = root;
//        while (current != NULL) {
//            if (current->left == NULL) {
//                cout << current->data << ", ";
//                current = current->right;
//            }
//            else {
//                // Find the inorder predecessor
//                node* predecessor = current->left;
//                while (predecessor->right != NULL && predecessor->right != current) {
//                    predecessor = predecessor->right;
//                }
//
//                // Make current as the right child of its inorder predecessor
//                if (predecessor->right == NULL) {
//                    predecessor->right = current;
//                    current = current->left;
//                }
//                // Restore the tree and print the current node
//                else {
//                    predecessor->right = NULL;
//                    cout << current->data << ", ";
//                    current = current->right;
//                }
//            }
//        }
//    }
	
	
	public:
		Bin_search_tree() {
	        root = NULL; // Initialize root to NULL in the constructor
	    }

		void inorder() {
	        if (root == NULL)
	            return;
	
	        node* curr = root;
	        stack<node*> s;
	        while (curr != NULL || !s.empty()) {
	            while (curr != NULL) {
	                s.push(curr);
	                curr = curr->left;
	            }
	            curr = s.top();
	            s.pop();
	            cout << curr->data << ", ";
	            curr = curr->right;
        	}	
		}
		
		
		void postorder() {
            if (root == NULL)
                return;
    
            stack<node*> s1, s2;
            s1.push(root);
            while (!s1.empty()) {
                node* curr = s1.top();
                s1.pop();
                s2.push(curr);
                if (curr->left)
                    s1.push(curr->left);
                if (curr->right)
                    s1.push(curr->right);
            }
            while (!s2.empty()) {
                cout << s2.top()->data << ", ";
                s2.pop();
            }
        }

        void preorder() {
            if (root == NULL)
                return;
    
            stack<node*> s;
            s.push(root);
            while (!s.empty()) {
                node* curr = s.top();
                s.pop();
                cout << curr->data << ", ";
                if (curr->right)
                    s.push(curr->right);
                if (curr->left)
                    s.push(curr->left);
            }
        }
	
	    // Wrapper function to start in-order traversal from the root
	    void display() {
//	        displayInOrder(root);
		cout<<"In order: "; inorder(); cout<<"\n";
		cout<<"Post order: "; postorder(); cout<<"\n";
		cout<<"Pre order: "; preorder(); cout<<"\n";
	    }
	    
	    void insert(int data) {
	        node *newNode;
	        newNode = new node;
	        newNode->data = data;
	        
	        newNode->parent = NULL;
	        newNode->left = NULL;
	        newNode->right = NULL;
	        
	        if (!root) {
	            root = newNode;
	            return;    
	        }
	        
	        node *current = root;
	        while (true) {
	            if (data < current->data) {
	                if (current->left == NULL) {
	                    current->left = newNode;
	                    newNode->parent = current;
	                    break; // Inserted the node, so exit loop
	                }
	                
	                current = current->left;
	            } else {
	                if (current->right == NULL) {
	                    current->right = newNode;
	                    newNode->parent = current;
	                    break; // Inserted the node, so exit loop
	                }
	                
	                current = current->right;
	            }
	        }
	    }
	    
	    void deleteNode(int data) {
		    node *current = root;
		    node *parent = NULL;
		
		    // Find the node to be deleted
		    while (current != NULL && current->data != data) {
		        parent = current;
		        if (data < current->data){
		            current = current->left;
				}
		        else{
		            current = current->right;
				}
		    }
		
		    // If the node was not found
		    if (current == NULL) {
		        cout << "Node with data " << data << " not found." << endl;
		        return;
		    }
		
		    // Case 1: Node to be deleted has no or one child
		    if (current->left == NULL || current->right == NULL) {
		        node* child = (current->left != NULL) ? current->left : current->right;
		        if (parent == NULL){ // Deleting root
		            root = child;
		    	} 
				else if (parent->left == current){
		            parent->left = child;
				} 
				else{
		            parent->right = child;
				}
				
		        if (child != NULL){ // Update the parent pointer of the child node
		            child->parent = parent;
				}
				
		        delete current;
		    }
		    // Case 2: Node to be deleted has two children
		    else {
		        // Find the inorder smallest (smallest node in the right subtree)
		        node* smallest = current->right;
		        while (smallest->left != NULL){
		            smallest = smallest->left;
				}
		        
		        // Copy the smallest's data to the current node
		        current->data = smallest->data;
		
		        // Delete the smallest node (which can only have one right child at most)
		        if (smallest->parent->left == smallest){
		            smallest->parent->left = smallest->right;
				} 
				else{
		            smallest->parent->right = smallest->right;
				}
		
		        if (smallest->right != NULL){
		            smallest->right->parent = smallest->parent;
				}
				
		        delete smallest;
		    }
		}
};

int main(){
	int op;
	Bin_search_tree b1;
	int d;
//	b1.insert(1);
//	b1.insert(3);
//	b1.insert(2);
//	b1.insert(7);
//	b1.insert(4);
//	b1.display();
//	
//	b1.deleteNode(2);
//	b1.deleteNode(1);
//	b1.display();

	do{
		cout<<"\n-----------------------------\n"
			<<"1. Insert                     |\n"
			<<"2. delete data                |\n"
			<<"99. Display All               |\n"
			<<"0. exit                       |"<<endl
			<<">>>";
		cin>>op;
		cout<<"-----------------------------\n";
		
		switch(op){
			case 1:
				cout<<"Data: ";
				cin>>d;
				b1.insert(d);
				break;
			
			case 2:
				cout<<"Data: ";
				cin>>d;
				b1.deleteNode(d);
				break;
			
			case 99:
				b1.display();
				break;
				
			case 0:
				cout<<"Exiting...";
				break;
				
			default:
				cout<<"Invalid Option..."<<endl;
				break;
		}
	} while(op != 0);
	getch();
	return 0;
}
