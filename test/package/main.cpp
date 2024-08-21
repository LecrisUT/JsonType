#include "json_type.hpp"

int main() {
    auto obj = JsonType::object();
    obj["A"] = JsonType::list();
    std::visit(
        [](auto&& A) {
            using T = std::decay_t<decltype(A)>;
            if constexpr (std::is_same_v<T, JsonType::list>) {
                A.push_back(1);
            }
        },
        obj["A"]);
    return 0;
}
