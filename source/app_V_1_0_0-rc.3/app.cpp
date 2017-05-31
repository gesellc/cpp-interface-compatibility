#include <part.h>
#include <iostream>
#include <memory>

int main()
{
  using namespace std;
  using namespace inventory_V_3_0_0;

  unique_ptr< part > p( create_part() );
  cout << p->id() << endl;
}
