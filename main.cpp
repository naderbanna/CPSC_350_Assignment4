#include <iostream>
#include <fstream>
#include <string>
#include "llQueue.h"
using namespace std;

int main(int argc, char **argv){

  //windows with student
  //genQueue <int> *windowQueue = new genQueue <int>;
  //students waiting for window
  llQueue <int> *studentTimes = new llQueue <int>;
  //genQueue <int> *studentTimes = new genQueue <int>;

  //availible windows
  //NaiveList<int> *regWindows = new NaiveList<int>;





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
      studentCounter--;
    }

  }

  cout << "Windows: " << numWindows << endl;
  cout << "Start Time: " << startTick << endl;
  cout << "Number of Students: " << numStudents << endl;

  while(studentTimes->isEmpty() != true){
    cout << studentTimes->peek() << endl;
    studentTimes->remove();
  }

  // int clockTick = 1;
  //
  // while(clockTick != 0){
  //
  // }

}
