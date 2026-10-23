#include "dec09.hpp"

int main() {

    vector<int> disk;
    size_t checksum = 0;
    if (!parse_input(disk)) {
        cout << "Error opening file." << endl;
        return EXIT_FAILURE;
    }

    //defrag disk
    for (int i=0; i<disk.size(); i++) {
        if (disk[i]==-1)
            for (int j=disk.size()-1; j>i; j--)
                if (disk[j]!=-1) {
                    swap(disk[i],disk[j]);
                    break;
                }
    }

    //compute checksum
    for (int i=0; i<disk.size(); i++) {
        if (disk[i]!=-1)
            checksum+=i*disk[i];
    }
        

    cout << "Filesystem checksum (challenge 1): " << checksum << endl;
    //Right answer: 6259790630969

    return EXIT_SUCCESS;
}