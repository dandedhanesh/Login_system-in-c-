#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void signup(){
    string username,password;
    cout<<"Enter username: ";getline(cin,username); 
    cout<<"Enter password: ";getline(cin,password);
    ofstream enter("data_p.txt",ios::app);
    enter<<username<<" "<<password<<endl;
  cout<<"Signup is successful"<<endl;
  enter.close();
  return;
}

void login(){
 string username,password;int buf;
    cout<<"Enter username: ";getline(cin,username);
    string u,p;
    cout<<"Enter password: ";getline(cin,password);
    ifstream search("data_p.txt");
    while(search>>u>>p){
        if(u==username && p==password){
         buf=1;
        }
    }    
search.close();
if(buf==1){
     cout<<"Successfully logged in !!!"<<endl;
}else {
    cout<<"Invalid credentials...Please try again !"<<endl;
        string input;cout<<"Would you like to Sign up(yes/no) : ";getline(cin,input);string buff = "yes";
        if(input!=buff){
       cout<<"Try again with rigth credentials"<<endl;
           login();
   } else {
     signup();
     cout<<"Now u can login"<<endl;  
     login();
   }
}
return;
}

void pass(){
    string u,p,password; cout<<"Enter password: ";getline(cin,password);
    ifstream hi("data_p.txt");
    while(hi>>u>>p){
        if(p==password){
             cout<<"Your credentials are found."<<endl;
            cout<<"Your username is: "<<u<<endl;
            break;
        }
    }
    return;
}
void user(){
  string u,p,username; cout<<"Enter username: ";getline(cin,username); 
    ifstream search("data_p.txt");
    while(search>>u>>p){
        if(u==username){
            cout<<"Your credentials are found."<<endl;
            cout<<"Your password is: "<<p<<endl;
            break;
        }
    }
    return;
}

void forget(){
    cout<<"Enter 1 for password if username is known "<<endl;
    cout<<"Enter 2 for username if password is known "<<endl;
    int y;cin>>y;cin.ignore();
    switch(y){
        case 1:
           user();break;
        case 2:
           pass();break;
        default:
           cout<<"Kindly select valid option"<<endl;      
    }
  return;
}


void datre(){
string u,p;string username,password,line;
 cout<<"Enter username: ";getline(cin,username);
    cout<<"Enter password: ";getline(cin,password);
    ifstream dh("data_p.txt");int count=0;
    while(getline(dh,line)){count++;} dh.close();
int temp=count;
ifstream dh1("data_p.txt");
ofstream sh("data.txt",ios::app);
while(dh1>>u>>p && temp>0){
    sh<<u<<" "<<p<<endl;
    temp--;       }
    dh1.close();string m,n;ofstream d1("data_p.txt");d1<<endl;d1.close();
    ofstream dh2("data_p.txt",ios::app);
    ifstream sh1("data.txt");
    while(sh1>>m>>n && count>0){
         count--;
        // cout<<m<<" "<<n<<endl;
        if(m==username && n==password ){
           continue;
        }else {
         dh2<<m<<" "<<n<<endl;
        }
    }
    sh1.close();ofstream d2("data.txt");d2<<endl;d2.close();
    cout<<"Deleted successfully"<<endl;
    return;
}


int main(){
    cout<<"Enter 1 for Login"<<endl;
    cout<<"Enter 2 for Signup"<<endl;
    cout<<"Enter 3 Forgot password"<<endl;int n;
    cout<<"Enter 4 for deletion of credentials"<<endl;
    cout<<"Input your choice: ";cin>>n;
    cin.ignore();
    switch(n){
        case 1:
         login();break;
        case 2:
         signup();break; 
        case 3:
         forget();break; 
        case 4:
          datre();break;  

        default:
           cout<<"Kindly select valid option"<<endl;  break;   
    }

}
