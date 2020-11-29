#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void welcomeScreen();
int  chooseUser();
void exitScreen();
map<string,int> TOTAL_ASSIGNMENT_COUNT{{"1",0},{"2",0},{"3",0},{"4",0},{"5",0},{"6",0},{"7",0},{"8",0}};
string USER_ID;



//login details
vector<unordered_map<string , string >> Det{
        {{"1" , "admin"} , {"2" , "admin"}} , 
        {{"1","admin"} , {"2","admin"}} , 
        {{"2","admin"} , {"1","admin"}} , 
        {{"1","admin"} , {"2","admin"}}
};

//login class
class Login{
    string id;
    string password;
    int user=0;
public: 
    Login(){
        id="";
        password="";
        USER_ID="";

    }
    bool EnterEP(int u){
            user = u;
            //clear screen
            system("CLS");

            cout<<"Enter Id:"<<endl;
            cin>>id;
            USER_ID = id;
            cout<<"Enter Password:"<<endl;
            cin>>password;
            return Validate();
    }
    bool Validate(){
        if(Det[user-1].find(id)==Det[user-1].end()){
            cout<<"Invalid id"<<endl;
            cout<<"Try Again"<<endl;
            getch();
            return false;
        }else if(Det[user-1][id]!=password){
            cout<<"Invalid password"<<endl;
            cout<<"Enter Again"<<endl;
            getch();

            return false;
        }else{
            return true;
        }
    }

};



//student detail maps
unordered_map<string , string> Student_Name{
    {"1" , "Elon Musk"} , {"2" , "Dawood"}
};

unordered_map<string , string> Student_FName{
    {"1" , "UnElon Musk"} , {"2" , "DadDawood"}
};
unordered_map<string , string> Student_sem{
    {"1" , "3"} , {"2" , "5"}
};
unordered_map<string , string> Student_mail{
    {"1" , "ElonNotMusk@tesla.com"} , {"2" , "Dawood@twentySixEleven.com"}
};
unordered_map<string , int> Student_AsCou{
    {"1" , 4} , {"2" , 1}
};

//class student
class student{
    string id;
    string name;
    string Fname;
    string semester;
    string email;
    int assignment_count ;
public:
    student(string i);
    void showProfile();
    void AssignmentCounter();
    void TimeTable();
    void LogOut();
    void Exit();
    int showMenu();
    ~student(){};
};


//teacher detail maps
unordered_map<string , string> Teacher_Name{
    {"1" , "Bill Door"} , {"2" , "Grosama bin loaden"}
};

unordered_map<string , string> Teacher_mail{
    {"1" , "BillDoor@ms.com"} , {"2" , "GbL@nine-eleven.com"}
};

//class Teacher
class Teacher{
    string id;
    string name;
    string email;
public:
    Teacher(string i);
    void showProfile();
    void CheckAssignmentStatus();
    void AddAssignment();
    void MarkAssignment();
    //void MarkAttendence();
    void LogOut();
    void Exit();
    int showMenu();
    ~Teacher(){};
};



//management detail maps
unordered_map<string , string> Management_Name{
    {"1" , "AtiSundar Pichai"} , {"2" , "BagDaddu"}
};

unordered_map<string , string> Management_mail{
    {"1" , "AtiSundar@Gugal.com"} , {"2" , "Bd@IsIs.com"}
};

//class Management
class Management{
    string id;
    string name;
    string email;
public:
    Management(string i);
    void showProfile();
    void AddStudent();
    void UpdateStudentDetail();
    void DeleteStudent();
    void UploadTimeTable();
    void LogOut();
    void Exit();
    int showMenu();
    ~Management(){};
};



//main function
int main(){
    welcomeScreen();
    
    //return the user number
    int userValue = chooseUser();

    //login as the user
    Login user1;
    while(!user1.EnterEP(userValue));
    cout<<"Login Succesfull"<<endl;
    getch();
    
    //make object 
    if(userValue==1){
        student s1(USER_ID);
    }else 
        if(userValue ==2){
            Teacher t1(USER_ID);
        }else
            if(userValue==3){
            /* code */
                Management m1(USER_ID);
            }
        
    

    return 0;
}

//Welcome Screen
void welcomeScreen(){
    system("CLS");
    cout<<"Welcome to College Management System"<<endl;
    getch();
}

