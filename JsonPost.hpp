/* 
 * File:   JsonPost.hpp
 * Author: mayur
 *
 * Created on 5 July, 2016, 11:35 PM
 */

#include <string>

#ifndef JSONPOST_HPP
#define	JSONPOST_HPP


class JsonPost {
public:
    JsonPost();
    JsonPost(const JsonPost& orig);
    std::string doGet(int id);
    std::string doGet();
    std::string doPost(std::string title, std::string body, int userID);
    std::string doUpdate(int id, std::string title, std::string body, int userID);
    int doDelete(int id);
    virtual ~JsonPost();
private:

};

#endif	/* JSONPOST_HPP */

