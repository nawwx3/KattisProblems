//lock thing - SIG Comp week 3 challenge 2
//3 sec run time


#include "lockRequest.h"

using namespace std;

void output(list<lockRequest> l);
void sortData(list<lockRequest> &l, lockRequest a);
void sortID(list<lockRequest> &l, lockRequest a);

int main() {

  // ------- variable declaration -------
  int testCase; //number of test cases to be run

  //sort the items based on data. to find and insert use binary search?
    //if sorting based on data may use some kind of linked list or a tree?
  int tempData;
  int tempTRID;
  char tempMode;

  bool running = true;

  list<lockRequest> lockData;
  list<lockRequest> lockID;
  lockRequest a;

  //take number of test cases input
  cin >> testCase;
  while(testCase < 0) {
    cin >> testCase;
  }

  //take main_data inputs
  //iterator to keep track of where the end is can be used as   iterator != list.end()
  for(int i = 0; i < testCase; i++) { //num through number of test cases
  cout << "enter stuff" << endl;
    cin >> tempMode >> tempTRID >> tempData;
    a.setMode(tempMode);
    a.setData(tempData);
    a.setTRID(tempTRID);

    cout << "help: " << lockData.size() << endl;

    a.setStatus(lockData, lockID, a);

    lockData.push_back(a);    //creates the start of the list
    lockID.push_back(a);    //creates the start of the list
    cout << "help: " << lockData.size() << endl;

    a.resetMode();

    while(running){  //the size will be at least 1 for it to get here

      cout << "lockData:  " << endl;
      output(lockData);

      cout << "lockID:  " << endl;
      output(lockID);
      cout << endl;

      cout << "enter stuff" << endl;
      cin >> tempMode;
      if(tempMode != '#'){
        cin >> tempTRID >> tempData;
        a.setMode(tempMode);
        a.setData(tempData);
        a.setTRID(tempTRID);

        a.setStatus(lockData, lockID, a);

        cout << "a.getData " << a.getData() << endl;
        a.findData(lockData, a.getData());

        sortData(lockData, a);

        cout << "sorted:   a.getData " << a.getData() << endl;
        a.findData(lockData, a.getData());

        sortID(lockID, a);

        a.resetMode();

      }
      else  //ends while loop
        running = false;
    }

  }
  return 0;
}

//input list, output stuff in list
void output(list<lockRequest> l) {
  list<lockRequest>::iterator it;
  for(it = l.begin(); it != l.end(); ++it) {
    cout << "TRID: " << (*it).getTRID();
    cout << "   data: " << (*it).getData();
    cout << "   S: " << (*it).getS();
    cout << "   X: " << (*it).getX();
    cout << "   status: " << (*it).getStatus() << endl;
  }
}

void sortData(list<lockRequest> & l, lockRequest a) {  //start from beginning of list and place element before elements with >= data as current data
  bool placed = false;
  list<lockRequest>::iterator next = l.begin();  //next is place where 'a' would be placed, making elements after it effectively move over
  while (!placed) {
    if (a.getData() <= (*next).getData() || next == l.end()) {
        // if data from to_be_placed is <= next, place at next's location
      l.insert(next, a);
      placed = true;
    } else //not placed, go to next spot
      next++;
  }
}

void sortID(list<lockRequest> & l, lockRequest a) {  //start from beginning of list and place element before elements with >= data as current data
  bool placed = false;
  list<lockRequest>::iterator next = l.begin();  //next is place where 'a' would be placed, making elements after it effectively move over
  while (!placed) {
    if (a.getTRID() <= (*next).getTRID() || next == l.end()) {
        // if data from to_be_placed is <= next, place at next's location
      l.insert(next, a);
      placed = true;
    } else //not placed, go to next spot
      next++;
  }
}