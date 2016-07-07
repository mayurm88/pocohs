/* 
 * File:   JsonPost.hpp
 * Author: mayur
 *
 * Created on 5 July, 2016, 11:35 PM
 */

#include <string>
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Parser.h"
#include "Poco/URI.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Exception.h"
#include "Poco/StreamCopier.h"
#include <iostream>

#ifndef JSONPOST_HPP
#define	JSONPOST_HPP


class JsonPost {
public:
    JsonPost();
    JsonPost(const JsonPost& orig);
    std::string doGet(int id);
    Poco::JSON::Object::Ptr doGetJSON(int id);
    Poco::JSON::Array::Ptr doGetJSON();
    std::string doGet();
    std::string doPost(std::string title, std::string body, int userID);
    Poco::JSON::Object::Ptr doPostJSON(std::string title, std::string body, int userID);
    std::string doUpdate(int id, std::string title, std::string body, int userID);
    Poco::JSON::Object::Ptr doUpdateJSON(int id, std::string title, std::string body, int userID);
    int doDelete(int id);
    virtual ~JsonPost();
private:

};

#endif	/* JSONPOST_HPP */

