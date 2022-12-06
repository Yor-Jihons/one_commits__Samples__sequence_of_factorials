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



int main( int argc, char** argv ){
    int n;
    {
        std::string str1;
        std::getline( cin, str1 );
        n = std::atoi( str1.c_str() );
    }

    std::vector<int> nums( n );
    {
        std::string str2;
        std::getline( cin, str2 );
        Util::StrVec sv = Util::split( str2 );
        for( int i = 0; i < n; i++ ){
            nums[i] = std::atoi( sv[i].c_str() );
        }
    }

    Original::Factorial fact;
    for( int i = 0; i < n; i++ ){
        cout << fact.At( nums[i] ) << flush;
        if( i != (n - 1) ) cout << " " << flush;
    }
    cout << endl;
return 0;
}
