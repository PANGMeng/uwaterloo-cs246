#ifndef __IOSTREAM__
#define __IOSTREAM__

#include <iostream>

#endif // __IOSTREAM__


#ifndef __ISTRING_H__
#define __ISTRING_H__

struct iString{
  char * chars;
  unsigned int length;
  unsigned int capacity;
  iString();
  iString(const char *);
  iString(const iString&);
  iString &operator=(const iString&);
  iString &operator=(const char *);
  ~iString();
};

// Add other declarations here:

// inline iString operator=(const iString&, const char *);
inline iString& operator+(const iString& self, const iString& other);
inline iString& operator+(const iString&, const char *);
// inline iString operator/(const iString&, const iString&);
// inline iString operator%(const iString&, const iString&);
// inline ostream operator%(const iString&, const iString&);
std::ostream &operator<<(std::ostream &out, const iString &c);
std::istream &operator>>(std::istream &in, const iString &c);
#endif
