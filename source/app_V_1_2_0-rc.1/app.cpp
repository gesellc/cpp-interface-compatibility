#include <part.h>
#include <iostream>
#include <memory>

int main()
{
  using namespace std;
  using namespace inventory_V_4_0_0;

  unique_ptr< part_v2 > p( dynamic_cast< part_v2* >( create_part() ) );
  p->id( 100 );
  p->name( "wingnut" );
  cout << p->id() << endl;
  cout << p->name() << endl;
}
