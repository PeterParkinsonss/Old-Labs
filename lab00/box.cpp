#include "box.h"
using namespace std;

// FІXΜЕ: implement the Box methods defined in box.h

Box::Box(int w , char b){
  width = w;
  boxChar = b;
}

int Box::getWidth() const{
  return width;
  }
char Box::getBoxChar() const{

  return boxChar;
} 
void Box::setBoxChar(char newChar){
  boxChar = newChar;
 // boxChar = '$';
}
void Box::operator+=(int offset){
  width = width + offset;
}
// FІXΜЕ: implement the functions declared in box.h

void operator-=(Box& b, int offset){
  b.width = b.width - offset;
}

 std::ostream& operator<<(std::ostream& out, const Box& b){
  for(int i = 0; i < b.width; i++){    
    for(int j = 0; j < b.width; j++){
      out << b.boxChar ;
    }
    out << endl;
  } 
  return out;
}
