#include "Base.hpp"
#include <iostream>
Base::~Base() {}

Base *generate() {
  srand(time(NULL));
  int index = rand() % 3;
  switch (index) {
  case (0):
    return (new A());
    break;
  case (1):
    return (new B());
    break;
  case (2):
    return (new C());
    break;
  }
  return (NULL);
}
void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    return (std::cout << "A" << std::endl, (void)a);
  } catch (std::bad_cast) {}
  try {
    B &b = dynamic_cast<B &>(p);
    return (std::cout << "A" << std::endl, (void)b);
  } catch (std::bad_cast) {}
  try {
    C &c = dynamic_cast<C &>(p);
    return (std::cout << "A" << std::endl, (void)a);
  } catch (std::bad_cast) {
    std::cout << "Unknown type" << std::endl;
  }
}