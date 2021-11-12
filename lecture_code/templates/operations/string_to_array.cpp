#include <iostream>
#include <string>

#include <vector>

std::vector<std::string> string_to_array(const std::string &s) {

  std::vector<std::string> words;
  size_t found = 0;
  size_t first = 0;
  while (found != std::string::npos) {
    first = found;
    found = s.find_first_of(' ', found);

    if (found != std::string::npos) {
      std::string word = s.substr(first, found - first);
      std::cout << first << " " << found << " " << word << std::endl;
      words.push_back(word);
      found++;
    } else {
      std::string word = s.substr(first);
      words.push_back(word);
    }
    // get the last
  }
  return words;
}

int main() {

  std::string ex = "Hi my name is adrian!";

  auto words = string_to_array(ex);

  for (const auto &word : words) {
    std::cout << word << std::endl;
  }

  ///
}
