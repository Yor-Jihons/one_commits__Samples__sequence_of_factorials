#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}

namespace Original{
    class Factorial{
        public:
            Factorial( int size = 7 ) : nums_(Factorial::CreateVec(size)){}

            int At( int index ){
                if( index < 0 || index > static_cast<int>(nums_.size()) ) throw std::out_of_range("Thrown FormatException!");
            return nums_[index];
            }
        protected:
            static std::vector<int> CreateVec( int n ){
                std::vector<int> nums( n );
                nums[0] = 1;
                for( int i = 1; i < n; i++ ){
                    nums[i] = nums[i - 1] * i;
                }
            return nums;
            }
        private:
            std::vector<int> nums_;
    };
}

namespace Original{
    class FormatException : public std::exception{
        public:
            FormatException(){}
            ~FormatException() = default;

            const char* what( void ) const noexcept{
                return "This data is wrong.";
            }
    };

    class OutOfBoundException : public std::exception{
        public:
            OutOfBoundException(){}
            ~OutOfBoundException() = default;

            const char* what( void ) const noexcept{
                return "This data is out of bound.";
            }
    };
}


namespace Original{
    bool IsDigitString( const std::string& str ){
        for( int i = 0; i < static_cast<int>(str.size()); i++ ){
            if( std::isdigit( str[i] ) == 0 ) return false;
        }
    return true;
    }
    int ConvertStringToInt( const std::string& str ){
        if( !IsDigitString( str ) ) throw FormatException();
        int n = std::atoi( str.c_str() );
    return n;
    }

    bool IsValidNumber4N( int n ){
        if( n >= 1 && n <= 10 ) return true;
    return false;
    }

    bool IsValidNumber4An( int n ){
        if( n >= 0 && n <= 6 ) return true;
    return false;
    }
}



int main( int argc, char** argv ){
    try{
        int n;
        {
            std::string str1;
            std::getline( cin, str1 );
            n = std::atoi( str1.c_str() );
            if( !Original::IsValidNumber4N( n ) ) throw Original::OutOfBoundException();
        }

        std::vector<int> nums( n );
        {
            std::string str2;
            std::getline( cin, str2 );
            Util::StrVec sv = Util::split( str2 );
            for( int i = 0; i < n; i++ ){
                nums[i] = std::atoi( sv[i].c_str() );
                if( !Original::IsValidNumber4An( nums[i] ) ) throw Original::OutOfBoundException();
            }
        }

        Original::Factorial fact;
        for( int i = 0; i < n; i++ ){
            cout << fact.At( nums[i] ) << flush;
            if( i != (n - 1) ) cout << " " << flush;
        }
        cout << endl;
    }catch( std::exception& e ){
        cout << e.what() << endl;
    }
return 0;
}
