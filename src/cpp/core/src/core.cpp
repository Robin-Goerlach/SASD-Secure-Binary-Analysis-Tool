#include <sasd/core/core.hpp>

namespace sasd::core {

auto api_version() noexcept -> std::uint32_t {
    return 1U;
}

} // namespace sasd::core