//Choosing User
int chooseUser(){
    system("CLS");
    cout<<"Login:"<<endl;
    cout<<"User type:"<<endl;
    cout<<"1.Student"<<endl;
    cout<<"2.Teacher"<<endl;
    cout<<"3.Management"<<endl;
    cout<<"4.Library"<<endl;
    cout<<"5.Exit"<<endl;

    int n=10;
    while(n>5 || n<1){
        cout<<endl<<"Enter the required value:"<<endl;
        string s;
        cin>>s;
        if(s.length()==1){
            n = (int)(s[0]-'0');
        }else{
            n=10;
        }
        if(n>5 || n<1){
            cout<<"Invalid Input!! Try Again!!"<<endl;
        }
    }
    
    if(n==5){
        cout<<"Are you sure you want to exit? \n Enter 1 for confirmation \n for previous screen press any other key"<<endl;
        string conf ;
        cin>>conf;

        if(conf=="1"){
             exitScreen();
        }else{
            return chooseUser();
        }        
    }
    return n;

}

//Exit Screen
void exitScreen(){
    system("CLS");
    cout<<"Thankyou for using our platform"<<endl;
    exit(0);
}



//student class
//constructor student
student::student(string i)
{
    id = i;
    name = Student_Name[i];
    Fname = Student_FName[i];
    semester = Student_sem[i];
    email = Student_mail[i];
    assignment_count = Student_AsCou[i];

    //opens a display menu 
    bool cont=false;
    do{
        system("CLS");
        int option = showMenu();
        switch(option){
            case 1: showProfile();break;
            case 2: AssignmentCounter();break;
            case 3: TimeTable();break;
            case 4: LogOut();break;
            case 5: Exit();break;
            default : cout<<"couldn't identify"<<endl;
        }
        cout<<"Enter 1 to continue"<<endl<<"Enter any other key to exit"<<endl;
        string s;
        cin>>s;
        if(s.size()==1){
            if(s[0]=='1'){
                cont = true;
            }else
            {
                cont = false;
                Exit(); 
                break;
            }
            
        }else{
            cont = false;
            Exit();
            break;
        }

    }while(cont);
   

}

void student:: AssignmentCounter(){
    cout<<"You have submitted "<<assignment_count<<" out of "<<TOTAL_ASSIGNMENT_COUNT[semester]<<" assignments"<<endl;
    getch();
}

void student::LogOut(){
        cout<<"Logged Out"<<endl;
    getch();
    main();
    Exit();
}
void student::Exit(){
    exitScreen();
}
void student:: TimeTable(){
    cout<<"Time Table Creation is still in progress"<<endl;
    getch();
}

//show menu function for students
int student::showMenu(){
    system("CLS");
    cout<<"Choose from these option:"<<endl;
    cout<<"1. showProfile"<<endl;
    cout<<"2. Assignment counter"<<endl;
    cout<<"3. TimeTable"<<endl;
    cout<<"4. Log Out"<<endl;
    cout<<"5. Exit"<<endl;
    string s;
    cin>>s;
    int val=0;
    if(s.size()==1){
        val = stoi(s);
        if(val>=1 and val<=5){
            return val;
        }else{
            cout<<"Try Again"<<endl;
            return showMenu();
        }
    }else{
        cout<<"Try Again"<<endl;
        return showMenu();
    }
    return val;
}

//show profile student
void student::showProfile(){
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Fname:"<<Fname<<endl;
        cout<<"semester:"<<semester<<endl;
        cout<<"Email:"<<email<<endl;
        getch();
}


//teacher

//teacher class
//constructor teacher
Teacher::Teacher(string i)
{
    id = i;
    name = Teacher_Name[i];
    email = Teacher_mail[i];

    //opens a display menu 
    bool cont=false;
    do{
        system("CLS");
        int option = showMenu();
        switch(option){
            case 1: showProfile();break;
            case 2: CheckAssignmentStatus();break;
            case 3: AddAssignment();break;
            case 4: MarkAssignment();break;
            //case 5: MarkAttendence();break;
            case 6: LogOut();break;
            case 7: Exit();break;
            default : cout<<"couldn't identify"<<endl;
        }
        cout<<"Enter 1 to continue"<<endl<<"Enter any other key to exit"<<endl;
        string s;
        cin>>s;
        if(s.size()==1){
            if(s[0]=='1'){
                cont = true;
            }else
            {
                cont = false;
                Exit();
                break;
            }
            
        }else{
            cont = false;
            Exit();

            break;
        }

    }while(cont);
   

}

