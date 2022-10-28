#include <iostream>

#include <vector_random_generator/vector_random_generator.hpp>


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

template<typename Type>
void vector_type (std::uint64_t length = 200) {

    std::vector<Type> vector;

    std::random_device rd;

    set_random_vector(vector, rd, length);

    std::cout << "{";

    for (std::size_t i=0; i < length; i++) {

        std::cout << vector[i];

        if(i != (length - 1))
            std::cout << ", ";

        if((i + 1) % 10 == 0 && i != (length - 1))
            std::cout << std::endl;

    }

    std::cout << "}" << std::endl;

}

int main(int argc, char* argv[]) {

    if(argc == 1) {
        std::cout << "run" << std::endl;

        vector_type<std::int8_t>();
    }

    else if(argc == 2){
        std::cout << "run..." << std::endl;

        std::uint64_t length = std::stol(argv[1]);

        vector_type<std::int8_t>(length);
    }

    else if(argc == 3){
        std::cout << "ruuuuuuuuuuuuuuuun..." << std::endl;

        std::string type(argv[1]);
        std::uint64_t length = std::stol(argv[2]);

        if(type == "uint8_t"){
            vector_type<std::uint8_t>(length);
        }
        else if(type == "string"){
           vector_type<std::string>(length);
        }
        else if(type == "float"){
            vector_type<float>(length);
        }
    }
}
