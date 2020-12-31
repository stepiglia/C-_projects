//classes and objects: Classes = group your functions 

class StefClass{
//public --> means that you can use it outside of the class
public: 
  void coolSaying(){
    cout << "ciao << endl; 
  }
}

//an object is how you access the stuff inside of your class. 
//Creating an object lets C++ know from which class to call the function from. 
// Because you could have a function with the same name in multiple classes 

int main(){
  StefClass StefObject; //we are making an object of that class
  StefObject.coolSaying(); 
  return 0; 
}