void Teacher::CheckAssignmentStatus(){
    cout<<"Enter the id of student you want to check assignment status of"<<endl;
    string S_id;
    cin>>S_id;
    if(Student_AsCou.find(S_id)!=Student_AsCou.end()){
        string sem = Student_sem[S_id];
        cout<<"Student has submitted "<<Student_AsCou[S_id]<<" out of "<<TOTAL_ASSIGNMENT_COUNT[sem]<<endl;
    }else{
        cout<<"Student Not present"<<endl;
    }
}

void Teacher::MarkAssignment(){
    cout<<"Enter the student's id"<<endl;
    string S_Id;
    cin>>S_Id;
    cout<<"How many assignments have the student submitted?"<<endl;
    int val ;
    cin>>val;
    Student_AsCou[S_Id]+=val;
}
void Teacher::AddAssignment(){
    cout<<"Enter the semester you want to add assignment for:"<<endl;
    string sem ;
    cin>>sem;
    cout<<"How many assignment you want to add?"<<endl;
    int val ;
    cin>>val;
    TOTAL_ASSIGNMENT_COUNT[sem]+=val;
}
void Teacher::LogOut(){
        cout<<"Logged Out"<<endl;
    getch();
    main();
    Exit();
}
void Teacher::Exit(){
    exitScreen();
}

//show menu function for teacher
int Teacher::showMenu(){
    system("CLS");
    cout<<"Choose from these option:"<<endl;
    cout<<"1. showProfile"<<endl;
    cout<<"2. Check Assignment Status"<<endl;
    cout<<"3. Add Assignment"<<endl;
    cout<<"4. Mark Assignment"<<endl;
   // cout<<"5. Mark Attendence"<<endl;
    cout<<"6. Log Out"<<endl;
    cout<<"7. Exit"<<endl;
    string s;
    cin>>s;
    int val=0;
    if(s.size()==1){
        val = stoi(s);
        if(val>=1 and val<=7){
            return val;
        }else{
            cout<<"Try Again"<<endl;
            return showMenu();
        }
    }else{
        cout<<"Try Again"<<endl;
        return showMenu();
    }
    return val;
}

//show profile teacher
void Teacher::showProfile(){
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Email:"<<email<<endl;
        getch();
}


//Management

//Management class
//constructor Management
Management::Management(string i)
{
    id = i;
    name = Management_Name[i];
    email = Management_mail[i];

    //opens a display menu 
    bool cont=false;
    do{
        system("CLS");
        int option = showMenu();
        switch(option){
            case 1: showProfile();break;
            case 2: AddStudent();break;
            case 3: UpdateStudentDetail();break;
            case 4: DeleteStudent();break;
            //case 5: UploadTimeTable();break;
            case 6: LogOut();break;
            case 7: Exit();break;
            default : cout<<"couldn't identify"<<endl;
        }
        cout<<"Enter 1 to continue"<<endl<<"Enter any other key to exit"<<endl;
        string s;
        cin>>s;
        if(s.size()==1){
            if(s[0]=='1'){
                cont = true;
            }else
            {
                cont = false;
                Exit();
                break;
            }
            
        }else{
            cont = false;
            Exit();

            break;
        }

    }while(cont);
   

}

void Management::DeleteStudent(){
    //delete student
    cout<<"Enter the Id to be deleted"<<endl;
    string S_ID;
    cin>>S_ID;
    if(Det[0].find(S_ID)!=Det[0].end()){
        Det[0].erase(S_ID);
        Student_Name.erase(S_ID);
        Student_FName.erase(S_ID);
        Student_sem.erase(S_ID);
        Student_mail.erase(S_ID);
        Student_AsCou.erase(S_ID);
        cout<<"Deletion Successful"<<endl;
    }else{
        cout<<"Student Don't exist"<<endl;
    }
}

