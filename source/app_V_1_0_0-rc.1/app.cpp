#include <part.h>
#include <iostream>
#include <memory>

int main()
{
  using namespace std;
  using namespace inventory_V_1_0_0;

  unique_ptr< part > p( new part );
  cout << p->id() << endl;
}
