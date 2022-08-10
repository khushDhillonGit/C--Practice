// C++ program to demonstrate
// the use of static Static
// variables in a Function
#include <iostream>
#include <string>
using namespace std;

void demo()
{
	// static variable
  static int count = 0; //static variable is only created once in memory and can be used throughout the program
	cout << count << " ";
	
	// value is updated and
	// will be carried to next
	// function calls
	count++;
}
void printCrap(){
  cout << "Shityy words" << endl;
}

int main()
{
	for (int i=0; i<5; i++)	
		demo();
  printCrap();
  demo();

	return 0;
}
