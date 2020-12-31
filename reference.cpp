//classes and objects: Classes = group your functions 

class StefClass{
//public --> means that you can use it outside of the class
public: 
  void coolSaying(){
    cout << "ciao << endl; 
  }
  string name; //DON'T DO THIS. Making class variables public is not a good practice. It makes programs easy to mess up 
  
  void setName(string x){ //setter function. We don't have direct access to the variable so we change it with this function 
    name = x
  }
  
  string getName(){ //and to get the value of the variable we use this other function 
    return name; 
  }
  
private:
  string name2; //you make the variable private and instead you make the function that accesses it public in order to use it 
  
}

//an object is how you access the stuff inside of your class. 
//Creating an object lets C++ know from which class to call the function from. 
// Because you could have a function with the same name in multiple classes 

int main(){
  StefClass StefObject; //we are making an object of that class
  StefObject.coolSaying(); 
  return 0; 
}
