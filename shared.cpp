#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; 
int shared = 0; 

void writerThreadFunction() {
    mtx.lock();
    std::cout << "Writer thread" << std::endl;
    sharedData = 1024; 
    mtx.unlock(); 
}

void readerThreadFunction() {
    mtx.lock();
    std::cout << "Reader thread: " << sharedData << std::endl;
    mtx.unlock();
}

int main() {
    std::thread writerThread(writerThreadFunction);
    std::thread readerThread(readerThreadFunction);
    writerThread.join();
    readerThread.join();
    return 0;
}
