class properties
{
public:
    virtual int integer() const { return 0; }
    virtual double floatingpoint() const { return 0; }
};


class extended_properties
{
public:
    virtual int integer() const { return 0; }
    virtual double floatingpoint() const { return 0; }
    virtual void integer( int ){}
    virtual void floatingpoint( double ){}
};

int main()
{
  properties p;
  extended_properties ep;
}