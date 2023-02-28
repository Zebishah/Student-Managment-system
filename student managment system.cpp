#include <iostream>

#include <string>

using namespace std;

struct students {
  int regNo;
  string name, emailid;
  float CGPA;
};

int search(students stdz[], int & present, int rollno);
bool checkingRegNo(students stdz[], int & present, int regNo);
bool checkingCGPA(students stdz[], int & present, int CGPA);
void display(students stdz[], int & present);

int intialize(students stdz[], int Nstds, int & present) {
  int presentCopy = present;
  for (int i = presentCopy; i < presentCopy + Nstds; ++i) {
    cout << "\nEnter the Data of student " << i + 1 << endl <<
      endl;
    cout << "Enter name : ";
    cin.ignore();
    getline(cin, stdz[i].name);
    bool regValid = false;
    do {
      int regNo;
      cout << "Enter reg no of student " << i + 1 << " : ";
      cin >> regNo;
      regValid = checkingRegNo(stdz, present, regNo);
      if (regValid) stdz[i].regNo = regNo;
    } while (!regValid);
    do {
      cout << "Enter cgpa : ";
      cin >> stdz[i].CGPA;
    } while (!checkingCGPA(stdz, present, stdz[i].CGPA));
    cout << "Enter email : ";
    cin.ignore();
    getline(cin, stdz[i].emailid);
    present++;
    cout << "\n<----------------------------------------------------->\n";
  }
  return 1;
}

int insert(students stdz[], int & present) {
  cout << "\nEnter the Data of student " << present + 1 << endl << endl;
  cout << "Enter Name :";
  cin.ignore();
  getline(cin, stdz[present].name);
  bool regValid = false;
  do {
    int regNo;
    int rollno;
    cout << "Enter reg no of student " << present + 1 << " : ";
    cin >> regNo;
    regValid = checkingRegNo(stdz, present, regNo);
    if (regValid) stdz[present].regNo = regNo;
  } while (!regValid);
  do {
    cout << "Enter cgpa : ";
    cin >> stdz[present].CGPA;
  } while (!checkingCGPA(stdz, present, stdz[present].CGPA));
  cout << "Enter Email Address :";
  cin.ignore();
  getline(cin, stdz[present].emailid);
  cout << endl;
  present++;
  cout << "\n<----------------------------------------------------->\n";
  return 0;
  cout << "\n<----------------------------------------------------->\n";
}

bool checkingCGPA(students stdz[], int & present, int CGPA) {
  bool three_digit;
  three_digit = CGPA > 1.00 && CGPA < 4.00;
  if (!three_digit) {
    cout << "CGPA you written of this student is not valid!! please enter valid CGPA of this student..... " << endl;
    return false;
  }
  return true;
}

bool update(students stdz[], int & present, int rollno) {
  if (present == 0) {
    cout << "No data is entered ....." << endl;
  } else {
    for (int i = 0; i < present; i++) {
      if (rollno == stdz[i].regNo) {
        cout << "\nPrevious data:" << endl << endl;
        cout << "Data of Student " << i + 1 << ":" <<
          endl;
        cout << "Name : " << stdz[i].name << endl;
        cout << "reg no : " << stdz[i].regNo << endl;
        cout << "cgpa : " << stdz[i].CGPA << endl;
        cout << "email id : " << stdz[i].emailid << endl;
        cout << "\n<------------------------------------------------------->\n";
        cout << "\nEnter new data for student" << i + 1 <<
          ":" << endl << endl;
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, stdz[i].name);
        bool regValid = false;
        do {
          int regNo;
          stdz[i].regNo = -1;
          cout << "Enter reg no of student " << i + 1 << " : ";
          cin >> regNo;
          regValid = checkingRegNo(stdz, present, regNo);
          if (regValid) stdz[i].regNo = regNo;
        } while (!regValid);
        do {
          cout << "Enter cgpa : ";
          cin >> stdz[i].CGPA;
        } while (!checkingCGPA(stdz, present, stdz[i].CGPA));
        cout << "Enter email id :";
        cin.ignore();
        getline(cin, stdz[i].emailid);
        cout << "\n<------------------------------------------------------->\n";
      }
    }
  }
  return true;
}

int search(students stdz[], int & present, int rollno) {
  for (int i = 0; i < present; i++) {
    if (rollno == stdz[i].regNo)
      return i;
  }
  return -1;
}

bool checkingRegNo(students stdz[], int & present, int regNo) {
  bool four_digit;
  four_digit = regNo > 999 && regNo < 10000;
  if (!four_digit) {
    cout << "registration number is not valid!! please enter valid registration number..... " << endl;
    return false;
  }
  if (search(stdz, present, regNo) != -1) {
    cout << "Reg No already exist. " << endl;
    return false;
  }
  return true;
}

