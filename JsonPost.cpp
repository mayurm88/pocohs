/* 
 * File:   JsonPost.cpp
 * Author: mayur
 * 
 * Created on 5 July, 2016, 11:35 PM
 */

#include "JsonPost.hpp"


using Poco::Net::HTTPClientSession;
using Poco::URI;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPMessage;
using Poco::Exception;
using Poco::Net::HTTPResponse;
using Poco::StreamCopier;
using Poco::JSON::Object;
using Poco::JSON::Array;
using Poco::JSON::Parser;
using Poco::Dynamic::Var;

Object::Ptr JsonPost::doGetJSON(int id){
    std::string jsonStr = doGet(id);
    Parser parser;
    Var result = parser.parse(jsonStr);
    Object::Ptr object = result.extract<Object::Ptr>();
    return object;
}

Array::Ptr JsonPost::doGetJSON(){
    std::string jsonStr = doGet();
    Parser parser;
    Var result = parser.parse(jsonStr);
    Array::Ptr arr = result.extract<Array::Ptr>();
    return arr;
}

Object::Ptr JsonPost::doPostJSON(std::string title, std::string body, int userID){
    std::string jsonStr = doPost(title, body, userID);
    Parser parser;
    Var result = parser.parse(jsonStr);
    Object::Ptr object = result.extract<Object::Ptr>();
    return object;
}


Object::Ptr JsonPost::doUpdateJSON(int id, std::string title, std::string body, int userID){
    std::string jsonStr = doUpdate(id, title, body, userID);
    Parser parser;
    Var result = parser.parse(jsonStr);
    Object::Ptr object = result.extract<Object::Ptr>();
    return object;
}

std::string JsonPost::doGet(int id){
    try{
        std::string result;
        URI uri("http://jsonplaceholder.typicode.com/posts/" + std::to_string(id) );
        std::string path(uri.getPathAndQuery());
        HTTPClientSession session(uri.getHost(), uri.getPort());
        HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
        HTTPResponse response;
        session.sendRequest(request);
        std::istream& rs = session.receiveResponse(response);
        if(response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK){
            StreamCopier::copyToString(rs, result);
            return result;
        }
        else
            return "";
    }
    catch(Exception& exc){
        std::cerr<< exc.displayText() << std::endl;
    }
    return "";
}

std::string JsonPost::doGet(){
    try{
        std::string result;
        URI uri("http://jsonplaceholder.typicode.com/posts/");
        std::string path(uri.getPathAndQuery());
        HTTPClientSession session(uri.getHost(), uri.getPort());
        HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
        HTTPResponse response;
        session.sendRequest(request);
        std::istream& rs = session.receiveResponse(response);
        if(response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK){
            StreamCopier::copyToString(rs, result);
            return result;
        }
        else
            return "";
    }
    catch(Exception& exc){
        std::cerr<< exc.displayText() << std::endl;
    }
    return "";
}

std::string JsonPost::doPost(std::string title, std::string body, int userID){
    try{
        std::string result;
        URI uri("http://jsonplaceholder.typicode.com/posts/");
        std::string path(uri.getPathAndQuery());
        HTTPClientSession session(uri.getHost(), uri.getPort());
        session.setKeepAlive(true);
        HTTPRequest request(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_1);
        request.setKeepAlive(true);
        request.setContentType("application/x-www-form-urlencoded");
        std::string requestBody("title="+title+"&body="+body+"&userID="+std::to_string(userID));
        request.setContentLength(requestBody.length());
        HTTPResponse response;
        std::ostream& ostreamSession = session.sendRequest(request);
        ostreamSession << requestBody;
        std::istream& rs = session.receiveResponse(response);
        if(response.getStatus() == Poco::Net::HTTPResponse::HTTP_CREATED){
            StreamCopier::copyToString(rs, result);
            return result;
        }
        else
            return "";
    }
    catch(Exception& exc){
        std::cerr<< exc.displayText() << std::endl;
    }
    return "";
}

std::string JsonPost::doUpdate(int id, std::string title, std::string body, int userID){
    try{
        std::string result;
        URI uri("http://jsonplaceholder.typicode.com/posts/" + std::to_string(id));
        std::string path(uri.getPathAndQuery());
        HTTPClientSession session(uri.getHost(), uri.getPort());
        session.setKeepAlive(true);
        HTTPRequest request(HTTPRequest::HTTP_PUT, path, HTTPMessage::HTTP_1_1);
        request.setKeepAlive(true);
        request.setContentType("application/x-www-form-urlencoded");
        std::string requestBody("id="+std::to_string(id)+"&title="+title+"&body="+body+"&userID="+std::to_string(userID));
        request.setContentLength(requestBody.length());
        HTTPResponse response;
        std::ostream& ostreamSession = session.sendRequest(request);
        ostreamSession << requestBody;
        std::istream& rs = session.receiveResponse(response);
        if(response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK){
            StreamCopier::copyToString(rs, result);
            return result;
        }
        else
            return "";
    }
    catch(Exception& exc){
        std::cerr<< exc.displayText() << std::endl;
    }
    return "";
}

int JsonPost::doDelete(int id){
    try{
        std::string result;
        URI uri("http://jsonplaceholder.typicode.com/posts/" + std::to_string(id) );
        std::string path(uri.getPathAndQuery());
        HTTPClientSession session(uri.getHost(), uri.getPort());
        HTTPRequest request(HTTPRequest::HTTP_DELETE, path, HTTPMessage::HTTP_1_1);
        HTTPResponse response;
        session.sendRequest(request);
        std::istream& rs = session.receiveResponse(response);
        if(response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
            return 0;
        else
            return -1;
    }
    catch(Exception& exc){
        std::cerr<< exc.displayText() << std::endl;
    }
    return -1;
}

JsonPost::JsonPost() {
}

JsonPost::JsonPost(const JsonPost& orig) {
}

JsonPost::~JsonPost() {
}

