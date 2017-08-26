/*
 * Developed by Alexander Hart
 * Plant Computational Genomics Lab
 * University of Connecticut
 *
 * 2017
*/

#ifndef ENTAP_EXCEPTIONHANDLER_H
#define ENTAP_EXCEPTIONHANDLER_H

#include <string>
#include <exception>
#include <sstream>

class ExceptionHandler: public std::exception{

    public:
        ExceptionHandler(const std::string&, int);
        const char* what();
        int getErr_code() const;
        void print_msg();

    private:
        int err_code;
        std::string message;
    };

#endif //ENTAP_EXCEPTIONHANDLER_H
