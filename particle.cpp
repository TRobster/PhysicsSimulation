#include <stdlib.h>
#include <vector>
#include <iostream>


using namespace std;

using fl = float; 

class Particle
{
    fl x;
    fl y;
    fl z;
    fl vel;
    fl force;
    fl dens;

    public:
        void updatePOS(fl x, fl y, fl z);

        Particle()
        {
            fl x = 0;
            fl y = 0;
            fl z = 0;
            fl vel = 0;
            fl force = 0;
            fl dens = 0;
        }
        Particle(fl x0, fl y0, fl z0)
        {
            fl x = x0;
            fl y = y0;
            fl z = z0;

        }

        vector<float> returnCart()
        {
            vector<float> cart {this->x, this->y, this->z};
            return cart;

        }

};

void Particle::updatePOS(fl x1, fl y1, fl z1)
{
    this->x += x1;
    this->y += y1;
    this->z += z1;
}

int main()
{
    Particle x(10, 10, 10);
    Particle y; 
    vector<float> k = x.returnCart();
    vector<float> mew = y.returnCart();

    for (int i = 0; i < 3; i++)
    {
        cout << k[i] << endl;
        cout << mew[i] << endl;
    }
}
