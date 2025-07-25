#include "filesystem.h"
#include <string.h>

#define MAX_FILES 100

struct File {
    char name[32];
    char data[256];
};

struct FileSystem {
    File files[MAX_FILES];
    int fileCount;
};

FileSystem fs;

void create_file(const char* name, const char* data) {
    if (fs.fileCount < MAX_FILES) {
        File* file = &fs.files[fs.fileCount++];
        strncpy(file->name, name, 32);
        strncpy(file->data, data, 256);
    }
}

const char* read_file(const char* name) {
    for (int i = 0; i < fs.fileCount; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            return fs.files[i].data; // Return file data
        }
    }
    return nullptr; // File not found
}
