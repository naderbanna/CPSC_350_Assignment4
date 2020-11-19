#include <iostream>
#include <fstream>
#include <string>
#include "llQueue.h"
using namespace std;

struct student{
  int requiredTime = 0;
  int waitTime = 0;
};

struct window{
  student stu;
  int idleTime = 0;
  int timer = 0;
};

struct window2{
  bool isAvail = true;
  int student = 0;
  int time = 0;
};



int main(int argc, char **argv){


  llQueue <student> *studentLine = new llQueue <student>;
  llQueue <student> *studentServed = new llQueue <student>;
  llQueue <window> *windowsOpen = new llQueue <window>;
  llQueue <window> *windowsClosed = new llQueue <window>;

  llQueue <int> *studentTimes = new llQueue <int>;
  //llQueue <int> *longestStudentWait = new llQueue <int>;
  //llQueue <int> *longestWindowIdle = new llQueue<int>;




  int numWindows;
  int startTick;
  int numStudents;
  int studentCounter;

  string inputFile;
  cout << "Enter a file name: " << endl;
  cin >> inputFile;
  ifstream fileStream;
  fileStream.open(inputFile);

  string lineStr = "";
  int ln = 0;
  while(getline(fileStream, lineStr)){
    ln++;
    cout << lineStr << endl;
    if(ln == 1){
      numWindows = stoi(lineStr);
    }
    if(ln == 2){
      startTick = stoi(lineStr);
    }
    if(ln == 3){
      numStudents = stoi(lineStr);
      studentCounter = numStudents;
    }
    if(studentCounter != 0 && ln > 3){
      studentTimes->insert(stoi(lineStr));
      // struct student s = {.requiredTime = stoi(lineStr), .waitTime = 0};
      // studentLine->insert(s);
      studentCounter--;
    }

  }


  //functionality for dynamic # of windows and managing all student and window variables
  //needed for calculation

  // for(int i = 0; i < numWindows; i++){
  //   struct window w = {.stu = studentLine->peek(), .idleTime = 0, .timer = 0};
  //   studentLine->remove();
  //   windowsClosed->insert(w);
  //
  // }

  cout << "Windows: " << numWindows << endl;
  cout << "Start Time: " << startTick << endl;
  cout << "Number of Students: " << numStudents << endl;


  //functionality for dynamic # of windows and managing all student and window variables
  //needed for calculation

  // while(!windowsClosed->isEmpty()){
  //   cout << windowsClosed->peek().stu.requiredTime << endl;
  //   windowsClosed->remove();
  // }
  //
  // cout << endl;
  // while(!studentLine->isEmpty()){
  //   cout << studentLine->peek().requiredTime << endl;
  //   studentLine->remove();
  // }

  int clockTick = 1;
  int studentWait = 0;
  int totalStudentWait = 0;
  int windowWait = 0;
  float windowIdle = 0;
  float studentNumWait = 0;
  studentCounter = 0;

  struct window2 tempWin;

//functionality for dynamic # of windows and managing all student and window variables
//needed for calculation

  // while(clockTick != 0){
  //   //insert student to open window, move window to closed
  //   while(!windowsOpen->isEmpty()){
  //     windowsOpen->peek().stu = studentLine->peek();
  //     windowsOpen->peek() = {.stu = studentLine->peek(), .timer = 0};
  //     windowsOpen->peek().stu.waitTime = clockTick;
  //     studentLine->remove();
  //     windowsClosed->insert(windowsOpen->peek());
  //     windowsOpen->remove();
  //   }
  //   //increase count & remove student if time is up
  //   while(!windowsClosed->isEmpty()){
  //     windowsClosed->peek().timer++;
  //     if(windowsClosed->peek().timer > windowsClosed->peek().stu.requiredTime){
  //       studentServed->insert(windowsClosed->peek().stu);
  //       windowsClosed->peek().timer = 0;
  //       windowsOpen->insert(windowsClosed->peek());
  //       windowsClosed->remove();
  //     }
  //
  //   }
  //
  //
  //
  //   ++clockTick;
  //
  //   // if(studentLine->isEmpty() && ){
  //   //   cout << "clock tick 0" << endl;
  //   //   clockTick = 0;
  //   // }
  //
  // }



//original functionality for a single window
studentNumWait = studentTimes->getSize()-numWindows+1;
 while(clockTick != 0){
   //check available windows & insert students until all windows are full
   if(tempWin.isAvail == true){
     tempWin.student = studentTimes->peek();
     studentTimes->remove();
     tempWin.time++;
     tempWin.isAvail = false;
     cout << "added to window" << endl;
   }
   //increase time if window is still in use
   if(tempWin.isAvail == false){
     tempWin.time++;
     cout << "window increase time" << endl;
   }
   //remove student
   if(tempWin.time == tempWin.student+1 && tempWin.isAvail == false){
     tempWin.student = 0;
     tempWin.time = 0;
     tempWin.isAvail = true;
     cout << "student removed from window" << endl;
   }


   //total student wait time
   if(!studentTimes->isEmpty()){
         ++totalStudentWait;
   }

   ++clockTick;

   if(studentTimes->isEmpty() && tempWin.student == 0){
     cout << "clock tick 0" << endl;
     clockTick = 0;
   }


 }

  cout << "student wait time: " << totalStudentWait << endl;
  cout << "mean student wait time: " << totalStudentWait/studentNumWait << endl;
  cout << "student longest wait time: " << studentNumWait << endl;
  cout << "students waiting over 10 minutes: " << endl;
  cout << "mean window idle time: " << windowIdle << endl;
  //cout << "longest window idle: " << longestWindowIdle->peek() << endl;
  cout << "windows idle for over 5 minutes: " << endl;

}
