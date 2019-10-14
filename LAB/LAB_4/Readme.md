# LAB 4

## ClassConcepts and Inheritance
- WriteaClassnamedStudentwiththebelowgivenDataMembers
	- Student Name, Student Age, Student Enrollment Number, Student CGPA,Discipline
	- Write functions to set and get student CGPA and student Discipline
	- Write Default Constructor which initializes the data members with “Rohit” 18“25CSE2019” 7.5 and ‘CSEBTECH’
	- Allow parameterized constructors through which objects can be initialized. Makea minimum of three different parameterized constructors
	- Create a copy constructor for those who want to instantiate a new object with anold object
	- Write a member function which can print all details of any Student object
	- Create a class StudentClub which inherits Student class in a protected mode
		- Create an object of StudentClub class. See how can we callparameterized constructors of the base class Student from the StudentClub class constructor
		- Write a function in the StudentClub class which marks a student eligiblefor elections by setting a data member voting to 1 whenever the CGPA ofthe student is greater than 7
		- Access various data members of the base class from derived class objectvia the ‘.’ operator. Access member functions of the base class viaderived class object
		- Have a static data member in the derived class which keeps track of theStudents made eligible for voting
		- Access data member using name of the class
		- Create another class MusicClub which inherit StudentClub in publicmode
			- Have data members MusicClubID (int) andMusicClubInstrument(string)
			- Through Music Club constructor try to call the constructor of thebase Class StudentClub
			- Print the details of the student through a member function. Thismust include its voting member value and MusicClubID andMusicClubInstrument string
			- Access data members of Student class in Music class and viaMusic Class object
			- Write a member function which checks the age of the student andallocate him a specific instrument (MusicClubInstrument =“Guitar”) only if the age > 16 years.
