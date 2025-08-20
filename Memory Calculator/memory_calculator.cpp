#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Student {
    T Id;
    string sname;

public: 
    Student(T Id, string name){
        this->Id = Id;
        this->sname = name;
    }

    void ShowData(){
        cout << "Student ID : " << Id << ", Name: " << sname << endl;
    }
    T getId(){
        return Id;
    }
};

int main(){
    vector<Student<int>> list;
    int option;

    while(1){
        cout << "1. Add Student ID: " << endl;
        cout << "2. Display All Students ID: " << endl;
        cout << "3. Delete Student ID: " << endl;
        cout << "4. Search Student by ID: " << endl;
        cout << "0. Exit..... " << endl;
        cout << "Enter option: ";
        cin >> option;

        if(option == 1){
            string name;
            int ID;

            cout << "Enter ID: ";
            cin >> ID;

            cout << "Enter Name: ";
            cin >> name;
            list.push_back(Student<int>(ID, name));
            cout << "Added Student.." << endl;
        }

        else if(option == 2){
            if(list.empty()){
                cout << "No students to display." << endl;
            } else {
                for(int i = 0; i < list.size(); i++){
                    list[i].ShowData();
                }
            }
        }

        else if(option == 3){
            bool found = false;
            int ID;
            cout << "Enter Student ID to delete : ";
            cin >> ID;
            for(auto it = list.begin(); it != list.end(); it++){
                if(it->getId() == ID){
                    list.erase(it);
                    cout << "Student ID Deleted..." << endl;
                    found = true;
                    break;
                }
            }

            if(found == false){
                cout << "ID not found.." << endl;
            }
        }

        else if(option == 4){
            bool found = false;
            int ID;
            cout << "Enter Student ID to Find : ";
            cin >> ID;
            for(int i = 0; i < list.size(); i++){
                if(list[i].getId() == ID){
                    list[i].ShowData();
                    found = true;
                    break; 
                }
            }
            if(found == false){
                cout << "ID not found.." << endl;
            }
        }

        else if(option == 0){
            cout << "Thank You...." << endl;
            break;
        }

        else{
            cout << "Wrong option." << endl;
        }
    } 

    return 0;
}