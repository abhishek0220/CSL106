#include<bits/stdc++.h>
using namespace std;
class Student{
public:
	string Name,Discipline,Enrollment_number;
	int Age;
	float cgpa;
	Student(){  //Default Constructor
		initialize();
	}
	Student(string na){ //Constructor with 1 argument
		initialize();
    Name=na;
	}
  Student(string na, int ag){
    initialize();
		Name=na;
		Age=ag;
	}
  Student(string na, int ag,string id){
    initialize();
		Name=na;
		Age=ag;
    Enrollment_number=id;
	}
	Student(const Student &obj1){
		Name=obj1.Name;
		Age=obj1.Age;
		Enrollment_number=obj1.Enrollment_number;
		cgpa=obj1.cgpa;
		Discipline=obj1.Discipline;
	}
  void set(float cg,string dis){
    cgpa=cg;
    Discipline=dis;
  }
  float getCGPA(){
    return cgpa;
  }
  string getDiscipline(){
    return Discipline;
  }
  void initialize(){
    Name="Rohit";
		Age=18;
		Enrollment_number="25CSE2019";
		cgpa=7.5;
		Discipline="CSEBTECH";
  }
	void display(){
		cout<<"Name : "<<Name<<endl;
		cout<<"Age : "<<Age<<endl;
		cout<<"Enrollment number : "<<Enrollment_number<<endl;
		cout<<"CGPA : "<<cgpa<<endl;
		cout<<"Discipline : "<<Discipline<<endl;
	}
};
class StudentClub : protected Student{
  public:
	int voting;
  static int no_of_student;
  StudentClub(){
    vote_check();
  }
  StudentClub(string na):Student(na){}
  StudentClub(string na,int ag):Student(na,ag){}
  StudentClub(string na,int ag,string uid):Student(na,ag,uid){}
  void dis(){
    display();
    cout<<"Voting : "<<voting<<endl;
  }
  private:
  void vote_check(){
    voting=0;
    if(cgpa>7)
      voting=1;
      no_of_student++;
  }
};
class MusicClub : public StudentClub {
  public:
  int MusicClubID;
  string MusicClubInstrument;
  MusicClub(){
    MusicClubID=1;
    MusicClubInstrument="No_Instrument";
    check();
  }
  MusicClub(int i,string ins){
    MusicClubID=i;
    MusicClubInstrument=ins;
  }
  void print(){
    dis();
    cout<<"MusicClub ID : "<<MusicClubID<<endl;
    cout<<"MusicClub Instrument : "<<MusicClubInstrument<<endl;
  }
  void check(){
    if(Age>16)
      MusicClubInstrument="Guitar";
  }
};
int StudentClub::no_of_student = 0;
int main(){
	MusicClub obj1;
  obj1.print();
	return 0;
}