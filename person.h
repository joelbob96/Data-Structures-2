#include <iostream>
#include <string>
#include <ctime>
#pragma warning(suppress : 38)
#pragma warning(suppress : 39)
#pragma warning(suppress : 40)
#pragma warning(suppress : 41)
#pragma warning(suppress : 42)

class person{
  private:
  std::string fname;
  std::string lname;
  int day;
  int month;
  int year;
  int age;
  
  public:
  person(){
    fname = "default";
    lname = "name";
    day = 0;
    month = 0;
    year = 0;
  }

  person(std::string fn, std::string ln, int mth, int dy, int yr){
    fname = fn;
    lname = ln;
    day = dy;
    month = mth;
    year = yr;
    findAge();
  }

  // Gets the date and calculates the age.
  void findAge(){
    time_t now = time(0);
    tm * tmp = localtime(&now);
    int todayDay = tmp->tm_mday;
    int todayMonth = 1 + tmp->tm_mon;
    int todayYear = 1900 + tmp->tm_year;
    
    //int todayDay = 23;
    //int todayMonth = 1;
    //int todayYear = 2021;
    int i = 1;
    if(todayMonth >= month){
      if((todayDay <= day) && (todayMonth = month)){}
      else{i = 0;}
      }
    int diff = todayYear - year;
    age = diff - i;
  }

  void setFirstName(std::string fn){
    fname = fn;
  }

  void setLastName(std::string ln){
    lname = ln;
  }

  void setDay(int dy){
    day = dy;
  }

  void setMonth(int mth){
    month = mth;
  }

  void setYear(int yr){
    year = yr;
  }

  void setAge(int a){
    age = a;
  }

  //overload operator cout
  void output(std::ostream& s)const{
    s <<  '\n' << fname << " " << lname << ", age " << age <<  " was born on " << month << "-" << day << "-" << year << "\n";
  }

  friend std::ostream& operator<<(std::ostream& s, const person& p) {
      p.output(s);
      return s;
  }

  void inputPerson(){
  std::string fname;
  std::string lname;

  int i, j, k;
  
  std::cout << "Please enter the person's first name: ";
  std::cin >> fname;
  setFirstName(fname);

  std::cout << "Please enter the person's last name: ";
  std::cin >> lname;
  setLastName(lname);

  std::cout << "Please enter the person's birth year: ";
  while(i != -1){
    if(!(std::cin >> i)) {
      std::cout << "\n input not accepted, stopping input\n";
      break;
     } // rejects non integer input
    if ((1899 < i) && ( i <= 2022)){
      setYear(i);
      break;
      }else {
        //while ((getchar()) != '\n');
        std::cout << "Please enter an integer between 1900 and 2021: ";
      }
    }

  std::cout << "Please enter the person's birth month: ";
  while(j != -1){
    if(!(std::cin >> j)) {
      std::cout << "\n input not accepted, stopping input\n \n";
      break;
     } // rejects non integer input
    if((j > 0) && (j < 13)){
      setMonth(j);
      break;
    }else{
      //while ((getchar()) != '\n');
      std::cout << "Please enter an integer between 1 and 12: ";
    }
  }

  std::cout << "Please enter the person's birth day: ";
  while(k != -1){
    if(!(std::cin >> k)) {
      std::cout << "\n input not accepted, stopping input\n";
      break;
     } // rejects non integer input
    if((k > 0) && (k < 32)){
      setDay(k);
      break;
    }else{
      //while ((getchar()) != '\n');
      std::cout << "Please enter an integer between 1 and 31: ";
    }
  }
  findAge();
}

};