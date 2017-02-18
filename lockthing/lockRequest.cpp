//
// Created by Nathan Welch on 2/10/2017.
//

#include "lockRequest.h"
using namespace std;

lockRequest::lockRequest() {
  m_data;
  m_TRID;
  m_mode;
  m_S = 0;
  m_X = 0;
}

lockRequest::lockRequest(int data, int TRID, char mode){
  m_data = data;
  m_TRID = TRID;
  m_mode = mode;
  m_S = 0;
  m_X = 0;

  if(mode == 'S')
    m_S = 1;
  if(mode == 'X')
    m_X = 1;
}

void lockRequest::resetMode() {
  m_S = 0;
  m_X = 0;

}

list<lockRequest>::iterator lockRequest::findData(list<lockRequest> & lockData, int data) {
  list<lockRequest>::iterator it = lockData.begin();
  cout << "from findData: " << (*it).m_TRID << "," << (*it).m_data << "   " << data << endl;
  while((*it).m_data < data && it != lockData.end() ) {
    cout << "data increase ptr" << endl;
    it++;
  }
  cout << "from findData: " << (*it).m_TRID << "," << (*it).m_data << "   " << data << endl;
  return it;
}

list<lockRequest>::iterator lockRequest::findID(list<lockRequest> & lockID, int ID) {
  list<lockRequest>::iterator it = lockID.begin();
  cout << "from findID: " << (*it).m_TRID << "," << (*it).m_data << endl;
  while((*it).m_TRID < ID && it != lockID.end() ) {
    it++;
  }
  return it;
}

void lockRequest::setData(int data) {
  m_data = data;
  return;
}

void lockRequest::setTRID(int TRID) {
  m_TRID = TRID;
  return;
}

void lockRequest::setMode(char mode) {
  if(mode == 'S' || mode == 's')
    m_S = 1;
  if(mode == 'X' || mode == 'x')
    m_X = 1;
  return;
}

void lockRequest::setStatus(list<lockRequest> & lockData, list<lockRequest> & lockID, lockRequest & a) {
  /*Denied because of conflict
   * different TRID && at least one m_X == 1
   * for two locks of same data item
   *
   *    have to get to the fist place where
   * data_of_a == data in list
   *
   *    if same, compare TRID numbers
   *      -> if same, granted
   *      -> if different, look at X's for all list_data_of_same_number
   *          if one X -> denied
   *          if no X -> granted
   */

  /*Denied because of previous denial
   * previous denial -> ignored
   * previous ignore -> ignored
   *
   *    have to look at all locations that have same TRID numbers
   *      -> going to go through all entries anyway
   *      -> if this is the case, is there any need to sort?
   *        -> could make a second list one TRID sorted, one data sorted
   *
   *
   */

  cout << "help in setStatus: " << lockData.size() << endl;


  if(lockData.size() == 0) {
      a.m_status = "GRANTED";
      return;
    }

  //find correct place to check
  list<lockRequest>::iterator dataPlace = findData(lockData, a.getData());
  list<lockRequest>::iterator idPlace = findID(lockID, a.getTRID());




  //check to see if TRID will cause conflict
  while(a.m_TRID == (*idPlace).getTRID()) {
    cout <<"in the first while  "  << (*idPlace).getTRID() << "," << (*idPlace).getData() << "   " << a.m_data << "," << a.m_TRID << endl;

    //if previous TRID is denied, current id is ignored
    if((*idPlace).getStatus() == "DENIED"  ) {
      a.m_status = "IGNORED";
      return;
    }
    //if previous TRID is ignored, current id is ignored
    if((*idPlace).getStatus() == "IGNORED"  ) {
      a.m_status = "IGNORED";
      return;
    }
    idPlace++;
  }

  //check to see if data will cause conflict
  while(a.m_data == (*dataPlace).getData() && dataPlace != lockID.end()) {
    cout <<"in the second while  " << (*dataPlace).getTRID() << "," << (*dataPlace).getData() << "   " << a.m_data << "," << a.m_TRID << endl;


    /*
     * works for checking previous entries but is not updated for current
     * when same data different TRID with current having 'x'
     */

    //while data is same, compare TRID's
    //if same, granted
    if(a.m_TRID == (*dataPlace).getTRID()) {
      a.m_status = "GRANTED";
    }
    else {     //if different look at X's, if no X, granted
      //if no X -> granted
      cout << "else " << endl;
      if((*dataPlace).getX() == 0)
        a.m_status = "GRANTED";
      if((*dataPlace).getX() == 1) {
        a.m_status = "DENIED";
        return;
      }
    }
    dataPlace++;
  }
  //neither TRID nor data are the same so no chance of conflict
  a.m_status = "GRANTED";
  return;
}

