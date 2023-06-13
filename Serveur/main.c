#include "request.h"
#include "createFilmotheque.h"

int main(int argc, char** argv) {
    struct Netflux* n = createFilmotheque(argv[1]);
    requestExe(n);
    return 0;
}