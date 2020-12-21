// stringbad.h --
#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class Stringbad {
   private:
    char *str;
    int len;
    static int num_strings;

   public:
    Stringbad(const char *s);
    Stringbad();
    ~Stringbad();
    friend std::ostream &operator<<(std::ostream &os, const Stringbad &st);
};

#endif
