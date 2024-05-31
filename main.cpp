#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TaskManager
{
private:

    string* task;
    bool* comp;
    int size;
    int capacity;

    void resize()
    {
        capacity*=2;
        string* newtask= new string[capacity];
        bool* newcomp = new bool[capacity];

        for(int i = 0; i < size; i++)
        {
            newtask[i]=task[i];
            newcomp[i]=comp[i];
        }
        delete[] task;
        delete[] comp;

        task=newtask;
        comp=newcomp;
    }

public:

    TaskManager():size(0),capacity(10)
    {
        task=new string[capacity];
        comp = new bool[capacity]();
    }
    ~TaskManager()
    {
        delete[] task;
        delete[] comp;
    }

    void addtask()
    {
        string Task;
        cin.ignore();
        int i=1;
        cout<<"Enter Your Task Detail (or press Enter to stop):"<<endl;
        while(true)
        {
            if (size==capacity)
            {
                resize();
            }
            cout<<i<<". ";
            getline(cin,Task);
            if (Task.empty())
            { 
             break;
            }
            task[size]=Task;
            comp[size]=false;
            size++;
            i++;
        }
    }
  
    void displaytask() {
        if (size == 0) {
            cout << "No tasks to display.\n";
            return;
        }
        
        for (int i = 0; i < capacity; i++)
        {
            if (!comp[i])
            {    
                if(task[i]!="")
                cout<<i+1<<". "<<task[i]<<endl;
            }
            if(comp[i])
            {
                 
                if(task[i]!="")
                cout<<i+1<<". "<<task[i]<<" [Completed]"<<endl;

            }
            
        }
    }
    void deltask()
    {
        int index ;
        cout<<"Enter your task number : ";
        cin>>index;
        if(index>0 && index<size)
        {
            for (int i= index-1; i <size-1 ;i++)
            {
                task[i]=task[i+1];
                comp[i]=comp[i+1];
            }
            size--;
            task[size].clear();
            
            cout<<"Task Deleted Successfully"<<endl;
        }else{
            cout<<"Invalid Task Number"<<endl;
        }
    }
   void marktaskascompleted()
{
    int index;
    cout << "Enter The Number Of Task You Want To Mark As Completed" << endl;
    cin >> index;
    if (index > 0 && index <= size)
    {
        comp[index - 1] = true;
       
        cout << "Task marked as completed." << endl;
    }
    else
    {
        cout << "Invalid Task Number" << endl;
    }
}

};

int main()
{
    TaskManager tm;
    int choose;
    bool lolo=true;

  
    do
    {
          cout<<"\n";
    cout << "+---------------------------+\n";
    cout << "|        To-Do List         |\n";
    cout << "+---------------------------+\n";
    cout << "| 1. Add Task               |\n";
    cout << "| 2. Display Tasks          |\n";
    cout << "| 3. Delete Task            |\n";
    cout << "| 4. Mark Task as Completed |\n";
    cout << "| 5. Exit                   |\n";
    cout << "+---------------------------+\n";
       cout<<"\n";
    cout << "Enter your choice: ";
        cin >> choose;

    switch(choose)
    {
        case 1:{
            tm.addtask();
            break;
        }
        case 2:{
            tm.displaytask();
            break;
        }
        case 3:{
            tm.deltask();
            break;
        }
        case 4:{
            tm.marktaskascompleted();
            break;
        }
        case 5:{
            cout<<"Exiting the program"<<endl;
            lolo=false;
            break;
        }
        default:cout<<"Invalid choice. Please try again.\n";
        
    }

    } while (lolo);
    
}