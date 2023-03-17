#include "/workspaces/TP4/randomwalk.hpp"

void RandomWalk::update(std::mt19937 &G)
{
    n++;
    s += 2 * U(G) - 1;
};

int main()
{
    std::mt19937 G(0);
    RandomWalk RW(0, 0.5);
    std::ofstream file("RW.dat");
    for (int i = 0; i < 10000; i++)
    {
        RW.update(G);
        file << RW.time() << " " << RW.val() << std::endl;
    }
    file.close();
    RandomWalk_with_Min RWm(0, 0.5);
    std::ofstream file2("RWmin.dat");
    for (int i = 0; i < 10000; i++)
    {
        RWm.update(G);
        file2 << RWm.time() << " " << RWm.val() << " " << RWm.minimum() << std::endl;
    }
    return 0;
}