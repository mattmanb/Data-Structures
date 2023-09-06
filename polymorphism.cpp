//
//  OverloadOverride - demonstrate when a function is
//                     declare-time overloaded vs. runtime
//                     overridden
//
//  Taken from Davis, C++ for Dummies, Fifth Edition, pp.270
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Student
{
  public:
    // uncomment one or the other of the next
    // two lines; one binds calcTuition() early and
    // the other late
          float calcTuition()
//    virtual float calcTuition()
    {
        cout << "We're in Student::calcTuition" << endl;
        return 0;
    }
};

class GraduateStudent : public Student
{
  public:
    float calcTuition()
    {
        cout << "We're in GraduateStudent::calcTuition" 
             << endl;
        return 0;
    }
};

void fn(Student& x)
{
    x.calcTuition();   // to which calcTuition() does 
                     // this refer?
}

int main(int nNumberofArgs, char* pszArgs[])
{
    // pass a base class object to function
    // (to match the declaration)
    Student s;
    fn(s);

    // pass a specialization of the base class instead
    GraduateStudent gs;
    fn(gs);

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
    return 0; 
}
