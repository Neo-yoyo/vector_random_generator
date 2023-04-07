#include <iostream>
#include <fstream>

#include <vector_random_generator/vector_random_generator.hpp>



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


    /// Всё что вывели в консоль - записываем в файл
    /// выходная директория
    std::string path_out{"/home/neo_yoyo/Документы/trash"};

    /// формируем имя выходного файла
    std::string out_filename = path_out + "/" + "random_set.txt";

    /// открываем выходной файл
    std::ofstream out_file(out_filename);

    /// Если мы не можем открыть этот файл для записи данных,
    if (!out_file)
    {
        /// то выводим сообщение об ошибке и выполняем функцию exit()
        std::cerr << "File could not be opened for writing!" << std::endl;
        exit(1);
    }

    out_file << "{";
    for (std::size_t i=0; i < length; i++){
        out_file << vector[i];

        if(i != (length - 1))
            out_file << ", ";

        if((i + 1) % 10 == 0 && i != (length - 1))
            out_file << std::endl;

    }

    out_file << "}" << std::endl;

    /// закрываем файл
    out_file.close();

}



int main(int argc, char* argv[]) {

    if(argc == 1) {
        std::cout << "run" << std::endl;

        vector_type<std::uint16_t>();
    }


    else if(argc == 2){
        std::cout << "run..." << std::endl;

        std::uint64_t length = std::stol(argv[1]);

        vector_type<std::uint16_t>(length);
    }


    else if(argc == 3){
        std::cout << "ruuuuuuuuuuuuuuuun..." << std::endl;

        std::string type(argv[1]);
        std::uint64_t length = std::stol(argv[2]);

        if(type == "uint8"){
            vector_type<std::uint8_t>(length);
        }
        else if(type == "uint16"){
           vector_type<std::uint16_t>(length);
        }
        else if(type == "uint32"){
           vector_type<std::uint32_t>(length);
        }
        else if(type == "uin64"){
           vector_type<std::uint64_t>(length);
        }
        else if(type == "int8"){
           vector_type<std::int8_t>(length);
        }
        else if(type == "int16"){
           vector_type<std::int16_t>(length);
        }
        else if(type == "int32"){
           vector_type<std::int32_t>(length);
        }
        else if(type == "int64"){
           vector_type<std::int64_t>(length);
        }
        else if(type == "string"){
           vector_type<std::string>(length);
        }
        else if(type == "float"){
            vector_type<float>(length);
        }
        else if(type == "double"){
            vector_type<double>(length);
        }
    }

    return 0;
}


/// пример

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> fb9db57 (amend 2)

=======
/// amend
>>>>>>> 89be182 (amend)
<<<<<<< HEAD
=======

>>>>>>> 6d77136 (amend)
=======
>>>>>>> fb9db57 (amend 2)












