#include <iostream>
#include <fstream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Constructor
    Person(const string& n, int a) : name(n), age(a) {}
    void set(const string& n, int a){
		name = n;
		age = a;
	}

    // Default constructor for reading from file
    Person() : age(0) {}
};

// Function to write a Person object to a file
void appendToFile(const Person& person, const string& filename) {
    ofstream file(filename, ios::binary | ios::app);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&person), sizeof(Person));
    file.close();
}

void writeToFile(const Person& person, const string& filename) {
    ofstream file(filename, ios::binary);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&person), sizeof(Person));
    file.close();
}

// Function to read Person objects from a file
void readFromFile(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    Person person;
    while (file.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        cout << "Name: " << person.name << ", Age: " << person.age << endl;
    }

    file.close();
}

int main() {
	
    // Writing objects to a file
//    Person person1("John", 25);
//    Person person2("Alice", 30);
//
//    writeToFile(person1, "people.txt");
//    writeToFile(person2, "people.txt");
//
//    // Reading objects from a file
//    readFromFile("people.txt");
	
	int op;
	char str[99]; int age;
	Person P;
	
	do{
		cout<<"1. Write\n"
			<<"2. Append\n"
			<<"99. read\n"
			<<"0. exit\n>";
			
		cin>>op;
		
		switch(op){
			case 1:
				cout<<"Name: ";
					cin>>str;
				cout<<"Age: ";
					cin>>age;
				P.set(str, age);
				writeToFile(P, "people.txt");
				break;
			
			case 2:
				cout<<"Name: ";
					cin>>str;
				cout<<"Age: ";
					cin>>age;
				P.set(str, age);
				appendToFile(P, "people.txt");
				break;
				
			case 99:
				readFromFile("people.txt");
				break;
				
			case 0:
				cout<<"Exitting.....";
				break;
				
			default:
				cout<<"invalid";
				break;
		}	
	}while(op != 0);
    return 0;
}
