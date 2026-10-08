#include <sasd/core/core.hpp>

#include <cassert>

int main() {
    assert(sasd::core::api_version() == 1U);
    return 0;
}
