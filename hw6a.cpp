#include <iostream>
using namespace std;

class Car
{
private:
  int year;
  string make;
  int speed;
public:

  Car(int yr, string mk)
  {
    year = yr;
    make = mk;
    speed = 0;
  }

int getYear()
{
  return year;
}
string getMake()
{
  return make;
}
int getSpeed()
{
  return speed;
}

void accelerate()
{
  speed += 5;
}

void brake()
{
  speed -= 5;
}
};


int main()
{
  Car car(1967, "Ford Mustang");

  for (int i = 0; i < 5; ++i)
  {
    car.accelerate();
    cout << "1967 Ford Mustang - current speed : " << car.getSpeed() << endl;
  }

  for (int i = 0; i < 5; ++i)
  {
    car.brake();
    cout << "1967 Ford Mustang - current speed : " << car.getSpeed() << endl;
  }
return 0;}


