#include "badcard.hpp"
#include "goodcard.hpp"
#include "bitcard.hpp"

#include <iostream>
#include <random>


// A set of flags that determine which tests to run.
constexpr unsigned bad = 0x01;   // 0b001
constexpr unsigned good = 0x02;  // 0b010
constexpr unsigned bits = 0x04;  // 0b100

int 
main(int argc, char* argv[])
{
  // Initialize the random number facility.
  std::random_device rand;
  std::default_random_engine prng(rand());

  // Check arguments to determine which tests to run. If nothing is specified
  // run all tests. If any arguments are specified, run only those tests.
  unsigned which = bad | good | bits;
  if (argc > 1)
    which = 0;
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "bad") {
      which |= bad;
    }
    else if (arg == "good") {
      which |= good;
    }
    else if (arg == "bits") {
      which |= bits;
    }
    else {
      std::cerr << "invalid argument\n";
      return 1;
    }
  }

  if (which & bad) {
    std::cout << "--- bad ---\n";
    BadDeck d1 = get_bad_deck();
    BadDeck d2 = d1;
    std::cout << d2 << '\n';
    std::shuffle(d2.begin(), d2.end(), prng);
    std::cout << d2 << '\n';
    std::sort(d2.begin(), d2.end());
    std::cout << d2 << '\n';
    if (d2 != d1)
      std::cout << "deck not reordered!\n";
  }

  if (which & good) {
    std::cout << "--- good ---\n";
    GoodDeck d1 = get_good_deck();
    GoodDeck d2 = d1;
    std::cout << d2 << '\n';
    std::shuffle(d2.begin(), d2.end(), prng);
    std::cout << d2 << '\n';
    std::sort(d2.begin(), d2.end());
    std::cout << d2 << '\n';
    if (d2 != d1)
      std::cout << "deck not reordered!\n";
  }

  if (which & bits) {
    std::cout << "--- bits ---\n";
    BitDeck d1 = get_bit_deck();
    BitDeck d2 = d1;
    std::cout << d2 << '\n';
    std::shuffle(d2.begin(), d2.end(), prng);
    std::cout << d2 << '\n';
    std::sort(d2.begin(), d2.end());
    std::cout << d2 << '\n';
    if (d2 != d1)
      std::cout << "deck not reordered!\n";
  }
}
