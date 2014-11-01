#include <iostream>
#include <string>
#include <sstream>
#include "Vector.h"

using namespace std;


int main(){
   Vector * vecs[4];
   vecs[0] = vecs[1] = vecs[2] = vecs[3] = 0;
   string oper;
   while(cin){
      cout << "Command?" << endl;
      cin >> oper;
      if (oper == "q")
         break;
      else if(oper == "new"){
         int which;
         int size;
         cout << "Which vector?(0-3) ";
         cin >> which;
         cout << "What is the size of the vector? ";
         cin >> size;
         delete vecs[which];
         vecs[which] = new Vector(size);
         cout << "What are the fields of the vector? (Give " << size << ") " <<endl;
         for (int i = 0; i < size; ++i){
            string reading;
            while(cin >> reading){
               stringstream ss(reading);
               if ( ss >> vecs[which]->fields[i] ){
                  break;
               }//if
               else{
                  cout << reading << " is not a number." << endl;
               }//else
            }//while
         }//for
      }//new
      else if (oper == "print"){
         int which;
         cout << "Which vector?(0-3) ";
         cin >> which;
         cout << *(vecs[which]) << endl;
      }//if
      else if (oper == "copy"){
         int which, copy;
         cout << "Which vector will be copied from?(0-3) ";
         cin >> which; 
         cout << "Which vector will be copied to?(0-3) ";
         cin >> copy;
         delete vecs[copy];
         vecs[copy] = new Vector(*(vecs[which]));
      }//if
      else if (oper == "+"){
         int a, b, which;
         cout << "Which vectors will be added?(0-3) ";
         cin >> a >> b;
         cout << "Which vector will they be stored in?(0-3) ";
         cin >> which;
         Vector * temp = new Vector(*vecs[a] + *vecs[b]);
         delete vecs[which];
         vecs[which] = temp;
      }//if
      else if (oper == "-"){
         int a, b, which;
         cout << "Which vectors will be subtracted?(0-3) ";
         cin >> a >> b;
         cout << "Which vector will they be stored in?(0-3) ";
         cin >> which;
         Vector * temp = new Vector(*vecs[a] - *vecs[b]);
         delete vecs[which];
         vecs[which] = temp;
      }//if
      else if (oper == "change"){
         int which, field, change;
         cout << "Which vector will be changed?(0-3) ";
         cin >> which;
         cout << "Which field will be changed?(0-"<<vecs[which]->size<<") ";
         cin >> field;
         cout << "What will the field be changed to? ";
         cin >> change;
         vecs[which]->fields[field] = change;
      }//if
      else if ( oper == "*" ){
         int which, n, where;
         cout << "Which vector will be changed?(0-3) ";
         cin >> which;
         cout << "What will the vector be multiplied by?(int) ";
         cin >> n;
         cout << "Where will the new vector be stored?(0-3) ";
         cin >> where;
         Vector * temp = new Vector(*vecs[which] * n);
         delete vecs[where];
         vecs[where] = temp;
      }//if
      else if ( oper == "/" ){
         int which, n, where;
         cout << "Which vector will be changed?(0-3) ";
         cin >> which;
         cout << "What will the vector be multiplied by?(int) ";
         cin >> n;
         cout << "Where will the new vector be stored?(0-3) ";
         cin >> where;
         Vector * temp = new Vector(*vecs[which] / n);
         delete vecs[where];
         vecs[where] = temp;
      }//if
      else{
         cout << oper << " is not a valid command." << endl;
         cout << "Valid commands are:" << endl;
         cout << "   new: creates new vector" << endl;
         cout << "   copy: copies a vector" << endl;
         cout << "   print: prints a vector to cout" << endl;
         cout << "   change: changes one field of a vector" << endl;
         cout << "   +: adds two vectors" << endl;
         cout << "   -: subtracts two vectors" << endl;
         cout << "   *: multiplies a vector by an int" << endl; 
         cout << "   /: divides a vector by an int" << endl;
      }//else
   }//while
   for (int i = 0; i < 4; ++i){
     delete vecs[i];
   }
}//main

ostream& operator<<(ostream &out, const Vector & v){
   out << "(" << v.fields[0];
   for (int i = 1; i < v.size; ++i){
      out << "," << v.fields[i];
   }
   out << ")";
   return out;
}

istream& operator>>(istream &in, Vector & v);

Vector::Vector(int size):size(size), fields(new int[size]){
   for (int i = 0; i < size; ++i)
      fields[i] = 0;
}

Vector Vector::operator+(const Vector & v){
   if (size != v.size){
      cout << "Cannot add vectors of different sizes. Empty returned." << endl;
      Vector empty(size);
      return empty;
   }
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i] + v.fields[i];
   }
   return temp;
}

Vector Vector::operator-(const Vector & v){
   if (size != v.size){
      cout << "Cannot subtract vectors of different sizes. Empty returned." << endl;
      Vector empty(size);
      return empty;
   }
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i] - v.fields[i];
   }
   return temp;
}

Vector Vector::operator*(const int & n){
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i]*n;
   }
   return temp;
}

Vector Vector::operator/(const int & n){
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i]/n;
   }
   return temp;
}

Vector operator*(const int & n, Vector & v){
   return v*n;
}
