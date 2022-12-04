#pragma once

#include <random>
#include <vector>
#include <string>
#include <map>
#include <concepts>

// Максимальная длинна строки
#define MAX_LENGTH_STRING   32

// Максимальный размер массива
#define MAX_SIZE_VECTOR     100


/** @brief Для заполнения контейнера используется генератор случайных значений для разных типов.
 * Сначала утанавливаются произвольные значения разных типов, затем вектор заполняется рандомными величинами.
 * Для контейнеров, где ключ и значение представлены одноименными типами этого достаточно
 * В случаях когда ключ и значение имеют разноименные типы, важно чтобы длинна сгенерированных случайным образом векторов для ключа и значения совпадала.
 * Также в этом случае важно, чтобы в сгенерированном векторе ключей все значения были уникальными, иначе тест не выполняется для повторяющихся элементов
 */


/**
 * @brief	Устанавливает произвольное значение (для интегральных типов)
 *
 * @param value_	Значение переменной.
 * @param rd_		random device
 */
template<typename Type>
concept integer_type = std::integral<Type>;


template <integer_type I>
inline void set_random(I& value_, std::random_device &rd_) {
    // Получим минимальное значение для этого типа
    I min = std::numeric_limits<I>::min();
    // Получим максимальное значение для этого типа
    I max = std::numeric_limits<I>::max();
    // Создадим ограничитель для произволього значения
    std::uniform_int_distribution<I> dist(min, max);
    // получим произвольное значение
    value_ = static_cast<I>(dist(rd_));
}



/**
 * @brief	Устанавливает произвольное значение (для bool типа)
 *
 * @param value_	Значение переменной.
 * @param rd_		random device
 */
template<>
inline void set_random<bool>(bool &value_, std::random_device &rd_) {
    std::uint8_t tmp;
    set_random<std::uint8_t>(tmp, rd_);
    value_ = (tmp % 2) == 0 ? true : false;
}



/**
 * @brief	Устанавливает произвольное значение (для string типа)
 *
 * @param value_	Значение переменной.
 * @param rd_		random device
 */
template<typename Type>
concept string_type = std::same_as<Type, std::string>;

template<string_type S>
inline void set_random(S &value_, std::random_device &rd_) {
    std::uint32_t length;
    set_random<std::uint32_t>(length, rd_);
    length = length % MAX_LENGTH_STRING;
    value_.resize(length);
    std::uint8_t rnd = 0x00;
    for (std::uint32_t cycle=0; cycle < length; cycle++) {
        set_random<std::uint8_t>(rnd, rd_);
        value_[cycle] = static_cast<char>(0x21 + rnd % (0x7E - 0x21));
    }
}



/**
 * @brief	Генерируем произвольные значения  (для float и double)
 *
 * @param value_	Значение переменной с плавающей точкой
 * @param rd_		random device
 */
template<typename Type>
concept float_type = std::floating_point<Type>;

template<float_type F>
inline void set_random(F &value_, std::random_device &rd_) {
    std::uint16_t tmp_1;
    std::uint8_t tmp_2 = 0;

    set_random<std::uint16_t>(tmp_1, rd_);

    while (tmp_2 == 0)
        set_random<std::uint8_t>(tmp_2, rd_);

    value_ = static_cast<F>(tmp_1) / static_cast<F>(tmp_2);
}


///**
// * @brief	Устанавливает произвольное значение (для float типа)
// *
// * @param value_	Значение переменной.
// * @param rd_		random device
// */
//template<>
//inline void set_random<float>(float &value_, std::random_device &rd_) {
//    set_random_f<float>(value_, rd_);
//}


///**
// * @brief	Устанавливает произвольное значение (для double типа)
// *
// * @param value_	Значение переменной.
// * @param rd_		random device
// */
//template<>
//inline void set_random<double>(double& value_, std::random_device& rd_) {
//    set_random_f<double>(value_, rd_);
//}



///**
// * @brief	Устанавливает произвольное значение (для положительного типа xt::udec8_t )
// *
// * @param value_	Значение переменной.
// * @param rd_		random device
// */
//template<>
//inline void set_random<xt::udec8_t>(xt::udec8_t& value_, std::random_device& rd_) {

//    std::uint64_t tmp;
//    set_random (tmp, rd_);
//    value_ = xt::udec8_t::make(tmp);
//}

///**
// * @brief	Устанавливает произвольное значение (для беззнакового типа xt::dec8_t )
// *
// * @param value_	Значение переменной.
// * @param rd_		random device
// */
//template<>
//inline void set_random<xt::dec8_t>(xt::dec8_t& value_, std::random_device& rd_) {

//    std::int64_t tmp;
//    set_random (tmp, rd_);
//    value_ = xt::dec8_t::make(tmp);
//}

/**
 * @brief	ЗАполняет произвольными значечениями вектор
 *
 * @param value_	Значение переменной.
 * @param rd_		random device
 */
template<typename Type>
inline void set_random_vector(std::vector<Type> &value_, std::random_device &rd_) {
    std::uint32_t length;

    set_random<std::uint32_t>(length, rd_);
    length = length % MAX_SIZE_VECTOR;

    value_.resize(length);

    for (std::uint32_t cycle=0; cycle < length; cycle++) {
        set_random<Type>(value_[cycle], rd_);
    }
}


/**
 * @brief	Заполняет произвольными значечениями вектор заданной длины
 *
 * Перегрузка функции set_random_vector необходима для контейнеров, где ключ и значение имеют разноименные типы.
 * Здесь важно чтобы длинна сгенерированных случайным образом векторов для ключа и значения совпадала.
 * Также в этом случае важно, чтобы в сгенерированном векторе ключей все значения были уникальными, иначе тест не выполняется для повторяющихся элементов
 *
 * @param value_	Значение переменной.
 * @param rd_		random device
 * @param length_ длинна вектора
 */
template<typename Type>
inline void set_random_vector(std::vector<Type> &value_, std::random_device &rd_, std::uint32_t length_) {

    value_.resize(length_);

    /// карта для проверки сгенерированных чисел на уникальность
    std::map<Type, bool> values;

    for (std::uint32_t cycle=0; cycle < length_; cycle++) {
        /// временная переменная для генерации случайного значения
        Type value;
        /// Здесь мы отбираем только уникальные значения
        do {
            /// генерируем случайное значение
            set_random<Type>(value, rd_);
        }
        /// если такоего значения нет
        while (values.find(value) != values.end());
        /// добавляем его в карту
        values.insert(std::pair<Type, bool>(value, true));

        value_[cycle] = value;
    }
}

