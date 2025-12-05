#include "ScalarConverter.hpp"

enum LiteralType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_SPECIAL,
    TYPE_INVALID
};

static bool char_check(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return true;
    return false;
}

static bool special_check(const std::string &str)
{
    const std::string specials[6] = {
        "nan",
        "nanf",
        "+inf",
        "+inff",
        "-inf",
        "-inff",
    };

    for (size_t i = 0; i < 6; i++)
    {
        if (specials[i] == str)
            return true;
    }
    return false;
}

static bool int_check(const std::string &str)
{
    errno = 0;
    char *end;
    long val = strtol(str.c_str(), &end, 10);

    if (errno == ERANGE)
        return false;

    if (end == str.c_str())
        return false;

    while (*end)
    {
        if (!isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }

    return val >= INT_MIN && val <= INT_MAX;
}

static bool float_check(const std::string &str)
{
    if (str[str.size() - 1] != 'f')
        return false;

    if (str.find('.') == std::string::npos)
        return false;

    std::string s = str.substr(0, str.size() - 1);
    if (s.empty())
        return false;

    const char *cstr = s.c_str();
    char *end;
    errno = 0;

    double val = strtod(cstr, &end);

    if (errno == ERANGE)
        return false;

    if (end == cstr)
        return false;

    while (*end)
    {
        if (!isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }

    return val >= -FLT_MAX && val <= FLT_MAX;
}

static bool double_check(const std::string &str)
{
    if (str.find('.') == std::string::npos)
        return false;

    const char *cstr = str.c_str();
    char *end;
    errno = 0;

    strtod(cstr, &end);

    if (errno == ERANGE)
        return false;

    if (end == cstr)
        return false;

    while (*end)
    {
        if (!isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }

    return true;
}

static LiteralType detectType(const std::string &str)
{
    if (str.empty())
        return TYPE_INVALID;

    if (char_check(str))
        return TYPE_CHAR;

    if (special_check(str))
        return TYPE_SPECIAL;

    if (int_check(str))
        return TYPE_INT;

    if (float_check(str))
        return TYPE_FLOAT;

    if (double_check(str))
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

void print_scalar(const double *val)
{
    // --- char ---
    std::cout << "char: ";
    if (!val || std::isnan(*val) || std::isinf(*val) || *val < 0 || *val > 127)
        std::cout << "impossible";
    else if (!isprint(static_cast<char>(*val)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(*val) << "'";
    std::cout << std::endl;

    // --- int ---
    std::cout << "int: ";
    if (!val || std::isnan(*val) || std::isinf(*val) || *val < INT_MIN || *val > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(*val);
    std::cout << std::endl;

    // --- float ---
    std::cout << "float: ";
    if (!val)
        std::cout << "impossible" << std::endl;
    else
    {
        float f = static_cast<float>(*val);
        if (std::isnan(f))
            std::cout << "nanf";
        else if (std::isinf(f))
            std::cout << (f > 0 ? "+inff" : "-inff");
        else
            std::cout << std::fixed << std::setprecision(1) << f << "f";
        std::cout << std::endl;
    }

    // --- double ---
    std::cout << "double: ";
    if (!val)
        std::cout << "impossible" << std::endl;
    else
    {
        if (std::isnan(*val))
            std::cout << "nan";
        else if (std::isinf(*val))
            std::cout << (*val > 0 ? "+inf" : "-inf");
        else
            std::cout << std::fixed << std::setprecision(1) << *val;
        std::cout << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    const LiteralType type = detectType(str);
    double val;
    char *end = 0;

    switch (type)
    {
    case TYPE_CHAR:
        val = static_cast<double>(str[0]);
        break;
    case TYPE_INT:
        val = static_cast<double>(std::strtol(str.c_str(), &end, 10));
        break;
    case TYPE_FLOAT:
        val = std::strtod((str.substr(0, str.length() - 1)).c_str(), &end);
        break;
    case TYPE_DOUBLE:
        val = std::strtod(str.c_str(), &end);
        break;
    case TYPE_SPECIAL:
        if (str == "nan" || str == "nanf")
            val = std::numeric_limits<double>::quiet_NaN();
        else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
            val = std::numeric_limits<double>::infinity();
        else if (str == "-inf" || str == "-inff")
            val = -std::numeric_limits<double>::infinity();
        break;
    default:
        print_scalar(NULL);
        return;
    }
    print_scalar(&val);
}
