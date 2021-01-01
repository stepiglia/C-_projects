//classes and objects: Classes = group your functions 

class StefClass{
//public --> means that you can use it outside of the class
  
  //-------PUBLIC-------- 
public: 
  
  StefClass(string z){
    setName(z);
    cout << "This will get printed as soon as you call the object"; 
  } //the costuctor name is always the same as the class name . It is useful when you want to 
  
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

  //-------PRIVATE--------
private:
  string name2; //you make the variable private and instead you make the function that accesses it public in order to use it 
  
}

//an object is how you access the stuff inside of your class. 
//Creating an object lets C++ know from which class to call the function from. 
// Because you could have a function with the same name in multiple classes 

int main(){
  StefClass obj; //we are making an object of that class + the constuctor will run 
  obj.coolSaying(); 
  return 0; 
  
  obj.setName("Sir Stef");
  cout << obj.getName(); //we need to do this because remember we don't have direct access to the variable 
 
   StefClass obj("")
  
}

//-------CONSTRUCTORS--------
//it's a function that gets called  automatically as soon as you 
//create an object 


//-------SWITCH--------
switch(age) {
  case 16: 
    cout << "Hey you can drive now!" << endl; 
    break;
  case 18: 
    cout << "Get lotto tickets!" << endl; 
    break;
  case 21: 
    cout << "Buy me some beer!" << endl; 
    break;
  default: 
    cout << "Sorry you get nothing" << endl; 
}

//-------FUNCTION OVERLOADING--------
//it's the idea of bulding more than one function with the same name 
//that take different types of data depending on what you take in
void printNumber(int x){
  cout << "i am printing an integere" << x << endl; 
}

void printNumber(float x){
  cout << "i am printing a float" << x << endl; 
}
  
int a = 54; 
float b = 21.4869; 

printNumber(a); 
printNumber(b); 

//that's why you have to declare the type of variables you pass into functions btw :)


