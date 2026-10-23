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
    for (int i=disk.size()-1; i>=0; i--) {
        if (disk.at(i)!=-1) {
            max_ID = disk.at(i);
            break;
        }
    }

    print_disk(disk);

    //defrag disk
    for (int id=max_ID; id>=0; id--) {
        optional<diskBlock> block = find_block_with_ID(disk, id);
        optional<diskBlock> empty = find_empty_space(disk,block->size);

        if (!empty || empty->right>block->left) {
            if (block->size!=empty->size) cout << "Size mismatch\n";
            continue;
        }
        
        while (block->left!=block->right && empty->left!=empty->right) {
            swap(block->left,empty->left);
            block->left++;
            empty->left++;
        }

        print_disk(disk);
    }

    //compute checksum
    for (int i=0; i<disk.size(); i++) {
        if (disk.at(i) != -1)
            checksum += i * disk.at(i);
    }
        

    cout << "Filesystem checksum - block defrag (challenge 2): " << checksum << endl;
    //Right answer: 

    return EXIT_SUCCESS;

}