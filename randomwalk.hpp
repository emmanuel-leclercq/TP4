#include <iostream>
#include <random>
#include <cmath>
#include <fstream>

class RandomWalk
{
protected:
    unsigned n; // temps courant n
    int s;      // valeur de S_n
    int s_init; // valeur de S_0
    std::bernoulli_distribution U;

public:
    RandomWalk(int s0, double p) : n(0), s(s0), s_init(s0), U(p){};
    int val() const { return s; };       // accesseur à s
    unsigned time() const { return n; }; // accesseur à n;
    virtual void reset()
    {
        n = 0;
        s = s_init;
    }; // redémarrage à l'état initial
    void update(std::mt19937 &G){};
    // passage de n à n+1 avec générateur G
};

class RandomWalk_with_Min : public RandomWalk
{
protected:
    int m; // valeur de M_n
public:
    RandomWalk_with_Min(int s0, double p) : RandomWalk(s0, p), m(s0){};
    int minimum() const { return m; }; // accesseur à m
    virtual void reset()
    {
        RandomWalk::reset();
        m = s_init;
    }; // redémarrage à l'état initial
    void update(std::mt19937 &G)
    {
        RandomWalk::update(G);
        if (s < m)
        {
            m = s;
        };
    };
    // compléter/modifier les méth. de la classe mère si nécessaire.
};
