/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */

#ifndef __EIRODS_ERROR_H__
#define __EIRODS_ERROR_H__

// =-=-=-=-=-=-=-
// STL Includes
#include <string>
#include <sstream>
#include <vector>
#include <cstdarg>

// =-=-=-=-=-=-=-
// irods includes
#include "rodsType.hpp"

// =-=-=-=-=-=-=-
// boost assertion handling macro, needed everywhere
// see http://stackoverflow.com/questions/1067226/c-multi-line-macro-do-while0-vs-scope-block
// for the WHY!? regarding the while(0) loop
#ifndef BOOST_ASSERT_MSG
#define BOOST_ASSERT_MSG( cond, msg ) do \
{ if (!(cond)) { std::ostringstream str; str << msg; std::cerr << str.str(); std::abort(); } \
} while(0)
#endif
#include <boost/assert.hpp>

namespace eirods {
    /// =-=-=-=-=-=-=-
    /// @brief error stack object which holds error history
    class error {
    public:
        // =-=-=-=-=-=-=-
        // Constructors
        error();
        error( 
            bool,          // status
            long long,     // error code 
            std::string,   // message
            std::string,   // file name
            int,           // line number
            std::string ); // function  
        error( 
            bool,           // status
            long long,      // error code
            std::string,    // message
            std::string,    // file name 
            int,            // line number     
            std::string,    // function
            const error& ); // previous error 
        error( const error& );   

        // =-=-=-=-=-=-=-
        // Destructor
        ~error();
		 
        // =-=-=-=-=-=-=-
        // Operators
        error& operator=( const error& );
		
        // =-=-=-=-=-=-=-
        // Members
        bool        status() const;
        long long   code() const;
        std::string result();
        bool        ok();

        // =-=-=-=-=-=-=-
        // Mutators
        void code  ( long long _code   ) { code_   = _code;   }
        void status( bool      _status ) { status_ = _status; }
        
    private:
        // =-=-=-=-=-=-=-
        // Attributes
        bool        status_;
        long long   code_;
        std::string message_;
        std::vector< std::string > result_stack_;
        
        // =-=-=-=-=-=-=-
        // Members
        std::string build_result_string( std::string, int, std::string );
		
    }; // class error

    error assert_error(bool expr_, long long code_, const std::string& file_, const std::string& function_, int line_, const std::string& format_, ...);
    error assert_pass(bool expr_, const error& _error, const std::string& _file, const std::string& _function, int _line, const std::string& _format, ...);
    error assert_pass_msg(bool expr_, const error& _error, const std::string& _file, const std::string& _function, int _line, const std::string& _format, ...);
    
}; // namespace eirods



#define ERROR( code_, message_ ) ( eirods::error( false, code_, message_, __FILE__, __LINE__, __FUNCTION__ ) )
#define PASS( prev_error_ ) (eirods::error( prev_error_.status(), prev_error_.code(), "", __FILE__, __LINE__, __FUNCTION__, prev_error_ ) )
#define PASSMSG( message_, prev_error_ ) (eirods::error( prev_error_.status(), prev_error_.code(), message_, __FILE__, __LINE__, __FUNCTION__, prev_error_ ) )
#define CODE( code_ ) ( eirods::error( true, code_, "", __FILE__, __LINE__, __FUNCTION__ ) )
#define SUCCESS( ) ( eirods::error( true, 0, "", __FILE__, __LINE__, __FUNCTION__ ) )

#define ASSERT_ERROR(expr_, code_, format_, ...)  (eirods::assert_error(expr_, code_, __FILE__, __FUNCTION__, __LINE__, format_, ##__VA_ARGS__))
#define ASSERT_PASS(prev_error_, format_, ...) (eirods::assert_pass(prev_error_.ok(), prev_error_, __FILE__, __FUNCTION__, __LINE__, format_, ##__VA_ARGS__))
#define ASSERT_PASS_MSG(prev_error_, format_, ...) (eirods::assert_pass_msg(prev_error_.ok(), prev_error_, __FILE__, __FUNCTION__, __LINE__, format_, ##__VA_ARGS__))

#endif // __EIRODS_ERROR_H__


