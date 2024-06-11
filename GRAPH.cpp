#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class Graph {
    struct node {
        char vertex;  // Vertex this edge points to
        int weight;
        node *down;
    };

    struct List {
        char vertex;  // Vertex label
        node *down;
        List *next;
    };

    List *head;
    int length = 0;
    
    List* findVertex(char vertex) {
        List *current = head;
        while (current != nullptr) {
            if (current->vertex == vertex) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int findIndex(char *vertices, char vertex, int length) {
        for (int i = 0; i < length; ++i) {
            if (vertices[i] == vertex) {
                return i;
            }
        }
        return -1;
    }

	public:
	    Graph(){
	    	head = nullptr;
		}
	
	    void insertVertex(char vertex) {
	        List *newList = new List;
	        newList->vertex = vertex;
	        newList->down = nullptr;
	        newList->next = nullptr;
	
	        if (head == nullptr) {
	            head = newList;
	        } else {
	            List *current = head;
	            while (current->next != nullptr) {
	                current = current->next;
	            }
	            current->next = newList;
	        }
	
	        length++;
	    }
	
	    void insertEdge(char from, char to, int weight) {
	        List *fromList = findVertex(from);
	        List *toList = findVertex(to);
	
	        if (fromList == nullptr) {
	            insertVertex(from);
	            fromList = findVertex(from);
	        }
	        if (toList == nullptr) {
	            insertVertex(to);
	            toList = findVertex(to);
	        }
	
	        node *newNode = new node;
	        newNode->vertex = to;
	        newNode->weight = weight;
	        newNode->down = nullptr;
	
	        if (fromList->down == nullptr) {
	            fromList->down = newNode;
	        } else {
	            node *currentNode = fromList->down;
	            while (currentNode->down != nullptr) {
	                currentNode = currentNode->down;
	            }
	            currentNode->down = newNode;
	        }
	    }
	
	    void display() {
	        List *currentList = head;
	        while (currentList != nullptr) {
	            cout << "Vertex " << currentList->vertex << " connects to: ";
	            node *currentNode = currentList->down;
	            while (currentNode != nullptr) {
	                cout << currentNode->vertex << "(" << currentNode->weight << ") ";
	                currentNode = currentNode->down;
	            }
	            cout << endl;
	            currentList = currentList->next;
	        }
	    }
	
	    void displayMatrix() {
	        if (length == 0) {
	            cout << "Graph is empty" << endl;
	            return;
	        }
	
	        // Create a map of vertex to index
	        char *vertices = new char[length];
	        List *currentList = head;
	        int index = 0;
	        while (currentList != nullptr) {
	            vertices[index++] = currentList->vertex;
	            currentList = currentList->next;
	        }
	
	        // Initialize the matrix with zeros
	        int **matrix = new int*[length];
	        for (int i = 0; i < length; ++i) {
	            matrix[i] = new int[length]();
	        }
	
	        // Fill the matrix with edge weights
	        currentList = head;
	        while (currentList != nullptr) {
	            int fromIndex = findIndex(vertices, currentList->vertex, length);
	            node *currentNode = currentList->down;
	            while (currentNode != nullptr) {
	                int toIndex = findIndex(vertices, currentNode->vertex, length);
	                matrix[fromIndex][toIndex] = currentNode->weight;
	                currentNode = currentNode->down;
	            }
	            currentList = currentList->next;
	        }
	
	        // Print the matrix
	        
	        cout << setw(12) << "";
	        for (int i = 0; i < length; ++i) {
	            cout << setw(10) << vertices[i] << " |";
	        }
	        cout << endl;
	
	        for (int i = 0; i < length; ++i) {
	            cout << setw(10) << vertices[i] << " |";
	            for (int j = 0; j < length; ++j) {
	                cout << setw(10) << matrix[i][j] << " |";
	            }
	            cout << endl;
	        }
	
	        // Clean up
	        delete[] vertices;
	        for (int i = 0; i < length; ++i) {
	            delete[] matrix[i];
	        }
	        delete[] matrix;
	    }
		
		void bfsTraversal(char startVertex) {
		    List* startList = findVertex(startVertex);
		    if (startList == nullptr) {
		      cout << "Vertex " << startVertex << " not found." << endl;
		      return;
		    }
		
		    queue<List*> vertexQueue;
		    bool visited[length] = {false};
		
		    vertexQueue.push(startList);
		    visited[findIndex(getVertices(), startVertex, length)] = true;
		
		    while (!vertexQueue.empty()) {
		      List* currentList = vertexQueue.front();
		      vertexQueue.pop();
		
		      cout << currentList->vertex << " ";
		
		      node* currentNode = currentList->down;
		      while (currentNode != nullptr) {
		        int toIndex = findIndex(getVertices(), currentNode->vertex, length);
		        if (!visited[toIndex]) {
		          visited[toIndex] = true;
		          vertexQueue.push(findVertex(currentNode->vertex));
		        }
		        currentNode = currentNode->down;
		      }
		    }
		
		    cout << endl;
		}
		
		void dfsTraversal(char startVertex) {
		    List* startList = findVertex(startVertex);
		    if (startList == nullptr) {
		      cout << "Vertex " << startVertex << " not found." << endl;
		      return;
		    }
		
		    stack<List*> vertexStack;
		    bool visited[length] = {false};
		
		    vertexStack.push(startList);
		    visited[findIndex(getVertices(), startVertex, length)] = true;
		
		    while (!vertexStack.empty()) {
		      List* currentList = vertexStack.top();
		      vertexStack.pop();
		
		      cout << currentList->vertex << " ";
		
		      node* currentNode = currentList->down;
		      while (currentNode != nullptr) {
		        int toIndex = findIndex(getVertices(), currentNode->vertex, length);
		        if (!visited[toIndex]) {
		          visited[toIndex] = true;
		          vertexStack.push(findVertex(currentNode->vertex));
		        }
		        currentNode = currentNode->down;
		      }
		    }
		
		    cout << endl;
		}
		
		// Delete a vertex and its edges
		void deleteVertex(char vertex) {
		    List* vertexList = findVertex(vertex);
		    if (vertexList == nullptr) {
		      cout << "Vertex " << vertex << " not found." << endl;
		      return;
		    }
		
		    // Remove the vertex from the linked list (if it's the head)
		    if (vertexList == head) {
		      head = head->next;
		      delete vertexList;
		      length--;
		    } else {
		      List* currentList = head;
		      while (currentList->next != nullptr && currentList->next->vertex != vertex) {
		        currentList = currentList->next;
		      }
		      if (currentList->next != nullptr) {
		        List* temp = currentList->next;
		        currentList->next = temp->next;
		        delete temp;
		        length--;
		      }
		    }
		
		    // Remove edges from other vertices pointing to the deleted vertex
		    currentList = head;
		    while (currentList != nullptr) {
		      	node* prevNode = nullptr;
		      	node* currentNode = currentList->down;
		      	while (currentNode != nullptr) {
		        	if (currentNode->vertex == vertex) {
			        	if (prevNode == nullptr) {
			            	currentList->down = currentNode->down;
			        	} 
						else {
			            	prevNode->down = currentNode->down;
			        	}
			        	delete currentNode;
			        	currentNode = (prevNode == nullptr) ? currentList->down : prevNode->down;
		        	} 
					else {
		          		prevNode = currentNode;
		          		currentNode = currentNode->down;
		        	}
		      	}
		      	currentList = currentList->next;
		    }
		}
};

int main() {
    Graph g;
    g.insertEdge('A', 'B', 5);
    g.insertEdge('A', 'C', 10);
    g.insertEdge('B', 'C', 2);
    g.insertEdge('C', 'A', 3);

    g.display();
    g.displayMatrix();

    getch();
    return 0;
}
