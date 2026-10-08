#pragma once

#include <cstdint>

namespace sasd::core {

/// The first public core contract. More domain types will be added behind
/// this library without coupling them to a UI, operating system, or language.
[[nodiscard]] auto api_version() noexcept -> std::uint32_t;

} // namespace sasd::core
