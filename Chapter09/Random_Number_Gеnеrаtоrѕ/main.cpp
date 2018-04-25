#include <iostream>

using namespace std;

static const int A = 1;
static const int M = 10;

class Random
{
    private:
        int state;

    public:
        explicit Random(int initialValue = 1);	

        int randomInt();
        double random0_1();
		int randomInt(int low, int high);
};

Random::Random(int initialValue)
{
    if(initialValue < 0)
		initialValue += M;

    state = initialValue;

    if(state == 0)
        state = 1;
}

int Random::randomInt( )
{
	return state = (A * state) % M;
}

double Random::random0_1( )
{
	return static_cast<double>(randomInt()) / M;	
}

int main()
{
    return 0;
}