void deleterecord(students stdz[], int & present, int rollno) {
  if (present == 0) {
    cout << "No data is entered ...." << endl;
    cout << "\n<----------------------------------------------------->\n";
  } else {
    int a;
    cout << "Press 1 to delete all record .." << endl;
    cout << "Press 2 to delete specific record.." << endl;
    cin >> a;
    if (a == 1) {
      present = 0;
      cout << "All record is deleted..!!" << endl;
      cout << "\n<----------------------------------------------------->\n";
    } else if (a == 2) {
      int rollno;
      cout << "Enter the roll no of student which you wanted to delete :" <<
        endl;
      cin >> rollno;
      for (int i = 0; i < present; i++) {
        if (rollno == stdz[i].regNo) {
          for (int j = i; j < present; j++) {
            stdz[j].name = stdz[j + 1].name;
            stdz[j].regNo = stdz[j + 1].regNo;
            stdz[j].CGPA = stdz[j + 1].CGPA;
            stdz[j].emailid = stdz[j + 1].emailid;
          }
          present--;
          cout << "Your required record is deleted ........" << endl;
          cout << "\n<----------------------------------------------------->\n";
        }
      }
    }
  }
  cout << "\n<----------------------------------------------------->\n";
}

int sort(students stdz[], int & present, string sort_by, char order) {
  for (int i = 0; i < present; i++) {
    for (int j = i; j < present; j++) {
      bool flip;
      if (order == 'a')
        flip = stdz[i].regNo > stdz[j].regNo;
      if (order == 'd')
        flip = stdz[i].regNo < stdz[j].regNo;

      if (flip) {
        students temp = stdz[i];
        stdz[i] = stdz[j];
        stdz[j] = temp;
      }
    }
  }
  display(stdz, present);
  cout << "\n<------------------------------------------------------->\n";
  return 0;
  cout << "\n<------------------------------------------------------->\n";
}
void display(students stdz[], int & present) {
  cout << "\n<------------------------------------------------------->\n";
  for (int i = 0; i < present; i++) {
    cout << "Name of student " << i + 1 << " is: " <<
      stdz[i].name << endl;
    cout << "Reg No of student " << i + 1 << " is: " <<
      stdz[i].regNo << endl;
    cout << "CGPA of student " << i + 1 << " is: " <<
      stdz[i].CGPA << endl;
    cout << "Email of student " << i + 1 << " is: " <<
      stdz[i].emailid << endl;
    cout << endl;
    cout << "\n<----------------------------------------------------->\n";
  }
}

int main() {
  int Check;
  int present = 0;
  int Nstds;
  students stdz[30];
  do {
    cout << "Press 1 to Intialize." << endl;
    cout << "Press 2 to Insert." << endl;
    cout << "Press 3 to Search." << endl;
    cout << "Press 4 to display." << endl;
    cout << "Press 5 to update." << endl;
    cout << "Press 6 to delete." << endl;
    cout << "Press 7 to sort." << endl;
    cout << "Press 8 to exit program." << endl;
    cout << "Please Enter your Desired Option: ";
    cin >> Check;
    if (Check > 7 || Check < 1) {
      return 0;
    }
    switch (Check) {
    case 1:
      int Nstds;
      int instances;
      cout << "How many students are there: ";
      cin >> Nstds;
      intialize(stdz, Nstds, present);
      break;
    case 2:
      insert(stdz, present);
      break;
    case 3: {

      int rollno;
      cout << "Enter the reg no of student which u want to search:" << endl;
      cin >> rollno;
      int index = 0;
      index = search(stdz, present, rollno);
      cout << "\nName of student is " << stdz[index].name <<
        "\nRegNo of student is " << stdz[index].regNo <<
        "\nCGPA of student is " << stdz[index].CGPA <<
        "\nEmail of student is " << stdz[index].emailid <<
        endl << endl;
      break;
    }
    case 4:
      display(stdz, present);
      break;
    case 5:
      int rollno;
      cout << "Enter the roll no of student which you want to update :" << endl;
      cin >> rollno;
      update(stdz, present, rollno);
      break;
    case 6:
      deleterecord(stdz, present, rollno);
      break;
    case 7: {

      string sort_by;
      char order;
      bool flip;
      do {
        cout << "1: Sort in Ascending.\n" << "2: Sort in Descending.\n" << "Enter choice: ";
        cin >> order;
      } while (!(order == 'a' || order == 'd'));
      sort(stdz, present, sort_by, order == 'a' ? 'a' : 'd');
      break;
    }
    }
  } while (Check != -1);
  return 0;
}