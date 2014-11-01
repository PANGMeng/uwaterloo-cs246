#ifndef ___VECTOR__H_
#define ___VECTOR__H_

#include <iostream>

struct Vector{
   int size;
   int * fields;
   
   //Constructor(s)
   explicit Vector(int size);
   
   #ifdef BIGTHREE
   //Copy Constructor
   Vector(const Vector & v):size(v.size),fields(new int[size]){
      for (int i = 0; i < size ; ++i){
         fields[i] = v.fields[i];
      }
   }
   //Destructor
   ~Vector(){
      delete[] fields;
   }

   //Assignemnt Operator
   Vector& operator=(Vector v){
      int temp_size = v.size;
      v.size = this->size;
      this->size = temp_size;

      int * temp_fields = v.fields;
      v.fields = this->fields;
      this->fields = temp_fields;

      return *this;
   }
   #endif

   Vector operator+(const Vector & v);
   Vector operator-(const Vector & v);
   Vector operator*(const int & n);
   Vector operator/(const int & n);
};

std::ostream& operator<<(std::ostream &out, const Vector & v);
std::istream& operator>>(std::istream &in, Vector & v);

#endif
