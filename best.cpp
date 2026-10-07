#include <iostream>

using namespace std;

void bestFit(int blockSize[], int m, const int processSize[], int n)
{
    int* allocation = new int[n];

    for (int i = 0; i < n; ++i)
        allocation[i] = -1;

    for (int i = 0; i < n; ++i) {
        int bestIdx = -1;
        int minSobrante = -1;

        for (int j = 0; j < m; ++j) {
            if (blockSize[j] >= processSize[i]) {
                int sobrante = blockSize[j] - processSize[i];
                if (bestIdx == -1 || sobrante < minSobrante) {
                    minSobrante = sobrante;
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nNo. Proceso\tTamano Proceso\tNo. Bloque\n";
    for (int i = 0; i < n; ++i) {
        cout << " " << (i + 1) << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << (allocation[i] + 1);
        else
            cout << "No Asignado";
        cout << "\n";
    }

    delete[] allocation;
}


int main()
{
    int blockSize[]   = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 301};

    int m = sizeof(blockSize)   / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);
    return 0;
}