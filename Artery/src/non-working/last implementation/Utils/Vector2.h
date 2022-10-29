#pragma once

namespace engine {

    template <typename T>
    class Vector2
    {
    public:
        constexpr Vector2();

        constexpr Vector2(T X, T Y);

        template <typename U>
        constexpr explicit Vector2(const Vector2<U>& vector);

        T x;
        T y;
    };


    template <typename T>
    constexpr Vector2<T> operator -(const Vector2<T>& right);

    template <typename T>
    constexpr Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);

    template <typename T>
    constexpr Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);

    template <typename T>
    constexpr Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

    template <typename T>
    constexpr Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);

    template <typename T>
    constexpr Vector2<T> operator *(const Vector2<T>& left, T right);

    template <typename T>
    constexpr Vector2<T> operator *(T left, const Vector2<T>& right);

    template <typename T>
    constexpr Vector2<T>& operator *=(Vector2<T>& left, T right);

    template <typename T>
    constexpr Vector2<T> operator /(const Vector2<T>& left, T right);

    template <typename T>
    constexpr Vector2<T>& operator /=(Vector2<T>& left, T right);

    template <typename T>
    constexpr bool operator ==(const Vector2<T>& left, const Vector2<T>& right);

    template <typename T>
    constexpr bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

#include <Utils/Vector2.inl>

    using Vector2i = Vector2<int>;
    using Vector2u = Vector2<unsigned int>;
    using Vector2f = Vector2<float>;

}