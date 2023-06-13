#include "request.h"

int main(int argc, char** argv) {
    struct Netflux* n = createFilmotheque(argv[1]);
    requestExe(n);

    deleteNetflux(&n);

    return 0;
}