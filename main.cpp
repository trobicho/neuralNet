#include "NeuralNet.h"
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));
    NeuralNet neuralNet(28*28, 10);
    return 0;
}
