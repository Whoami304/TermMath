#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

void BasicOp(double*pa,double*px,char *pres);
void AdvancedOp(double *pa,char *pres);
void FileOpen(string file); 
void Binary(int );
void Decimal(int);
int convertBinaryToDecimal(long long);
void CalcSquare(int a,int b,int c);
void ReadFromFile(string);


int main(){ 
  
  
  double a,x;
  char res; 
  string choose_op,file,fl;
  
  FileOpen(file);
  ReadFromFile(fl);
  cout << "\nEnter operation:"; 
  
  cin>> choose_op;

  if(choose_op == "1"){
   cout << "\nEnter number:";
   cin >> a;
  
   cout << "\nEnter number:";
   cin >> x;

   cout << "+,-,*,/" << endl; 
   cout << "\nEnter operation:";
   cin >> res;
  BasicOp(&a,&x,&res);
  }
  else if(choose_op == "2" ){
      
      
      cout << "1)Power" << endl;
      cout << "2)Mod" << endl;
      cout << "3)Square root" <<endl;      
      cout << "4)cos " << endl;
      cout << "5)sin " << endl;
      cout << "6)tg  " << endl;
      cout<< "\nEnter operation:"; 
      cin >> res;
      
      cout << "\nEnter Number >>";
      cin >> a;
      AdvancedOp(&a,&res);    
  }
  
  else if(choose_op == "3"){
     
    unsigned int n;
    unsigned long long factorial = 1;

    cout << "\nEnter a positive Integer Number: ";
    cin >> n;

    for(int i = 1; i <=n; ++i){
    
        factorial *= i;
    }
    cout << ">>>>>>\tFactorial of " << n << " = " << factorial<<endl; 
 }
 else if(choose_op == "4"){
        
 
		cout << "\nEnter number:";
		cin >> a;
		Binary(a);
		
   }
 else if(choose_op == "5"){  //not working//
     long long n;

    cout << "Enter a binary number: ";
    cin >> n;
 
    cout <<"\n"<< n << " in binary = " << convertBinaryToDecimal(n) << " in decimal"<<endl;
    return 0;
 }    
 else if (choose_op == "6") { //fibonacci block
	    
	int a, b, n;
	a = 0;
	b = 1;
	
	cout << "\nEnter number:";
	cin >> n;
	while (n <= 0)
	{
		cout << "Enter the number bigger than 0: ";
		cin >> n;
	}
	while (n != 0)
	{
		a += b;
		b = a - b ;
		n = n - 1;
		cout  << a<<" " << endl;
	}
	return 0;
}   

else if(choose_op == "7"){
    int  a,b,c;
    int D; 
    
    cout << "\nEnter a:"<<endl; 
    cin >> a;
    
    cout << "\nEnter b:" <<endl; 
    cin >> b;

    cout << "\nEnter c:" << endl;
    cin >> c;
    CalcSquare(a,b,c);
  }
else if(choose_op == "8"){
     float num;
     
     cout << "\nEnter Number in Rad:";
     cin >> num;     
    
    cout <<"Result is "<< num*180/M_PI<<endl;
  }
  else if(choose_op == "9"){    
      float nums;
      cout << "Enter number in grad:";  
      cin >> nums;
    
     cout <<"\nResult is "<< nums*180/M_PI << endl;
  }  
 
           
  string OP;
  
  cout << "restart/close:";
  cin >> OP; 

  if(OP == "restart"){
      cout << main();
  } 
  else if(OP == "close"){
      cout << "Program closed" << endl;
  }
  else{
      cout << "Error,operation can't found" << endl;
  }

}

void ReadFromFile(string fl){
     fl = "menu.txt";
     fstream fins;
     fins.open(fl,fstream :: in | fstream :: out | fstream :: app);
     
     if(!fins.is_open()){
        cout << "ERROR,can't open this file" << endl;
     }
     else {
         char s;
         while(fins.get(s)){
             cout << s;
         }
      fins.close();
    }
     return;
}


void CalcSquare(int a,int b,int c){
      int D;
     
     D = pow(b,2) - 4 * a * c;
    cout << "D =" << sqrt(D) << endl;


    if(D < 0){
        cout << "can't calculate this operation"<<endl;;
    } 
    else if(D > 0){
        int x_1,x_2;
        
        x_1 = -b+sqrt(D)/2*a;
        x_1 = -b-sqrt(D)/2*a;
        cout << "x(1) ="<< x_1 << endl;
        cout << "x(2) ="<< x_2 << endl; 
    }
    else if(D == 0){
        int x;
        x = -b/2*a;
        cout << "x ="<< x <<endl;
    }
    else{
        cout << "unknown operation" << endl;
    }
 }


int convertBinaryToDecimal(long long n){

    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

 void Binary(int a) {
	long long int n = 0;
	int k, m = 0;
	while (a) {
		k = a % 2;
		a = a / 2;
		n += k * pow(10,m);
		m++;
	}
	cout <<"result\t"<< n << endl;
}
 
 
 
 void BasicOp(double *pa,double *px,char *pres ){
   if(*pres == '+'){ 
    cout <<"result is "<<  *pa + *px << endl;
   }
   else if(*pres == '-'){
    cout <<"result is "<< *pa - *px << endl;    
   }
   else if(*pres == '*'){
       cout << "result is " << *pa * *px << endl;
   }
   else if(*pres == '/'){
       cout << "result is " << *pa / *px << endl;
   }   
               
}


void AdvancedOp(double *pa,char *pres){
     if(*pres == '1'){
         cout << "\nresult is "<<pow(*pa,2);
     } 
     else if(*pres == '2'){
         cout <<"\nresult is "<< abs(*pa);
     }
     else if(*pres == '3'){
         cout << "result is " << sqrt(*pa);
     }    
     else if(*pres == '4'){
         cout << cos(*pa*M_PI/180);
     }
     else if(*pres == '5'){     
     cout << sin (*pa*M_PI/180);
     }
     else if(*pres == '6'){
        cout << tan(*pa*M_PI/180);
     }

} 
void FileOpen(string file){
     file = "math.txt";
     fstream fs;
     fs.open(file,fstream :: in | fstream :: out | fstream :: app);
     
     if(!fs.is_open()){
         cout << "Error is detected" << endl;
     }
     else{
         char ch;
         while(fs.get(ch)){
             cout << ch; 
         }
      fs.close();
     }
}

    
  