void Management::UpdateStudentDetail(){
    //update student detail
    cout<<"Enter details for student:"<<endl;
    string S_id;
    cout<<"Enter the Id for student to be updated"<<endl;
    cin>>S_id;
    if(Student_Name.find(S_id)==Student_Name.end()){
        cout<<"Student not present"<<endl;
        cout<<"Press 1 to add student"<<endl;
        string s;
        cin>>s;
        if(s.size()==1 and s=="1"){
            AddStudent();
            return;
        }else{
            return;
        }
        return;
    }else{
        cout<<"choose the value to be edited:"<<endl;
        cout<<"1. Password"<<endl;
        cout<<"2. Name"<<endl;
        cout<<"3. Father's Name"<<endl;
        cout<<"4. Semester"<<endl;
        cout<<"5. Email"<<endl;
        cout<<"6. Assignment Count"<<endl;
        string s;
        cin>>s;
        if(s.size()==1){
            if(s=="1"){
                cout<<"Enter new Password:"<<endl;
                string a;
                cin>>a;
                Det[0][S_id] = a;
                cout<<"Password updated successfully"<<endl;
                return;
            }else
            if(s=="2"){
                cout<<"Enter new Name:"<<endl;
                string a;
                cin>>a;
                Student_Name[S_id] = a;
                cout<<"Name updated successfully"<<endl;
                return;
            }else
            if(s=="3"){
                cout<<"Enter new Father's Name:"<<endl;
                string a;
                cin>>a;
                Student_FName[S_id] = a;
                cout<<"Father's Name updated successfully"<<endl;
                return;

            }else
            if(s=="4"){
                cout<<"Enter new semester:"<<endl;
                string a;
                cin>>a;
                Student_sem[S_id] = a;
                cout<<"semester updated successfully"<<endl;
                return;
                    
            }else
            if(s=="5"){
                cout<<"Enter new Email:"<<endl;
                string a;
                cin>>a;
                Student_mail[S_id] = a;
                cout<<"Email updated successfully"<<endl;
                return;

            }else
            if(s=="6"){
                cout<<"Enter new count of assignment:"<<endl;
                int a;
                cin>>a;
                Student_AsCou[S_id] = a;
                cout<<"count updated successfully"<<endl;
                return;
                    
            }else{
                cout<<"Error! Try Again"<<endl;
                return;
            }
            
        }else{
            cout<<"Try Again"<<endl;
            return;
        }
    }
    cout<<"Enter More students? press one for yes"<<endl;
    string yes;
    cin>>yes;
    if(yes=="1"){
        AddStudent();
        return;
    }else{
        return;
    }

}
void Management::AddStudent(){
    //add student
    cout<<"Enter details for student:"<<endl;
    string S_id;
    cout<<"Enter the Id for student"<<endl;
    cin>>S_id;
    if(Student_Name.find(S_id)!=Student_Name.end()){
        cout<<"Student already present"<<endl;
        return;
    }else{
        cout<<"Enter the following one by one"<<endl;
        cout<<"Password:";
        string Password;
        cin>>Password;
        cout<<"Name:";
        string SName;
        cin>>SName;
        cout<<"Father's Name:";
        string Fname;
        cin>>Fname;
        cout<<"Semester:";
        string Semester;
        cin>>Semester;
        cout<<"Email:";
        string EmailId;
        cin>>EmailId;
        cout<<"Assignment Count:";
        int AssignmentC;
        cin>>AssignmentC;

        Det[0].insert({S_id , Password});
        Student_Name.insert({S_id , SName});
        Student_FName.insert({S_id , Fname});
        Student_sem.insert({S_id , Semester});
        Student_mail.insert({S_id , EmailId});
        Student_AsCou.insert({S_id , AssignmentC});
        cout<<"Insertion Successful"<<endl;
    }
    cout<<"Enter More students? press one for yes"<<endl;
    string yes;
    cin>>yes;
    if(yes=="1"){
        AddStudent();
        return;
    }else{
        return;
    }
}

void Management::LogOut(){
    cout<<"Logged Out"<<endl;
    getch();
    main();
    Exit();
}
void Management::Exit(){
    exitScreen();
}

//show menu function for Management
int Management::showMenu(){
    system("CLS");
    cout<<"Choose from these option:"<<endl;
    cout<<"1. showProfile"<<endl;
    cout<<"2. Add Student"<<endl;
    cout<<"3. Update Student Details"<<endl;
    cout<<"4. Delete Student"<<endl;
    //cout<<"5. Mark Attendence"<<endl;
    cout<<"6. Log Out"<<endl;
    cout<<"7. Exit"<<endl;
    string s;
    cin>>s;
    int val=0;
    if(s.size()==1){
        val = stoi(s);
        if(val>=1 and val<=7){
            return val;
        }else{
            cout<<"Try Again"<<endl;
            return showMenu();
        }
    }else{
        cout<<"Try Again"<<endl;
        return showMenu();
    }
    return val;
}

//show profile Management
void Management::showProfile(){
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Email:"<<email<<endl;
        getch();
}
