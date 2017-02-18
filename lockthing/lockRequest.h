//
// Created by Nathan Welch on 2/10/2017.
//

#ifndef LOCKTHING_LOCKREQUEST_H
#define LOCKTHING_LOCKREQUEST_H

#include <list>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class lockRequest {
public:
  lockRequest();
  lockRequest(int data, int TRID, char mode);

  void resetMode();
  list<lockRequest>::iterator findData(list<lockRequest> & l, int finder);
  list<lockRequest>::iterator findID(list<lockRequest> & l, int finder);

  void setData(int data);
  void setTRID(int TRID);
  void setMode(char mode);
  void setStatus(list<lockRequest> & lockData, list<lockRequest> & lockID,
                 lockRequest & a);

  int getData() { return m_data; }
  int getTRID() { return m_TRID; }
  int getS() { return m_S; }
  int getX() { return m_X; }
  string getStatus() { return m_status; }



private:
  int m_data;
  int m_TRID;
  int m_S;
  int m_X;
  char m_mode;
  string m_status;
};


#endif //LOCKTHING_LOCKREQUEST_H
