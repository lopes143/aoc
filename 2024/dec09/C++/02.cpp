#include "dec09.hpp"

int main() {

    vector<int> disk;
    int max_ID = 0;
    size_t checksum = 0;
    if (!parse_input(disk)) {
        cout << "Error opening file." << endl;
        return EXIT_FAILURE;
    }

    //get max_ID
    for (size_t i=disk.size(); i>0; i--) {
        if (disk.at(i-1)!=-1) {
            max_ID = disk.at(i-1);
            break;
        }
    }

    //print_disk(disk);

    //defrag disk
    for (int id=max_ID; id>=0; id--) {
        pair<int,int> block = find_block_with_ID(disk, id);
        int block_size = block.second-block.first+1;
        pair<int,int> empty = find_empty_space(disk, block_size);
        if (empty.first!=-1 && empty.second!=-1 && empty.second<block.first) {
            fill_empty_with_block(disk, block, empty);
        }

        //print_disk(disk);
    }

    //compute checksum
    for (size_t i=0; i<disk.size(); i++) {
        if (disk.at(i) != -1)
            checksum += i * disk.at(i);
    }
        

    cout << "Filesystem checksum - block defrag (challenge 2): " << checksum << endl;
    //Right answer: 

    return EXIT_SUCCESS;

}