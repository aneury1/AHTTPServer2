#pragma once
#include "HttpServer.h"

#define INVALID_HTTP_URI "InvalidHttpUriFromAhttpServer"
void handleClientInfoFromThread(std::shared_ptr<ClientInfo> client);

Response *getFavIcon(Request *request);
ParserEndpoint parseRequest(Request &request, ParserEndpoint notFoundHandler);
std::unordered_map<std::string, std::string> parseRequest(const std::string &request);
std::unordered_map<std::string, std::string> parseHeaders(const std::string &request);
std::string RequestVerbToString(RequestVerb httpVerb);
std::string fetchJsBuilder(
    std::string url, 
    std::string body, 
    std::map<std::string,std::string>fetchOptions,
    std::map<std::string,std::string>httpHeaders);
Response *DefaultEndpoint(Request *request);
Response *DefaultEndpointW200(Request *request);

std::pair<std::string, ParserEndpoint> getEndpointFromMap(const std::string uri,const std::map<std::string, ParserEndpoint>& enpointList);
UrlDatatype getNodeDataTypeByPattern(const std::string& routeNode);
const std::string UrlDatatypeAsStr(const UrlDatatype& type);
UrlDatatype getDataTypeByValue(std::string value);
std::vector<std::string> splitWords(std::string word, char sp);
bool validatePatterByUrl(std::vector<std::string> uri, std::vector<std::string> pattern);
std::unordered_map<std::string, std::string> parseUrlParams(std::string url);



std::string generateStrRequestPaylod(const std::string& path, const RequestVerb& verb); 
std::string extractHttpVerb(const std::string request);
std::string extractUrlWithQueryParams(std::string request);
std::string extractUrl(std::string request);
std::string buildHttpResponseResponse(
    std::unordered_map<std::string, std::string> headers,
    std::string body,
    HttpResponseCode statusCode
);



std::string RequestVerbToString(RequestVerb httpVerb);