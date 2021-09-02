#include <iostream>
#include <random>
using namespace std;

int length;
string password;


/*this functon finds if the password is valid by going through a range of ascii numbers and returning a bool based on if the conditions are met*/
bool validator(){
  bool specialChar = false; //decides if there is or isnt special characters
  bool numbers = false; //decides if there are numbers or not
  bool upper = false; //decides if there are uppercase characters
  bool lower = false; //decides if there are lowercase characters
  pswdLengthError:
cout << "What is your password?" << endl;
cin >> password;
if(password.length() > 999){
        cout << " Error: Password length exceeds maxiumum" << endl << endl;
        fflush(stdin);
        system("clear");
        goto pswdLengthError;
        //used to "reset" the program in case length exceeds 999
      }
  //this for loop checks for numbers
  for(char j = 48; j != 57; j++){
    size_t found = password.find(j);
    if(found != string::npos){
      numbers = true;
    }
  }
  if(numbers != true){
    cout << "The password is not valid! It doesn't contain any numbers!" << endl << endl;
    goto invalid;
  }
  //this for loop searches for special characters
  for(char i = 33; i != '~'; i++){
    size_t found = password.find(i);
    if(found != string::npos){
      specialChar = true;
    }
    /*i is reassigned so it can jump to where special chars start again on ascii table*/
    switch(i){
      case '/':
      i = 57;
      break;
      case '@':
      i = 91;
      break;
      case '`':
      i = 123;
      break;
    }
  }
  if(specialChar != true){
    cout << "The password is not valid! It doesn't contain special characters!" << endl << endl;
    goto invalid;
  }
  //this looks for capital letters
  for(char j = 97; j != 122; j++){
    size_t found = password.find(j);
    if(found != string::npos){
      upper = true;
    }
  }
  if(upper != true){
    cout << "The password is not valid! It doesn't contain any uppercase letters!" << endl << endl;
    goto invalid;
  }
    //this looks for lowercase letters
  for(char j = 65; j != 90; j++){
    size_t found = password.find(j);
    if(found != string::npos){
      lower = true;
    }
  }
  if(lower != true){
    cout << "The password is not valid! It doesn't contain any uppercase letters!" << endl << endl;
    goto invalid;
  }

if(specialChar && numbers && upper && lower == true && password.length() > 12){
  cout << endl <<"The password is valid and safe!" << endl << endl;
  return true;
}
invalid:
return false;
}

void generatedPswd(){
  char generated[length];
  random_device rd; // obtain a random number from hardware
  mt19937 gen(rd()); // seed the generator
  uniform_int_distribution<> distr(33, 126); // define the range
  for(int i = 0; i < length; i++){
    generated[i] = distr(gen);
  }
  cout << endl << "Generated password is:";
  cout << endl << endl << "\u001b[33m" <<generated << "\e[0;37m" << endl << endl;
}

int main() {
  string reset;
  int menuchoice;
  errorcatch:
  cout << "This is a password generator and validator! " << endl;
  cout << "\e[1;31m 'y' signifies yes and 'n' signifies no\e[0;37m" << endl;
  cout << "Type in the number that corresponds to your choice" << endl << endl;
  cout << "\u001b[34m1. Password Generator\e[0;37m" << endl;
  cout << "\u001b[33m2. Password Validator\e[0;37m" << endl;
  cout << "\u001b[32m3. Password Strength Info\e[0;37m" << endl;
  cin >> menuchoice;
  system("clear");
  switch(menuchoice){
    case 1:
      cout << "What length do you want the password to be?" <<endl;
      cin >> length;
      if(length > 999){
        cout << " Error: Password length exceeds maxiumum" << endl << endl;
        fflush(stdin);
        goto errorcatch;
        //used to "reset" the program in case length exceeds 999
      }
    generatedPswd();
    break;
    case 2:
    validator();
    break;
    case 3:
    cout << "A good password constitutes at least one special character, one number, uppercase, and lowercase letters." << endl << "I usually recommend a password length of at least 12." <<endl << "The length and number of the aforementioned character types depends on your usecase." << endl <<  "If you are trying to hide from the feds than I think you better get off my github and do something much more technical to escape them. Good luck with that!" << endl << "If you're just an average employee or businessman than this program should work well enough for you." << endl << endl << "\e[1;31m WARNING! Computers can NEVER be truly random, so use the program at your own risk." << endl << " The generated password may not be valid.\e[0;37m" << endl << endl;
    break;
    default:
      cout << "An error occured";
      exit(EXIT_FAILURE);
    break;
  }
  cout << "Do you want to create or validate another password?" << endl;
  cin >> reset;
  if(reset == "n"){
    system("clear");
    cout << "Thanks for using my validator, and have a nice day :)";
    return 0;
  }
    fflush(stdin);
    system("clear");
    goto errorcatch; //resets the program if they choose anything other than n
  return 0;
}
