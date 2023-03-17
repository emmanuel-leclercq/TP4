#include "/workspaces/TP4/randomwalk.hpp"



int main()
{
    std::mt19937 G(time(nullptr));
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
        file2 << RWm.time() << " " << RWm.minimum() << std::endl;
    }
    return 0;
}