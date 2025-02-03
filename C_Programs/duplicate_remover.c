#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <gcrypt.h>
#include <limits.h>  // For PATH_MAX

// If PATH_MAX is not defined, set it to 4096
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define BUFFER_SIZE 16384

// Function to check if the path is a file or a directory
int is_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);  // Check if it's a regular file
}

// Function to compute the SHA-256 hash of a file
void compute_sha256_hash(const char *filename, unsigned char *hash) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    gcry_md_hd_t handle;
    gcry_md_open(&handle, GCRY_MD_SHA256, 0);

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        gcry_md_write(handle, buffer, bytes_read);
    }

    memcpy(hash, gcry_md_read(handle, 0), gcry_md_get_algo_dlen(GCRY_MD_SHA256));
    gcry_md_close(handle);

    fclose(file);
}

// Function to compare files and ask user for deletion
void check_for_duplicates(const char *file1, const char *file2) {
    if (is_file(file1) && is_file(file2)) {
        unsigned char hash1[32], hash2[32];
        compute_sha256_hash(file1, hash1);
        compute_sha256_hash(file2, hash2);

        // Compare the hashes
        if (memcmp(hash1, hash2, 32) == 0) {
            printf("Duplicate found: %s and %s\n", file1, file2);
            printf("Do you want to delete %s? (y/n): ", file2);
            char response;
            scanf(" %c", &response);
            if (response == 'y' || response == 'Y') {
                if (remove(file2) == 0) {
                    printf("File deleted: %s\n", file2);
                } else {
                    perror("Failed to delete file");
                }
            } else {
                printf("File not deleted: %s\n", file2);
            }
        }
    }
}

// Recursive function to scan directories and check for duplicates
void scan_directory(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    char filepath1[PATH_MAX], filepath2[PATH_MAX];

    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build the full path for the first file
        snprintf(filepath1, sizeof(filepath1), "%s/%s", dirpath, entry->d_name);

        // Check against the rest of the directory entries
        DIR *dir2 = opendir(dirpath);
        struct dirent *entry2;
        while ((entry2 = readdir(dir2)) != NULL) {
            if (strcmp(entry2->d_name, entry->d_name) != 0) {
                snprintf(filepath2, sizeof(filepath2), "%s/%s", dirpath, entry2->d_name);
                check_for_duplicates(filepath1, filepath2);
            }
        }
        closedir(dir2);
    }

    closedir(dir);
}

int main() {
    char dirpath[PATH_MAX];
    printf("Enter the directory path: ");
    scanf("%s", dirpath);

    scan_directory(dirpath);
    return 0;
}

