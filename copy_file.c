#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int src = open("source.txt", O_RDONLY);
    int dest = open("dest.txt", O_WRONLY | O_CREAT, 0644);
    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }
    close(src);
    close(dest);
    return 0;
}
