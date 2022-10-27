#include <iostream>

#include <vector_random_generator/vector_random_generator.hpp>




int main(int argc, const char** argv) {

    std::vector<std::uint8_t> vector;
//    std::vector<std::uint16_t> vector;
//    std::vector<std::uint32_t> vector;
//    std::vector<std::int64_t> vector;

//    std::vector<std::int8_t> vector;
//    std::vector<std::int16_t> vector;
//    std::vector<std::int32_t> vector;
//    std::vector<std::int64_t> vector;

//    std::vector<std::string> vector;

//    std::vector<float> vector;
//    std::vector<double> vector;

//    std::vector<xt::dec8_t> vector;
//    std::vector<xt::udec8_t> vector;

    std::random_device rd;
    std::uint32_t length = 200;

    set_random_vector(vector, rd, length);

//    set_random_vector(vector, rd);


    std::cout << "{";

    for (std::size_t i=0; i < vector.size(); i++) {

        std::cout << (int)vector[i];

        if(i != (vector.size() - 1))
            std::cout << ", ";

        if((i + 1) % 10 == 0 && i != (vector.size() - 1))
            std::cout << std::endl;

    }

     std::cout << "}";

}
