#include <iostream>
#include <fstream>
#include <string>
#include "llQueue.h"
//#include "listNode.h"
using namespace std;

struct window{
  bool isAvail = true;
  int student = 0;
  int time = 0;
};

int main(int argc, char **argv){

  //windows with student
  //llQueue <int> *windowQueue = new llQueue <int>;
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

  //NaiveList<window> *registrar = new NaiveList<window>(tempWin);
  struct window tempWin;
  //registrar->insertFront(tempWin);



  cout << "Windows: " << numWindows << endl;
  cout << "Start Time: " << startTick << endl;
  cout << "Number of Students: " << numStudents << endl;

  while(studentTimes->isEmpty() != true){
    cout << studentTimes->peek() << endl;
    studentTimes->remove();
  }

  int clockTick = 1;
  int studentWait = 0;
  int windowWait = 0;
  int windowIdle = 0;

  //if(numElements = )

  while(clockTick != 0){
    //check available windows & insert students until all windows are full
    if(tempWin.isAvail == true){
      tempWin.student = studentTimes->peek();
      studentTimes->remove();
      tempWin.time++;
      tempWin.isAvail = false;
    }
    if(tempWin.isAvail == false){
      tempWin.time++;
    }
    if(tempWin.time == tempWin.student && tempWin.isAvail == false){
      tempWin.student = 0;
      tempWin.time = 0;
      tempWin.isAvail = true;
    }


    //total student wait time
    if(!studentTimes->isEmpty()){
      ++studentWait;
    }

    //add student to window queue is availible
    // if(windowQueue->isEmpty() == true){
    //   windowQueue->insert(studentTimes->peek());
    //   studentTimes->remove();
    // }
    //remove student from window queue when increase in time since insertion = peek()


    //count window idle time when no one is at window
    // if(windowQueue->isEmpty()){
    //   ++windowIdle;
    // }
    ++clockTick;
  }

}
