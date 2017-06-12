#include <iostream>
#include <optional>
#include <fstream>
#include <tuple>
#include <string>
#include <algorithm>
#include <vector>

#include "either"

using namespace std;

using error_mesage = string;

either < error_mesage, size_t >
file_lines_count(string_view filename)
{
    ifstream file(filename.data());
    if (!file) return "Can not open file"s;
    return count(std::istreambuf_iterator<char>(file),
                 std::istreambuf_iterator<char>(),
                 '\n');
};


auto safe_sum = [](auto a, auto b)
{
    static_assert(integral_constant<int32_t, a.value + b.value>::value
                  <= numeric_limits<int16_t>::max());
    return a + b;
};


int main()
{
    file_lines_count("Makefidle")
            .if_left_do([](error_mesage error_message) { cerr << error_message << endl; })
            .if_right_do([](int count) { cout << "File lines count: " << count << endl; });

    file_lines_count("Makefile")
            .match_call([](auto result) { cout << "Result: " << result << endl; });

    safe_sum(integral_constant<int16_t, 55525>{},
             integral_constant<int16_t, 55555>{});

    return 0;
}