import moderna.variant_error;
import moderna.test_lib;
#include <stdexcept>
#include <system_error>

auto tests =
  moderna::test_lib::make_tester("variant_error")
    .add_test(
      "cast_add_back",
      []() {
        moderna::variant_error<std::out_of_range> err{std::out_of_range{"yay"}};
        static_assert(std::same_as<
                      decltype(err.cast_add_back<std::system_error>()),
                      moderna::variant_error<std::out_of_range, std::system_error>>);
      }
    )
    .add_test(
      "cast_add_front",
      []() {
        moderna::variant_error<std::out_of_range> err{std::out_of_range{"yay"}};
        static_assert(std::same_as<
                      decltype(err.cast_add_front<std::system_error>()),
                      moderna::variant_error<std::system_error, std::out_of_range>>);
      }
    )
    .add_test(
      "what",
      []() {
        struct lol_error {
          constexpr const char *what() const noexcept {
            return "HAHA";
          }
        };
        constexpr moderna::variant_error<lol_error> err{lol_error{}};
        static_assert(err.what() == "HAHA");
      }
    )
    .add_test("cast_to", []() {
      moderna::variant_error<std::out_of_range> err{std::out_of_range{"lol"}};
      static_assert(std::same_as<
                    decltype(err.cast_to<
                             moderna::variant_error<std::system_error, std::out_of_range>>()),
                    moderna::variant_error<std::system_error, std::out_of_range>>);
    });

int main() {
  tests.print_or_exit();
}