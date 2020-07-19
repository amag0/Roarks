#include <string>
#include <iostream>
// try to construct an area analysis builder
// Class Builder introduce un objeto como parámetro de otro
// y una función como método del objeto

class A
{
  private:
  std::string as;
  public:
  A(std::string a):as(a){}
};
class func
{
  private:
  std::string os;
  public:
  func(std::string out):os(out){}
  void operator()() {std::cout<<os<<std::endl;}
};
class B
{
  public:
  A* param;
  public:
  B(){param = NULL; method = NULL;}
  B& operator =(const B& other);
  func* method;
};
B& B::operator =(const B& other)
{
  if (this != &other)
  {
    this->param = other.param;
    this->method = other.method;
  }
  return *this;
}
class Builder
{
  private:
  class B object;
  
  public:
  bool reset() {object* = new B(); return true;}
  bool SetParam(int type) 
  { 
    switch (type)
    {
      case 1: A p = new A("type 1"); param = *p;  break;
      case 2: A p = new A("type 2"); param = *p; break;
      default: A p = new A(""); return false;
    }
    return true;
  }
  bool SetMethod() 
  { 
    func f = new func(object.param->as);
    return true;
  }
  B& Get() {return object;}
};
int main()
{
  Builder MyBuilder;
  if(!MyBuilder.reset()) { std::cout<<"failed reseting builder"<<std::endl;}
  if(!MyBuilder.SetParam(1)) { std::cout<<"failed setting param"<<std::endl;}
  if(!MyBuilder.SetMethod()) {std::cout<<"failed setting  method"<<std::endl;}
  B MyObject = MyBuilder.Get();
  MyObject.method;
  return 0x0;
}